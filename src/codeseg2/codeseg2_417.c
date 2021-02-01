#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_80095D70 {
    u8 padding[0x264];
    s32 unk264;
};

void func_80095D70(struct unkfunc_80095D70 *arg0, s32 arg1)
{
    arg0->unk264 = arg1;
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_417", func_80095D78);
