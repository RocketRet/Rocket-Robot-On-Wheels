#include <include_asm.h>
#include <ultra64.h>

s32 func_80052810(s32 *arg0, s32 arg1)
{
    return arg0[0x0D] + (arg1 * arg0[0x0C]);
}
