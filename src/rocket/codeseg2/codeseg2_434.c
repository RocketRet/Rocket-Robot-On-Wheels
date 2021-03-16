#include <include_asm.h>
#include <ultra64.h>

f32 func_80099C00(f32 *arg0, f32 arg1)
{
    if (arg0[0] > arg1)
    {
        return arg0[0];
    }
    else if (arg1 > arg0[1])
    {
        return arg0[1];
    }
    else
    {
        return arg1;
    }
}
