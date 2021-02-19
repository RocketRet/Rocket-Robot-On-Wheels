#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "codeseg1/codeseg1_123", func_8000D110);

INCLUDE_ASM(s32, "codeseg1/codeseg1_123", func_8000D144);

s32 D_800BEB20;

s32 *func_8000D15C()
{
    return &D_800BEB20;
}

// void func_8000D168(u8 *arg0, u8 arg1, s32 arg2)
// {
//     u8 *v0 = arg2;
//     while (v0-- != -1)
//     {
//         *arg0 = arg1;
//         arg0++;
//     }
// }

INCLUDE_ASM(s32, "codeseg1/codeseg1_123", func_8000D168);

INCLUDE_ASM(s32, "codeseg1/codeseg1_123", func_8000D18C);
