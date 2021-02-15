#include <include_asm.h>
#include <ultra64.h>
#include <macros.h>
#include <types.h>

extern struct GfxContext D_800A5DA8;
extern struct GfxTask* D_800A5DBC;

extern void *D_800AAF68;

void func_80046D20()
{
    D_800A5DA8 = D_800A5DBC->ctx;
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_150", func_80046D58);

INCLUDE_ASM(s32, "codeseg2/codeseg2_150", func_80046FBC);

// TODO regalloc
// void func_8004721C()
// {
//     gDPSetDepthImage(D_800A5DA8.dlHead++, OS_K0_TO_PHYSICAL(D_800AAF68));
//     gDPPipeSync(D_800A5DA8.dlHead++);
//     gDPSetRenderMode(D_800A5DA8.dlHead++, G_RM_NOOP, G_RM_NOOP2);
//     gDPSetCycleType(D_800A5DA8.dlHead++, G_CYC_FILL);
//     gDPSetColorImage(D_800A5DA8.dlHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, OS_K0_TO_PHYSICAL(D_800AAF68));
//     gDPSetFillColor(D_800A5DA8.dlHead++, GPACK_ZDZ(G_MAXFBZ, 0) << 16 | GPACK_ZDZ(G_MAXFBZ, 0));
//     gDPFillRectangle(D_800A5DA8.dlHead++, 18, 14, 301, 225);
//     gDPPipeSync(D_800A5DA8.dlHead++);
//     gDPSetColorImage(D_800A5DA8.dlHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, OS_K0_TO_PHYSICAL(D_800A5DBC->framebuffer));
//     gDPSetCombineKey(D_800A5DA8.dlHead++, G_CK_NONE);
//     gDPSetAlphaCompare(D_800A5DA8.dlHead++, G_AC_THRESHOLD);
//     gDPSetTexturePersp(D_800A5DA8.dlHead++, G_TP_PERSP);
//     gDPSetTextureDetail(D_800A5DA8.dlHead++, G_TD_CLAMP);
//     gDPSetTextureConvert(D_800A5DA8.dlHead++, G_TC_FILT);
//     gDPPipelineMode(D_800A5DA8.dlHead++, G_PM_1PRIMITIVE);
// }

INCLUDE_ASM(s32, "codeseg2/codeseg2_150", func_8004721C);
