#include <include_asm.h>
#include <ultra64.h>
#include <macros.h>

extern f64 D_8001DB80; // 1.0
extern f32 D_8001DB88; // pi
extern f64 D_8001DB90; // 0.5

extern f32 sinf(f32);

// TODO almost
// void get_sin_cos(f32 angle, f32 *sinOut, f32 *cosOut)
// {
//     f32 sinVal;
//     f64 cosVal;
//     s32 negativeCos;
//     sinVal = sinf(angle); // f0
//     *sinOut = sinVal;
//     // fvar2 = ;
//     cosVal = sqrtf(D_8001DB80 - sinVal * sinVal); // cos = sqrt(1.0 - sin^2(angle))
//     // negativeCos = 
//     // *cosOut = negativeCos ? -cosVal : cosVal;
//     if ((s32)((absf(angle) / D_8001DB88) + D_8001DB90) & 1)
//     {
//         *cosOut = -cosVal;
//     }
//     else
//     {
//         *cosOut = cosVal;
//     }
// }

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_433", get_sin_cos);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_433", func_80099264);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_433", func_800992F4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_433", func_80099408);

f32 func_800995D8(f32 x)
{
    return -sinf(x);
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
