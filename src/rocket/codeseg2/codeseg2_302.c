#include <include_asm.h>
#include <ultra64.h>
#include "types.h"
#include "gfx.h"
#include "mem.h"


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_302", func_80075100);

extern struct GfxContext gGfxContext; // 0x10 bytes

#define MACRO_FUNC_800751D8(x) (((x) + 0xF < 0) ? (x) + 0x1E : (x) + 0xF)

int func_80046268();
int func_80046354();
int func_8004632C();
int func_80046318();
int func_800463B4();
int func_800462E4();

void func_800751D8(s32 **arg0, s32 arg1)
{
    struct GfxContext *s1;
    Gfx **s2;
    s32 var4;
    push_second_heap_state();
    s1 = &gGfxContext;
    s2 = &gGfxContext.dlHead;
    func_80046268(s2);
    func_80046354(0xFF, 0x80, 0, 0xFF);
    func_8004632C(arg0[4], arg0[5]);
    var4 = MACRO_FUNC_800751D8(arg0[1][3]);
    func_80046318(arg0[1][2], var4 >> 4);
    func_800463B4(s1, arg1, 0, 0, 0);
    func_800462E4(s2);
    pop_second_heap_state();
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_302", func_8007529C);

struct unkfunc_80075348 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

void func_80075348(struct unkfunc_80075348 *arg0, s32 arg1)
{
    s32 s0 = arg1;
    struct unkfunc_80075348 *s1 = arg0;
    bzero(s1, s0 * sizeof(struct unkfunc_80075348));
    for (s0--; s0 >= 0; s1++, s0--)
    {
        s1->unk0 = -1;
        s1->unk4 = 0;
        s1->unk8 = 0;
        s1->unkC = 1;
    }
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_302", func_800753B4);

void func_800923E8(struct GfxContext*, struct TexturedMaterial*, s32, s32, s32, s32, s32);

// Draws a textured material as a rect
void func_80075458(struct TexturedMaterial* material, s32 alpha, s32 textureIndex, s32 minX, s32 maxX, s32 minY, s32 maxY) {
    s32 totalRows;
    s32 remainingRows;
    s32 maxTmemBytes;
    s32 rowsDrawn;
    s32 curRowCount;
    s32 rowsPerTile;
    s32 offsetX, offsetY;
    s32 fmt, texHeight;
    struct Texture* cur_texture;
    s32 boundsMinX, boundsMaxX, boundsMinY, boundsMaxY;

    offsetX = 0;
    offsetY = 0;
    boundsMinX = MARGIN_X;
    boundsMinY = MARGIN_Y;
    boundsMaxX = SCREEN_WIDTH - MARGIN_X;
    boundsMaxY = SCREEN_HEIGHT - MARGIN_Y;
    if (minX < boundsMinX) {
        offsetX = boundsMinX - minX;
        minX = boundsMinX;
    }
    if (maxX > boundsMaxX) {
        offsetX = 0;
        maxX = boundsMaxX;
    }
    if (minY < boundsMinY) {
        minY = boundsMinY;
    }
    if (maxY > boundsMaxY) {
        offsetY = (maxY - boundsMaxY) & ~1;
        maxY = boundsMaxY;
    }
    if ((minX < maxX) && (minY < maxY)) {
        gDPPipeSync(NEXT_GFX(gGfxContext.dlHead));
        gDPSetCycleType(NEXT_GFX(gGfxContext.dlHead), G_CYC_1CYCLE);
        gDPSetRenderMode(NEXT_GFX(gGfxContext.dlHead), G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetEnvColor(NEXT_GFX(gGfxContext.dlHead), material->header.envColorR, material->header.envColorG, material->header.envColorB, alpha);
        gDPSetCombineLERP(NEXT_GFX(gGfxContext.dlHead),
            TEXEL0, 0, ENVIRONMENT, 0,  TEXEL0, 0, ENVIRONMENT, 0,
            TEXEL0, 0, ENVIRONMENT, 0,  TEXEL0, 0, ENVIRONMENT, 0);
        gDPSetTexturePersp(NEXT_GFX(gGfxContext.dlHead), G_TP_NONE);
        gDPSetTextureFilter(NEXT_GFX(gGfxContext.dlHead), G_TF_POINT);
        cur_texture = material->textures[textureIndex];
        texHeight = cur_texture->header.height;
        fmt = cur_texture->header.imFormat;
        if (fmt == G_IM_FMT_CI) {
            maxTmemBytes = 0x800;
        } else {
            maxTmemBytes = 0x1000;
        }
        rowsPerTile = maxTmemBytes / cur_texture->header.bytesPerRow;
        totalRows = maxY - minY;
        if (rowsPerTile < texHeight) {
            rowsPerTile &= 0x1FFE;
        }
        rowsDrawn = 0;
        while (1) {
            if (rowsDrawn >= totalRows) {
                break;
            }
            curRowCount = rowsPerTile;
            remainingRows = totalRows - rowsDrawn;
            if (remainingRows < rowsPerTile) {
                curRowCount = remainingRows;
            }
            func_800923E8(&gGfxContext, material, textureIndex, 0, 0, 0, rowsDrawn + offsetY);
            gDPSetTile(NEXT_GFX(gGfxContext.dlHead), cur_texture->header.imFormat, cur_texture->header.imSize, cur_texture->header.bytesPerRow >> 3, 0, 0, 0,
                G_TX_NOMIRROR | G_TX_CLAMP, material->heightPower, G_TX_NOLOD,
                G_TX_NOMIRROR | G_TX_CLAMP, material->widthPower, G_TX_NOLOD);
            gDPSetTileSize(NEXT_GFX(gGfxContext.dlHead), 0, 0 << 2, 0 << 2, (cur_texture->header.width - 1) << 2, (curRowCount - 1) << 2);
            gSPTextureRectangle(NEXT_GFX(gGfxContext.dlHead),
                minX << 2, (maxY - (rowsDrawn + curRowCount)) << 2,
                maxX << 2, (maxY - rowsDrawn) << 2, 0,
                //! While not technically a bug since it looks fine at native N64 resolution, this T texture coordinate offset causes issues with higher
                // sampling resolution due to rounding errors during texture sampling. Turning the full pixel offset into a quarter pixel offset with
                // the commented out code fixes it.
                offsetX << 5, ((curRowCount - 1) << 5) /* + (3 << 3) */,
                1 << 10, -1 << 10);
            rowsDrawn += rowsPerTile;
        }
        gDPSetTexturePersp(NEXT_GFX(gGfxContext.dlHead), G_TP_PERSP);
    }
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_302", func_80075884);
