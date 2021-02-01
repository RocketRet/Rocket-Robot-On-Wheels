#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_80037EC0 {
    s32 unk0;
    s32 unk4;
};

void func_80037EC0(struct unkfunc_80037EC0 *arg0, s32 arg1)
{
    arg0->unk4 = arg1;
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_89", func_80037EC8);
