#include <include_asm.h>
#include <ultra64.h>

struct unkD_800C0440 {
    u8 padding[0x10];
    f32 unk10;
    f32 unk14;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
};

extern struct unkD_800C0440 D_800C0440;

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
