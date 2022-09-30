#include <include_asm.h>
#include <ultra64.h>
#include <macros.h>

extern f32 sinf(f32);

void sincosf(f32 angle, f32 *sinOut, f32 *cosOut)
{
    f32 sinVal;
    f64 cosVal;
    s32 negativeCos;
    s32 num_half_rotations;

    sinVal = sinf(angle);
    *sinOut = sinVal;
    cosVal = sqrtf(1.0 - sinVal * sinVal);
    num_half_rotations = (s32)(0.5 + fabsf(angle) / (float)M_PI);

    if (num_half_rotations & 1) {
        *cosOut = -cosVal;
    } else {
        *cosOut = cosVal;
    }
}

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

// asm(".include \"src/rocket/codeseg2/codeseg2_433_rodata.s\"");
