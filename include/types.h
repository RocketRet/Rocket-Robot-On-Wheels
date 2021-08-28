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

struct RecordHeader {
    u32 type;
    u32 length;
};

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

struct TexturedMaterial {
    uintptr_t romAddress;
    struct TextureGroupHeader header;
    u8 widthPower;  // Width as a power of two (rounded up)
    u8 heightPower; // Height as a power of two (rounded up)
    u16 unk22;
    struct Texture **textures;
};

struct MaterialGfx {
    uintptr_t materialData; // ROM address of textured material data, RAM address of TexturedMaterial struct, or color of solid shaded material (00RRGGBB)
    u32 gfxCount; // Number of Gfx commands, or zero if not loaded
    Gfx *gfx; // Pointer to Gfx command array
    struct MaterialGfx **unkC;
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

struct unkVertexDataStorage28 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

struct VertexDataStorage {
    u8 *unk0; // 1 byte per vertex? not used?
    s32 unk4; // num vertex colors
    void *unk8; // vertex colors
    s32 unkC; // num vertex positions
    void *unk10; // vertex positions
    s16 *unk14; // vertex position indices
    s32 unk18; // num texture coords
    void *unk1C; // texture coords
    s16 *unk20; // texture coord indices
    s16 *unk24;
    struct unkVertexDataStorage28 *unk28;
    s32 unk2C;
};

struct Submodel {
    Gfx *unk0;
    struct unkfunc_80093DDC unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    Vec3f unk14;
    u8 unk20;
    u8 unk21;
    u8 unk22;
    u8 unk23;
    f32 unk24;
};

struct unkfunc_800882B8 {
    u8 padding1[0x38];
    s32 unk38;
    u8 padding2[0x134 - 0x38 - 0x04];
    s32 unk134;
    s32 unk138;
    s32 unk13C;
};

struct Model {
    /* 0x000 */ struct unkfunc_8001E044_inner *unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00C */ struct unkfunc_800882B8 *unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ Mtx3f unk18;
    /* 0x03C */ Vec3f unk3C;
    /* 0x048 */ u8 padding3[0x6C - 0x3C - 0x0C];
    /* 0x06C */ Vec3f unk6C;
    /* 0x078 */ u8 padding3_1[0xE0 - 0x6C - 0x0C];
    /* 0x0E0 */ s16 unkE0;
    /* 0x0E2 */ s16 unkE2;
    /* 0x0E4 */ u32 unkE4;
    /* 0x0E8 */ Vtx *unkE8;
    /* 0x0EC */ struct VertexDataStorage *vertexDataStorage;
    /* 0x0F0 */ Gfx *unkF0;
    /* 0x0F4 */ struct Submodel *submodels;
    /* 0x0F8 */ s32 numSubmodels;
    /* 0x0FC */ s32 unkFC;
    /* 0x100 */ f32 unk100;
    /* 0x104 */ u8 padding4[0x110 - 0x100 - 0x04];
    /* 0x110 */ s8 unk110;
    /* 0x111 */ u8 unk111;
    /* 0x112 */ int unk112_7 : 1;
    /* 0x112 */ int unk112_0 : 7;
    /* 0x113 */ u8 unk113;
    /* 0x114 */ s32 unk114;
    /* 0x118 */ s32 unk118;
    /* 0x11C */ s32 unk11C;
    /* 0x120 */ f32 unk120;
    /* 0x124 */ f32 unk124;
    /* 0x128 */ f32 unk128;
    /* 0x12C */ f32 unk12C;
    /* 0x130 */ f32 unk130;
    /* 0x134 */ Vec3f unk134;
    /* 0x140 */ s32 unk140;
    /* 0x144 */ Vec3f *unk144;
    /* 0x148 */ s32 unk148;
    /* 0x14C */ s32 unk14C;
    /* 0x150 */ s32 unk150;
    /* 0x154 */ s32 unk154;
    /* 0x158 */ s32 unk158;
    /* 0x15C */ u8 padding5[0x170 - 0x158 - 0x04];
    /* 0x170 */ f32 unk170;
    /* 0x174 */ f32 unk174;
    /* 0x178 */ s32 unk178;
    /* 0x17C */ s32 unk17C;
    /* 0x180 */ s32 unk180;
};

struct unkfunc_8001E044_2 {
    struct unkfunc_8001E044_inner *unk0;
    u8 padding[0x24 - 0x00 - 0x04];
    u32 unk24;
    u32 unk28;
    u32 unk2C;
};

struct unkfunc_8001E044_inner {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    void (*unk10)(struct Model*, void*, s32);
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    void (*unk20)(struct Model*, void*, s32);
    u8 padding1[0x40 - 0x20 - 0x04];
    void (*unk40)(struct Model*);
    s32 unk44;
    s32 unk48;
    void (*unk4C)(struct Model*, void*);
    u8 padding2[0x68 - 0x4C - 0x04];
    void (*unk68)(struct Model*, s32, void*, s32);
    void (*unk6C)(struct Model*, s32, Gfx *);
};

#endif
