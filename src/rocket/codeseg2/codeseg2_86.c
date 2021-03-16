#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_800367EC {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_86", func_800367A0);

void func_800367EC(struct unkfunc_800367EC *arg0)
{
    arg0->unk8 = 0;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_86", func_800367F4);

void func_8003698C(s32 *arg0, s32 arg1)
{
    arg0[1] = arg1;
    arg0[3] = 1;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_86", func_8003699C);

// TODO is this the same struct as unkfunc_800367EC
struct unkfunc_80036AEC {
    u8 padding[0x18];
    s32 unk18;
};

void func_80036AEC(struct unkfunc_80036AEC *arg0)
{
    arg0->unk18 = 0;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_86", func_80036AF4);
