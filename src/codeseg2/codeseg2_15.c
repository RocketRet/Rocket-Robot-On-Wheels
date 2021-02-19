#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "codeseg2/codeseg2_15", func_80020A20);

void func_80020A84(s32 **arg0)
{
    arg0[0x3F][4] = 1; // TODO probably a struct
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_15", func_80020A94);
