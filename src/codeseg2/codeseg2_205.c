#include <include_asm.h>
#include <ultra64.h>
#include <types.h>

void func_800576E0(Mtx3f a, Mtx3f b, Mtx3f out)
{
    func_80057708(b, a, out);
}

void func_80057708(Mtx3f a, Mtx3f b, Mtx3f out)
{
    s32 i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            out[i][j] = 
                a[0][j] * b[0][i] +
                a[1][j] * b[1][i] +
                a[2][j] * b[2][i];
        }
    }
}

void func_80057778(Mtx3f a, Mtx3f b, Mtx3f out)
{
    s32 i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            out[i][j] = 
                a[j][0] * b[i][0] +
                a[j][1] * b[i][1] +
                a[j][2] * b[i][2];
        }
    }
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_205", func_800577E8);
