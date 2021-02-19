#include <include_asm.h>
#include <ultra64.h>

extern f32 D_8009FE14;

struct unkfunc_800451D0 {
    u8 padding[0x260];
    s32 unk260;
    f32 unk264;
};

// TODO reorder
// void func_800451D0(struct unkfunc_800451D0 *arg0, s32 arg1)
// {
//     if (arg1 != arg0->unk260)
//     {
//         arg0->unk260 = arg1;
//         arg0->unk264 = D_8009FE14;
//     }
// }

INCLUDE_ASM(s32, "codeseg2/codeseg2_134", func_800451D0);
