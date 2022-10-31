#include <include_asm.h>
#include <ultra64.h>
#include "types.h"

void func_800824A0(struct unkfunc_800824A0 *arg0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_243", func_80066D70);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_243", func_80066E3C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_243", func_80066F24);

void func_80067108(s32 *arg0)
{
    arg0[0x8D] = arg0[0x04];
    func_800824A0((struct unkfunc_800824A0*) arg0);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_243", func_8006712C);
