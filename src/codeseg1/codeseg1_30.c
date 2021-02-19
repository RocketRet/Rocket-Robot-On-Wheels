#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "codeseg1/codeseg1_30", func_80004F20);

u8 *func_80004F74(u8 *arg0, u8 *arg1)
{
    arg0[0xBC] = *arg1; // TODO probably a struct
    return arg1 + 1;
}

INCLUDE_ASM(s32, "codeseg1/codeseg1_30", func_80004F84);

INCLUDE_ASM(s32, "codeseg1/codeseg1_30", func_8000505C);

u8 *func_80005094(u8 *arg0, u8 *arg1)
{
    arg0[0xD4] = *arg1; // TODO probably a struct
    return arg1 + 1;
}

INCLUDE_ASM(s32, "codeseg1/codeseg1_30", func_800050A4);

INCLUDE_ASM(s32, "codeseg1/codeseg1_30", func_800050EC);
