#ifndef __MACROS_H__
#define __MACROS_H__

#ifndef FLT_MAX
#define FLT_MAX 3.4028235e38f
#endif

#define ROMADDR(x) ((u32)x + 0xB0000000)

#define RAM_END 0x80400000
#define FRAMEBUFFER_BYTES ((SCREEN_WIDTH) * (SCREEN_HEIGHT) * sizeof(u16))

#define NEXT_GFX(gfx) (++gfx - 1)

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

#define SQUARED(x) \
    ((x) * (x))

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

#define VEC3F_MAG_SQUARED(x) \
    ((x)[0] * (x)[0] + (x)[1] * (x)[1] + (x)[2] * (x)[2])

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
    __asm__("sqrt.d %0,%1" : "=f" (out) : "f" (in));
    return out;
}

#define fabsf __inline_absf

static __inline__ __const__ f32 __inline_absf (f32 in)
{
    float out;
    __asm__("abs.s %0,%1" : "=f" (out) : "f" (in));
    return out;
}

#endif