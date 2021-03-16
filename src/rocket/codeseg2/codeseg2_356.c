#include <include_asm.h>
#include <ultra64.h>
#include <types.h>

struct unkfunc_800841C4 {
    u8 padding[0x170];
    s32 unk170;
    u8 padding2[0x22C - 0x170 - 0x04];
    s32 unk22C;
};

void func_80084030(struct unkfunc_800841C4 *arg0, s32 arg1)
{
    arg0->unk170 = arg1;
    arg0->unk22C |= 0x00800000;
}

void func_80084048(struct unkfunc_800841C4 *arg0)
{
    arg0->unk22C |= 0x00080000;
}

void func_8008405C(s32 arg0, f32 arg1)
{
    Vec3f vec;
    vec[2] = arg1;
    vec[1] = arg1;
    vec[0] = 0;
    func_8008408C(arg0, vec);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_356", func_8008408C);
