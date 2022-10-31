#include <include_asm.h>
#include <ultra64.h>

extern u16* D_800A5990;

u32 func_80042A50(s32 arg0, u16 *arg1);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_123", func_800429C0);

s32 func_80042A28(s32 arg0)
{
    return func_80042A50(arg0, D_800A5990);
}
