#include <include_asm.h>
#include <ultra64.h>

s32 func_80004D60(u8 *arg0, s32 arg1)
{
    arg0[0xD2] = 0; // TODO probably a struct
    return arg1;
}

INCLUDE_ASM(s32, "codeseg1/codeseg1_27", func_80004D6C);
