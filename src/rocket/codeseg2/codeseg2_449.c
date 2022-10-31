#include <include_asm.h>
#include <ultra64.h>
#include <types.h>


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_449", func_8009C730);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_449", func_8009C7C4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_449", func_8009C8DC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_449", func_8009CDBC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_449", func_8009CEF8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_449", func_8009CFF4);

struct unkfunc_8009D61C {
    u8 padding[0xA4];
    void (*unkA4)(struct unkfunc_8009D61C **, s32);
};

void func_8009D61C(s32 arg0, struct unkfunc_8009D61C ***arg1)
{
    (*arg1[1])->unkA4(arg1[1], arg0);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_449", func_8009D64C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_449", func_8009D764);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_449", func_8009D84C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_449", func_8009D898);

extern struct MaterialGfx *materialTable;

Gfx *func_800922C4(struct MaterialGfx *, s32);
void func_80086310(struct unkfunc_800338D0 *arg0, s32 arg1, Gfx *arg2);

void func_8009DA54(struct unkfunc_800338D0 *arg0, s32 arg1, Gfx* arg2)
{
    if (arg0->unk26D == 0 && arg0->unk258.gfx == 0)
    {
        arg0->unk258.materialData.raw = materialTable[arg1].materialData.raw;
        gSPDisplayList(arg2, func_800922C4(&arg0->unk258, 1));
    }
    else
    {
        func_80086310(arg0, arg1, arg2);
    }
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_449", func_8009DAD0);

