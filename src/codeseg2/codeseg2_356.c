#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_800841C4 {
    u8 padding[0x22C];
    s32 unk22C;
};

INCLUDE_ASM(s32, "codeseg2/codeseg2_356", func_80084030);

void func_80084048(struct unkfunc_800841C4 *arg0)
{
    arg0->unk22C |= 0x00080000;
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_356", func_8008405C);

INCLUDE_ASM(s32, "codeseg2/codeseg2_356", func_8008408C);
