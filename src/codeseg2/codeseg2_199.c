#include <include_asm.h>
#include <ultra64.h>
#include <types.h>

INCLUDE_ASM(s32, "codeseg2/codeseg2_199", func_80056C10);

void mtx3f_concat(Mtx3f a, Mtx3f b, Mtx3f out)
{
    s32 i, j;
    for (i = 2; i >= 0; i--)
    {
        for (j = 2; j >= 0; j--)
        {
            out[i][j] = a[0][j] * b[i][0] + 
                        a[1][j] * b[i][1] + 
                        a[2][j] * b[i][2];
        }
    }
}

void mtx4f_concat(Mtx4f a, Mtx4f b, Mtx4f out)
{
    s32 i, j;
    for (i = 3; i >= 0; i--)
    {
        for (j = 3; j >= 0; j--)
        {
            out[i][j] = a[0][j] * b[i][0] + 
                        a[1][j] * b[i][1] + 
                        a[2][j] * b[i][2] + 
                        a[3][j] * b[i][3];
        }
    }
}

void func_80056D44(s32 arg0, f32 *arg1, f32 *arg2, f32 *arg3)
{
    s32 i, j;
    bzero(arg3, arg0 * sizeof(f32));
    for (i = 0; i < arg0; i++)
    {
        for (j = 0; j < arg0; j++)
        {
            arg3[i] += arg1[i + j * arg0] * arg2[j];
        }
    }
}

void vec3f_rotate(Mtx3f mat, Vec3f in, Vec3f out)
{
    out[0] = mat[0][0] * in[0] + mat[1][0] * in[1] + mat[2][0] * in[2];
    out[1] = mat[0][1] * in[0] + mat[1][1] * in[1] + mat[2][1] * in[2];
    out[2] = mat[0][2] * in[0] + mat[1][2] * in[1] + mat[2][2] * in[2];
}
