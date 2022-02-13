#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_82", func_80035870);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_82", func_80035E08);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_82", func_80035EB0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_82", func_800361C4);

void func_800362DC(s32 *arg0, s32 arg1)
{
    arg0[1] = arg1;
    func_80056BD0(arg0 + 0x5);
}

void func_80036300(s32 **arg0)
{
    func_8003B89C(arg0[1], arg0[1][0x79] + 0x134);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_82", func_80036328);

struct unkfunc_800364F8_sub8 {
    u8 padding[0x134];
    s32 unk134;
};

struct unkfunc_800364F8 {
    s32 unk0;
    s32 unk4;
    struct unkfunc_800364F8_sub8 *unk8;
};

void func_800364F8(struct unkfunc_800364F8 *arg0)
{
    func_8003B89C(arg0->unk4, &arg0->unk8->unk134);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_82", func_80036520);

struct unkfunc_800367EC {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_82", func_800367A0);

void func_800367EC(struct unkfunc_800367EC *arg0)
{
    arg0->unk8 = 0;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_82", func_800367F4);

void func_8003698C(s32 *arg0, s32 arg1)
{
    arg0[1] = arg1;
    arg0[3] = 1;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_82", func_8003699C);

// TODO is this the same struct as unkfunc_800367EC
struct unkfunc_80036AEC {
    u8 padding[0x18];
    s32 unk18;
};

void func_80036AEC(struct unkfunc_80036AEC *arg0)
{
    arg0->unk18 = 0;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_82", func_80036AF4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_82", func_80036B80);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_82", func_80036D3C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_82", func_80036D84);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_82", func_80037844);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_82", func_80037BC8);
