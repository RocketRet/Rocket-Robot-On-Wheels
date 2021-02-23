#include <include_asm.h>
#include <ultra64.h>

extern f32 D_8001B3C0;

void func_800454B0(f32 *arg0)
{
    arg0[0xAD] = D_8001B3C0;
    func_800875E8();
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_138", func_800454D8);
