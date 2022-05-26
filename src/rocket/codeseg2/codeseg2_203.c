#include <include_asm.h>
#include <ultra64.h>
#include <types.h>

f32 vec3f_magnitude();
void vec3f_scale(f32, Vec3f, Vec3f);
void mtx3f_rotate_axis(f32, Vec3f, Mtx3f);

void mtx3f_axis_angle(Vec3f in, Mtx3f out)
{
    float magnitude;
    Vec3f normalized;

    magnitude = vec3f_magnitude(in);
    if (magnitude > 1.0E-4f) { // magnitude > 1E-4
        vec3f_scale(1.0f / magnitude, in, normalized); // vec3f_scale(1 / magnitude, in, normalized)
        mtx3f_rotate_axis(magnitude, normalized, out);
    }
    else {
        // build identity matrix
        bzero(out, sizeof(Mtx3f));
        out[0][0] = out[1][1] = out[2][2] = 1.0f; // 1.0f
    }
}

void mtx4f_compose(Vec3f translation, Mtx3f rotation, Mtx4f out)
{
    s32 i,j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            out[i][j] = rotation[i][j];
        }
    }
    for (i = 0; i < 3; i++)
    {
        out[3][i] = translation[i];
    }
    for (i = 0; i < 3; i++)
    {
        out[i][3] = 0;
    }
    out[3][3] = 1.0f;
}

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
