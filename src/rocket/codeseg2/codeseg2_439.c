#include <include_asm.h>
#include <ultra64.h>
#include <types.h>
#include <macros.h>

void vec3f_scale(float, Vec3f, Vec3f);
float vec2f_magnitude(Vec2f in);

float vec3f_safe_normalize(Vec3f in, Vec3f out)
{
    float xsq = in[0] * in[0];
    float ysq = in[1] * in[1];
    float zsq = in[2] * in[2];
    float mag = sqrtf(xsq + ysq + zsq);

    if (mag > 1e-4f)
    {
        vec3f_scale(1.0f / mag, in, in);
    }
    else
    {
        VEC3F_COPY(in, out);
    }

    return mag;
}

s32 func_8009AA68(Vec3f in)
{
    return fabsf(in[0] * in[0] + in[1] * in[1] + in[2] * in[2] - 1.0f) < 1e-4f;
}

float vec3f_dist(Vec3f a, Vec3f b)
{
    Vec3f diff;
    float sumSq;

    diff[0] = (a[0] - b[0]);
    diff[1] = (a[1] - b[1]);
    diff[2] = (a[2] - b[2]);

    sumSq = diff[0] * diff[0] + diff[1] * diff[1] + diff[2] * diff[2];
    return sqrtf(sumSq);
}

float vec3f_xy_dist(Vec3f a, Vec3f b)
{
    Vec3f diff;

    diff[0] = (a[0] - b[0]);
    diff[1] = (a[1] - b[1]);
    diff[2] = (a[2] - b[2]);

    return vec2f_magnitude(diff);
}

float vec3f_dist_sq(Vec3f a, Vec3f b)
{
    Vec3f diff;

    diff[0] = (a[0] - b[0]);
    diff[1] = (a[1] - b[1]);
    diff[2] = (a[2] - b[2]);

    return diff[0] * diff[0] + diff[1] * diff[1] + diff[2] * diff[2];
}

float vec2f_magnitude(Vec2f in)
{
    float magSq = in[0] * in[0] + in[1] * in[1]; 
    return sqrtf(magSq);
}

void vec3f_scale(float scale, Vec3f in, Vec3f out)
{
    s32 i;
    for (i = 0; i < 3; i++)
    {
        out[i] = scale * in[i];
    }
}

#define CROSS_PRODUCT(out, a, b) \
    (out)[0] = (a)[1] * (b)[2] - (a)[2] * (b)[1]; \
    (out)[1] = (a)[2] * (b)[0] - (a)[0] * (b)[2]; \
    (out)[2] = (a)[0] * (b)[1] - (a)[1] * (b)[0];

void vec3f_cross_product(Vec3f a, Vec3f b, Vec3f out)
{
    CROSS_PRODUCT(out, a, b);
}

void func_8009AC68(Vec3f in, Vec3f out[2])
{
    s32 i, j;
    Vec3f val;
    Vec3f* cur_vec;

    val[0] = 1.0f;
    val[1] = 0.0f;
    val[2] = 0.0f;
    CROSS_PRODUCT(out[0], in, val);
    
    if (out[0][0] * out[0][0] + out[0][1] * out[0][1] + out[0][2] * out[0][2] < 1e-4f)
    {
        val[0] = 0.0f;
        val[2] = 1.0f;
        CROSS_PRODUCT(out[0], in, val);
    }

    cur_vec = &out[1];
    CROSS_PRODUCT(*cur_vec, in, out[0]);

    // TODO goto
    i = 0;
    start:
    if (i < 2)
    {
        float x;
        float y;
        float z;
        float mag;
        x = out[0][0];
        y = out[0][1];
        z = out[0][2];
        mag = sqrtf(x * x + y * y + z * z);
        for (j = 0; j < 3; j++)
        {
            out[0][j] /= mag;
        }
        out++;
        i++;
        goto start;
    }
}

void vec3f_scale_add(float aScale, Vec3f a, float bScale, Vec3f b, Vec3f out)
{
    s32 i;
    for (i = 0; i < 3; i++)
    {
        out[i] = a[i] * aScale + b[i] * bScale;
    }
}

void vec3f_lerp(float t, Vec3f a, Vec3f b, Vec3f out)
{
    s32 i;
    for (i = 0; i < 3; i++)
    {
        out[i] = a[i] * t + b[i] * (1.0f - t);
    }
}

const float D_8001DCEC = 1e-4f;
const float D_8001DCF0 = 1e-4f;
const float D_8001DCF4 = 0.5f;
const float D_8001DCF8 = 0.5f;
const float D_8001DCFC = 1e-4f;
const float D_8001DD00 = 1.0f;
const float D_8001DD04 = -1.0f;

// void vec3f_lerp(Vec3f a, Vec3f b)
// {
//     float dot = a[0] * b[0] + a[1] * b[1] * a[2] * b[2];

// }

// INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_439", vec3f_lerp);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_439", func_8009AEC8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_439", func_8009AF20);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_439", func_8009AFB4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_439", func_8009B138);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_439", func_8009B3B4);
