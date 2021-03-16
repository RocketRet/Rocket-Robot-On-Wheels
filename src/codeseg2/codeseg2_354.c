#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_80083A10 {
    u8 padding[0x1E4];
    void *unk1E4;
    u8 padding2[0x22C - 4 - 0x1E4];
    s32 unk22C;
};

void func_80083A10(struct unkfunc_80083A10 *arg0, void **arg1)
{
    arg1[2] = arg0->unk1E4;
    arg0->unk1E4 = arg1;
    arg0->unk22C &= 0x7FFFFFFF;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_354", func_80083A34);
