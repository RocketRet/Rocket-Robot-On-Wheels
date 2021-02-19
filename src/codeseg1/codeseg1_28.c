#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "codeseg1/codeseg1_28", func_80004D80);

s32 func_80004D94(s32 arg0, s32 arg1)
{
    return arg1 + 2; // TODO probably a struct
}

INCLUDE_ASM(s32, "codeseg1/codeseg1_28", func_80004D9C);

s32 func_80004DE4(s32 *arg0, s32 arg1)
{
    arg0[0x21] = 0; // TODO probably a struct
    return arg1;
}
