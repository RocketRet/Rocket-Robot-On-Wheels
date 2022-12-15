#include <include_asm.h>
#include <ultra64.h>
#include "types.h"
#include "codeseg2.h"

void func_80047B60(struct RenderParams arg0, u32* newCycleType, u32* newRenderMode1, u32* newRenderMode2) {
    *newCycleType = arg0.cycleType == 1 ? G_CYC_1CYCLE : G_CYC_2CYCLE;
    switch (arg0.renderMode) {
    case 1:
        *newRenderMode1 = G_RM_AA_ZB_OPA_SURF;
        *newRenderMode2 = G_RM_AA_ZB_OPA_SURF2;
        break;
    case 2:
        *newRenderMode1 = G_RM_AA_ZB_OPA_SURF;
        *newRenderMode2 = G_RM_AA_ZB_OPA_SURF2;
        break;
    case 3:
        *newRenderMode1 = G_RM_AA_ZB_TEX_EDGE;
        *newRenderMode2 = G_RM_AA_ZB_TEX_EDGE2;
        break;
    case 4:
    case 6:
        *newRenderMode1 = G_RM_AA_ZB_XLU_SURF;
        *newRenderMode2 = G_RM_AA_ZB_XLU_SURF2;
        break;
    case 5:
    case 7:
        *newRenderMode1 = G_RM_AA_ZB_XLU_DECAL;
        *newRenderMode2 = G_RM_AA_ZB_XLU_DECAL2;
        break;
    }
    if (arg0.cycleType == 2) {
        *newRenderMode1 = G_RM_PASS;
    }
}

