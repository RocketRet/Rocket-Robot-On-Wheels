#include <include_asm.h>
#include <ultra64.h>
#include <types.h>

extern f32 D_8001BA0C;

void get_sin_cos(f32, f32*, f32*);

// TODO float load
// void mtx3f_rotate_axis(f32 angle, Vec3f arg1, Mtx3f out)
// {
//     s32 i,j;
//     f32 temp, sinVal, cosVal;

//     get_sin_cos(angle, &sinVal, &cosVal);
//     temp = D_8001BA0C - cosVal;
//     for (i = 0; i < 3; i++)
//     {
//         for (j = 0; j < 3; j++)
//         {
//             out[i][j] = temp * arg1[i] * arg1[j];
//         }
//     }

//     for (i = 0; i < 3; i++)
//     {
//         out[i][i] += cosVal;
//     }

//     temp = sinVal * arg1[2];

//     out[0][1] += temp;
//     out[1][0] -= temp;

//     temp = sinVal * arg1[1];
    
//     out[0][2] -= temp;
//     out[2][0] += temp;

//     temp = sinVal * arg1[0];
    
//     out[1][2] += temp;
//     out[2][1] -= temp;
// }

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_202", mtx3f_rotate_axis);
