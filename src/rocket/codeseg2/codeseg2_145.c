#include <include_asm.h>
#include <ultra64.h>
#include "codeseg2.h"

void func_80046340(f32 arg0, f32 arg1)
{
    D_800C0440.unk10 = arg0;
    D_800C0440.unk14 = arg1;
}

void func_80046354(u8 arg0, u8 arg1, u8 arg2, u8 arg3)
{
    D_800C0440.unk18 = arg0;
    D_800C0440.unk19 = arg1;
    D_800C0440.unk1A = arg2;
    D_800C0440.unk1B = arg3;
}
