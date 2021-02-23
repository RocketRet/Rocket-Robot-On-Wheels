#include <include_asm.h>
#include <ultra64.h>

extern f32 D_8001B3D8;

void func_80045B60(f32 *arg0)
{
    arg0[0x8F] = D_8001B3D8;
    func_800875E8();
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_141", func_80045B88);
