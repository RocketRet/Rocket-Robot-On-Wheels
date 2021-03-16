#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_426", func_800987B0);

void func_800987FC(s32 arg0, s32 *arg1)
{
    arg1[0x09] = 1; // TODO probably a struct
}

void func_80098808(s32 arg0, s32 *arg1)
{
    arg1[0x09] = 0; // TODO probably a struct
    arg1[0x16] = 0;
}
