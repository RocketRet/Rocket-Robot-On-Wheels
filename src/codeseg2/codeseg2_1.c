#include <include_asm.h>
#include <ultra64.h>
#include <types.h>
#include <macros.h>

struct unkfunc_8001DE50_sub {
    f32 unk0[9];
};

struct unkfunc_8001DE50_arg0 {
    s32 unk0;
    struct unkfunc_8001DE50_arg1 *unk4;
    Vec3f unk8;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    Mtx3f unk20;
    // f32 unk20[2][4];
    // s32 unk40;
    s32 unk44;
    s32 unk48;
    s32 unk4C;
    s32 unk50;
};

struct unkfunc_8001DE50_arg1 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    Mtx3f unk18;
    // f32 unk18[2][4];
    // s32 unk38;
    Vec3f unk3C;
};

void func_80056BD0(void*);

// TODO regalloc
// void func_8001DE50(struct unkfunc_8001DE50_arg0 *arg0, struct unkfunc_8001DE50_arg1 *arg1)
// {
//     struct unkfunc_8001DE50_arg0 *t0 = arg0;
//     t0->unk4 = arg1;
//     VEC3F_COPY(t0->unk8, arg1->unk3C);
//     MTX3F_COPY(t0->unk20, arg1->unk18);
//     func_80056BD0(&t0->unk50);
// }

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_1", func_8001DE50);
