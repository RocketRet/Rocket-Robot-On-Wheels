#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_800356F0 {
    s32 unk0;
    s32 unk4;
};

void func_800356F0(struct unkfunc_800356F0 *arg0, s32 arg1)
{
    arg0->unk4 = arg1;
}

void func_800356F8(s32 *arg0, s32 arg1)
{
    arg0[2] = arg1;
    if (arg1 == 3)
    {
        arg0[4] = 0;
        arg0[5] = 0;
    }
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_81", func_80035714);

INCLUDE_ASM(s32, "codeseg2/codeseg2_81", func_800357B8);
