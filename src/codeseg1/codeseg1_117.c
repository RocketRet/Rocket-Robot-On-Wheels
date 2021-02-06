#include <include_asm.h>
#include <ultra64.h>
#include <PR/sched.h>


extern OSSched *gSchedulerPtr;
extern s32 *D_800BEB14;

// void func_8000CCA0(void *arg0)
// {
//     gSchedulerPtr = arg0;
// }

INCLUDE_ASM(s32, "codeseg1/codeseg1_117", func_8000CCA0);

// TODO different compiler
// void func_8000CCAC()
// {
//     D_800BEB14 = func_8000D110(0x58);
//     // What is D_800BEB14?
//     osCreateMesgQueue(&D_800BEB14[2], &D_800BEB14[8], 4);
//     osCreateMesgQueue(&D_800BEB14[12], &D_800BEB14[18], 4);
//     osScAddClient(gSchedulerPtr, D_800BEB14, &D_800BEB14[2]);
// }

INCLUDE_ASM(s32, "codeseg1/codeseg1_117", func_8000CCAC);

// TODO different compiler
// void func_8000CD14()
// {
//     s16 *mesg;
//     do {
//         osRecvMesg(&D_800BEB14[2], &mesg, 1); // OS_MESG_BLOCK
//         osRecvMesg(&D_800BEB14[2], NULL, 0); // OS_MESG_NOBLOCK
//     } while (*mesg != 1);
// }

extern u8 _binary_bin_rspboot_code_bin_start[];
extern u8 _binary_bin_rspboot_code_bin_end[];

INCLUDE_ASM(s32, "codeseg1/codeseg1_117", func_8000CD14);

// TODO different compiler
// void do_audio_task(s32 *arg0)
// {
//     OSScTask task;
//     u32 arr[8];

//     task.msg = arr;
//     task.next = NULL;
//     task.flags = OS_SC_NEEDS_RSP;
//     task.msgQ = &D_800BEB14[12];
//     task.list.t.data_ptr = (void*)arg0[0];
//     task.list.t.data_size = (void*)arg0[1];
//     task.list.t.type = M_AUDTASK;
//     task.list.t.ucode_boot = &_binary_bin_rspboot_code_bin_start;
//     task.list.t.ucode_boot_size = _binary_bin_rspboot_code_bin_end - _binary_bin_rspboot_code_bin_start;
//     task.list.t.flags = 0;
//     task.list.t.ucode = (void*)arg0[2];
//     task.list.t.ucode_data = (void*)arg0[3];
//     task.list.t.ucode_size = SP_UCODE_SIZE;
//     task.list.t.ucode_data_size = SP_UCODE_DATA_SIZE;
//     task.list.t.dram_stack = NULL;
//     task.list.t.dram_stack_size = 0x0;
//     task.list.t.output_buff = NULL;
//     task.list.t.output_buff_size = NULL;
//     task.list.t.yield_data_ptr = NULL;
//     task.list.t.yield_data_size = 0x0;

//     osSendMesg(osScGetCmdQ(gSchedulerPtr), (OSMesg)&task, OS_MESG_BLOCK);
//     osRecvMesg(&D_800BEB14[12], NULL, OS_MESG_BLOCK);
// }

INCLUDE_ASM(s32, "codeseg1/codeseg1_117", do_audio_task);
