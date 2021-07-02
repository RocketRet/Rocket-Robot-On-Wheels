#include <include_asm.h>
#include <ultra64.h>
#include <types.h>

extern f32 D_8001BA10;
extern f32 D_8001BA14;
extern f32 D_8001BA18;

f32 vec3f_magnitude();
void vec3f_scale(f32, f32*, f32*);
void mtx3f_rotate_axis(f32, f32*, f32*);

// TODO float load
// void mtx3f_axis_angle(Vec3f in, Mtx3f out)
// {
//     float magnitude;
//     Vec3f normalized;

//     magnitude = vec3f_magnitude(in);
//     if (magnitude > D_8001BA10) { // magnitude > 1E-4
//         vec3f_scale(D_8001BA14 / magnitude, in, normalized); // vec3f_scale(1 / magnitude, in, normalized)
//         mtx3f_rotate_axis(magnitude, normalized, out);
//     }
//     else {
//         // build identity matrix
//         bzero(out, sizeof(Mtx3f));
//         out[0][0] = out[1][1] = out[2][2] = D_8001BA18; // 1.0f
//     }
// }

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_203", mtx3f_axis_angle);

extern f32 D_8001BA1C;

// TODO float load
// void mtx4f_compose(Vec3f translation, Mtx3f rotation, Mtx4f out)
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

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_203", mtx4f_compose);

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
