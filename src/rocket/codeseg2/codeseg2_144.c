#include <include_asm.h>
#include <ultra64.h>
#include "codeseg2.h"

extern f32 D_8001B420;

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_144", func_80046200);

void func_80046268()
{
    func_80089D5C();
    D_800A5C3C.unk34 = alloc_second_heap(0x3C00);
    D_800C0440.unk10 = 1.0f;
    D_800C0440.unk14 = 1.0f;
    D_800A5C3C.unk28 = 0;
    D_800C0440.unk18 = 0xFF;
    D_800C0440.unk19 = 0xFF;
    D_800C0440.unk1A = 0xFF;
    D_800C0440.unk1B = 0xFF;
    D_800C0440.unk0 = 0x14;
    D_800C0440.unk4 = 0x14;
    D_800C0440.unk8 = 0x140;
    D_800C0440.unkC = 1;
}

void func_800462E4(Gfx **dlHead)
{
    func_8008AAEC(dlHead);
    (*dlHead)--;
}

void func_80046318(s32 arg0, s32 arg1)
{
    D_800C0440.unk8 = arg0;
    D_800C0440.unkC = arg1;
}

void func_8004632C(s32 arg0, s32 arg1)
{
    D_800C0440.unk0 = arg0;
    D_800C0440.unk4 = arg1;
}
