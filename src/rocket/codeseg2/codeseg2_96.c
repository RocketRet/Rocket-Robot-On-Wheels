#include <ultra64.h>
#include "include_asm.h"
#include "types.h"
#include "mem.h"
#include "gfx.h"
#include "mathutils.h"
#include "macros.h"

extern struct GfxContext gGfxContext;
extern struct GfxTask* gCurGfxTask;
extern Vec3f D_800A53A0;

struct unkfunc_8003B144 {
    u8 pad[0xC];
    Mtx3f unkC;
};

struct unkfunc_8003ACD4 {
    u8 pad0[0xC];
    Mtx3f unkC;
    Mtx4f unk30;
    u8 pad70[0xA0 - 0x70];
    f32 unkA0;
    f32 unkA4;
    f32 unkA8;
    f32 unkAC;
};

void mtxf_to_mtx(Mtx4f mf, Mtx *m);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_80039490);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_80039590);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_800398E0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_80039A40);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_80039C34);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_80039D98);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_80039E28);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_80039F80);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_8003A468);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_8003AA04);

void func_8003ACD4(struct unkfunc_8003ACD4* arg0) {
    u16 perspNorm;

    // Set up the perspective matrix
    guPerspective(&gCurGfxTask->perspectiveMtx, &perspNorm, arg0->unkA0 * (180.0f / (float)M_PI), arg0->unkA4, arg0->unkA8 * 16.0f, arg0->unkAC * 16.0f, 1.0f);
    gSPPerspNormalize(NEXT_GFX(gGfxContext.dlHead), perspNorm);
    mtxf_to_mtx(arg0->unk30, &gCurGfxTask->viewMtx);
    // Set up the viewing matrix
    gSPMatrix(NEXT_GFX(gGfxContext.dlHead), &gCurGfxTask->perspectiveMtx, G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPMatrix(NEXT_GFX(gGfxContext.dlHead), &gCurGfxTask->viewMtx, G_MTX_PROJECTION | G_MTX_MUL | G_MTX_NOPUSH);
    // Set up an identity model matrix to start with
    guMtxIdent(&gCurGfxTask->identityModelMtx);
    gSPMatrix(NEXT_GFX(gGfxContext.dlHead), &gCurGfxTask->identityModelMtx, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_8003ADFC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_8003AF94);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_8003B068);

void func_8003B144(struct unkfunc_8003ACD4 *arg0) {
    f32 lightDir[3];
    s32 i;
    Lights1* lights;

    if (D_800AAF78[1] != 0) {
        vec3f_rotate(arg0->unkC, D_800A53A0, lightDir);
        vec3f_normalize(lightDir);
        lights = (Lights1*)SEGMENTED_TO_VIRTUAL(D_8009F094.unk0->light);

        for (i = 0; i < 3; i++) {
            lights->a.l.col[i] = lights->a.l.colc[i] = D_800A5398.asArray[i];
            lights->l[0].l.col[i] = lights->l[0].l.colc[i] = D_800A539C.asArray[i];
            lights->l[0].l.dir[i] = (s32) (lightDir[i] * 127.0f);
        }

        gSPSetLights1(NEXT_GFX(gGfxContext.dlHead), (*D_8009F094.unk0->light));
    }
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_8003B298);

void func_8003B358(struct unkfunc_8003ACD4 *arg0)
{
    func_8003ACD4(arg0);
    func_8003B144(arg0);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_8003B388);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_8003B544);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_8003B674);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_8003B6BC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_8003B7D0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_8003B89C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_8003BA40);

f32 func_8009990C(f32, f32);
f32 func_80098900(f32);

void func_8003C364(f32 *arg0, struct ControllerData *arg1, f32 *arg2)
{
    f32 f20 = func_8009990C(-arg1->x, arg1->y);
    f32 f0 = func_8009990C(arg0[4], arg0[3]);
    *arg2 = func_80098900(f20 + f0);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_8003C3C8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_8003C434);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_8003C584);

#ifdef NONMATCHING
struct unkfrustum_test_24 {
    u8 pad0[0x4C];
    Vec3f unk4C[4];
};

struct unkfrustum_test {
    Vec3f eyePos;
    Vec3f unkC;
    u8 pad18[0x24 - 0x18];
    struct unkfrustum_test_24 unk24;
};

// https://decomp.me/scratch/QdhPo
s32 frustum_test(struct unkfrustum_test* arg0, Vec3f position, f32 cullRadius, f32 renderDistance, f32* arg4, f32* alphaOut) {
    Vec3f cameraOffset;
    s32 var_a1;
    f32 cameraDistanceSq;
    f32 renderDistanceSq;
    Vec3f *v0;

    VEC3F_SUB(cameraOffset, position, arg0->eyePos);
    // If the render distance isn't infinity, calculate the distance from the camera to the object
    if (renderDistance != FLT_MAX) {
        cameraDistanceSq = VEC3F_MAG_SQUARED(cameraOffset);
        renderDistanceSq = SQUARED(renderDistance);
        // Check if the object is further than the render distance
        if (renderDistanceSq < VEC3F_MAG_SQUARED(cameraOffset)) {
            return 1;
        }
    }
    // Test the object against the four side planes of the view frustum
    for (var_a1 = 3; var_a1 >= 0; var_a1--) {
        // Check if the object is fully behind the current frustum plane given, accounting for culling radius
        if (cullRadius < VEC3F_DOT(cameraOffset, arg0->unk24.unk4C[var_a1])) {
            return 2;
        }
    }
    v0 = &arg0->unkC;
    *arg4 = VEC3F_DOT(cameraOffset, *v0);
    
    // Check if the object is within 10 units of the max render distance
    if ((renderDistance != FLT_MAX) && SQUARED(renderDistance - 10.0f) < cameraDistanceSq) {
        // If it is, calculate the alpha of the object based on how far it is from the max render distance
        *alphaOut = 1.0f - (cameraDistanceSq - SQUARED(renderDistance - 10.0f)) / (renderDistanceSq - SQUARED(renderDistance - 10.0f));
    } else {
        // Otherwise, make it fully opaque
        *alphaOut = 1.0f;
    }
    return 0;
}
#else
INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", frustum_test);
#endif

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_8003C8EC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_8003C9A4);

struct unkfunc_8003CA8C {
    u8 padding[0xD8];
    s32 unkD8;
    s32 unkDC;
    f32 unkE0;
};

void func_8003CA8C(struct unkfunc_8003CA8C *arg0, f32 *arg1)
{
    arg0->unkD8 = 1;
    if (arg1)
    {
        arg0->unkDC = 1;
        arg0->unkE0 = *arg1;
    }
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_8003CAAC);
