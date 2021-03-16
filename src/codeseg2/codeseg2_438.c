#include <include_asm.h>
#include <ultra64.h>
#include <macros.h>
#include <types.h>

extern Vec3f gZeroVec3f;

void set_vec3f_zero(Vec3f vec)
{
    VEC3F_COPY(vec, gZeroVec3f);
}

void set_vec3f_scalar(Vec3f vec, f32 val)
{
    vec[0] = vec[1] = vec[2] = val;
}

void set_vec3f_components(Vec3f vec, f32 x, f32 y, f32 z)
{
    vec[0] = x;
    vec[1] = y;
    vec[2] = z;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_438", func_8009A85C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_438", func_8009A8C4);

f32 vec3f_magnitude(Vec3f vec)
{
    f32 x2 = vec[0] * vec[0];
    f32 y2 = vec[1] * vec[1];
    f32 z2 = vec[2] * vec[2];
    return sqrtf(x2 + y2 + z2);
}

f32 vec3f_normalize(Vec3f vec)
{
    s32 i = 0;
    f32 x2 = vec[0] * vec[0];
    f32 y2 = vec[1] * vec[1];
    f32 z2 = vec[2] * vec[2];
    f32 mag = sqrtf(x2 + y2 + z2);

    for (; i < 3; i++)
    {
        vec[i] /= mag;
    }

    return mag;
}
