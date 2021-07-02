#include <include_asm.h>
#include <ultra64.h>

f32 clampf_abs(f32 val, f32 absMax)
{
    f32 ret = val;
    if (val > absMax)
    {
        ret = absMax;
    }
    else if (val < -absMax)
    {
        ret = -absMax;
    }
    return ret;
}
