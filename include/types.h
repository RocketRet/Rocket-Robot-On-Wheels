#ifndef __TYPES_H__
#define __TYPES_H__

#include <PR/sched.h>

#ifdef TARGET_N64
typedef u32 uintptr_t;
typedef s32 intptr_t;
typedef u32 ptrdiff_t;
#else
#include <stdint.h>
#endif

struct GfxContext {
    u32 unk0;
    Gfx *dlStart;
    Gfx *dlHead;
    Mtx *unkC;
};

struct GfxTask {
    void *framebuffer;
    struct GfxContext ctx;
    u32 unk14;
    u8 filler[0x120 - 0x14 - 0x04];
    u16 unk120;
    u16 unk122;
    u16 unk124;
    u16 unk126;
    struct GfxTask *unk128;
    u32 unk12C;
    OSScTask schedTask;
};

typedef float Vec2f[2];
typedef float Vec3f[3];
typedef float Mtx3f[3][3];
typedef float Mtx4f[4][4];

struct ControllerData {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 vec3f_magnitude;
    /* 0x0C */ u16 buttonHeld;
    /* 0x0E */ s16 buttonPressed;
    /* 0x10 */ s16 buttonReleased;
};

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

struct unkfunc_80093DDC {
    u8 unk0_4 : 4;
    u8 unk0_0 : 4;
    u8 unk1;
    u8 unk2;
    u8 unk3;
};

struct TextureGroupHeader {
    struct unkfunc_80093DDC unk4;
    u16 unk8;
    u16 unkA;
    u32 unkC;
    u32 unk10;
    u8 unk14;
    u8 numTextures;
    u8 unk16;
    u8 unk17;
    u32 unk18;
    u32 unk1C;
};

struct TextureGroup {
    u32 romAddress;
    struct TextureGroupHeader header;
    u8 widthPower;  // Width as a power of two (rounded up)
    u8 heightPower; // Height as a power of two (rounded up)
    u16 unk22;
    struct Texture **textures;
};

struct unkD_800ADAD0 {
    struct TextureGroup *textureGroup;
    u32 unk4;
    Gfx *unk8;
    s32 unkC;
};

struct unkfunc_80091F54 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18[0xC0];
    u32 unk318[0xC1];
};

struct unkfunc_8009C28C {
    u8 padding[0x230];
    s32 unk230;
    s32 unk234[0x06]; // TODO real array length
    s32 unk24C;
    s32 unk250[0x08]; // TODO real array length
    s32 unk270;
    s32 unk274[0x08]; // TODO real array length
    s32 unk294;
    s32 unk298[0x08]; // TODO real array length
    s32 unk2B8;
    s32 unk2BC[0x08]; // TODO real array length
    s32 unk2DC;
    s32 unk2E0[0x08]; // TODO real array length
    s32 unk300;
    s32 unk304[0x08]; // TODO real array length
    s32 unk324;
    s32 unk328[0x08]; // TODO real array length
    u8 padding2[0x3A8 - 0x328 - (0x8 * 4)];
    s32 unk3A8;
    s32 unk3AC[0x08]; // TODO real array length
};

struct VertexDataStorage {
    s32 unk0; // vertex count
    s32 unk4; // num vertex colors
    void *unk8; // vertex colors
    s32 unkC; // num vertex positions
    void *unk10; // vertex positions
    s16 *unk14; // vertex position indices
    s32 unk18; // num texture coords
    void *unk1C; // texture coords
    s16 *unk20; // texture coord indices
    s32 unk24;
    s32 unk28;
    s32 unk2C;
};

struct Submodel {
    s32 unk0;
    struct unkfunc_80093DDC unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    u8 unk20;
    u8 unk21;
    u8 unk22;
    u8 unk23;
    f32 unk24;
};

struct Model {
    struct unkfunc_8001E044_inner *unk0;
    u8 padding[0x0C - 0x00 - 0x04];
    u32 unkC;
    u8 padding2[0x18 - 0x0C - 0x04];
    Mtx3f unk18;
    Vec3f unk3C;
    u8 padding3[0xE0 - 0x3C - 0x0C];
    s16 unkE0;
    s16 unkE2;
    u32 unkE4;
    u32 unkE8;
    struct VertexDataStorage *vertexDataStorage;
    u8 padding3_2[0xF4 - 0xEC - 0x04];
    struct Submodel *submodels;
    s32 numSubmodels;
    s32 unkFC;
    f32 unk100;
    u8 padding4[0x110 - 0x100 - 0x04];
    u8 unk110;
    u8 unk111;
    u8 unk112;
    u8 unk113;
    s32 unk114;
    u8 padding5[0x14C - 0x114 - 0x04];
    s32 unk14C;
};

struct unkfunc_8001E044_2 {
    struct unkfunc_8001E044_inner *unk0;
    u8 padding[0x24 - 0x00 - 0x04];
    u32 unk24;
    u32 unk28;
    u32 unk2C;
};

struct unkfunc_8001E044_inner {
    u8 padding[0x40];
    void (*unk40)(struct Model*);
    u8 padding2[0x68 - 0x40 - 0x04];
    void (*unk68)(struct Model*, s32, void*, s32);
};

#endif
