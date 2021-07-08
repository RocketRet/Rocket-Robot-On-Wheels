#include <include_asm.h>
#include <ultra64.h>

extern f32 D_8001B3C0;

void func_800454B0(f32 *arg0, s32 arg1, u8 *dataPtr)
{
    arg0[0xAD] = D_8001B3C0;
    func_800875E8(arg0, arg1, dataPtr);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_138", func_800454D8);
