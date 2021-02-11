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
extern f32 D_800A5DC0[3];

extern Gfx *gDisplayListHead;

extern struct GfxContext D_800A5DA8;

// TODO different compiler
// TODO regalloc
// void load_translation_mtx(f32 *translation)
// {
//     Mtx m;
//     f32 scale;
//     Mtx *m2;
//     VEC3F_COPY(D_800A5DC0, translation);
//     m2 = --D_800A5DA8.unkC;
//     scale = D_8001B434;
//     guTranslate(m2, translation[0] * D_8001B430, translation[1] * D_8001B430, translation[2] * D_8001B430);
//     guScale(&m, scale, scale, scale);
//     guMtxCatL(&m, m2, m2);
//     gSPMatrix(D_800A5DA8.dlHead++, m2, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_PUSH);
// }

INCLUDE_ASM(s32, "codeseg2/codeseg2_152", load_translation_mtx);

// TODO different compiler
// TODO regalloc
// void pop_matrix()
// {
//     gSPPopMatrix(D_800A5DA8.dlHead++, 1);
// }

INCLUDE_ASM(s32, "codeseg2/codeseg2_152", pop_matrix);

INCLUDE_ASM(s32, "codeseg2/codeseg2_152", func_800477D8);

INCLUDE_ASM(s32, "codeseg2/codeseg2_152", func_80047844);

INCLUDE_ASM(s32, "codeseg2/codeseg2_152", func_80047908);

INCLUDE_ASM(s32, "codeseg2/codeseg2_152", func_8004797C);
