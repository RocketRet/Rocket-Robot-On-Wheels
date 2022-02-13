#include <include_asm.h>
#include <ultra64.h>
#include <types.h>


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_198", func_80056BD0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_198", func_80056C10);

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

void vec3f_transform(Mtx4f mat, Vec3f in, f32 w, Vec3f out)
{
    s32 i, j;
    for (i = 0; i < 3; i++)
    {
        out[i] = mat[3][i] * w;
        for (j = 0; j < 3; j++)
        {
            out[i] += mat[j][i] * in[j];
        }
    }
}

void mtx3f_transpose(Mtx3f in, Mtx3f out)
{
    s32 i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            out[i][j] = in[j][i];
        }
    }
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_198", func_80056F50);

extern f32 D_8001BA0C;

void get_sin_cos(f32, f32*, f32*);

// float load
#ifdef NON_MATCHING
void mtx3f_rotate_axis(f32 angle, Vec3f arg1, Mtx3f out)
{
    s32 i,j;
    f32 temp, sinVal, cosVal;

    get_sin_cos(angle, &sinVal, &cosVal);
    temp = D_8001BA0C - cosVal;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            out[i][j] = temp * arg1[i] * arg1[j];
        }
    }

    for (i = 0; i < 3; i++)
    {
        out[i][i] += cosVal;
    }

    temp = sinVal * arg1[2];

    out[0][1] += temp;
    out[1][0] -= temp;

    temp = sinVal * arg1[1];
    
    out[0][2] -= temp;
    out[2][0] += temp;

    temp = sinVal * arg1[0];
    
    out[1][2] += temp;
    out[2][1] -= temp;
}
#else
INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_198", mtx3f_rotate_axis);
#endif
