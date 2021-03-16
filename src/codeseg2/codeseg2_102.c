#include <include_asm.h>
#include <ultra64.h>
#include <types.h>

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_102", func_8003BA40);

f32 func_8009990C(f32, f32);
f32 func_80098900(f32);

void func_8003C364(f32 *arg0, struct ControllerData *arg1, f32 *arg2)
{
    f32 f20 = func_8009990C(-arg1->x, arg1->y);
    f32 f0 = func_8009990C(arg0[4], arg0[3]);
    *arg2 = func_80098900(f20 + f0);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_102", func_8003C3C8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_102", func_8003C434);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_102", func_8003C584);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_102", func_8003C764);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_102", func_8003C8EC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_102", func_8003C9A4);

struct unkfunc_8003CA8C {
    u8 padding[0xD8];
    s32 unkD8;
    s32 unkDC;
    f32 unkE0;
};

void func_8003CA8C(struct unkfunc_8003CA8C *arg0, f32 *arg1)
{
    arg0->unkD8 = 1;
    if (arg1)
    {
        arg0->unkDC = 1;
        arg0->unkE0 = *arg1;
    }
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_102", func_8003CAAC);
