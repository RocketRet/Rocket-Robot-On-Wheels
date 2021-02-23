#include <include_asm.h>
#include <ultra64.h>
#include <types.h>

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
