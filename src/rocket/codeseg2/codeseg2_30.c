#include <include_asm.h>
#include <ultra64.h>
#include "types.h"

void func_800263B4(struct unkfunc_800263B4 *);

void func_80026450(struct unkfunc_800263B4 *arg0)
{
    func_800263B4(arg0);
    arg0->unk234 = -1;
    arg0->unk238 = -1;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_30", func_80026484);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_30", func_80026504);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_30", func_80026588);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_30", func_80026644);
