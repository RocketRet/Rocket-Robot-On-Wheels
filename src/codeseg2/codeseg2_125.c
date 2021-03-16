#include <include_asm.h>
#include <ultra64.h>

extern s32 D_800A5990;

void func_80042AA0(s32 arg0)
{
    func_80042AC8(arg0, D_800A5990);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_125", func_80042AC8);
