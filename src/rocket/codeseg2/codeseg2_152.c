#include <include_asm.h>
#include <ultra64.h>
#include <types.h>
#include <macros.h>

void func_800476A0(Gfx *arg0, Vtx * arg1, u32 arg2, u32 arg3)
{
    gSPVertex(arg0, arg1, arg2, arg3);
}

// extern f32 D_8001B430;
// extern f32 D_8001B434;
// extern f32 D_8001B438;
// extern f32 D_8001B448;
extern Vec3f D_800A5DC0;

extern struct GfxContext gGfxContext;

struct test {
    f32 a;
    f32 b;
    f32 c;
};

void load_translation_mtx(f32 *translation)
{
    Mtx temp;
    Mtx *newMtx;
    float scale = 16.0f;
    float inverseScale = 1 / scale;
    VEC3F_COPY(D_800A5DC0, translation);
    newMtx = --gGfxContext.unkC;
    guTranslate(newMtx, translation[0] * scale, translation[1] * scale, translation[2] * scale);
    guScale(&temp, inverseScale, inverseScale, inverseScale);
    guMtxCatL(&temp, newMtx, newMtx);
    gSPMatrix(++gGfxContext.dlHead - 1, newMtx, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_PUSH);
}

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

void func_800477D8(struct unkfunc_800477D8 *arg0, Vec3f arg1, struct unkfunc_800477D8_inner arg2)
{
    s32 i;
    for (i = 0; i < 3; i++)
    {
        arg0->unk0[i] = (arg1[i] - D_800A5DC0[i]) * 256.0f;
    }

    arg0->unkC = arg2;
}

const f32 D_8001B43C = 256.0f;
const f32 D_8001B440 = 127.0f;
const f32 D_8001B444 = 2147483648.0f;

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_152", func_80047844);

void func_80047908(struct unkfunc_800477D8 *arg0, Vec3f arg1, struct unkfunc_800477D8_inner arg2, s32 arg3, s32 arg4)
{
    s32 i;
    for (i = 0; i < 3; i++)
    {
        arg0->unk0[i] = (arg1[i] - D_800A5DC0[i]) * 256.0f;
    }

    arg0->unkC = arg2;
    arg0->unk8 = arg3;
    arg0->unkA = arg4;
}

const f32 D_8001B44C = 1.0f;
const f32 D_8001B450 = 2147483648.0f;
const f32 D_8001B454 = 1.0f;
const f32 D_8001B458 = 2147483648.0f;
const f32 D_8001B45C = 1.0f;
const f32 D_8001B460 = 2147483648.0f;
const f32 D_8001B464 = 1.0f;
const f32 D_8001B468 = 2147483648.0f;

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_152", func_8004797C);
