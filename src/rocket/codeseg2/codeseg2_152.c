#include <include_asm.h>
#include <ultra64.h>
#include <types.h>
#include <macros.h>

void func_800476A0(Gfx *arg0, Vtx * arg1, u32 arg2, u32 arg3)
{
    gSPVertex(arg0, arg1, arg2, arg3);
}

extern f32 D_8001B430;
extern f32 D_8001B434;
extern f32 D_8001B438;
extern f32 D_8001B448;
extern Vec3f D_800A5DC0;

extern Gfx *gDisplayListHead;

extern struct GfxContext gGfxContext;

struct test {
    f32 a;
    f32 b;
    f32 c;
};

// TODO float load
// void load_translation_mtx(f32 *translation)
// {
//     Mtx m;
//     f32 scale;
//     Mtx *m2;
//     VEC3F_COPY(D_800A5DC0, translation);
//     m2 = --gGfxContext.unkC;
//     scale = D_8001B434;
//     guTranslate(m2, translation[0] * D_8001B430, translation[1] * D_8001B430, translation[2] * D_8001B430);
//     guScale(&m, scale, scale, scale);
//     guMtxCatL(&m, m2, m2);
//     gSPMatrix(++gGfxContext.dlHead - 1, m2, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_PUSH);
// }

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_152", load_translation_mtx);

void pop_matrix()
{
    gSPPopMatrix(++gGfxContext.dlHead - 1, G_MTX_MODELVIEW);
}

struct unkfunc_800477D8_inner {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
};

struct unkfunc_800477D8 {
    s16 unk0[3];
    s16 unk6;
    s16 unk8;
    s16 unkA;
    struct unkfunc_800477D8_inner unkC;
};

// TODO float load, regalloc
// void func_800477D8(struct unkfunc_800477D8 *arg0, Vec3f arg1, struct unkfunc_800477D8_inner arg2)
// {
//     s32 i;
//     s16 *arr = &arg0->unk0[0];
//     for (i = 0; i < 3; i++)
//     {
//         arr[i] = (arg1[i] - D_800A5DC0[i]) * D_8001B438;
//     }

//     arg0->unkC = arg2;
// }

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_152", func_800477D8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_152", func_80047844);

// TODO regalloc
// void func_80047908(struct unkfunc_800477D8 *arg0, Vec3f arg1, struct unkfunc_800477D8_inner arg2, s32 arg3, s32 arg4)
// {
//     s32 i;
//     s16 *arr = &arg0->unk0[0];
//     for (i = 0; i < 3; i++)
//     {
//         arr[i] = (arg1[i] - D_800A5DC0[i]) * D_8001B448;
//     }

//     arg0->unkC = arg2;
//     arg0->unk8 = arg3;
//     arg0->unkA = arg4;
// }

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_152", func_80047908);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_152", func_8004797C);
