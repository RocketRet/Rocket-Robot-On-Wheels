#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "codeseg1/codeseg1_39", func_80006010);

extern s32 D_800BD30C;

void func_80006084(s32 arg0)
{
    D_800BD30C = arg0;
}
