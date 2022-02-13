#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_53", func_8002CFA0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_53", func_8002D050);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_53", func_8002D42C);

void func_8002D678(s32 arg0, s32 (*arg1)[3], s32 arg2, s32 arg3, s32 arg4)
{
    s32 i;
    for (i = 0; i < arg0; i++)
    {
        arg1[i][0] = arg4 + (arg1[i][0] - arg3);
    }
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_53", func_8002D6AC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_53", func_8002D724);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_53", func_8002D7A0);
