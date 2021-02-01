#include <include_asm.h>
#include <ultra64.h>

// IDO?

extern s32 D_800BD2F8;
extern s32 D_800BD304;
extern s32 D_800BD308;

INCLUDE_ASM(s32, "codeseg1/codeseg1_35", func_80005C30);

INCLUDE_ASM(s32, "codeseg1/codeseg1_35", func_80005CB4);

INCLUDE_ASM(s32, "codeseg1/codeseg1_35", func_80005D2C);

INCLUDE_ASM(s32, "codeseg1/codeseg1_35", func_80005D64);

struct unkfunc_80005D8C {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
};

void func_80005D8C(struct unkfunc_80005D8C *arg0)
{
    if (arg0 && arg0->unk10 < 0)
    {
        D_800BD2F8 = arg0;
    }
}

// TODO Doesn't match, different opt flags or different compiler
// s32 func_80005DAC()
// {
//     return D_800BD2F8;
// }

INCLUDE_ASM(s32, "codeseg1/codeseg1_35", func_80005DAC);

INCLUDE_ASM(s32, "codeseg1/codeseg1_35", func_80005DBC);

void func_80006220(u8 *);

// TODO Doesn't match, different opt flags or different compiler
// void func_80005E14(s32 arg0)
// {
//     u8 sp10[4];
//     sp10[0] = 0;
//     func_80006220(sp10);
// }

INCLUDE_ASM(s32, "codeseg1/codeseg1_35", func_80005E14);

// TODO Doesn't match, different opt flags or different compiler
// void func_80005E3C(s32 arg0)
// {
//     u8 sp10[4];
//     sp10[0] = 1;
//     func_80006220(sp10);
// }

INCLUDE_ASM(s32, "codeseg1/codeseg1_35", func_80005E3C);

INCLUDE_ASM(s32, "codeseg1/codeseg1_35", func_80005E68);

INCLUDE_ASM(s32, "codeseg1/codeseg1_35", func_80005E9C);

INCLUDE_ASM(s32, "codeseg1/codeseg1_35", func_80005EEC);

// TODO Doesn't match, different opt flags or different compiler
// s32 func_80005F5C(s32 *arg0)
// {
//     return arg0[1];
// }

INCLUDE_ASM(s32, "codeseg1/codeseg1_35", func_80005F5C);

void func_80005F68(s32 arg0)
{
    D_800BD304 = arg0;
}

void func_80005F74(s32 arg0)
{
    D_800BD308 = arg0;
}
