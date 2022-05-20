#ifndef __CODESEG2_H__
#define __CODESEG2_H__

#include <types.h>

struct unkfunc_8001DFD0 {
    u32 unk0;
    s32 unk4;
    s32 unk8;
    void* unkC;
    void* unk10;
    u8 pad1[0x64];
    Vec3f unk78;
    Vec3f unk84;
    u8 pad2[0x50];
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

#endif