#include <include_asm.h>
#include <ultra64.h>
#include <types.h>

f32 clampf_abs(f32, f32);

f32 func_80057280(Mtx3f arg0)
{
    // Calculate the trace of the matrix (sum of primary diagonal)
    f32 trace = arg0[0][0] + arg0[1][1] + arg0[2][2];
    // Convert the trace to the cosine of the matrix's rotational angle
    return clampf_abs((trace - 1.0) * 0.5, 1.0);
}

const f64 D_8001BA38 = 1.0;
const f64 D_8001BA40 = 0.5;
const u64 D_8001BA48 = 0x3FEFFFFDE7210BE9; // Can't match as a double for some reason
const f64 D_8001BA50 = -0.9998999834060669;
const f32 D_8001BA58 = 3.1415927;
const f32 D_8001BA5C = 65536.0f;
const f32 D_8001BA60 = 16.0f;
const f32 D_8001BA64 = 65536.0f;
const f32 D_8001BA68 = 65536.0f;
const f32 D_8001BA6C = 0.0000009536743f;

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_204", func_800572D8);

void vec3f_scale(f32, Vec3f, Vec3f);

void func_8005759C(Vec3f arg0, Vec3f arg1)
{
    Vec3f sp10;
    f32 sp20;
    func_800572D8(arg0, &sp20, sp10);
    vec3f_scale(sp20, sp10, arg1);
}

void func_800575DC(Mtx3f arg0)
{
    vec3f_normalize(&arg0[0]);
    vec3f_cross_product(&arg0[0], &arg0[1], &arg0[2]);
    vec3f_normalize(&arg0[2]);
    vec3f_cross_product(&arg0[2], &arg0[0], &arg0[1]);
    vec3f_normalize(&arg0[1]);
}

void vec3f_transpose_rotate(Mtx3f mat, Vec3f in, Vec3f out)
{
    out[0] = mat[0][0] * in[0] + mat[0][1] * in[1] + mat[0][2] * in[2];
    out[1] = mat[1][0] * in[0] + mat[1][1] * in[1] + mat[1][2] * in[2];
    out[2] = mat[2][0] * in[0] + mat[2][1] * in[1] + mat[2][2] * in[2];
}

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

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_204", func_800577E8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_204", func_800578C0);
