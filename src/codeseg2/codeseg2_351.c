#include <include_asm.h>
#include <ultra64.h>

u32 func_800830C0(u32 *arg0)
{
    return (~arg0[0x70]) >> 0x1F;
}
