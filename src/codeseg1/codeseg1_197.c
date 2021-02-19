#include <include_asm.h>
#include <ultra64.h>

void func_8001436C();

void *func_80014360()
{
    return func_8001436C;
}

INCLUDE_ASM(s32, "codeseg1/codeseg1_197", func_8001436C);

INCLUDE_ASM(s32, "codeseg1/codeseg1_197", func_800143DC);
