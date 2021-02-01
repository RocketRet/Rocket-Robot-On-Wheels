#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_80005F90 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
};

void func_80005F90(struct unkfunc_80005F90 *arg0, s32 arg1)
{
    arg0->unk10 = arg1;
}

INCLUDE_ASM(s32, "codeseg1/codeseg1_37", func_80005F98);

INCLUDE_ASM(s32, "codeseg1/codeseg1_37", func_80005FA4);
