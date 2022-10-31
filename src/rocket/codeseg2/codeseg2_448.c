#include <include_asm.h>
#include <ultra64.h>
#include "codeseg2.h"

void func_80050868(struct unkfunc_8001DFD0 *arg0, void* arg1, void* arg2);

void func_8009C300(struct unkfunc_8001DFD0 *arg0, void **arg1, void* arg2)
{
    func_80050868(arg0, arg1, arg2);
    arg1[81] = arg0; // might be a struct
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_448", func_8009C338);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_448", func_8009C4C8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_448", func_8009C5C8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_448", func_8009C6D8);
