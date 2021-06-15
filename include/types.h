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

struct unkD_800ADAD0_sub {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    s16 unk14;
    s16 unk16;
    u32 unk18;
    u32 unk1C;
};

struct unkD_800ADAD0 {
    struct unkD_800ADAD0_sub *unk0;
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

#endif
