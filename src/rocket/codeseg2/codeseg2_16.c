#include <include_asm.h>
#include <ultra64.h>
#include <types.h>

extern struct MaterialGfx *materialTable;

void func_80020AF0(struct unkfunc_8009C28C *arg0, s32 arg1, Gfx* arg2)
{
    if (arg1 != -1 && arg1 == arg0->unk230)
    {
        arg0->unk234[0] = materialTable[arg1].materialData;
        gSPDisplayList(arg2, func_800922C4(arg0->unk234, 1));
    }
    else
    {
        func_80086310(arg0, arg1, arg2);
    }
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_16", func_80020B6C);
