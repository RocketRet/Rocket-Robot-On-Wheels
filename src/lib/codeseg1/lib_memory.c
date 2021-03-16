#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "lib/codeseg1/lib_memory", __MusIntMemInit);

INCLUDE_ASM(s32, "lib/codeseg1/lib_memory", __MusIntMemMalloc);

INCLUDE_ASM(s32, "lib/codeseg1/lib_memory", __MusIntMemRemaining);

s32 D_800BEB20;

s32 *__MusIntMemGetHeapAddr()
{
    return &D_800BEB20;
}

// void __MusIntMemSet(u8 *arg0, u8 arg1, s32 arg2)
// {
//     u8 *v0 = arg2;
//     while (v0-- != -1)
//     {
//         *arg0 = arg1;
//         arg0++;
//     }
// }

INCLUDE_ASM(s32, "lib/codeseg1/lib_memory", __MusIntMemSet);

INCLUDE_ASM(s32, "lib/codeseg1/lib_memory", __MusIntMemMove);
