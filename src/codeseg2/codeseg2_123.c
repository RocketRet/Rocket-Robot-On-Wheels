#include <include_asm.h>
#include <ultra64.h>

extern s32 D_800A5990;

INCLUDE_ASM(s32, "codeseg2/codeseg2_123", func_800429C0);

void func_80042A28(s32 arg0)
{
    func_80042A50(arg0, D_800A5990);
}
