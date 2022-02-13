#include <include_asm.h>
#include <ultra64.h>
#include <mem.h>


void read_vec3f(u8 **dataPtrPtr, Vec3f arg1)
{
    int i;
    *dataPtrPtr = ALIGN_PTR(*dataPtrPtr, 4);
    for (i = 0; i < 3; i++)
    {
        arg1[i] = READ_VALUE(dataPtrPtr, f32);
    }
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_371", func_80085D94);
