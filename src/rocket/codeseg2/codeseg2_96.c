#include <ultra64.h>
#include "include_asm.h"
#include "types.h"
#include "mem.h"
#include "gfx.h"
#include "mathutils.h"

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_80039490);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_80039590);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_800398E0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_80039A40);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_80039C34);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_80039D98);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_80039E28);

extern struct GfxContext gGfxContext;

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_80039F80);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_8003A468);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_8003AA04);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_8003ACD4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_8003ADFC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_8003AF94);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_8003B068);

extern Vec3f D_800A53A0;

struct unkfunc_8003B144 {
    u8 pad[0xC];
    Mtx3f unkC;
};

void func_8003B144(struct unkfunc_8003B144 *arg0) {
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


// INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_8003B144, s32);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_8003B298);

void func_8003B358(struct unkfunc_8003B144 *arg0)
{
    func_8003ACD4();
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

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_96", func_8003C764);

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
