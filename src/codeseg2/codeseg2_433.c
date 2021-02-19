#include <include_asm.h>
#include <ultra64.h>

extern f64 D_8001DB90;

extern f32 __sinf(f32);

// void func_800991C0(f32 arg0, f32 arg1, f32 *arg2, f32 *arg3)
// {
//     *arg2 = __sinf(arg0);
// }

INCLUDE_ASM(s32, "codeseg2/codeseg2_433", func_800991C0);

INCLUDE_ASM(s32, "codeseg2/codeseg2_433", func_80099264);

INCLUDE_ASM(s32, "codeseg2/codeseg2_433", func_800992F4);

INCLUDE_ASM(s32, "codeseg2/codeseg2_433", func_80099408);

f32 func_800995D8(f32 x)
{
    return -__sinf(x);
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_433", func_800995F8);

INCLUDE_ASM(s32, "codeseg2/codeseg2_433", func_800997BC);

INCLUDE_ASM(s32, "codeseg2/codeseg2_433", func_8009990C);

INCLUDE_ASM(s32, "codeseg2/codeseg2_433", func_800999D4);

INCLUDE_ASM(s32, "codeseg2/codeseg2_433", func_80099A34);

INCLUDE_ASM(s32, "codeseg2/codeseg2_433", func_80099A9C);

INCLUDE_ASM(s32, "codeseg2/codeseg2_433", func_80099B08);

INCLUDE_ASM(s32, "codeseg2/codeseg2_433", func_80099B8C);

INCLUDE_ASM(s32, "codeseg2/codeseg2_433", func_80099BCC);
