#include <include_asm.h>
#include <ultra64.h>


s32 func_80003780(s32 arg0) {
    return arg0 + 0x78;
}


INCLUDE_ASM(s32, "codeseg1/codeseg1_2", func_80003788);

INCLUDE_ASM(s32, "codeseg1/codeseg1_2", func_8000388C);

INCLUDE_ASM(s32, "codeseg1/codeseg1_2", func_8000398C);

INCLUDE_ASM(s32, "codeseg1/codeseg1_2", func_80003A9C);

INCLUDE_ASM(s32, "codeseg1/codeseg1_2", func_80003B7C);
