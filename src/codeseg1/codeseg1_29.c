#include <include_asm.h>
#include <ultra64.h>

s32 func_80004DF0(s32 arg0, s32 arg1)
{
    return arg1 + 1;
}

INCLUDE_ASM(s32, "codeseg1/codeseg1_29", func_80004DF8);

u8 *func_80004E68(u8 *arg0, u8 *arg1)
{
    arg0[0xCA] = *arg1; // TODO probably a struct
    return arg1 + 1;
}

INCLUDE_ASM(s32, "codeseg1/codeseg1_29", func_80004E78);

INCLUDE_ASM(s32, "codeseg1/codeseg1_29", func_80004ECC);
