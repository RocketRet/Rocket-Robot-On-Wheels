#include <include_asm.h>
#include <ultra64.h>
#include <types.h>

void func_8001E044(struct Model *arg0, s32 arg1, u8 *dataPtr, s32 arg3);

void func_8006B7C0(struct Model *arg0, s32 arg1, u8 *arg2, s32 arg3) {
    s32 temp_v0;

    func_8001E044(arg0, arg1, arg2, arg3);
    if (func_80042A28(--arg0->unk14C) != 0) {
        temp_v0 = arg0->unk114;
        if (temp_v0 != 2) {
            if (temp_v0 == 0) {
                func_8008C590(arg0->unkC, arg0);
            }
            arg0->unk114 = 2;
        }
    }
}

// This can play the ticket get sound
INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_266", func_8006B82C);

void func_8006BA48(struct Model *arg0, s32 arg1, u8 *arg2, s32 arg3) {
    s32 temp_v0;

    func_8001E044(arg0, arg1, arg2, arg3);
    if (func_80042BA0(--arg0->unk14C) != 0) {
        temp_v0 = arg0->unk114;
        if (temp_v0 != 2) {
            if (temp_v0 == 0) {
                func_8008C590(arg0->unkC, arg0);
            }
            arg0->unk114 = 2;
        }
    }
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_266", func_8006BAB4);

// TODO investigate if this is possibly the same struct used as a union
void func_8006BBE4(struct unkfunc_8001E044_2 *arg0, s32 arg1, s32 arg2) {
    s32 (*temp_v0)(struct Model *);

    arg0->unk2C = 0x7FFFFFFF;
    func_80087E88(arg0, arg1, arg2);
    if (func_80042AA0(arg0->unk24) != 0) {
        func_8006BF3C(arg0, 2);
    }
    temp_v0 = arg0->unk0->unk40;
    if (temp_v0 != 0) {
        temp_v0((struct Model*)arg0);
    }
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_266", func_8006BC4C);
