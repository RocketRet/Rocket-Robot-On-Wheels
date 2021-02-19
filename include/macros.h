#ifndef __MACROS_H__
#define __MACROS_H__

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

#define VEC3F_COPY(dst, src) \
    __builtin_memcpy(dst, src, 3 * sizeof(f32))

#define sqrtf __inline_sqrtf

static __inline__ __const__ f32 __inline_sqrtf (f32 in)
{
    float out;
    __asm__("sqrt.s %0,%1" : "=f" (out) : "f" (in));
    return out;
}

#endif