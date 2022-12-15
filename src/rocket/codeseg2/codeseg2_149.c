#include <ultra64.h>
#include "include_asm.h"
#include "gfx.h"

// bss
extern struct GfxTask D_800C1460[2];
extern Gfx D_800C1770[2][0x1000];


extern struct GfxContext gGfxContext;
extern Gfx D_800A5CC0[];

extern u8 *D_800AAF6C;
extern u8 *D_800AAF70;
extern struct GfxTask* gCurGfxTask;

// void func_80046CBC();
void update_gfx_context();
void schedule_gfx_task(void);
void func_80046D58();
void func_80046CBC();

void func_80046B40()
{
    u32 i;
    struct GfxTask *task;
    osViSetSpecialFeatures(OS_VI_DITHER_FILTER_ON | OS_VI_GAMMA_OFF); 
    for (i = 0; i < 2; i++)
    {
        task = &D_800C1460[i];
        if (i == 0)
        {
            task->framebuffer = D_800AAF6C;
        }
        else
        {
            task->framebuffer = D_800AAF70;
        }
        bzero(task->framebuffer, FRAMEBUFFER_BYTES);
        task->unk124 = 2;
        task->ctx.dlHead = task->ctx.dlStart = D_800C1770[i];
        task->ctx.unk0 = 0x1000 * sizeof(Gfx);
        task->unk128 = task;
        task->ctx.unkC = (Mtx*)((u32)task->ctx.dlStart + task->ctx.unk0);
        task->unk120 = i;
    }
    gCurGfxTask = &D_800C1460[2];
    D_800AAF78[0] = K0BASE;
    func_80046CBC();
    update_gfx_context();
    func_80046D58();
    gSPDisplayList(NEXT_GFX(gGfxContext.dlHead), D_800A5CC0);
    draw_rectangle(0, 0, 0, 0xFF, 0x12, 0xE, 0x12D, 0xE1);
    schedule_gfx_task();
}

extern s32 D_800AAF7C;

void func_80046CBC(void) {
    s32 temp_v1_2;

    if ((uintptr_t)++gCurGfxTask >= (uintptr_t) &D_800C1460[2]) {
        gCurGfxTask = &D_800C1460[0];
    }
    if (D_8009F094.unk0 != 0) {
        temp_v1_2 = D_8009F094.unk0->unk128[gCurGfxTask->unk120];
        if (temp_v1_2 != 0) {
            D_800AAF7C = temp_v1_2;
        }
    }
}

