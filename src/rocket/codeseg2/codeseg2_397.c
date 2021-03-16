#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_397", func_800907B0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_397", func_8009099C);

extern s32 D_8009F094;
extern s32 D_800AF3FC;

void func_80091024(s32 arg0, s32 arg1)
{
    D_800AF3FC = 1;
    func_8009099C(D_8009F094);
}

void func_80091054()
{
    D_800AF3FC = 0;
}
