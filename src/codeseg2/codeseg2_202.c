#include <include_asm.h>
#include <ultra64.h>
#include <types.h>

extern f32 D_8001BA0C;

// TODO float load
// void func_80056FA0(s32 arg0, Vec3f arg1, Mtx3f out)
// {
//     s32 i,j;
//     f32 val, val2, val3;

//     func_800991C0(arg0, &val2, &val3);
//     val = D_8001BA0C - val2;
//     for (i = 0; i < 3; i++)
//     {
//         for (j = 0; j < 3; j++)
//         {
//             out[i][j] = val * arg1[i] * arg1[j];
//         }
//     }

//     for (i = 0; i < 3; i++)
//     {
//         out[i][i] += val3;
//     }

//     val = val2 * arg1[2];

//     out[0][1] += val;
//     out[1][0] -= val;

//     val = val2 * arg1[1];
    
//     out[0][2] -= val;
//     out[2][0] += val;

//     val = val2 * arg1[0];
    
//     out[1][2] += val;
//     out[2][1] -= val;
// }

INCLUDE_ASM(s32, "codeseg2/codeseg2_202", func_80056FA0);
