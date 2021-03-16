#include <include_asm.h>
#include <ultra64.h>

s32* func_8007F540(s32 **arg0)
{
    s32* ret = arg0[2];
    if (ret)
    {
        arg0[2] = (s32**)*ret;
    }
    return ret;
}

void func_8007F55C(s32 *arg0, s32 *arg1)
{
    if (arg1)
    {
        arg1[0] = arg0[2];
        arg0[2] = arg1;
    }
}
