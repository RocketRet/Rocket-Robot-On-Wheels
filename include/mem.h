#ifndef __MEM_H__
#define __MEM_H__

#include <ultra64.h>

struct AssetHeader {
    u32 unk0;
    u32 unk4;
    u32 data1Len;
    u16 data2Len;
    u16 unkE;
};

struct Asset {
    struct AssetHeader header;
    void *data1;
    void *data2;
};

struct AssetHandlerHeader {
    u8 handlerIndex;
    u8 compressionParams;
    u8 unk2;
    u8 unk3;
    u32 compressedLength;
};


struct DecompressionParams {
    u32 lengthOffset;
    u32 negativeShift; // unused
    u32 shift;
    u32 mask;
};

extern u32 *assetTable;
extern s32 assetTableAddress;
extern s32 assetTableLength;

extern u8 _dataEndRom[];
extern void (*assetHandlers[])(s32, struct AssetHandlerHeader*, struct Asset*);

void *main_alloc_copy(s32 size, u8 *src);
void *main_alloc_bzero(u32 len);
void *main_alloc_nozero(u32 len);
void dma_read(u32 romAddr, void *ramAddr, u32 len);
void *alloc_second_heap(u32 len);
void decompress(struct DecompressionParams *arg0, u32 compressedSize, u8 *src, u32 uncompressedSize, u8 *dst);

#endif
