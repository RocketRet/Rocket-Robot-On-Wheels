#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_800338D0 {
    u8 padding[0x258];
    s32 unk258;
};

void func_800338D0(s32 arg0, struct unkfunc_800338D0 *arg1)
{
    arg1->unk258 = 0;
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_74", func_800338D8);

INCLUDE_ASM(s32, "codeseg2/codeseg2_74", func_80033958);

INCLUDE_ASM(s32, "codeseg2/codeseg2_74", func_80033A24);

INCLUDE_ASM(s32, "codeseg2/codeseg2_74", func_80033FFC);

INCLUDE_ASM(s32, "codeseg2/codeseg2_74", func_80034124);

INCLUDE_ASM(s32, "codeseg2/codeseg2_74", func_80034144);

struct unkfunc_80034164 {
    u8 padding[0x278];
    s32 unk278;
};

void func_80034164(struct unkfunc_80034164 *arg0)
{
    func_80085094(&arg0->unk278);
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_74", func_80034184);

INCLUDE_ASM(s32, "codeseg2/codeseg2_74", func_800341A4);

INCLUDE_ASM(s32, "codeseg2/codeseg2_74", func_80034294);
