#include <include_asm.h>
#include <ultra64.h>

struct unkD_800A5C3C {
    u8 padding[0x28];
    s16 unk28;
    u8 padding2[0x34 - 0x28 - 0x02];
    s32 unk34;
};

struct unkD_800C0440 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    f32 unk10;
    f32 unk14;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
};

extern struct unkD_800A5C3C D_800A5C3C;
extern struct unkD_800C0440 D_800C0440;
extern f32 D_8001B420;

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_144", func_80046200);

// TODO float load
// {
//     func_80089D5C();
//     D_800A5C3C.unk34 = func_800615A4(0x3C00);
//     D_800C0440.unk10 = D_8001B420;
//     D_800C0440.unk14 = D_8001B420;
//     D_800A5C3C.unk28 = 0;
//     D_800C0440.unk18 = 0xFF;
//     D_800C0440.unk19 = 0xFF;
//     D_800C0440.unk1A = 0xFF;
//     D_800C0440.unk1B = 0xFF;
//     D_800C0440.unk0 = 0x14;
//     D_800C0440.unk4 = 0x14;
//     D_800C0440.unk8 = 0x140;
//     D_800C0440.unkC = 1;
// }

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_144", func_80046268);

void func_800462E4(s32 *arg0)
{
    func_8008AAEC();
    (*arg0) -= 8;
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
