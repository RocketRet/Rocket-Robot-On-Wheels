#include <include_asm.h>
#include <ultra64.h>
#include <types.h>

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_133", func_80044190);

const Vec3f D_8001B314 = { -1.0f, 2.3f, 0.0f };

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_133", func_800442F4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_133", func_80044D78);

struct unkfunc_800451D0 {
    u8 padding[0x260];
    s32 unk260;
    f32 unk264;
};

extern struct {
    f32 unk0;
} D_8009FE14;

void func_800451D0(struct unkfunc_800451D0 *arg0, s32 arg1)
{
    if (arg1 != arg0->unk260)
    {
        arg0->unk260 = arg1;
        arg0->unk264 = D_8009FE14.unk0;
    }
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_133", func_800451F0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_133", func_80045250);
