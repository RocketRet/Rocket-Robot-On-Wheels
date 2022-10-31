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


static inline Gfx* next_gfx() {
    Gfx* ret = gGfxContext.dlHead;
    gGfxContext.dlHead++;
    return ret;
}

static inline s32 unk_parse_struct_unkfunc_80093DDC(struct unkfunc_80093DDC arg0) {
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

static inline struct unkfunc_80093DDC unk_make_struct_unkfunc_80093DDC() {
    struct unkfunc_80093DDC ret;
    ret.unk0_0 = 0;
    ret.unk0_4 = 0;
    ret.unk1 = 0;
    ret.unk2 = 0;
    ret.unk3 = unk_parse_struct_unkfunc_80093DDC(ret);
    return ret;
}

#endif