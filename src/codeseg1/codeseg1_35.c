#include <include_asm.h>
#include <ultra64.h>

// IDO?

struct unkfunc_80005D8C {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
};

extern struct unkfunc_80005D8C *D_800BD2F8;
extern s32 D_800BD304;
extern s32 D_800BD308;

INCLUDE_ASM(s32, "codeseg1/codeseg1_35", func_80005C30);

INCLUDE_ASM(s32, "codeseg1/codeseg1_35", func_80005CB4);

INCLUDE_ASM(s32, "codeseg1/codeseg1_35", func_80005D2C);

INCLUDE_ASM(s32, "codeseg1/codeseg1_35", func_80005D64);

void func_80005D8C(struct unkfunc_80005D8C *arg0)
{
    if (arg0 && arg0->unk10 < 0)
    {
        D_800BD2F8 = arg0;
    }
}

s32 func_80005DAC()
{
    return D_800BD2F8;
}

INCLUDE_ASM(s32, "codeseg1/codeseg1_35", func_80005DBC);

void func_80006220(u8 *);

struct unkfunc_80005E3C {
    u8 unk0;
    u32 unk4;
};

void func_80005E14(s32 arg0)
{
    struct unkfunc_80005E3C sp10;
    sp10.unk0 = 0;
    sp10.unk4 = arg0;
    func_80006220(&sp10);
}

void func_80005E3C(s32 arg0)
{
    struct unkfunc_80005E3C sp10;
    sp10.unk0 = 1;
    sp10.unk4 = arg0;
    func_80006220(&sp10);
}

INCLUDE_ASM(s32, "codeseg1/codeseg1_35", func_80005E68);

INCLUDE_ASM(s32, "codeseg1/codeseg1_35", func_80005E9C);

INCLUDE_ASM(s32, "codeseg1/codeseg1_35", func_80005EEC);

s32 func_80005F5C(s32 *arg0)
{
    return arg0[1];
}

void func_80005F68(s32 arg0)
{
    D_800BD304 = arg0;
}

void func_80005F74(s32 arg0)
{
    D_800BD308 = arg0;
}
