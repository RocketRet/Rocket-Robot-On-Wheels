#include <include_asm.h>
#include <ultra64.h>
#include <types.h>
#include <macros.h>

extern f32 D_8001DCD0;
extern f32 D_8001DCD4;

void vec3f_scale(f32, Vec3f, Vec3f);

// float load, regalloc
#ifdef NON_MATCHING
f32 vec3f_safe_normalize(Vec3f in, Vec3f out)
{
    f32 magSq;
    f32 mag;
    f32 ret;

    magSq = in[0] * in[0] + in[1] * in[1] + in[2] * in[2];
    mag = sqrtf(magSq);
    if (mag > D_8001DCD0)
    {
        vec3f_scale(D_8001DCD4 / mag, in, out);
    }
    else
    {
        VEC3F_COPY(out, in);
    }

    return mag;
}
#else
INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_439", vec3f_safe_normalize);
#endif

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_439", func_8009AA68);

f32 vec3f_dist(Vec3f a, Vec3f b)
{
    Vec3f diff;
    f32 sumSq;

    diff[0] = (a[0] - b[0]);
    diff[1] = (a[1] - b[1]);
    diff[2] = (a[2] - b[2]);

    sumSq = diff[0] * diff[0] + diff[1] * diff[1] + diff[2] * diff[2];
    return sqrtf(sumSq);
}

void vec3f_xy_dist(Vec3f a, Vec3f b)
{
    Vec3f diff;

    diff[0] = (a[0] - b[0]);
    diff[1] = (a[1] - b[1]);
    diff[2] = (a[2] - b[2]);

    return vec2f_magnitude(diff);
}

f32 vec3f_dist_sq(Vec3f a, Vec3f b)
{
    Vec3f diff;

    diff[0] = (a[0] - b[0]);
    diff[1] = (a[1] - b[1]);
    diff[2] = (a[2] - b[2]);

    return diff[0] * diff[0] + diff[1] * diff[1] + diff[2] * diff[2];
}

f32 vec2f_magnitude(Vec2f in)
{
    f32 magSq = in[0] * in[0] + in[1] * in[1]; 
    return sqrtf(magSq);
}

void vec3f_scale(f32 scale, Vec3f in, Vec3f out)
{
    s32 i;
    for (i = 0; i < 3; i++)
    {
        out[i] = scale * in[i];
    }
}

void vec3f_cross_product(Vec3f a, Vec3f b, Vec3f out)
{
    out[0] = a[1] * b[2] - a[2] * b[1];
    out[1] = a[2] * b[0] - a[0] * b[2];
    out[2] = a[0] * b[1] - a[1] * b[0];
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_439", func_8009AC68);

void vec3f_scale_add(f32 aScale, Vec3f a, f32 bScale, Vec3f b, Vec3f out)
{
    s32 i;
    for (i = 0; i < 3; i++)
    {
        out[i] = a[i] * aScale + b[i] * bScale;
    }
}
