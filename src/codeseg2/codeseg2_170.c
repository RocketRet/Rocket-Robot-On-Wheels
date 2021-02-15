#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "codeseg2/codeseg2_170", func_8004EAA0);

INCLUDE_ASM(s32, "codeseg2/codeseg2_170", func_8004EC08);

struct unkfunc_8004EC64 {
    u8 padding[0x18];
    s32 unk18;
};

void func_8004EC64(struct unkfunc_8004EC64 *arg0)
{
    arg0->unk18 = 1;
}
