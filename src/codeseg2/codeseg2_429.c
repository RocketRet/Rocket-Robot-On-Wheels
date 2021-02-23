#include <include_asm.h>
#include <ultra64.h>

f32 func_80098990(f32 arg0, f32 arg1)
{
    f32 ret = arg0;
    if (ret > arg1)
    {
        ret = arg1;
    }
    else if (ret < -arg1)
    {
        ret = -arg1;
    }
    return ret;
}
