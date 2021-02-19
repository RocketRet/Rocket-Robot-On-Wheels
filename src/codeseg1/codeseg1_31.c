#include <include_asm.h>
#include <ultra64.h>

s32 func_80005160(s16 *arg0, s32 arg1)
{
    arg0[0x56] = 0; // TODO probably a struct
    return arg1;
}

INCLUDE_ASM(s32, "codeseg1/codeseg1_31", func_8000516C);
