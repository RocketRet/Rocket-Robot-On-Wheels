#include <include_asm.h>
#include <ultra64.h>
#include <types.h>

struct unkfunc_800841C4 {
    u8 padding[0x22C];
    s32 unk22C;
};

INCLUDE_ASM(s32, "codeseg2/codeseg2_358", func_80084140);

void func_800841C4(struct unkfunc_800841C4 *arg0)
{
    arg0->unk22C |= 0x00040000;
}

void func_800841D8(s32 arg0, f32 arg1)
{
    Vec3f vec;
    vec[2] = arg1;
    vec[1] = arg1;
    vec[0] = 0;
    func_80084208(arg0, vec);
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_358", func_80084208);

void func_8008428C(s32 arg0, f32 arg1)
{
    Vec3f vec;
    vec[2] = arg1;
    vec[1] = arg1;
    vec[0] = 0;
    func_800842BC(arg0, vec);
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_358", func_800842BC);
