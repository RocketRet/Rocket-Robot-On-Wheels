#include "librocket.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int32_t s32;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

struct DecompressionParams decompressionParamsTable[2] = {
    {3, 10, 6, 0x3F},
    {3, 11, 5, 0x1F}
};

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
        uint8_t *compressionBuffer = malloc(handlerHeader.compressedLength);
        readAmount = fread(compressionBuffer, 1, handlerHeader.compressedLength, romFile);
        decompress(&decompressionParamsTable[handlerHeader.compressionParams],
            handlerHeader.compressedLength,
            compressionBuffer,
            asset.header.imageBytes,
            texData);
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
    uint8_t *tempRowData = malloc(bytesPerRow);
    uint8_t *data8 = (uint8_t *)data;
    for (i = 0; i < height / 2; i++)
    {
        memcpy(tempRowData, &data8[bytesPerRow * i], bytesPerRow);
        memcpy(&data8[bytesPerRow * i], &data8[bytesPerRow * (height - i - 1)], bytesPerRow);
        memcpy(&data8[bytesPerRow * (height - i - 1)], tempRowData, bytesPerRow);
    }
}
