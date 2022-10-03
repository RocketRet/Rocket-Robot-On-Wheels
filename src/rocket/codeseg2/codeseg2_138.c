#include <include_asm.h>
#include <ultra64.h>
#include "macros.h"

void func_800454B0(f32 *arg0, s32 arg1, u8 *dataPtr)
{
    arg0[0xAD] = FLT_MAX;
    func_800875E8(arg0, arg1, dataPtr);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_138", func_800454D8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_138", func_80045580);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_138", func_80045628);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_138", func_8004570C);
