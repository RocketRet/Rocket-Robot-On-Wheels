#ifndef __MACROS_H__
#define __MACROS_H__

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

#define VEC3F_COPY(dst, src) \
    __builtin_memcpy(dst, src, 3 * sizeof(f32))

#define VEC3F_ADD(dst, a, b) \
    (dst)[0] = (a)[0] + (b)[0]; \
    (dst)[1] = (a)[1] + (b)[1]; \
    (dst)[2] = (a)[2] + (b)[2]

#define VEC3F_SUB(dst, a, b) \
    (dst)[0] = (a)[0] - (b)[0]; \
    (dst)[1] = (a)[1] - (b)[1]; \
    (dst)[2] = (a)[2] - (b)[2]

#define MTX3F_COPY(dst, src) \
    __builtin_memcpy(dst, src, 9 * sizeof(f32))

#define sqrtf __inline_sqrtf
#define sqrt __inline_sqrt

static __inline__ __const__ f32 __inline_sqrtf (f32 in)
{
    float out;
    __asm__("sqrt.s %0,%1" : "=f" (out) : "f" (in));
    return out;
}

static __inline__ __const__ f64 __inline_sqrt (f64 in)
{
    float out;
    __asm__("sqrt.s %0,%1" : "=f" (out) : "f" (in));
    return out;
}

#define absf __inline_absf

static __inline__ __const__ f32 __inline_absf (f32 in)
{
    float out;
    __asm__("abs.s %0,%1" : "=f" (out) : "f" (in));
    return out;
}

#endif