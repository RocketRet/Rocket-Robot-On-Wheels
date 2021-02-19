#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "codeseg2/codeseg2_333", func_8007F3C0);

INCLUDE_ASM(s32, "codeseg2/codeseg2_333", func_8007F404);

INCLUDE_ASM(s32, "codeseg2/codeseg2_333", func_8007F494);

s32* func_8007F524(s32 **arg0)
{
    s32* ret = arg0[2];
    if (ret)
    {
        arg0[2] = (s32**)*ret;
    }
    return ret;
}
