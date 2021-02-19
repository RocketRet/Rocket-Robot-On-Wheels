#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "codeseg2/codeseg2_190", func_80052770);

s32 func_800527F8(s32 *arg0, s32 arg1)
{
    return arg0[0x0D] + (arg1 * arg0[0x0C]);
}
