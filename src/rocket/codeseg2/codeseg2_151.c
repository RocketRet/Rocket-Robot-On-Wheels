#include <include_asm.h>
#include <ultra64.h>
#include <PR/sched.h>
#include <types.h>
#include "codeseg2.h"

extern struct unkfunc_80093DDC D_800A5DB8; // 0x04 bytes
extern struct GfxTask* gCurGfxTask; // 0x04 bytes

extern u32* D_800AAF7C;
extern u32 D_800AAF84;
extern OSMesgQueue *gSchedMesgQueue;

extern u64 D_800D1770[];
extern u64 D_800E4820[];

extern u64 D_800C0460[SP_DRAM_STACK_SIZE64];
extern u64 D_800C0860[OS_YIELD_DATA_SIZE];


extern OSMesgQueue D_80017DE4;

void schedule_gfx_task(void) {
    struct unkfunc_80093DDC sp10;
    Gfx* temp_v1;
    Gfx* temp_v1_2;
    Mtx* temp_a0_3;
    struct GfxTask* temp_a0;
    u8 temp_v1_3;
    OSScTask* sched_task;
    s8 phi_v1;

    gDPFullSync(next_gfx());
    gSPEndDisplayList(next_gfx());
    if (D_800A5DB8.unk0_0 != 0 && D_800A5DB8.unk0_4 != 0 && D_800A5DB8.unk1 != 0 && D_800A5DB8.unk2 != 0) {
        sp10 = D_800A5DB8;
    } else {
        sp10 = unk_make_struct_unkfunc_80093DDC();
    }
    sched_task = &gCurGfxTask->schedTask;
    sched_task->list.t.data_ptr = gCurGfxTask->unk14;
    sched_task->list.t.data_size = (u8*)gGfxContext.dlHead - (u8*)gCurGfxTask->unk14;
    sched_task->list.t.flags = 0;
    sched_task->list.t.type = 1;
    sched_task->list.t.ucode_boot = rspbootTextStart;
    sched_task->list.t.ucode_boot_size = (u8*)rspbootTextEnd - (u8*)rspbootTextStart;
    sched_task->list.t.ucode = gspF3DEX2_fifoTextStart;
    sched_task->list.t.ucode_data = gspF3DEX2_fifoDataStart;
    sched_task->list.t.output_buff = D_800D1770;
    sched_task->list.t.output_buff_size = D_800E4820;
    sched_task->list.t.ucode_data_size = 0x800;
    sched_task->list.t.dram_stack = D_800C0460;
    sched_task->list.t.dram_stack_size = 0x400;
    sched_task->list.t.yield_data_ptr = D_800C0860;
    sched_task->list.t.yield_data_size = 0xC00;
    gCurGfxTask->schedTask.next = NULL;
    sched_task->flags = 0x63;
    sched_task->msgQ = &D_80017DE4;
    sched_task->msg = (void*) &gCurGfxTask->unk124;
    sched_task->framebuffer = gCurGfxTask->framebuffer;
    osWritebackDCache(gCurGfxTask, 0x188);
    osWritebackDCache(gGfxContext.dlStart, (u8*)gGfxContext.dlHead - (u8*)gGfxContext.dlStart);
    osWritebackDCache(gGfxContext.unkC, (u8*)gGfxContext.dlStart + gGfxContext.unk0 - (u8*)gGfxContext.unkC);
    osWritebackDCache(D_800AAF7C, D_800AAF84);
    osSendMesg(gSchedMesgQueue, sched_task, OS_MESG_BLOCK);
}
