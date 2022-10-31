#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_8002B434 {
    u8 padding[0x268];
    u32 unk268;
};

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_44", func_8002ACA0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_44", func_8002AD8C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_44", func_8002ADE4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_44", func_8002AF64);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_44", func_8002B124);

// This is getting a booster pack
INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_44", func_8002B1BC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_44", func_8002B2F4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_44", func_8002B384);

void func_80085094(u32*);

void func_8002B434(struct unkfunc_8002B434 *arg0)
{
    func_80085094(&arg0->unk268);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_44", func_8002B454);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_44", func_8002B4A0);
