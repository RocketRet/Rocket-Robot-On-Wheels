#include <include_asm.h>
#include <ultra64.h>

s32 func_80004760(u8 *arg0, s32 arg1)
{
    arg0[0xB8] = 0; // TODO probably a struct
    return arg1;
}

INCLUDE_ASM(s32, "codeseg1/codeseg1_18", func_8000476C);

INCLUDE_ASM(s32, "codeseg1/codeseg1_18", func_80004888);

INCLUDE_ASM(s32, "codeseg1/codeseg1_18", func_80004964);

INCLUDE_ASM(s32, "codeseg1/codeseg1_18", func_80004978);

INCLUDE_ASM(s32, "codeseg1/codeseg1_18", func_8000499C);

INCLUDE_ASM(s32, "codeseg1/codeseg1_18", func_80004A04);
