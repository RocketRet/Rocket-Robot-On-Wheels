#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_80088980 {
    u8 padding[0x16];
    s16 unk16;
};

extern u32 gTextScissorLeft;
extern u32 gTextScissorTop;
extern u32 gTextScissorRight;
extern u32 gTextScissorBottom;

void func_80088980(struct unkfunc_80088980 *arg0, s16 arg1)
{
    arg0->unk16 = arg1;
}

void func_80088988(s16 *arg0, s16 arg1, s16 arg2)
{
    arg0[0] = arg1;
    arg0[1] = arg2;
}

void set_text_scissor(s32 left, s32 right, s32 top, s32 bottom)
{
    gTextScissorLeft = left;
    gTextScissorTop = top;
    gTextScissorRight = right;
    gTextScissorBottom = bottom;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_378", func_800889B8);

extern u16 D_800ADAF8;

void func_80089D5C(Gfx **dlPtr)
{
    Gfx *head = *dlPtr;

    D_800ADAF8 = 0;
    gTextScissorLeft = 0;
    gTextScissorTop = 0;
    gTextScissorRight = 320;
    gTextScissorBottom = 240;
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

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_378", func_80089F18);


void func_8008AAEC(Gfx **dlHead)
{
    Gfx *newHead = *dlHead;
    gSPTexture(newHead++, 0x8000, 0x8000, 0, 0, G_OFF);
    gDPSetCombineMode(newHead++, G_CC_SHADE, G_CC_SHADE);
    if (D_800ADAF8 & 1)
    {
        gDPSetRenderMode(newHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    }
    if (D_800ADAF8 & 2)
    {
        gDPSetAlphaCompare(newHead++, G_AC_NONE);
    }
    gSPEndDisplayList(newHead++);
    *dlHead = newHead;
}

void func_8008ABA0(u16 *arg0, u16 arg1)
{
    arg0[10] &= ~arg1; // TODO probably a struct
}

void func_8008ABB4(u16 *arg0, u16 arg1)
{
    arg0[10] |= arg1; // TODO probably a struct
}

void func_8008ABC4(u16 *arg0, u16 arg1)
{
    arg0[10] &= ~4; // TODO probably a struct
}

void func_8008ABD4(u16 *arg0)
{
    arg0[10] |= 4; // TODO probably a struct
}

void func_8008ABE4(u8 *arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4)
{
    arg0[0x18] = arg1;
    arg0[0x19] = arg2;
    arg0[0x1A] = arg3;
    arg0[0x1B] = arg4;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_378", func_8008ABFC);
