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

typedef float Vec2f[2];
typedef float Vec3f[3];
typedef float Mtx3f[3][3];
typedef float Mtx4f[4][4];

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
    /* 0x000 */ void *framebuffer;
    /* 0x004 */ struct GfxContext ctx;
    /* 0x014 */ Gfx *dlStart;
    /* 0x018 */ Mtx perspectiveMtx;
    /* 0x058 */ Mtx viewMtx;
    /* 0x098 */ Mtx identityModelMtx;
    /* 0x0D8 */ Mtx3f unkD8;
    /* 0x0FC */ Mtx3f unkFC;
    /* 0x120 */ s16 unk120;
    /* 0x122 */ u16 unk122;
    /* 0x124 */ u16 unk124;
    /* 0x126 */ u16 unk126;
    /* 0x128 */ struct GfxTask *unk128;
    /* 0x12C : Alignment Padding */
    /* 0x130 */ OSScTask schedTask;
};

struct ControllerData {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 vec3f_magnitude;
    /* 0x0C */ u16 buttonHeld;
    /* 0x0E */ s16 buttonPressed;
    /* 0x10 */ s16 buttonReleased;
};

struct TextureHeader {
    /* 0x00 */ u16 width;
    /* 0x02 */ u16 height;
    /* 0x04 */ u8 imSize;   // G_IM_SIZ_x
    /* 0x05 */ u8 imFormat; // G_IM_FMT_x
    /* 0x06 */ u16 bytesPerRow;
    /* 0x08 */ u32 imageBytes;
    /* 0x0C */ u16 paletteBytes;
    /* 0x0E */ u16 unkE;
};

struct Texture {
    struct TextureHeader header;
    /* 0x10 */ void *imageData;
    /* 0x14 */ void *paletteData;
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

struct RenderParams {
    u8 unk0_4 : 4;
    u8 cycleType : 4;
    u8 unk1;
    u8 unk2;
    u8 renderMode;
};

struct TextureGroupHeader {
    struct RenderParams unk4;
    u16 flags;
    u16 baseTextureWidth;
    u16 baseTextureHeight;
    u8 clampWrapMirrorS;
    u8 clampWrapMirrorT;
    u8 envColorR;
    u8 envColorG;
    u8 envColorB;
    u8 envColorA;
    u8 unk14;
    u8 numTextures;
    u8 unk16;
    u8 unk17;
    u32 unk18;
    u32 unk1C;
};

struct TexturedMaterial {
    /* 0x00 */ uintptr_t romAddress;
    /* 0x04 */ struct TextureGroupHeader header;
    /* 0x20 */ u8 widthPower;  // Width as a power of two (rounded up)
    /* 0x21 */ u8 heightPower; // Height as a power of two (rounded up)
    /* 0x22 */ u16 unk22;
    /* 0x24 */ struct Texture **textures;
};

struct TileScrollParams {
    struct MaterialGfx *unk0;
    s32 unk4;
    s32 unk8;
    f32 tile0SpeedS;
    f32 tile0SpeedT;
    f32 tile1SpeedS;
    f32 tile1SpeedT;
};

struct MaterialGfx {
    // ROM address of textured material data, RAM address of TexturedMaterial struct, or color of solid shaded material (00RRGGBB)
    union {
        uintptr_t raw;
        struct TexturedMaterial *texturedMaterial;
        struct {
            u8 pad;
            u8 r;
            u8 g;
            u8 b;
        } color;
    } materialData;
    u32 gfxCount; // Number of Gfx commands, or zero if not loaded
    Gfx *gfx; // Pointer to Gfx command array
    struct TileScrollParams *scrollParams;
};

struct unkfunc_80091F54 {
    void *unk0;
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
    struct RenderParams unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    Vec3f unk14;
    u8 unk20;
    u8 unk21;
    u8 unk22;
    u8 unk23;
    s32 unk24;
};

struct unkfunc_800882B8 {
    u8 padding1[0x38];
    s32 unk38;
    u8 padding2[0x134 - 0x38 - 0x04];
    s32 unk134;
    s32 unk138;
    s32 *unk13C;
    s32 pad140;
    s32 unk144;
};

struct unkfunc_8001E248 {
    u8 pad[0x24];
    s32 unk24;
    s32 unk28;
};

struct GameObjectUnkFC {
    struct unkfunc_8001E248* unk0;
    s32 unk4;
    f32 unk8;
    f32 unkC;
    s32 unk10;
};

struct GameObjectUnkD8 {
    u8 pad[0x8];
    Vec3f unk8;
    u8 pad1[0x20 - 0x8 - sizeof(Vec3f)];
    Mtx3f unk20;
    u8 pad2[0x74 - 0x20 - sizeof(Mtx3f)];
    u32 unk74;
};

struct GameObject {
    /* 0x000 */ struct unkfunc_8001E044_inner *unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00C */ struct unkfunc_800882B8 *unkC;
    /* 0x010 */ void* unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ Mtx3f rotation;
    /* 0x03C */ Vec3f position;
    /* 0x048 */ Mtx3f unk48;
    /* 0x06C */ Vec3f unk6C;
    /* 0x078 */ Vec3f velocity;
    /* 0x084 */ Vec3f angular_velocity;
    /* 0x090 */ u8 padding3_1[0x9C - 0x90];
    /* 0x09C */ Vec3f angular_acceleration;
    /* 0x0A8 */ Vec3f unkA8;
    /* 0x0B4 */ Mtx3f unkB4;
    /* 0x0D8 */ struct GameObjectUnkD8 *unkD8;
    /* 0x0DC */ u8 padding3_2[0xE0 - 0xDC];
    /* 0x0E0 */ s16 unkE0;
    /* 0x0E2 */ s16 unkE2;
    /* 0x0E4 */ u32 unkE4;
    /* 0x0E8 */ Vtx *unkE8;
    /* 0x0EC */ struct VertexDataStorage *vertexDataStorage;
    /* 0x0F0 */ Gfx *unkF0;
    /* 0x0F4 */ struct Submodel *submodels;
    /* 0x0F8 */ s32 numSubmodels;
    /* 0x0FC */ struct GameObjectUnkFC* unkFC;
    /* 0x100 */ f32 unk100;
    /* 0x104 */ f32 unk104;
    /* 0x108 */ s32 unk108;
    /* 0x10C */ u8 padding4[0x110 - 0x10C];
    /* 0x110 */ union { // TODO reconcile the members of this union so it's just a bitfield
        u32 val;
        struct {
            s32 unk110_0 : 8;
            s32 unk110_8 : 2;
            s32 unk110_10 : 2;
            s32 unk110_12 : 5;
            s32 unk110_17 : 1; // sleeping
            s32 unk110_18 : 1;
            s32 unk110_19 : 1;
        } bitfield;
    } unk110;
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

struct unkfunc_80087D4C {
    u8 padding[0x18];
    Vec3f unk18;
    Mtx3f unk24;
    u32 unk48;
    u32 unk4C;
    f32 unk50[6];
};

struct unkfunc_8006BF3C {
    u8 padding[0xC];
    struct unkfunc_800882B8 *unkC;
    u8 padding2[0x3C - 0xC - 0x4];
    s32 unk3C;
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
    void (*unk10)(struct GameObject*, void*, s32);
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    void (*unk20)(struct GameObject*, void*, u8*);
    u8 padding1[0x40 - 0x20 - 0x04];
    void (*unk40)(struct GameObject*);
    s32 unk44;
    s32 unk48;
    void (*unk4C)(struct GameObject*, void*);
    u8 padding2[0x54 - 0x4C - 0x04];
    void (*unk54)(struct GameObject *, s32, void*);
    void (*unk58)(struct GameObject *, Vec3f); // position
    void (*unk5C)(struct GameObject *, Mtx3f); // rotation
    void (*unk60)(struct GameObject *, Vec3f); // velocity
    void (*unk64)(struct GameObject *, Vec3f); // angular_velocity
    u8 padding3[0x68 - 0x64 - 0x04];
    void (*unk68)(struct GameObject*, s32, void*, s32);
    void (*unk6C)(struct GameObject*, s32, Gfx *);
};

struct unkfunc_800338D0 {
    u8 padding[0x258];
    struct MaterialGfx unk258;
    u8 padding3[0x26D - 0x258 - 0x10];
    u8 unk26D;
};

struct unkfunc_800263B4 {
    u8 padding[0x234];
    s32 unk234;
    s32 unk238;
};

struct unkfunc_800824A0 {
    u8 padding[0x10];
    s32 unk10;
    u8 padding2[0x268 - 0x04 - 0x10];
    s32 unk268;
};

#endif
