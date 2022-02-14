#include "librocket.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define DIVIDE_ROUND_UP(a, b) (((a) + (b) - 1) / (b))
#define NEAREST_MULTIPLE(a, b) (((a) + (b) - 1) & ~((b) - 1))

typedef int32_t s32;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

struct DecompressionParams decompressionParamsTable[2] = {
    {3, 10, 6, 0x3F},
    {3, 11, 5, 0x1F}
};

struct CompressionWindow {
    uint16_t length;
    uint16_t offset;
};


// minOffset and maxOffset are both positive, but go backwards
// i.e. minOffset = 0 and maxOffset = 10 means look up to 10 bytes before the current position
static int find_windows(struct CompressionWindow *windows, struct CompressionWindow **bestWindow, uint8_t *input, int curPosition, int minOffset, int maxOffset, int maxLength, int lookahead)
{
    int numWindows = 0;
    int bestLength = 0;
    uint8_t *curOutput;
    uint8_t *curWindowPos;
    uint8_t *lastWindowPos;

    maxOffset = MIN(curPosition, maxOffset);
    curOutput = input + curPosition;
    curWindowPos = curOutput - maxOffset;
    lastWindowPos = curOutput - minOffset;

    while (curWindowPos <= lastWindowPos)
    {
        int curLength = 0;
        uint8_t *curInputByte = curWindowPos;
        uint8_t *curOutputByte = curOutput;
        while (*curInputByte == *curOutputByte && curLength < maxLength && (lookahead || curInputByte < curOutput))
        {
            curInputByte++;
            curOutputByte++;
            curLength++;
        }
        if (curLength >= 3)
        {
            windows[numWindows].length = curLength;
            windows[numWindows].offset = curOutput - curWindowPos;
            if (curLength > bestLength)
            {
                *bestWindow = &windows[numWindows];
                bestLength = curLength;
            }
            numWindows++;
        }
        curWindowPos++;
    }
    return numWindows;
}

static void put_bit(uint8_t **byteBuffer, uint32_t *bufferLength, uint32_t index, int val)
{
    uint32_t byteIndex = index / 8;
    uint32_t bitIndex = index % 8;

    if (byteIndex > *bufferLength)
    {
        *bufferLength *= 2;
        *byteBuffer = (uint8_t*)realloc(*byteBuffer, *bufferLength);
    }

    if (val)
    {
        (*byteBuffer)[byteIndex] |= 0x80 >> bitIndex;
    }
}

// dst is caller-freed memory!
int compress(struct DecompressionParams *params, uint32_t decompressedSize, uint8_t *src, uint8_t **dst, int lookahead)
{
    uint8_t *outputPtr, *inputPtr;
    uint32_t i;
    uint32_t compressedSize;

    // Calculate max offset and length from the given compression parameters
    uint32_t maxOffset = 0xFFFF >> params->shift;
    uint32_t maxLength = params->mask + params->lengthOffset - 1;

    // Initialize the layout byte array (may get reallocated later on by put_bit)
    uint32_t layoutBitIndex = 0;
    uint32_t layoutByteCount = 16;
    uint8_t *layoutBytes = (uint8_t*)malloc(layoutByteCount);

    // Worst (or best?) case scenario where a window is found for every position
    struct CompressionWindow *windowBuffer = (struct CompressionWindow *)calloc(MIN(maxOffset, decompressedSize), sizeof(struct CompressionWindow));
    struct CompressionWindow *foundWindows = (struct CompressionWindow *)calloc(decompressedSize, sizeof(struct CompressionWindow));
    int windowsFound = 0;
    // Find windows for compression
    i = 0;
    while (i < decompressedSize) 
    {
        // Look for the best window at this given position
        struct CompressionWindow *bestWindow;
        int numWindows = find_windows(windowBuffer, &bestWindow, src, i, 1, maxOffset, MIN(maxLength, decompressedSize - i), lookahead);

        // If any were found, encode that info into the layout bytes 
        if (numWindows > 0)
        {
            i += bestWindow->length;
            put_bit(&layoutBytes, &layoutByteCount, layoutBitIndex, 1);
            foundWindows[layoutBitIndex] = *bestWindow;
            layoutBitIndex++;
            windowsFound++;
        }
        // Otherwise, set the window length of this layout bit to zero to indicate no window found
        else
        {
            i++;
            put_bit(&layoutBytes, &layoutByteCount, layoutBitIndex, 0);
            foundWindows[layoutBitIndex].length = 0;
            layoutBitIndex++;
        }
    }

    free(windowBuffer);

    // Assemble compressed output
    compressedSize =
        // 1 byte for every 8 layout bits
        DIVIDE_ROUND_UP(layoutBitIndex, 8) +
        // 2 bytes for each window
        windowsFound * 2 +
        // 1 byte for every position where a window wasn't found
        layoutBitIndex - windowsFound;
        // Simplifies to:
        // DIVIDE_ROUND_UP(layoutBitIndex, 8) +
        // windowsFound + layoutBitIndex;
    *dst = (uint8_t*)malloc(compressedSize);
    outputPtr = &(*dst)[0];
    inputPtr = &src[0];

    // Write each layout byte and the subsequent data corresponding to it
    for (i = 0; i <= layoutBitIndex / 8; i++)
    {
        uint32_t j;

        // Write the current layout byte to the output
        *outputPtr = layoutBytes[i];
        outputPtr++;
        // Write either the window or the original byte for each of the 8 layout bits
        for (j = i * 8; j < MIN(i * 8 + 8, layoutBitIndex); j++)
        {
            struct CompressionWindow *curWindow = &foundWindows[j];
            // If a window was found for this position, write it
            if (curWindow->length > 0)
            {
                // Pack the length and offset into the window bytes based on the current compression parameters
                unsigned int outputLength = curWindow->length - params->lengthOffset + 1;
                unsigned int outputOffset = curWindow->offset;
                unsigned int outputWindow = (outputOffset << params->shift) | outputLength;
                // Write the window to the output
                outputPtr[0] = (outputWindow >> 8) & 0xFF;
                outputPtr[1] = (outputWindow >> 0) & 0xFF;
                outputPtr += 2;
                // Skip ahead in the input by the length of the window
                inputPtr += curWindow->length;
            }
            else
            {
                // Write a byte directly from the input to the output
                *outputPtr = *inputPtr;
                outputPtr += 1;
                inputPtr += 1;
            }
        }
    }

    free(layoutBytes);
    free(foundWindows);

    return compressedSize;
}

// Decompiled from the game
void decompress(struct DecompressionParams *params, uint32_t compressedSize, uint8_t *src, uint32_t uncompressedSize, uint8_t *dst)
{
    s32 layoutBitIndex;
    u8 *srcEnd;
    u8 *dstEnd;
    u8 layoutBits;

    srcEnd = src + compressedSize;
    dstEnd = dst + uncompressedSize;
    do
    {
        if (src >= srcEnd)
            return;
        layoutBitIndex = 7;
        layoutBits = *src++;
        while (1)
        {
            if (layoutBitIndex < 0 || src >= srcEnd || dst >= dstEnd)
            {
                break;
            }
            if ((u32)layoutBits & (1L << (layoutBitIndex)))
            {
                s32 firstByte = *src++;
                s32 secondByte = *src++;
                u16 bytes = firstByte << 8 | secondByte;
                u8 *curByte;
                u8 *lastByte;
                u16 offset = (bytes >> params->shift);
                u16 length = (bytes & params->mask) + params->lengthOffset - 1;
                curByte = dst - offset;
                lastByte = curByte + length;
                while (lastByte > curByte)
                {
                    *dst++ = *curByte++;
                }
            }
            else
            {
                *dst++ = *src++;
            }
            layoutBitIndex--;
        }
    } while (1);
}

unsigned int get_texture_address(FILE *romFile, unsigned int textureIndex)
{
    uint32_t romAddr;
    __attribute__((unused)) size_t readAmount;
    fseek(romFile, ASSET_TABLE_ADDR + sizeof(uint32_t) * textureIndex, SEEK_SET);
    readAmount = fread(&romAddr, sizeof(uint32_t), 1, romFile);
    romAddr = __builtin_bswap32(romAddr);
    return romAddr + ROM_CONTENT_START;
}

void read_texture_headers(FILE *romFile, struct Texture *texture, struct TextureCompressionHeader *handlerHeader, unsigned int textureIndex)
{
    unsigned int textureRomAddress = get_texture_address(romFile, textureIndex);
    __attribute__((unused)) size_t readAmount;
    fseek(romFile, textureRomAddress, SEEK_SET);
    readAmount = fread(&texture->header, sizeof(texture->header), 1, romFile);
    readAmount = fread(handlerHeader, sizeof(handlerHeader), 1, romFile);

    // Fix endianness
    texture->header.width = __builtin_bswap16(texture->header.width);
    texture->header.height = __builtin_bswap16(texture->header.height);
    texture->header.bytesPerRow = __builtin_bswap16(texture->header.bytesPerRow);
    texture->header.imageBytes = __builtin_bswap32(texture->header.imageBytes);
    texture->header.paletteBytes = __builtin_bswap16(texture->header.paletteBytes);
    texture->header.unkE = __builtin_bswap16(texture->header.unkE);

    handlerHeader->compressedLength = __builtin_bswap32(handlerHeader->compressedLength);
}

void read_texture(void *texData, void *palData, FILE *romFile, unsigned int textureIndex)
{
    struct Texture asset;
    struct TextureCompressionHeader handlerHeader;
    __attribute__((unused)) size_t readAmount;

    unsigned int dataRomAddress = get_texture_address(romFile, textureIndex) + sizeof(struct TextureHeader) + sizeof(struct TextureCompressionHeader);
    read_texture_headers(romFile, &asset, &handlerHeader, textureIndex);

    fseek(romFile, dataRomAddress, SEEK_SET);

    if (handlerHeader.handlerIndex == 0)
    {
        readAmount = fread(texData, 1, asset.header.imageBytes, romFile);
    }
    else
    {
        uint8_t *compressionBuffer = (uint8_t*)malloc(handlerHeader.compressedLength);
        readAmount = fread(compressionBuffer, 1, handlerHeader.compressedLength, romFile);
        decompress(&decompressionParamsTable[handlerHeader.compressionParams],
            handlerHeader.compressedLength,
            compressionBuffer,
            asset.header.imageBytes,
            (uint8_t*)texData);
        free(compressionBuffer);
    }
    if (palData != NULL && asset.header.paletteBytes > 0)
    {
        readAmount = fread(palData, asset.header.paletteBytes, 1, romFile);
    }
}

void swap_words(void *data, unsigned int numBytes, unsigned int bytesPerRow)
{
    uint32_t i;
    uint32_t tmp;
    uint32_t *data32 = (uint32_t *)data;
    uint32_t wordsPerRow = bytesPerRow / 4;
    uint32_t numWords = numBytes / 4;
    for (i = 0; i < numWords / 2; i++)
    {
        if ((2 * i) / wordsPerRow % 2 == 1)
        {
            tmp = data32[2 * i + 0];
            data32[2 * i + 0] = data32[2 * i + 1];
            data32[2 * i + 1] = tmp;
        }
    }
}

void flip_rows(void *data, unsigned int height, unsigned int bytesPerRow)
{
    uint32_t i;
    uint8_t *tempRowData = (uint8_t*)malloc(bytesPerRow);
    uint8_t *data8 = (uint8_t *)data;
    for (i = 0; i < height / 2; i++)
    {
        memcpy(tempRowData, &data8[bytesPerRow * i], bytesPerRow);
        memcpy(&data8[bytesPerRow * i], &data8[bytesPerRow * (height - i - 1)], bytesPerRow);
        memcpy(&data8[bytesPerRow * (height - i - 1)], tempRowData, bytesPerRow);
    }
}
