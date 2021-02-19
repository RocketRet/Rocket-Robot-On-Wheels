#include <include_asm.h>
#include <ultra64.h>

s32 D_800AF404[];

s32 func_800911B0(s32 arg0)
{
    return D_800AF404[arg0];
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_400", func_800911CC);
