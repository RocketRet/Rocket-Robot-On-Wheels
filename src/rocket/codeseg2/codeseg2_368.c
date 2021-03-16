#include <include_asm.h>
#include <ultra64.h>


struct unkfunc_8008530C {
    u8 padding[0x268];
    u32 unk268;
};

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_368", func_80085220);

void func_800852EC(struct unkfunc_8008530C *arg0)
{
    func_80085094(&arg0->unk268);
}

void func_8008530C(struct unkfunc_8008530C *arg0)
{
    func_80084A88(&arg0->unk268);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_368", func_8008532C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_368", func_8008546C);
