#include <include_asm.h>
#include <ultra64.h>
#include <types.h>
#include "mathutils.h"
#include "codeseg2.h"
#include "gfx.h"

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_380", func_8008AC50);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_380", func_8008AC88);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_380", func_8008AE1C);

INCLUDE_ASM(void, "rocket/codeseg2/codeseg2_380", func_8008AEA0, s32, struct unkfunc_8008B694*);

void add_render_entry(Gfx* arg0, Mtx* arg1, Mtx* arg2, f32 arg3, struct RenderParams arg4, u8 arg5) {
    struct RenderEntry* temp_a3;

    if ((arg5 != 0) && (u32)(D_800AF300 - D_800ADB00) < 256u) {
        temp_a3 = D_800AF300++;
        temp_a3->alpha = arg5;
        temp_a3->gfx = arg0;
        temp_a3->mtx1 = arg1;
        temp_a3->mtx2 = arg2;
        temp_a3->depth = arg3;
        if (arg5 < 0xFF) {
            u8 unk1 = arg4.unk1;
            u8 unk2 = arg4.unk2;
            if (unk2 == 3) {
                unk2 = 5;
            } else {
                unk2 = 4;
            }
            temp_a3->renderParams = unk_make_RenderParams(2, 2, unk1, unk2);
        } else {
            temp_a3->renderParams = arg4;
        }
    }
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_380", func_8008B3DC);

// Sorts an array of render entries by their depth
void func_8008B4BC(s32 length, struct RenderEntry** arg1) {
    s32 var_a2;
    s32 var_t2;
    s32 var_t4;
    s32 end;
    struct RenderEntry* swap_temp;

    if (length >= 2) {
        end = length;
        var_t4 = end / 2;
        end--;
        while (1) {
            if (var_t4 > 0) {
                var_t4 -= 1;
            } else {
                // Swap indices 0 and end
                swap_temp = arg1[0];
                arg1[0] = arg1[end];
                arg1[end] = swap_temp;
                end -= 1;
                if (!(end > 0)) {
                    break;
                }
            }
            var_t2 = var_t4;
            var_a2 = (var_t2 * 2) + 1;
            while (1) {
                if (!(end >= var_a2)) {
                    break;
                }
                if (var_a2 < end) {
                    if (arg1[var_a2]->depth < arg1[var_a2 + 1]->depth) {
                        var_a2 += 1;
                    }
                }
                if (!(arg1[var_t2]->depth < arg1[var_a2]->depth)) {
                    break;
                }
                // Swap indices var_t2 and var_a2
                swap_temp = arg1[var_t2];
                arg1[var_t2] = arg1[var_a2];
                arg1[var_a2] = swap_temp;
                var_t2 = var_a2;
                var_a2 += var_a2 + 1;
            }
        }
    }
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_380", func_8008B594);

static inline void divide_opaque_and_transparent(int totalEntryCount, struct RenderEntry* sortedEntryList[256], s32* opaqueEntryCount) {
    struct RenderEntry** opaqueEnd;
    struct RenderEntry** transparentStart;
    void* swapTemp;
    
    opaqueEnd = sortedEntryList;
    transparentStart = sortedEntryList + (totalEntryCount - 1);
    
    // Move all of the opaque entries to the start of the list and the transparent ones to the end
    while (1) {
        // Search forwards to find the first transparent entry in the list
        while (((*opaqueEnd)->renderParams.unk0_4) == 0x1 && opaqueEnd < transparentStart) {
            opaqueEnd++;
        }
        
        // Search backwards to find the last opaque entry in the list
        while (((*transparentStart)->renderParams.unk0_4) == 0x2 && opaqueEnd < transparentStart) {
            transparentStart--;
        }

        if (opaqueEnd >= transparentStart) {
            break;
        }
        
        // Swap the first transparent and last opaque entry
        swapTemp = *opaqueEnd;
        *opaqueEnd = *transparentStart;
        *transparentStart = swapTemp;
        opaqueEnd++;
        transparentStart--;
    }

    // If there's a leftover entry, check if it's opaque and bump the opaque end pointer by one if so
    if (((*opaqueEnd)->renderParams.unk0_4) == 0x1) {
        opaqueEnd++;
    }
    
    *opaqueEntryCount = opaqueEnd - sortedEntryList;
}

void func_8008B694(s32 arg0, struct unkfunc_8008B694* arg1) {
    Mtx *curMtx1 = NULL;
    Mtx *curMtx2 = NULL;
    struct RenderParams curRenderParams = unk_make_RenderParams(0, 0, 0, 0);
    u32 curCycleType = 0xFFFFFFFF;
    u32 curRenderMode1 = 0xFFFFFFFF;
    u32 curRenderMode2 = 0xFFFFFFFF;
    u8 curAlpha = 0xFF;
    u32 newCycleType;
    u32 newRenderMode1;
    u32 newRenderMode2;
    s32 opaqueEntryCount;
    s32 totalEntryCount;
    s32 curEntryIndex;
    struct RenderEntry* toDraw;
    struct RenderEntry* sortedEntryList[256];

    gDPPipeSync(NEXT_GFX(gGfxContext.dlHead));
    gDPSetPrimColor(NEXT_GFX(gGfxContext.dlHead), 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF);
    func_80092050();
    func_8008AEA0(arg0, arg1);
    totalEntryCount = D_800AF300 - D_800ADB00;
    for (curEntryIndex = 0; curEntryIndex < totalEntryCount; curEntryIndex++) {
        sortedEntryList[curEntryIndex] = &D_800ADB00[curEntryIndex];
    }
    if (totalEntryCount > 0) {
        // Split the render entries into an opaque list and a transparent list
        divide_opaque_and_transparent(totalEntryCount, sortedEntryList, &opaqueEntryCount);
        // Sort the opaque RenderEntry list
        func_8008B4BC(opaqueEntryCount, sortedEntryList);
        // Sort the transparent RenderEntry list
        func_8008B4BC(totalEntryCount - opaqueEntryCount, &sortedEntryList[opaqueEntryCount]);
    }
    curMtx1 = NULL;
    // Iterate over every entry in the two sorted lists
    curEntryIndex = 0;
    while (1) {
        if (!(curEntryIndex < totalEntryCount)) {
            break;
        }
        if (curEntryIndex < opaqueEntryCount) {
            // If we haven't gotten to transparent entries yet, iterate in forward order (front to back for performance)
            toDraw = sortedEntryList[curEntryIndex];
        } else {
            // Otherwise, iterate in reverse order (back to front for transparency correctness)
            toDraw = sortedEntryList[(totalEntryCount - (curEntryIndex - opaqueEntryCount)) - 1];
        }
        if ((toDraw->mtx1 != curMtx1) || (toDraw->mtx2 != curMtx2)) {
            if (toDraw->mtx2 != 0) {
                gSPMatrix(NEXT_GFX(gGfxContext.dlHead), toDraw->mtx1, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
                gSPMatrix(NEXT_GFX(gGfxContext.dlHead), toDraw->mtx2, G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
            } else if (toDraw->mtx1 != 0) {
                gSPMatrix(NEXT_GFX(gGfxContext.dlHead), toDraw->mtx1, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
            }
            curMtx2 = toDraw->mtx2;
            curMtx1 = toDraw->mtx1;
        }

        if (!unk_compare_RenderParams(curRenderParams, toDraw->renderParams)) {
            func_80047B60(toDraw->renderParams, &newCycleType, &newRenderMode1, &newRenderMode2);
            if ((newCycleType != curCycleType) || (newRenderMode1 != curRenderMode1) || (newRenderMode2 != curRenderMode2)) {
                gDPPipeSync(NEXT_GFX(gGfxContext.dlHead));
            }
            if (newCycleType != curCycleType) {
                gDPSetCycleType(NEXT_GFX(gGfxContext.dlHead), newCycleType);
            }
            if ((newRenderMode1 != curRenderMode1) || (newRenderMode2 != curRenderMode2)) {
                gDPSetRenderMode(NEXT_GFX(gGfxContext.dlHead), newRenderMode1, newRenderMode2);
            }
            curRenderParams = toDraw->renderParams;
            curCycleType = newCycleType;
            curRenderMode1 = newRenderMode1;
            curRenderMode2 = newRenderMode2;
        }
        if (toDraw->alpha != curAlpha) {
            gDPPipeSync(NEXT_GFX(gGfxContext.dlHead));
            gDPSetPrimColor(NEXT_GFX(gGfxContext.dlHead), 0x00, 0x00, 0x00, 0x00, 0x00, toDraw->alpha);
            curAlpha = toDraw->alpha;
        }
        gSPDisplayList(NEXT_GFX(gGfxContext.dlHead), toDraw->gfx);
        curEntryIndex += 1;
    }
    if (arg1->unkBC_1 && arg1->unkBC_2) {
        s32 rectTop = 214;
        s32 rectBottom = 212;
        rectTop *= arg1->unkC4;
        rectBottom *= arg1->unkC8;
        if (rectTop < rectBottom) {
            draw_rectangle(arg1->unkBD, arg1->unkBE, arg1->unkBF, arg1->unkC0, MARGIN_X, rectTop + MARGIN_Y, SCREEN_WIDTH - (MARGIN_X + 1), rectBottom + MARGIN_Y - 1);
        }
    }
    if (arg1->unkBC_3) {
        // Sign extend unkBC_1
        func_80091F54((arg1->unkBC_1 << 31) >> 31);
    }
    D_800AF300 = NULL;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_380", func_8008BCE8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_380", func_8008BD58);

struct unkfunc_8008BE58 {
    u8 padding[0x3C];
    Vec3f unk3C;
};

void func_8008BE58(struct unkfunc_8008BE58 *arg0, f32 arg1)
{
    set_vec3f_components(arg0->unk3C, 0, 0, arg1);
}

struct unkfunc_8008BE8C_unk4 {
    u8 pad0[0x4];
    s32 unk4;
};

struct unkfunc_8008BE8C {
    u8 pad0[0x1C];
    s32 unk1C;
    s32 pad20;
    struct unkfunc_8008BE8C_unk4** unk24;
};

struct unkfunc_8008BE8C_unk4* func_8008BE8C(struct unkfunc_8008BE8C* arg0, s32 toFind) {
    s32 i;

    for (i = 0; i < arg0->unk1C; i++) {
        if (arg0->unk24[i]->unk4 == toFind) {
            return arg0->unk24[i];
        }
    }
    
    return NULL;
}
