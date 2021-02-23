#include <include_asm.h>
#include <ultra64.h>
#include <types.h>


INCLUDE_ASM(s32, "codeseg2/codeseg2_381", func_8008AEA0);

INCLUDE_ASM(s32, "codeseg2/codeseg2_381", func_8008B24C);

INCLUDE_ASM(s32, "codeseg2/codeseg2_381", func_8008B3DC);

INCLUDE_ASM(s32, "codeseg2/codeseg2_381", func_8008B4BC);

INCLUDE_ASM(s32, "codeseg2/codeseg2_381", func_8008B594);

INCLUDE_ASM(s32, "codeseg2/codeseg2_381", func_8008B694);

INCLUDE_ASM(s32, "codeseg2/codeseg2_381", func_8008BCE8);

INCLUDE_ASM(s32, "codeseg2/codeseg2_381", func_8008BD58);

struct unkfunc_8008BE58 {
    u8 padding[0x3C];
    Vec3f unk3C;
};

void set_vec3f_components(Vec3f *, f32, f32, f32);

void func_8008BE58(struct unkfunc_8008BE58 *arg0, f32 arg1)
{
    set_vec3f_components(arg0->unk3C, 0, 0, arg1);
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_381", func_8008BE8C);
