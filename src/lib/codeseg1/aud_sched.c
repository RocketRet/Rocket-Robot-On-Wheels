#include <include_asm.h>
#include <ultra64.h>
#include <PR/sched.h>

#define QUEUE_SIZE	4

typedef struct
{
	OSScClient	client;
	OSMesgQueue frame_queue;
	OSMesg      frame_messages[QUEUE_SIZE];
	OSMesgQueue	task_queue;
	OSMesg		task_messages[QUEUE_SIZE];
} ossched_workspace_t;

extern OSSched *audio_sched;
extern ossched_workspace_t *sched_mem;

void __MusIntSchedInit(void *arg0)
{
    audio_sched = arg0;
}

void __OsSchedInstall()
{
    sched_mem = __MusIntMemMalloc(sizeof(ossched_workspace_t));
    osCreateMesgQueue(&sched_mem->frame_queue, &sched_mem->frame_messages[0], QUEUE_SIZE);
    osCreateMesgQueue(&sched_mem->task_queue, &sched_mem->task_messages[0], QUEUE_SIZE);
    osScAddClient(audio_sched, &sched_mem->client, &sched_mem->frame_queue);
}

void __OsSchedWaitFrame()
{
    OSScMsg *mesg;
    do {
        osRecvMesg(&sched_mem->frame_queue, (OSMesg *)&mesg, OS_MESG_BLOCK);
        osRecvMesg(&sched_mem->frame_queue, NULL, OS_MESG_NOBLOCK);
    } while (mesg->type != OS_SC_RETRACE_MSG);
}

extern u8 _binary_bin_rspboot_code_bin_start[];
extern u8 _binary_bin_rspboot_code_bin_end[];

void __OsSchedDoTask(s32 *arg0)
{
    OSScTask t;
    u8 padding[0x10]; // Why is this needed?
    OSScMsg message;

    t.next  = 0;
    t.msgQ  = &sched_mem->task_queue;
    t.msg   = &message;
    t.flags = OS_SC_NEEDS_RSP;

    t.list.t.data_ptr = (void*)arg0[0];
    t.list.t.data_size = (void*)arg0[1];
    t.list.t.type = M_AUDTASK;
    t.list.t.ucode_boot = &_binary_bin_rspboot_code_bin_start;
    t.list.t.ucode_boot_size = _binary_bin_rspboot_code_bin_end - _binary_bin_rspboot_code_bin_start;
    t.list.t.flags = 0;
    t.list.t.ucode = (void*)arg0[2];
    t.list.t.ucode_data = (void*)arg0[3];
    t.list.t.ucode_size = SP_UCODE_SIZE;
    t.list.t.ucode_data_size = SP_UCODE_DATA_SIZE;
    t.list.t.dram_stack = NULL;
    t.list.t.dram_stack_size = 0x0;
    t.list.t.output_buff = NULL;
    t.list.t.output_buff_size = NULL;
    t.list.t.yield_data_ptr = NULL;
    t.list.t.yield_data_size = 0x0;

    osSendMesg(osScGetCmdQ(audio_sched), (OSMesg)&t, OS_MESG_BLOCK);
    osRecvMesg(&sched_mem->task_queue, NULL, OS_MESG_BLOCK);
}
