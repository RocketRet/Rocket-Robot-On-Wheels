#include <include_asm.h>
#include <ultra64.h>
#include <PR/sched.h>
#include <types.h>
#include "codeseg2.h"

extern struct RenderParams D_800A5DB8; // 0x04 bytes
extern struct GfxTask* gCurGfxTask;

extern u32* D_800AAF7C;
extern u32 D_800AAF84;
extern OSMesgQueue *gSchedMesgQueue;

extern u64 D_800D1770[];
extern u64 D_800E4820[];

extern u64 D_800C0460[SP_DRAM_STACK_SIZE64];
extern u64 D_800C0860[OS_YIELD_DATA_SIZE];


extern OSMesgQueue D_80017DE4;

void schedule_gfx_task(void) {
    struct RenderParams sp10;
    OSScTask* sched_task;

    gDPFullSync(next_gfx());
    gSPEndDisplayList(next_gfx());
    if (D_800A5DB8.cycleType != 0 && D_800A5DB8.unk0_4 != 0 && D_800A5DB8.unk1 != 0 && D_800A5DB8.unk2 != 0) {
        sp10 = D_800A5DB8;
    } else {
        sp10 = unk_make_RenderParams(0, 0, 0, 0);
    }
    sched_task = &gCurGfxTask->schedTask;
    sched_task->list.t.data_ptr = (u64*)gCurGfxTask->dlStart;
    sched_task->list.t.data_size = (u8*)gGfxContext.dlHead - (u8*)gCurGfxTask->dlStart;
    sched_task->list.t.flags = 0;
    sched_task->list.t.type = M_GFXTASK;
    sched_task->list.t.ucode_boot = rspbootTextStart;
    sched_task->list.t.ucode_boot_size = (u8*)rspbootTextEnd - (u8*)rspbootTextStart;
    sched_task->list.t.ucode = gspF3DEX2_fifoTextStart;
    sched_task->list.t.ucode_data = gspF3DEX2_fifoDataStart;
    sched_task->list.t.output_buff = D_800D1770;
    sched_task->list.t.output_buff_size = D_800E4820;
    sched_task->list.t.ucode_data_size = SP_UCODE_DATA_SIZE;
    sched_task->list.t.dram_stack = D_800C0460;
    sched_task->list.t.dram_stack_size = SP_DRAM_STACK_SIZE8;
    sched_task->list.t.yield_data_ptr = D_800C0860;
    sched_task->list.t.yield_data_size = OS_YIELD_DATA_SIZE;
    gCurGfxTask->schedTask.next = NULL;
    sched_task->flags = OS_SC_NEEDS_RDP | OS_SC_NEEDS_RSP | OS_SC_LAST_TASK | OS_SC_SWAPBUFFER;
    sched_task->msgQ = &D_80017DE4;
    sched_task->msg = (void*) &gCurGfxTask->unk124;
    sched_task->framebuffer = gCurGfxTask->framebuffer;
    // Writes back both the OSTask and the matrices in the GfxTask
    osWritebackDCache(gCurGfxTask, sizeof(*gCurGfxTask));
    osWritebackDCache(gGfxContext.dlStart, (u8*)gGfxContext.dlHead - (u8*)gGfxContext.dlStart);
    osWritebackDCache(gGfxContext.unkC, (u8*)gGfxContext.dlStart + gGfxContext.unk0 - (u8*)gGfxContext.unkC);
    osWritebackDCache(D_800AAF7C, D_800AAF84);
    osSendMesg(gSchedMesgQueue, sched_task, OS_MESG_BLOCK);
}
