#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_80097010 {
    u8 padding[0x4C];
    s32 unk4C;
};

s32 func_80097010(struct unkfunc_80097010 *arg0)
{
    return arg0->unk4C + 2;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_422", func_8009701C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_422", func_800970B8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_422", func_80097134);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_422", func_80097404);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_422", func_80097438);
