#ifndef __MEM_H__
#define __MEM_H__

#include <ultra64.h>
#include <types.h>

#define READ_VALUE(x, type) ({*x += sizeof(type); *(type*)(*x - sizeof(type));})
static inline u32 read_u32(u8 **ptr) { *ptr += sizeof(u32); return *(u32*)(*ptr - sizeof(u32)); }
static inline u16 read_u16(u8 **ptr) { *ptr += sizeof(u16); return *(u16*)(*ptr - sizeof(u16)); }
static inline f32 read_f32(u8 **ptr) { *ptr += sizeof(f32); return *(f32*)(*ptr - sizeof(f32)); }
void read_vec3f(u8 **ptr, Vec3f out);

#define	ALIGN_PTR(s, align) (void *)(((u32)(s) + ((align)-1)) & ~((align)-1))

extern struct Texture **textureTable;
extern s32 textureTableAddress;
extern s32 textureTableLength;

extern u8 _assetsSegmentRomStart[];
extern void (*textureHandlers[])(s32, struct TextureCompressionHeader*, struct Texture*);
extern struct DecompressionParams compressionParamsTable[2];

void *main_alloc_copy(s32 size, u8 *src);
void *main_alloc_bzero(u32 len);
void *main_alloc_nozero(u32 len);
void dma_read(u32 romAddr, void *ramAddr, u32 len);
void *alloc_second_heap(u32 len);
void decompress(struct DecompressionParams *arg0, u32 compressedSize, u8 *src, u32 uncompressedSize, u8 *dst);
void push_second_heap_state();
void pop_second_heap_state();

struct Texture *load_texture(struct MaterialGfx *material);
struct TexturedMaterial *load_textured_material(struct MaterialGfx *arg0);

#endif
