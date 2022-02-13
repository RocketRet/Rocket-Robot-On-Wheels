#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_410", func_80094C50);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_410", func_80094DDC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_410", func_80095038);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_410", func_800950B8);

struct unkfunc_80095138 {
    u8 padding[0x234];
    s32 unk234[0x04];
    s32 unk244;
    s32 unk248[0x04];
    s32 unk258;
};

void func_80095138(struct unkfunc_80095138 *arg0, s32 arg1)
{
    arg0->unk234[arg0->unk244++] = arg1;
}

void func_80095154(struct unkfunc_80095138 *arg0, s32 arg1)
{
    arg0->unk248[arg0->unk258++] = arg1;
}
