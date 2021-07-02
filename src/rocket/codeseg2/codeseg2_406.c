#include <include_asm.h>
#include <ultra64.h>
#include <mem.h>

extern struct DecompressionParams compressionParamsTable[];

void asset_handler_decompress(u32 assetAddress, struct TextureCompressionHeader *header, struct Texture *asset)
{
    void *compressedData;

    push_second_heap_state();
    compressedData = (void *)alloc_second_heap(header->compressedLength);
    dma_read(assetAddress, compressedData, header->compressedLength);
    decompress(&compressionParamsTable[header->compressionParams], header->compressedLength,
               compressedData, asset->header.imageBytes, asset->imageData);
    pop_second_heap_state();
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_406", func_80094004);

struct Texture *dma_read_asset(u32 *param_1)
{
    struct Texture *asset;
    struct TextureCompressionHeader compressionParamsTable;
    u32 assetAddress;

    assetAddress = *param_1;
    
    asset = main_alloc_bzero(sizeof(struct Texture));

    dma_read(assetAddress, asset, sizeof(struct TextureHeader));
    assetAddress += sizeof(struct TextureHeader);

    dma_read(assetAddress, &compressionParamsTable, sizeof(struct TextureCompressionHeader));
    assetAddress += sizeof(struct TextureCompressionHeader);

    asset->imageData = main_alloc_nozero(asset->header.imageBytes);
    assetHandlers[compressionParamsTable.handlerIndex](assetAddress, &compressionParamsTable, asset);
    assetAddress += compressionParamsTable.compressedLength;
    if (asset->header.paletteBytes > 0)
    {
        asset->paletteData = main_alloc_nozero(asset->header.paletteBytes);
        dma_read(assetAddress, asset->paletteData, asset->header.paletteBytes);
    }
    return asset;
}

void adjust_asset_table(void)
{
    int iVar1;
    u32 *piVar2;
    int iVar3;

    textureTable = alloc_second_heap(textureTableLength * sizeof(u32));
    dma_read(textureTableAddress, textureTable, textureTableLength * sizeof(u32));
    piVar2 = textureTable;
    iVar1 = textureTableLength;
    for (iVar3 = 0; iVar3 < iVar1; iVar3++)
    {
        piVar2[iVar3] += (u32)_dataEndRom;
    }
}

void reset_asset_table()
{
    textureTable = NULL;
}
