#include <include_asm.h>
#include <ultra64.h>

void func_80037EF0(s32 *arg0)
{
    arg0[0xEA] = -1;
    func_800875E8();
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_90", func_80037F14);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_90", func_80038104);
