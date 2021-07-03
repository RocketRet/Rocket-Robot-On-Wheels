#include <include_asm.h>
#include <ultra64.h>
#include <types.h>

extern struct unkD_800ADAD0 *D_800ADAD0;

struct unkfunc_80079CA0 {
    void *unk0;
    u8 padding[0x27C - 0x04];
    s32 unk27C;
};

void func_80079CA0(struct unkfunc_80079CA0 *arg0, s32 arg1, Gfx *arg2) {
    struct unkD_800ADAD0 *temp_a0;
    s32 temp_a1;
    s32 temp_a2;
    u8 *phi_v0;

    if (arg1 != -1) {
        temp_a0 = &D_800ADAD0[arg1];
        temp_a2 = temp_a0->unk0;
        temp_a1 = temp_a2 & 0xF0000000;
        if (temp_a1 != 0) {
            if (temp_a1 == 0x80000000) {
                phi_v0 = temp_a2;
            } else {
                phi_v0 = load_texture_group(temp_a0, temp_a1, temp_a2);
            }
            if (phi_v0[0x15] >= 2U) {
                arg0->unk27C = D_800ADAD0[arg1].unk0;
                gSPDisplayList(arg2, func_800922C4(&arg0->unk27C, 1));
            } else {
                func_80086310(arg0, arg1, arg2);
            }
        } else {
            func_80086310(arg0, arg1, arg2);
        }
    }
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_316", func_80079D6C);
