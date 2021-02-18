#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_8006D458 {
    u8 padding[0x268];
    u32 unk268;
};

INCLUDE_ASM(s32, "codeseg2/codeseg2_276", func_8006D090);

INCLUDE_ASM(s32, "codeseg2/codeseg2_276", func_8006D22C);

INCLUDE_ASM(s32, "codeseg2/codeseg2_276", func_8006D438);

void func_8006D458(struct unkfunc_8006D458 *arg0)
{
    func_80084A88(&arg0->unk268);
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_276", func_8006D478);

INCLUDE_ASM(s32, "codeseg2/codeseg2_276", func_8006DA84);
