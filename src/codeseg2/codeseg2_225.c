#include <include_asm.h>
#include <ultra64.h>

extern OSIoMesg D_800E4DB0;
extern OSMesgQueue D_80017DFC;

// TODO different compiler
// void start_dma_read(u32 romAddr, void *ramAddr, s32 length)
// {
//     osInvalDCache(ramAddr, length);
//     osPiStartDma(&D_800E4DB0, 0, OS_READ, romAddr, ramAddr, length, &D_80017DFC);
//     return;
// }

INCLUDE_ASM(s32, "codeseg2/codeseg2_225", start_dma_read);

// TODO different compiler
// void do_dma_read(u32 romAddr, void *ramAddr, s32 length)
// {
//     OSMesg dummy;

//     osInvalDCache(ramAddr, length);
//     osPiStartDma(&D_800E4DB0, 0, OS_READ, romAddr, ramAddr, length, &D_80017DFC);
//     osRecvMesg(&D_80017DFC, &dummy, OS_MESG_BLOCK);
// }

INCLUDE_ASM(s32, "codeseg2/codeseg2_225", do_dma_read);

INCLUDE_ASM(s32, "codeseg2/codeseg2_225", func_80061A58);
