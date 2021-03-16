#include <include_asm.h>
#include <ultra64.h>

void func_8009C300(s32 arg0, s32 *arg1)
{
    func_80050868();
    arg1[81] = arg0; // might be a struct
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_448", func_8009C338);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_448", func_8009C4C8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_448", func_8009C5C8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_448", func_8009C6D8);
