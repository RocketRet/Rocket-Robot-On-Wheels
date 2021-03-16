#include <include_asm.h>
#include <ultra64.h>
#include <macros.h>

extern f64 D_8001DB80;
extern f32 D_8001DB88;
extern f64 D_8001DB90;

extern f32 __sinf(f32);

// TODO almost
// void func_800991C0(f32 arg0, f32 *arg1, f32 *arg2, f32 *arg3)
// {
//     f32 sinVal = __sinf(arg0); // f0
//     f32 fvar2;
//     f64 fvar4;
//     fvar4 = D_8001DB80 - sinVal * sinVal;
//     *arg1 = sinVal;
//     // fvar2 = ;
//     fvar2 = (absf(arg0) / D_8001DB88) + D_8001DB90;
//     if ((s32)(fvar2) & 1)
//     {
//         *arg2 = -fvar4;
//     }
//     else
//     {
//         *arg2 = fvar4;
//     }
// }

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_433", func_800991C0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_433", func_80099264);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_433", func_800992F4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_433", func_80099408);

f32 func_800995D8(f32 x)
{
    return -__sinf(x);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_433", func_800995F8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_433", func_800997BC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_433", func_8009990C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_433", func_800999D4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_433", func_80099A34);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_433", func_80099A9C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_433", func_80099B08);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_433", func_80099B8C);

s32 func_80099BCC(f32 *arg0, f32 arg1)
{
    return arg0[0] < arg1 && arg1 < arg0[1];
}
