#include <include_asm.h>
#include <ultra64.h>

extern void (*D_8009F070[9])();

// TODO different compiler
// void func_8001DE00()
// {
//     u32 i;
//     for (i = 0; i < 9; i++)
//     {
//         D_8009F070[i]();
//     }
// }

INCLUDE_ASM(s32, "codeseg2/codeseg2_0", func_8001DE00);
