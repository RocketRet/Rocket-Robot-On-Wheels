#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "codeseg2/codeseg2_332", func_8007F1D0);

INCLUDE_ASM(s32, "codeseg2/codeseg2_332", func_8007F1F4);

INCLUDE_ASM(s32, "codeseg2/codeseg2_332", func_8007F22C);

extern s32 D_8009FE10;

void func_8007F368(s32 arg0, u32 arg1)
{
    D_8009FE10 = arg1 < 1;
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_332", func_8007F378);
