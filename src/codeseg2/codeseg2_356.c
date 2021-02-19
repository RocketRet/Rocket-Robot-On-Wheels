#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_800841C4 {
    u8 padding[0x170];
    s32 unk170;
    u8 padding2[0x22C - 0x170 - 0x04];
    s32 unk22C;
};

void func_80084030(struct unkfunc_800841C4 *arg0, s32 arg1)
{
    arg0->unk170 = arg1;
    arg0->unk22C |= 0x00800000;
}

void func_80084048(struct unkfunc_800841C4 *arg0)
{
    arg0->unk22C |= 0x00080000;
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_356", func_8008405C);

INCLUDE_ASM(s32, "codeseg2/codeseg2_356", func_8008408C);
