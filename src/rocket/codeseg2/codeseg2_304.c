#include <include_asm.h>
#include <ultra64.h>

extern struct {
    f32 unk0;
} D_8009FE14;

struct unkfunc_80076734 {
    u8 padding[0x48];
    s32 unk48;
    s32 unk4C;
    f32 unk50;
};

void func_80076734(struct unkfunc_80076734 *arg0, s32 arg1);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_304", func_800765B0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_304", func_8007668C);

void func_800766E8(struct unkfunc_80076734 *arg0)
{
    func_80076734(arg0, 2);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_304", func_80076708);

void func_80076734(struct unkfunc_80076734 *arg0, s32 arg1)
{
    if (arg1 != arg0->unk48)
    {
        arg0->unk48 = arg1;
        arg0->unk50 = D_8009FE14.unk0;
    }
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_304", func_80076754);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_304", func_8007679C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_304", func_80076944);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_304", func_80076B54);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_304", func_80076C00);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_304", func_80076C64);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_304", func_80076E58);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_304", func_80076EB0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_304", func_800771E4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_304", func_800772D8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_304", func_80077498);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_304", func_800774DC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_304", func_80077514);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_304", func_800775A0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_304", func_80077714);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_304", func_80077774);
