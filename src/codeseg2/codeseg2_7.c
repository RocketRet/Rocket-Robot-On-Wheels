#include <include_asm.h>
#include <ultra64.h>
#include <types.h>

struct unkfunc_8001FA50 {
    struct unkfunc_8001FA50_2 *unk0;
    u8 padding[0x14];
    Mtx3f unk18;
};

struct unkfunc_8001FA50_2 {
    u8 padding[0x5C];
    void (*unk5C)(struct unkfunc_8001FA50 *, Mtx3f);
};

void func_800570D0(Vec3f, Mtx3f);
void mtx3f_concat(Mtx3f, Mtx3f, Mtx3f);

// void func_8001FA50(struct unkfunc_8001FA50 *arg0, f32 arg1, f32 arg2, f32 arg3)
// {
//     Vec3f vec;
//     Mtx3f a, b;
//     vec[0] = arg1;
//     vec[1] = arg2;
//     vec[2] = arg3;
//     func_800570D0(vec, a);
//     mtx3f_concat(a, arg0->unk18, b);
//     arg0->unk0->unk5C(arg0, b);
// }

INCLUDE_ASM(s32, "codeseg2/codeseg2_7", func_8001FA50);
