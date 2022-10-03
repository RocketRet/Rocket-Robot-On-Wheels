#include <include_asm.h>
#include <ultra64.h>
#include <types.h>
#include <macros.h>

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_207", func_80057970);

// Verbatim copy of guMtxF2L, not sure why the devs included another copy of it
void mtxf_to_mtx(Mtx4f mf, Mtx *m)
{
    int i, j;
    int e1, e2;
    int *ai, *af;

    ai = (int *)&m->m[0][0];
    af = (int *)&m->m[2][0];

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 2; j++) {
            e1 = FTOFIX32(mf[i][j * 2]);
            e2 = FTOFIX32(mf[i][j * 2 + 1]);
            *(ai++) = (e1 & 0xffff0000) | ((e2 >> 16) & 0xffff);
            *(af++) = ((e1 << 16) & 0xffff0000) | (e2 & 0xffff);
        }
    }
}

// TODO
// void func_80057AC0(Mtx *in, Mtx4f out)
// {
//     s32 i,j;
//     f32 temp[4][4];

//     guMtxL2F(temp, in);

//     for (i = 0; i < 4; i++)
//     {
//         for (j = 0; j < 4; j++)
//         {
//             out[i][j] = temp[i][j];
//         }
//     }
// }

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_207", func_80057AC0);

f32 func_8009990C(f32, f32);

void func_80057B38(Vec3f arg0, f32 *arg1, f32 *arg2)
{
    // f32 in;
    *arg1 = func_8009990C(arg0[1], arg0[0]);
    // in = ;
    *arg2 = func_8009990C(arg0[2], sqrtf(arg0[0] * arg0[0] + arg0[1] * arg0[1]));
}

extern Vec3f D_800AF77C;
extern Vec3f D_800AF788;

void mtx3f_rotate_axis(f32, s32 *, Mtx3f);

// TODO reorder
// void func_80057BAC(f32 arg0, f32 arg1, Mtx3f out)
// {
//     s32 i, j;
//     Mtx3f mat1;
//     Mtx3f mat2;
//     mtx3f_rotate_axis(arg0, D_800AF788, mat1);
//     mtx3f_rotate_axis(-arg1, D_800AF77C, mat2);

//     for (i = 2; i >= 0; i--)
//     {
//         for (j = 2; j >= 0; j--)
//         {
//             out[i][j] = mat1[0][j] * mat2[i][0] +
//                         mat1[1][j] * mat2[i][1] +
//                         mat1[2][j] * mat2[i][2];
//         }
//     }
// }

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_207", func_80057BAC);

void vec3f_scale(f32, Vec3f, Vec3f);
void vec3f_cross_product(Vec3f, Vec3f, Vec3f);
f32 vec3f_safe_normalize(Vec3f in, Vec3f out);
f32 vec3f_magnitude(Vec3f);

void func_80057C6C(Vec3f arg0, Mtx3f arg1)
{
    f32 mag = vec3f_magnitude(arg0);
    if (mag < 0.0001f)
    {
        bzero(arg1, sizeof(Mtx3f));
        arg1[0][0] = arg1[1][1] = arg1[2][2] = 1.0f;
    }
    else
    {
        vec3f_scale(1.0f / mag, arg0, arg1[0]);
        vec3f_cross_product(D_800AF788, arg1[0], arg1[1]);
        vec3f_safe_normalize(arg1[1], D_800AF77C);
        vec3f_cross_product(arg1[0], arg1[1], arg1[2]);
    }
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_207", func_80057D28);

// void func_80057EA4()
// {

// }

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_207", func_80057EA4);
