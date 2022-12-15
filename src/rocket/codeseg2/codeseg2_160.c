#include <include_asm.h>
#include <ultra64.h>
#include "types.h"
#include "codeseg2.h"
#include "mathutils.h"
#include "gfx.h"
#include "mem.h"

void custom_memcpy(void *, void *, s32);

struct unkfunc_8004A4F0 {
    u8 pad0[0x10];
    f32 unk10;
    u8 pad14[0xA0 - 0x14];
    s32 unkA0;
    Vec3f* unkA4;
    Gfx* unkA8;
    void* unkAC;
    s32 unkB0;
    s32 unkB4;
    Mtx3f unkB8;
    s32 unkDC;
    s32 unkE0;
    u8 unkE4;
    u8 unkE5;
    u8 unkE6;
    s32 padE8;
    u8 padEC[0x100 - 0xEC];
    s32 unk100;
};

struct unkfunc_8004A4F0_arg1 {
    u8 pad0[0xC];
    Vec3f unkC;
};

struct func_8004A4F0_temp_s0_2 {
    s16 unk0[3];
    u8 pad6[0x10 - 0x6];
};

void func_800577E8(Vec3f, Mtx3f, f32, Mtx*);
f32 func_8009911C(f32);

void func_8004A4F0(struct unkfunc_8004A4F0* arg0, struct unkfunc_8004A4F0_arg1* arg1, Vec3f arg2, Mtx3f arg3) {
    Vec3f sp10;
    Vec3f sp20;
    f32 sin1;
    f32 cos1;
    f32 sin2;
    f32 cos2;
    Mtx* baseMatrix;
    Mtx* scaleMatrix;
    f32 angle1;
    f32 angle2;
    f32 temp_f20_2;
    f32 temp_f24_2;
    f32 var_f22;
    s32 var_s2;
    s32 var_a0;
    s32 var_a2;
    struct func_8004A4F0_temp_s0_2* temp_s0_2;
    struct func_8004A4F0_temp_s0_2* var_s1;
    Lights1* temp_s0;
    Vec3f* temp_s0_3;

    temp_s0 = (Lights1*)SEGMENTED_TO_VIRTUAL(arg0->unkB4);
    bzero(temp_s0, sizeof(Lights1));
    temp_s0->a.l.col[0] = (u32)(arg0->unkE4 * 0.25f);
    temp_s0->a.l.col[1] = (u32)(arg0->unkE5 * 0.25f);
    temp_s0->a.l.col[2] = (u32)(arg0->unkE6 * 0.25f);
    memcpy(&temp_s0->a.l.colc[0], &temp_s0->a.l.col[0], 4);
    temp_s0->l[0].l.col[0] = (u32)(arg0->unkE4 * 0.75f);
    temp_s0->l[0].l.col[1] = (u32)(arg0->unkE5 * 0.75f);
    temp_s0->l[0].l.col[2] = (u32)(arg0->unkE6 * 0.75f);
    //! BUG: The copy of directional light is taken from the ambient light color instead of the primary directional light color
    memcpy(&temp_s0->l[0].l.colc[0], &temp_s0->a.l.col[0], 4);
    for (var_a0 = 0; var_a0 < 3; var_a0++) {
        temp_s0->l[0].l.dir[var_a0] = (u8) (arg1->unkC[var_a0] * -127.0f);
    }
    if (arg0->unkE0 < 2) {
        temp_s0_2 = (struct func_8004A4F0_temp_s0_2*)SEGMENTED_TO_VIRTUAL(arg0->unkB0);
        if (arg0->unkDC < 2) {
            custom_memcpy(temp_s0_2, arg0->unkAC, arg0->unkA0 * sizeof(struct func_8004A4F0_temp_s0_2));
            arg0->unkDC++;
        }
        if (arg0->unk100 == 0) {
            var_f22 = (D_8009FE10.unk4 - arg0->unk10) / 0.4f;
        } else {
            var_f22 = 1.0f;
        }
        if (var_f22 >= 1.0f) {
            var_f22 = 1.0f;
            arg0->unkE0++;
        }
        var_s2 = 0;
        while (1) {
            if (!(var_s2 < arg0->unkA0)) {
                break;
            }
            var_s1 = &temp_s0_2[var_s2];
            temp_s0_3 = &arg0->unkA4[var_s2];
            angle1 = (*temp_s0_3)[1];
            angle2 = (*temp_s0_3)[2] * var_f22;
            sincosf(angle1, &sin1, &cos1);
            sincosf(angle2, &sin2, &cos2);
            set_vec3f_components(sp10, cos2 * (*temp_s0_3)[0], sin2 * cos1 * (*temp_s0_3)[0], sin2 * sin1 * (*temp_s0_3)[0]);
            vec3f_transpose_rotate(arg0->unkB8, sp10, sp20);
            for (var_a2 = 0; var_a2 < 3; var_a2++) {
                var_s1->unk0[var_a2] = sp20[var_a2] * 256.0f;
            }
            var_s2 += 1;
        }
    }
    baseMatrix = gGfxContext.unkC - 2;
    scaleMatrix = gGfxContext.unkC - 1;
    gGfxContext.unkC = baseMatrix;
    func_800577E8(arg2, arg3, 0.0625f, baseMatrix);
    gSPMatrix(NEXT_GFX(gGfxContext.dlHead), baseMatrix, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    if (arg0->unk100 == 0) {
        temp_f24_2 = (func_8009911C((D_8009FE10.unk4 * 6.0f) + 0.0f) * 0.05f) + 1.0f;
        temp_f20_2 = (func_8009911C((D_8009FE10.unk4 * 7.23f) + 2.0f) * 0.05f) + 1.0f;
        guScale(scaleMatrix, temp_f24_2, temp_f20_2, (func_8009911C((D_8009FE10.unk4 * 5.27f) + 4.0f) * 0.05f) + 1.0f);
        gSPMatrix(NEXT_GFX(gGfxContext.dlHead), scaleMatrix, G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
    }
    unk_assign_RenderParams(2, 2, 1, 1);
    gSPDisplayList(NEXT_GFX(gGfxContext.dlHead), arg0->unkA8);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_160", func_8004AC3C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_160", func_8004B420);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_160", func_8004B8BC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_160", func_8004BB64);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_160", func_8004BBD0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_160", func_8004C268);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_160", func_8004C2A8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_160", func_8004C44C);
