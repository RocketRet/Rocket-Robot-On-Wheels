#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_800841C4 {
    u8 padding[0x22C];
    s32 unk22C;
};

INCLUDE_ASM(s32, "codeseg2/codeseg2_358", func_80084140);

void func_800841C4(struct unkfunc_800841C4 *arg0)
{
    arg0->unk22C |= 0x00040000;
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_358", func_800841D8);

INCLUDE_ASM(s32, "codeseg2/codeseg2_358", func_80084208);

INCLUDE_ASM(s32, "codeseg2/codeseg2_358", func_8008428C);

INCLUDE_ASM(s32, "codeseg2/codeseg2_358", func_800842BC);
