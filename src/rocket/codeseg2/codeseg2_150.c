#include <ultra64.h>
#include "include_asm.h"
#include "macros.h"
#include "types.h"
#include "gfx.h"
#include "codeseg2.h"

extern Vp D_800A5CB0;
extern struct RenderParams D_800A5DB8; // 0x04 bytes
extern struct GfxContext gGfxContext;
extern struct GfxTask* gCurGfxTask;

extern void *gDepthBuffer;

void update_gfx_context()
{
    gGfxContext = gCurGfxTask->ctx;
}

void func_80046D58(void) {
    struct RenderParams sp0;
    s32 segmentIndex;
    Gfx *dlStart;

    D_800A5DB8 = sp0 = unk_make_RenderParams(0, 0, 0, 0);
    dlStart = gGfxContext.dlHead;
    gCurGfxTask->dlStart = dlStart;
    gSPSegment(NEXT_GFX(gGfxContext.dlHead), 0x00, 0x00000000);
    segmentIndex = 1;
    while (1) {
        if (!(segmentIndex < 2)) {
            break;
        }
        if (D_800AAF78[segmentIndex] != 0) {
            gSPSegment(NEXT_GFX(gGfxContext.dlHead), segmentIndex, OS_K0_TO_PHYSICAL(D_800AAF78[segmentIndex]));
        }
        segmentIndex++;
    }
    gSPViewport(NEXT_GFX(gGfxContext.dlHead), &D_800A5CB0);
    gSPClearGeometryMode(NEXT_GFX(gGfxContext.dlHead), G_ZBUFFER | G_SHADE | G_CULL_FRONT | G_CULL_BACK | G_FOG | G_SHADING_SMOOTH);
    gSPSetGeometryMode(NEXT_GFX(gGfxContext.dlHead), G_ZBUFFER);
    gSPTexture(NEXT_GFX(gGfxContext.dlHead), 0x0000, 0x0000, 0, G_TX_RENDERTILE, G_OFF);
    gDPSetColorDither(NEXT_GFX(gGfxContext.dlHead), G_CD_BAYER);
    gDPSetAlphaDither(NEXT_GFX(gGfxContext.dlHead), G_AD_DISABLE);
    gDPSetColorImage(NEXT_GFX(gGfxContext.dlHead), G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, OS_K0_TO_PHYSICAL(gCurGfxTask->framebuffer));
}

void draw_rectangle(s32 red, s32 green, s32 blue, s32 alpha, s32 xl, s32 yl, s32 xh, s32 yh) {
    if (alpha == 0xFF) {
        gDPPipeSync(NEXT_GFX(gGfxContext.dlHead));
        gDPSetRenderMode(NEXT_GFX(gGfxContext.dlHead), G_RM_NOOP, G_RM_NOOP2);
        gDPSetCycleType(NEXT_GFX(gGfxContext.dlHead), G_CYC_FILL);
        gDPSetFillColor(NEXT_GFX(gGfxContext.dlHead), GPACK_RGBA5551(red, green, blue, 1) << 16 | GPACK_RGBA5551(red, green, blue, 1));
        gDPFillRectangle(NEXT_GFX(gGfxContext.dlHead), xl, yl, xh, yh);
    } else {
        gDPPipeSync(NEXT_GFX(gGfxContext.dlHead));
        gDPSetRenderMode(NEXT_GFX(gGfxContext.dlHead), G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCycleType(NEXT_GFX(gGfxContext.dlHead), G_CYC_1CYCLE);
        gDPSetPrimColor(NEXT_GFX(gGfxContext.dlHead), 0, 0, red, green, blue, alpha);
        gDPSetCombineMode(NEXT_GFX(gGfxContext.dlHead), G_CC_PRIMITIVE, G_CC_PRIMITIVE);
        gSPTextureRectangle(NEXT_GFX(gGfxContext.dlHead), xl << 2, yl << 2, (xh + 1) << 2, (yh + 1) << 2, 0, 0, 0, 0, 0);
    }
}

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
