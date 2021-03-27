#include <include_asm.h>
#include <ultra64.h>
#include <macros.h>
#include <types.h>

// bss
extern struct GfxTask D_800C1460[2];
extern Gfx D_800C1770[2][0x1000];


extern struct GfxContext gGfxContext;
extern Gfx D_800A5CC0[];

extern u8 *D_800AAF6C;
extern u8 *D_800AAF70;
extern s32 D_800AAF78;
extern struct GfxTask* gCurGfxTask;

// void func_80046CBC();
void update_gfx_context();
void func_80046D58();

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
        task->ctx.unkC = (u32)task->ctx.dlStart + task->ctx.unk0;
        task->unk120 = i;
    }
    gCurGfxTask = &D_800C1460[2];
    D_800AAF78 = 0x80000000;
    func_80046CBC();
    update_gfx_context();
    func_80046D58();
    gSPDisplayList(++gGfxContext.dlHead - 1, D_800A5CC0); // Nice
    func_80046FBC(0, 0, 0, 0xFF, 0x12, 0xE, 0x12D, 0xE1);
    schedule_gfx_task();
}

struct unkD_8009F094 {
    u8 padding[0x124];
    s32 unk124;
    s32 unk128;
};

extern struct unkD_8009F094 *D_8009F094;

extern s32 D_800AAF7C;

// void *func_80046CBC(void) {
//     s32 temp_v1;
//     s32 temp_v1_2;
//     u32 temp_v0;
//     void *phi_return;

//     temp_v0 = gCurGfxTask + 0x188;
//     gCurGfxTask = temp_v0;
//     if (temp_v0 >= (u32) D_800C1770) {
//         gCurGfxTask = (u32) (D_800C1770 - 0x310);
//     }
//     if (D_8009F094 != 0) {
//         temp_v1_2 = D_8009F094[gCurGfxTask->unk120].unk128;
//         phi_return = &D_800AAF7C;
//         if (temp_v1_2 != 0) {
//             D_800AAF7C = temp_v1_2;
//             phi_return = &D_800AAF7C;
//         }
//     }
//     return phi_return;
// }

INCLUDE_ASM(void*, "rocket/codeseg2/codeseg2_149", func_80046CBC);
