#include <include_asm.h>
#include <ultra64.h>
#include <macros.h>
#include <types.h>

extern struct GfxContext gGfxContext;
extern struct GfxTask* gCurGfxTask;

extern void *gDepthBuffer;

void update_gfx_context()
{
    gGfxContext = gCurGfxTask->ctx;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_150", func_80046D58);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_150", func_80046FBC);

void clear_depth_buffer()
{
    gDPSetDepthImage(NEXT_GFX(gGfxContext.dlHead), OS_K0_TO_PHYSICAL(gDepthBuffer));
    gDPPipeSync(NEXT_GFX(gGfxContext.dlHead));
    gDPSetRenderMode(NEXT_GFX(gGfxContext.dlHead), G_RM_NOOP, G_RM_NOOP2);
    gDPSetCycleType(NEXT_GFX(gGfxContext.dlHead), G_CYC_FILL);
    gDPSetColorImage(NEXT_GFX(gGfxContext.dlHead), G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, OS_K0_TO_PHYSICAL(gDepthBuffer));
    gDPSetFillColor(NEXT_GFX(gGfxContext.dlHead), GPACK_ZDZ(G_MAXFBZ, 0) << 16 | GPACK_ZDZ(G_MAXFBZ, 0));
    gDPFillRectangle(NEXT_GFX(gGfxContext.dlHead), 18, 14, 301, 225);
    gDPPipeSync(NEXT_GFX(gGfxContext.dlHead));
    gDPSetColorImage(NEXT_GFX(gGfxContext.dlHead), G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, OS_K0_TO_PHYSICAL(gCurGfxTask->framebuffer));
    gDPSetCombineKey(NEXT_GFX(gGfxContext.dlHead), G_CK_NONE);
    gDPSetAlphaCompare(NEXT_GFX(gGfxContext.dlHead), G_AC_THRESHOLD);
    gDPSetTextureDetail(NEXT_GFX(gGfxContext.dlHead), G_TD_CLAMP);
    gDPSetTexturePersp(NEXT_GFX(gGfxContext.dlHead), G_TP_PERSP);
    gDPSetTextureConvert(NEXT_GFX(gGfxContext.dlHead), G_TC_FILT);
    gDPPipelineMode(NEXT_GFX(gGfxContext.dlHead), G_PM_NPRIMITIVE);
}
