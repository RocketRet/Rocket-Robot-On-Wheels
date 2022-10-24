#include <include_asm.h>
#include <ultra64.h>
#include <types.h>

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_115", func_80040220);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_115", func_800402CC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_115", func_800406E8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_115", func_80040744);

const Vec3f D_8001B0A0 = { 1.5f, -0.025f, 0.0f };

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_115", func_800407A4);

void func_800409CC(s32 arg0)
{
    func_80085094(arg0 + 0x268);
}

void func_800409EC(s32 arg0)
{
    func_80084A88(arg0 + 0x268);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_115", func_80040A0C);

void func_80040FDC(void) {

}


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_115", func_80040FE4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_115", func_800410F4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_115", func_80041264);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_115", func_80041298);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_115", func_8004133C);

struct unkfunc_80041414 {
    u8 padding[0x230];
    s32 unk230;
    s32 unk234;
};

void func_80041414(struct unkfunc_80041414 *arg0)
{
    func_8007F580(arg0);
    arg0->unk234 = 0;
    arg0->unk230 = 0;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_115", func_80041444);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_115", func_800414C8);
