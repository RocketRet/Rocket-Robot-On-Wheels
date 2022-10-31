#include <include_asm.h>
#include <ultra64.h>

void func_8006FFD4(s32, s32, s32);

void func_8006FE70(s32 arg0)
{
    func_8006FFD4(arg0, 0, -1);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_283", func_8006FE94);

INCLUDE_ASM(void, "rocket/codeseg2/codeseg2_283", func_8006FFD4, s32, s32, s32);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_283", func_80070190);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_283", func_800701FC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_283", func_80070254);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_283", func_800702A8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_283", func_800702E4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_283", func_8007038C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_283", func_80070438);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_283", func_8007060C);
