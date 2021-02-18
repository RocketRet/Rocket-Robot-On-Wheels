#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_800841C4 {
    u8 padding[0x22C];
    s32 unk22C;
};

INCLUDE_ASM(s32, "codeseg2/codeseg2_362", func_80084410);

INCLUDE_ASM(s32, "codeseg2/codeseg2_362", func_80084424);

INCLUDE_ASM(s32, "codeseg2/codeseg2_362", func_8008443C);

void func_8008444C(struct unkfunc_800841C4 *arg0)
{
    arg0->unk22C |= 0x00004000;
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_362", func_8008445C);
