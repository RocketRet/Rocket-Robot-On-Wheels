#include <include_asm.h>
#include <ultra64.h>

extern f32 D_8001BA10;
extern f32 D_8001BA14;
extern f32 D_8001BA18;

f32 func_8009A958();
void func_8009ABD8(f32, f32*, f32*);
void func_80056FA0(f32, f32*, f32*);

// TODO different compiler
// void func_800570D0(s32 arg0, f32 *arg1)
// {
//     float fVar2;
//     f32 arr[4]; // how long is this array?

//     fVar2 = func_8009A958();
//     if (D_8001BA10 < fVar2) {
//         func_8009ABD8(D_8001BA14 / fVar2, arg1, arr);
//         func_80056FA0(fVar2, arr, arg1);
//     }
//     else {
//         func_800040B0(arg1, 0x24);
//         arg1[8] = D_8001BA18;
//         arg1[4] = D_8001BA18;
//         arg1[0] = D_8001BA18;
//     }
// }

INCLUDE_ASM(s32, "codeseg2/codeseg2_203", func_800570D0);

INCLUDE_ASM(s32, "codeseg2/codeseg2_203", func_80057174);

INCLUDE_ASM(s32, "codeseg2/codeseg2_203", func_80057204);
