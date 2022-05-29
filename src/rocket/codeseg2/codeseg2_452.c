#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_452", func_8009DEA0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_452", func_8009DEF8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_452", func_8009DF9C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_452", func_8009E05C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_452", func_8009E13C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_452", func_8009E1B0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_452", func_8009E5EC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_452", func_8009E6D4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_452", func_8009E7CC);

extern struct {
    f32 unk0;
} D_8009FE14;

struct unkfunc_8009E84C {
    u8 padding[0x18];
    s32 unk18;
    f32 unk1C;
};

void func_8009E84C(struct unkfunc_8009E84C *arg0, s32 arg1)
{
    if (arg1 != arg0->unk18)
    {
        arg0->unk18 = arg1;
        arg0->unk1C = D_8009FE14.unk0;
    }
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_452", func_8009E86C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_452", func_8009E9B4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_452", func_8009EA40);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_452", func_8009EC94);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_452", func_8009EDC8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_452", func_8009EE60);
