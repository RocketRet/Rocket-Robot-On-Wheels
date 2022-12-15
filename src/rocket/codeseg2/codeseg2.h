#ifndef __CODESEG2_H__
#define __CODESEG2_H__

#include <types.h>

struct unkfunc_8001DFD0 {
    u32 unk0;
    s32 unk4;
    s32 unk8;
    void* unkC;
    void* unk10;
    u8 pad0[0x48 - 0x14];
    s32 unk48;
    u8 unk4C;
    u8 pad1[0x78 - 0x4D];
    Vec3f unk78;
    Vec3f unk84;
    u8 pad2[0xE0 - 0x90];
    u16 unkE0;
    u16 unkE2;
    u32 unkE4;
    u32 unkE8;
    u32 unkEC;
    u32 unkF0;
    u32 unkF4;
    u32 unkF8;
    u32 unkFC;
    u32 unk100;
    f32 unk104;
    u32 unk108;
    u32 unk10C;
    s32 unk110_0 : 8;
    s32 unk110_8 : 2;
    s32 unk110_10 : 2;
    s32 unk110_12 : 5;
    s32 unk110_17 : 1;
};

extern struct GfxContext gGfxContext; // 0x10 bytes

struct unkD_800A5C3C {
    u8 padding[0x28];
    s16 unk28;
    s16 unk2A;
    u8 padding2[0x34 - 0x2C];
    void *unk34;
    Gfx *unk38;
    Gfx *unk3C;
};

struct unkD_800C0440 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    f32 unk10;
    f32 unk14;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
};

extern struct unkD_800A5C3C D_800A5C3C;
extern struct unkD_800C0440 D_800C0440;


struct RenderEntry {
    Gfx* gfx;
    Mtx* mtx1;
    Mtx* mtx2;
    f32 depth;
    struct RenderParams renderParams;
    u8 alpha;
};

struct unkfunc_8008B694 {
    u8 pad0[0xBC];
    u8 unkBC_0 : 1;
    u8 unkBC_1 : 1;
    u8 unkBC_2 : 1;
    u8 unkBC_3 : 1;
    u8 unkBC_4 : 1;
    u8 unkBC_5 : 1;
    u8 unkBC_6 : 1;
    u8 unkBC_7 : 1;
    u8 unkBD;
    u8 unkBE;
    u8 unkBF;
    u8 unkC0;
    f32 unkC4;
    f32 unkC8;
};

extern struct RenderEntry D_800ADB00[];
extern struct RenderEntry* D_800AF300;

void func_80047B60(struct RenderParams arg0, u32* newCycleType, u32* newRenderMode1, u32* newRenderMode2);
void func_8008AEA0(s32, struct unkfunc_8008B694*);
void func_8008B4BC(s32, struct RenderEntry**);
void func_80091F54(s32);
void func_80092050(void);

static inline Gfx* next_gfx() {
    Gfx* ret = gGfxContext.dlHead;
    gGfxContext.dlHead++;
    return ret;
}

static inline s32 unk_parse_RenderParams(struct RenderParams arg0) {
    s32 phi_v1;
    if (arg0.unk2 == 5) {
        phi_v1 = 7;
    } else if (arg0.unk2 == 3) {
        phi_v1 = 5;
    } else if (arg0.unk2 == 4) {
        phi_v1 = 6;
    } else if (arg0.unk0_4 == 2) {
        phi_v1 = 4;
    } else if (arg0.unk2 == 2) {
        phi_v1 = 3;
    } else if (arg0.unk1 == 2) {
        phi_v1 = 2;
    } else if (arg0.unk2 == 1) {
        phi_v1 = 1;
    } else {
        phi_v1 = 0;
    }
    return phi_v1;
}

extern struct RenderParams D_800A5DB8;

static inline struct RenderParams unk_make_RenderParams(s32 cycleType, s32 unk0_4, s32 unk1, s32 unk2) {
    struct RenderParams ret;
    ret.cycleType = cycleType;
    ret.unk0_4 = unk0_4;
    ret.unk1 = unk1;
    ret.unk2 = unk2;
    ret.renderMode = unk_parse_RenderParams(ret);
    return ret;
}

static inline s32 unk_compare_RenderParams(struct RenderParams a, struct RenderParams b) {
    return a.cycleType == b.cycleType && a.renderMode == b.renderMode;
}

static inline void unk_assign_RenderParams(s32 cycleType, s32 unk0_4, s32 unk1, s32 unk2) {
    struct RenderParams ret = unk_make_RenderParams(cycleType, unk0_4, unk1, unk2);
    if (!unk_compare_RenderParams(D_800A5DB8, ret)) {
        D_800A5DB8 = ret;
    }
}

static inline struct RenderParams unk_make_premade_RenderParams() {
    struct RenderParams ret;

    ret = unk_make_RenderParams(2, 1, 1, 1);

    return ret;
}

#endif