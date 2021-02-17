#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_80088980 {
    u8 padding[0x16];
    s16 unk16;
};

void func_80088980(struct unkfunc_80088980 *arg0, s16 arg1)
{
    arg0->unk16 = arg1;
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_378", func_80088988);

INCLUDE_ASM(s32, "codeseg2/codeseg2_378", func_80088994);

INCLUDE_ASM(s32, "codeseg2/codeseg2_378", func_800889B8);

extern u16 D_800ADAF8;
extern u32 D_800E5088;
extern u32 D_800E508C;
extern u32 gScreenWidth;
extern u32 gScreenHeight;

void func_80089D5C(Gfx **dlPtr)
{
    Gfx *head = *dlPtr;

    D_800ADAF8 = 0;
    D_800E5088 = 0;
    D_800E508C = 0;
    gScreenWidth = 320;
    gScreenHeight = 240;
    gDPPipeSync(head++);
    gDPSetCycleType(head++, G_CYC_1CYCLE);
    gSPTexture(head++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gDPSetAlphaCompare(head++, G_AC_NONE);
    gDPSetTexturePersp(head++, G_TP_NONE);
    gDPSetTextureFilter(head++, G_TF_BILERP);
    gDPSetTextureConvert(head++, G_TC_FILT);
    gDPSetTextureDetail(head++, G_TD_CLAMP);
    gDPSetTextureLOD(head++, G_TL_TILE);
    gDPSetTextureLUT(head++, G_TT_NONE);
    gDPSetRenderMode(head++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2)
    *dlPtr = head;
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_378", func_80089F18);

INCLUDE_ASM(s32, "codeseg2/codeseg2_378", func_8008AAEC);
