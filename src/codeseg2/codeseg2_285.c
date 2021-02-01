#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "codeseg2/codeseg2_285", func_80070950);

INCLUDE_ASM(s32, "codeseg2/codeseg2_285", func_80070A64);

INCLUDE_ASM(s32, "codeseg2/codeseg2_285", func_80070B34);

INCLUDE_ASM(s32, "codeseg2/codeseg2_285", func_80070BC4);

struct unkfunc_80070C3C {
    u8 padding[0x94];
    s32 unk94;
};

void func_80070C3C(struct unkfunc_80070C3C *arg0, s32 arg1)
{
    arg0->unk94 = arg1;
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_285", func_80070C44);

INCLUDE_ASM(s32, "codeseg2/codeseg2_285", func_80070F0C);
