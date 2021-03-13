#include <include_asm.h>
#include <ultra64.h>
#include <types.h>

extern f32 D_8001BA10;
extern f32 D_8001BA14;
extern f32 D_8001BA18;

f32 vec3f_magnitude();
void vec3f_scale(f32, f32*, f32*);
void func_80056FA0(f32, f32*, f32*);

// TODO float load
// void func_800570D0(Vec3f in, Mtx3f out)
// {
//     float magnitude;
//     Vec3f normalized;

//     magnitude = vec3f_magnitude(in);
//     if (D_8001BA10 < magnitude) {
//         vec3f_scale(D_8001BA14 / magnitude, in, normalized);
//         func_80056FA0(magnitude, normalized, out);
//     }
//     else {
//         bzero(out, 0x24);
//         out[0][0] = out[1][1] = out[2][2] = D_8001BA18;
//     }
// }

INCLUDE_ASM(s32, "codeseg2/codeseg2_203", func_800570D0);

extern f32 D_8001BA1C;

// TODO float load
// void func_80057174(Vec3f translation, Mtx3f rotation, Mtx4f out)
// {
//     s32 i,j;
//     for (i = 0; i < 3; i++)
//     {
//         for (j = 0; j < 3; j++)
//         {
//             out[i][j] = rotation[i][j];
//         }
//     }
//     for (i = 0; i < 3; i++)
//     {
//         out[3][i] = translation[i];
//     }
//     for (i = 0; i < 3; i++)
//     {
//         out[i][3] = 0;
//     }
//     out[3][3] = 1.0f;
// }

INCLUDE_ASM(s32, "codeseg2/codeseg2_203", func_80057174);

void mtx4f_decompose(Mtx4f in, Vec3f translation, Mtx3f rotation)
{
    s32 i,j;
    if (rotation)
    {
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                rotation[i][j] = in[i][j];
            }
        }
    }
    if (translation)
    {
        for (i = 0; i < 3; i++)
        {
            translation[i] = in[3][i];
        }
    }
}
