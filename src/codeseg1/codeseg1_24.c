#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "codeseg1/codeseg1_24", func_80004AE0);

INCLUDE_ASM(s32, "codeseg1/codeseg1_24", func_80004B34);

INCLUDE_ASM(s32, "codeseg1/codeseg1_24", func_80004B98);

s32 func_80004BA8(u8 *arg0, s32 arg1)
{
    arg0[0xD6] = 0; // TODO probably a struct
    return arg1;
}

INCLUDE_ASM(s32, "codeseg1/codeseg1_24", func_80004BB4);

s32 func_80004BC4(u8 *arg0, s32 arg1)
{
    arg0[0xD7] = 0; // TODO probably a struct
    return arg1;
}
