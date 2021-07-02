#ifndef __MEM_H__
#define __MEM_H__

#include <ultra64.h>
#include <types.h>

static inline u32 read_u32(u8 **ptr) { *ptr += sizeof(u32); return *(u32*)(*ptr - sizeof(u32)); }
static inline f32 read_f32(u8 **ptr) { *ptr += sizeof(f32); return *(f32*)(*ptr - sizeof(f32)); }
void read_vec3f(u8 **ptr, Vec3f out);

// #define READ_VAL(ptr, type) { *ptr += sizeof(type); *(type*)((u8*)*ptr - sizeof(type)); }

struct TextureHeader {
    u16 width;
    u16 height;
    u8 imSize;   // G_IM_SIZ_x
    u8 imFormat; // G_IM_FMT_x
    u16 bytesPerRow;
    u32 imageBytes;
    u16 paletteBytes;
    u16 unkE;
};

struct Texture {
    struct TextureHeader header;
    void *imageData;
    void *paletteData;
};

struct TextureCompressionHeader {
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

extern u32 *textureTable;
extern s32 textureTableAddress;
extern s32 textureTableLength;

extern u8 _dataEndRom[];
extern void (*textureHandlers[])(s32, struct TextureCompressionHeader*, struct Texture*);
extern struct DecompressionParams compressionParamsTable[2];

void *main_alloc_copy(s32 size, u8 *src);
void *main_alloc_bzero(u32 len);
void *main_alloc_nozero(u32 len);
void dma_read(u32 romAddr, void *ramAddr, u32 len);
void *alloc_second_heap(u32 len);
void decompress(struct DecompressionParams *arg0, u32 compressedSize, u8 *src, u32 uncompressedSize, u8 *dst);

#endif
