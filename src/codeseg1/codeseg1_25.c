#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "codeseg1/codeseg1_25", func_80004BD0);

INCLUDE_ASM(s32, "codeseg1/codeseg1_25", func_80004C7C);

INCLUDE_ASM(s32, "codeseg1/codeseg1_25", func_80004D1C);

s32 func_80004D44(u8 *arg0, s32 arg1)
{
    arg0[0xCE] = 0; // TODO probably a struct
    return arg1;
}
