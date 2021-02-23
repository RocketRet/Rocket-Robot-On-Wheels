#include <include_asm.h>
#include <ultra64.h>
#include <types.h>

void func_80084110(s32 arg0, f32 arg1)
{
    Vec3f vec;
    vec[2] = arg1;
    vec[1] = arg1;
    vec[0] = 0;
    func_80084140(arg0, vec);
}
