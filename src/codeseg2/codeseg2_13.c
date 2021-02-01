#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_80020730 {
    u8 padding[0xD8];
    u32 unkD8;
};

void func_80020730(struct unkfunc_80020730 *arg0, s32 arg1)
{
    arg0->unkD8 = arg1;
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_13", func_80020738);

INCLUDE_ASM(s32, "codeseg2/codeseg2_13", func_8002075C);
