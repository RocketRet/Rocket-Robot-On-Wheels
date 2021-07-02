#include <include_asm.h>
#include <ultra64.h>
#include <types.h>

extern f64 D_8001BA20;
extern f64 D_8001BA28;
extern f32 D_8001BA30;

f32 clampf_abs(f32, f32);

// TODO float load
// f32 func_80057280(Mtx3f arg0)
// {
//     f32 sum = arg0[0][0] + arg0[1][1] + arg0[2][2];
//     return clampf_abs((sum - D_8001BA20) * D_8001BA28, D_8001BA30); //clampf_abs((sum - 1.0) * 0.5, 1)
// }

INCLUDE_ASM(f32, "rocket/codeseg2/codeseg2_204", func_80057280, f32, f32);

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
