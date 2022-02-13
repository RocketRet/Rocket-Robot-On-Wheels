#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_8003CFD0 {
    u8 padding[0x18];
    s32 unk18[0x09];
    s32 unk3C;
};

void func_8003CFD0(struct unkfunc_8003CFD0 *arg0, s32 arg1)
{
    arg0->unk18[arg0->unk3C++] = arg1;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_106", func_8003CFEC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_106", func_8003D064);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_106", func_8003D0D8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_106", func_8003D12C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_106", func_8003D15C);
