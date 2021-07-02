#include <include_asm.h>
#include <ultra64.h>
#include <types.h>
#include <mem.h>

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_370", func_80085530);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_370", func_80085584);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_370", func_8008561C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_370", func_800856AC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_370", func_80085978);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_370", func_80085C68);

void func_80085D04(u8 **dataPtrPtr, Vec3f arg1, Mtx3f arg2)
{
    Vec3f vec;
    read_vec3f(dataPtrPtr, arg1);
    read_vec3f(dataPtrPtr, vec);
    mtx3f_axis_angle(vec, arg2);
}
