#include "librocket.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "n64graphics.h"

#define ROM_PATH_ARG 1
#define TEXTURE_INDEX_ARG 2
#define OUTPUT_FILE_ARG 3

const char *fmts[] = {
    "RGBA",
    "YUV",
    "CI",
    "IA",
    "I"
};

const char *sizs[] = {
    "4",
    "8",
    "16",
    "32"
};

const uint8_t sizeToDepth[] = {
    4,
    8,
    16,
    32
};

int main(int argc, char **argv)
{
    // Check if the texture index was provided
    if (argc < 4)
    {
        printf("Usage: %s [path/to/rom] [texture index] [output file]\n", argv[0]);
        return EXIT_SUCCESS;
    }
    const char *romPath = argv[ROM_PATH_ARG];
    const char *textureIndexArg = argv[TEXTURE_INDEX_ARG];
    const char *outputFilePath = argv[OUTPUT_FILE_ARG];
    
    // Parse the texture index string into a long
    char *endptr;
    int textureIndex = (int)strtol(argv[TEXTURE_INDEX_ARG], &endptr, 0);

    // Check if the end pointer is the end of the texture index string
    // If it isn't, then the string contained invalid characters
    if (endptr != (strlen(textureIndexArg) + textureIndexArg))
    {
        fprintf(stderr, "Invalid index given: %s\n", textureIndexArg);
        return EXIT_FAILURE;
    }

    // Attempt to open the provided rom
    FILE *romFile = fopen(romPath, "rb");
    if (romFile == NULL)
    {
        fprintf(stderr, "Failed to open rom file: %s\n", romPath);
        return EXIT_FAILURE;
    }

    fseek(romFile, 0, SEEK_END);
    long romLength = ftell(romFile);
    if (romLength != ROCKET_ROM_SIZE)
    {
        fprintf(stderr, "Rom is not 12MB, not a valid rom (real length 0x%lX)\n", romLength);
        return EXIT_FAILURE;
    }
    fseek(romFile, 0, SEEK_SET);

    struct Texture texture;
    struct TextureCompressionHeader compressionHeader;

    unsigned int romAddress = get_texture_address(romFile, textureIndex) + sizeof(struct TextureHeader) + sizeof(struct TextureCompressionHeader);
    read_texture_headers(romFile, &texture, &compressionHeader, textureIndex);

    if (compressionHeader.handlerIndex == 0)
    {
        printf(
            "Uncompressed texture: %d\n"
            "  ROM Address: 0x%04X\n"
            "  Data Length: 0x%08X\n",
            textureIndex,
            romAddress,
            texture.header.imageBytes);
    }
    else
    {
        printf(
            "Compressed texture: %d\n"
            "  ROM Address: 0x%04X\n"
            "  Data Length: 0x%08X\n"
            "  Compressed Length: 0x%08X\n"
            "  Compression Params: %d\n"
            "  Size: %u x %u\n"
            "  Format: %s%s\n"
            "  Bytes Per Row: 0x%04X\n"
            "  UnkE: 0x%04X\n"
            "  Handler unk: %d %d\n",
            textureIndex,
            romAddress,
            texture.header.imageBytes,
            compressionHeader.compressedLength,
            compressionHeader.compressionParams,
            texture.header.width, texture.header.height,
            fmts[texture.header.imFormat], sizs[texture.header.imSize],
            texture.header.bytesPerRow,
            texture.header.unkE,
            compressionHeader.unk2, compressionHeader.unk3);
    }

    uint8_t *imageData = malloc(texture.header.imageBytes);
    uint8_t *paletteData = NULL;
    if (texture.header.paletteBytes > 0)
    {
        paletteData = malloc(texture.header.paletteBytes);
    }
    read_texture(imageData, paletteData, romFile, textureIndex);

    // #define G_IM_SIZ_4b	0
    // #define G_IM_SIZ_8b	1
    // #define G_IM_SIZ_16b	2
    // #define G_IM_SIZ_32b	3
    // #define G_IM_SIZ_DD	5

    // #define G_TT_NONE	(0 << G_MDSFT_TEXTLUT)
    // #define G_TT_RGBA16	(2 << G_MDSFT_TEXTLUT)
    // #define G_TT_IA16	(3 << G_MDSFT_TEXTLUT)

    swap_words(imageData, texture.header.imageBytes, texture.header.bytesPerRow);
    flip_rows(imageData, texture.header.height, texture.header.bytesPerRow);

    int depth = sizeToDepth[texture.header.imSize];
    int realWidth = 8 * texture.header.bytesPerRow / depth;
    rgba *imgRGBA;
    ia *imgIA;
    uint8_t *rawRGBA;

    #define G_IM_FMT_RGBA	0
    #define G_IM_FMT_YUV	1
    #define G_IM_FMT_CI	2
    #define G_IM_FMT_IA	3
    #define G_IM_FMT_I	4

    // TODO trim padding

    switch (texture.header.imFormat)
    {
        case G_IM_FMT_RGBA:
            imgRGBA = raw2rgba(imageData, realWidth, texture.header.height, depth);
            rgba2png(outputFilePath, imgRGBA, realWidth, texture.header.height);
            free(imgRGBA);
            break;
        case G_IM_FMT_CI:
            rawRGBA = ci2raw(imageData, paletteData, realWidth, texture.header.height, depth);
            imgRGBA = raw2rgba(rawRGBA, realWidth, texture.header.height, 16);
            rgba2png(outputFilePath, imgRGBA, realWidth, texture.header.height);
            free(rawRGBA);
            free(imgRGBA);
            break;
        case G_IM_FMT_IA:
            imgIA = raw2ia(imageData, realWidth, texture.header.height, depth);
            ia2png(outputFilePath, imgIA, realWidth, texture.header.height);
            free(imgIA);
            break;
        case G_IM_FMT_I:
            imgIA = raw2i(imageData, realWidth, texture.header.height, depth);
            ia2png(outputFilePath, imgIA, realWidth, texture.header.height);
            free(imgIA);
            break;
    }
}
