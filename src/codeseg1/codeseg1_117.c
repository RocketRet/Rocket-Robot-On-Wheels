#include <include_asm.h>
#include <ultra64.h>


extern void *gSchedulerPtr;
extern s32 *D_800BEB14;

void func_8000CCA0(void *arg0)
{
    gSchedulerPtr = arg0;
}

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

INCLUDE_ASM(s32, "codeseg1/codeseg1_117", func_8000CD14);

// void func_8000CD7C(s32 *arg0)
// {
//     void *arr[0x22];

//     arr[21] = arr;
//     arr[9] = (void*) 0x1000;
//     arr[9] = (void*) 0x800;

//     osSendMesg(osScGetCmdQ(gSchedulerPtr), arr, 1); // OS_MESG_BLOCK
//     osRecvMesg(&D_800BEB14[12], NULL, 1); // OS_MESG_BLOCK
// }

INCLUDE_ASM(s32, "codeseg1/codeseg1_117", func_8000CD7C);
