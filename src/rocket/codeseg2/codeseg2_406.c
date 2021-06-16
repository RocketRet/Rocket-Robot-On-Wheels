#include <include_asm.h>
#include <ultra64.h>
#include <mem.h>

extern struct DecompressionParams compressionParamsTable[];

void asset_handler_decompress(u32 assetAddress, struct AssetHandlerHeader *header, struct Asset *asset)
{
    void *compressedData;

    push_second_heap_state();
    compressedData = (void *)alloc_second_heap(header->compressedLength);
    dma_read(assetAddress, compressedData, header->compressedLength);
    decompress(&compressionParamsTable[header->compressionParams], header->compressedLength,
               compressedData, asset->header.data1Len, asset->data1);
    pop_second_heap_state();
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_406", func_80094004);

struct Asset *dma_read_asset(u32 *param_1)
{
    struct Asset *asset;
    struct AssetHandlerHeader compressionParamsTable;
    u32 assetAddress;

    assetAddress = *param_1;
    
    asset = main_alloc_bzero(sizeof(struct Asset));

    dma_read(assetAddress, asset, sizeof(struct AssetHeader));
    assetAddress += sizeof(struct AssetHeader);

    dma_read(assetAddress, &compressionParamsTable, sizeof(struct AssetHandlerHeader));
    assetAddress += sizeof(struct AssetHandlerHeader);

    asset->data1 = main_alloc_nozero(asset->header.data1Len);
    assetHandlers[compressionParamsTable.handlerIndex](assetAddress, &compressionParamsTable, asset);
    assetAddress += compressionParamsTable.compressedLength;
    if (asset->header.data2Len > 0)
    {
        asset->data2 = main_alloc_nozero(asset->header.data2Len);
        dma_read(assetAddress, asset->data2, asset->header.data2Len);
    }
    return asset;
}

void adjust_asset_table(void)
{
    int iVar1;
    u32 *piVar2;
    int iVar3;

    assetTable = alloc_second_heap(assetTableLength * sizeof(u32));
    dma_read(assetTableAddress, assetTable, assetTableLength * sizeof(u32));
    piVar2 = assetTable;
    iVar1 = assetTableLength;
    for (iVar3 = 0; iVar3 < iVar1; iVar3++)
    {
        piVar2[iVar3] += (u32)_dataEndRom;
    }
}

void reset_asset_table()
{
    assetTable = NULL;
}
