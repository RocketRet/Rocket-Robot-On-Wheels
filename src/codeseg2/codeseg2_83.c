#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "codeseg2/codeseg2_83", func_80035EB0);

INCLUDE_ASM(s32, "codeseg2/codeseg2_83", func_800361C4);

void func_800362DC(s32 *arg0, s32 arg1)
{
    arg0[1] = arg1;
    func_80056BD0(arg0 + 0x5);
}
