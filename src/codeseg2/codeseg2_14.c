#include <include_asm.h>
#include <ultra64.h>

void func_80020780(s32 *arg0)
{
    s32 val = arg0[0x44];
    val &= ~(12 << 20);
    val &= ~(3 << 20);
    val |= (1 << 20);
    arg0[0x44] = val;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_14", func_800207AC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_14", func_8002085C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_14", func_8002090C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_14", func_8002095C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_14", func_800209BC);
