#include "librocket.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define ROM_PATH_ARG 1
#define ASSET_INDEX_ARG 2

int main(int argc, char **argv)
{
    // Check if the asset index was provided
    if (argc < 3)
    {
        printf("Usage: %s [path/to/rom] [asset index]\n", argv[0]);
        return EXIT_SUCCESS;
    }
    const char *romPath = argv[ROM_PATH_ARG];
    const char *assetIndexArg = argv[TEXTURE_INDEX_ARG];
    
    // Parse the asset index string into a long
    char *endptr;
    int assetIndex = (int)strtol(argv[TEXTURE_INDEX_ARG], &endptr, 0);

    // Check if the end pointer is the end of the asset index string
    // If it isn't, then the string contained invalid characters
    if (endptr != (strlen(assetIndexArg) + assetIndexArg))
    {
        fprintf(stderr, "Invalid index given: %s\n", assetIndexArg);
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

    struct Texture asset;
    struct TextureCompressionHeader handlerHeader;

    unsigned int romAddress = get_texture_address(romFile, assetIndex) + sizeof(struct TextureHeader) + sizeof(struct TextureCompressionHeader);
    read_texture_headers(romFile, &asset, &handlerHeader, assetIndex);

    if (handlerHeader.handlerIndex == 0)
    {
        printf(
            "Uncompressed asset: %d\n"
            "  ROM Address: 0x%04X\n"
            "  Data Length: 0x%08X\n",
            assetIndex,
            romAddress,
            asset.header.imageBytes);
    }
    else
    {
        printf(
            "Compressed asset: %d\n"
            "  ROM Address: 0x%04X\n"
            "  Data Length: 0x%08X\n"
            "  Compressed Length: 0x%08X\n"
            "  Compression Params: %d\n"
            "  Asset unk: %08X %08X %08X\n"
            "  Handler unk: %3d %3d\n",
            assetIndex,
            romAddress,
            asset.header.imageBytes,
            handlerHeader.compressedLength,
            handlerHeader.compressionParams,
            asset.header.unk0, asset.header.unk4, asset.header.unkE,
            handlerHeader.unk2, handlerHeader.unk3);
    }

    uint32_t i;
    for (i = 0; i < ASSET_TABLE_LEN; i++)
    {
        struct Texture texture;
        struct TextureCompressionHeader handlerHeader;
        read_texture_headers(romFile, &texture, &handlerHeader, i);
        printf(
            "Asset %u: \n"
            "  unk0: 0x%08X  unk4: 0x%08X  data1Len: 0x%08X  data2Len: 0x%04X  unkE: 0x%04X\n"
            "  handlerIndex: %3d  compressionParams: %3d  unk2: 0x%02X  unk3: 0x%02X  compressedLength: 0x%08X\n",
            i,
            texture.header.unk0, texture.header.unk4, texture.header.imageBytes, texture.header.paletteBytes, texture.header.unkE,
            handlerHeader.handlerIndex, handlerHeader.compressionParams, handlerHeader.unk2, handlerHeader.unk3, handlerHeader.compressedLength);
    }

    // uint8_t *romData = malloc(asset.header.data1Len);
    // uint8_t *data2 = NULL;
    // if (asset.header.data2Len > 0)
    // {
    //     data2 = malloc(asset.header.data2Len);
    // }
    // read_asset(romData, data2, romFile, assetIndex);

    // printf("Asset data:");
    // uint32_t i;
    // for (i = 0; i < asset.header.data1Len; i++)
    // {
    //     if (i % 32 == 0)
    //     {
    //         printf("\n  ");
    //     }
    //     printf("%02X ", romData[i]);
    // }
    // printf("\n");
    // free(romData);
    // if (data2 != NULL)
    // {
    //     printf("Asset data2:");
    //     for (i = 0; i < asset.header.data2Len; i++)
    //     {
    //         if (i % 32 == 0)
    //         {
    //             printf("\n  ");
    //         }
    //         printf("%02X ", data2[i]);
    //     }
    //     printf("\n");
    //     free(data2);
    // }
}
