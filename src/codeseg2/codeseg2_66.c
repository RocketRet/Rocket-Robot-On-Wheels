#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_8002FB6C {
    u8 padding[0x270];
    u32 unk270;
};


INCLUDE_ASM(s32, "codeseg2/codeseg2_66", func_8002F690);

INCLUDE_ASM(s32, "codeseg2/codeseg2_66", func_8002F724);

void func_8002FB6C(struct unkfunc_8002FB6C *arg0)
{
    func_80085094(&arg0->unk270);
}

void func_8002FB8C(struct unkfunc_8002FB6C *arg0)
{
    func_80084A88(&arg0->unk270);
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_66", func_8002FBAC);

INCLUDE_ASM(s32, "codeseg2/codeseg2_66", func_8002FC2C);

INCLUDE_ASM(s32, "codeseg2/codeseg2_66", func_8002FC9C);

INCLUDE_ASM(s32, "codeseg2/codeseg2_66", func_8002FDB4);

INCLUDE_ASM(s32, "codeseg2/codeseg2_66", func_8002FDF8);

INCLUDE_ASM(s32, "codeseg2/codeseg2_66", func_800303FC);
