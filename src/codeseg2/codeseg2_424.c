#include <include_asm.h>
#include <ultra64.h>
#include <types.h>


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_424", func_800976D0);

struct unkfunc_8009778C {
    u8 padding[0x7C];
    f32 unk7C;
    u32 unk80;
    u32 unk84;
    u32 unk88;
    f32 unk8C;
    u32 unk90;
    u32 unk94;
    f32 unk98;
};

void func_8009778C(struct unkfunc_8009778C *arg0, Vec3f arg1)
{
    arg0->unk7C = arg1[0];
    arg0->unk8C = arg1[1];
    arg0->unk98 = arg1[2];
}

struct unkfunc_800977A8 {
    u8 padding[0x62];
    s8 unk62;
};

void func_800977A8(struct unkfunc_800977A8 *arg0)
{
    arg0->unk62 = 0;
}
