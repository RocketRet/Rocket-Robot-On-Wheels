#include <include_asm.h>
#include <ultra64.h>

extern OSIoMesg D_800E4DB0;
extern OSMesgQueue D_80017DFC;

// TODO different compiler
// void start_dma_read(u32 romAddr, void *ramAddr, s32 length)
// {
//     osInvalDCache(ramAddr, length);
//     osPiStartDma(&D_800E4DB0, OS_MESG_PRI_NORMAL, OS_READ, romAddr, ramAddr, length, &D_80017DFC);
//     return;
// }

INCLUDE_ASM(s32, "codeseg2/codeseg2_225", start_dma_read);

// TODO different compiler
// void do_dma_read(u32 romAddr, void *ramAddr, s32 length)
// {
//     OSMesg dummy;

//     osInvalDCache(ramAddr, length);
//     osPiStartDma(&D_800E4DB0, OS_MESG_PRI_NORMAL, OS_READ, romAddr, ramAddr, length, &D_80017DFC);
//     osRecvMesg(&D_80017DFC, &dummy, OS_MESG_BLOCK);
// }

INCLUDE_ASM(s32, "codeseg2/codeseg2_225", do_dma_read);

struct unkD_800AAF64 {
};

struct unkD_800E4DD0 {
    u32 romAddr;
    u32 ramAddr;
    u32 size;
    u32 *unkC;
};

extern s32 D_800AAF60;
extern s32 D_800AAF64;
extern u32 D_800AF5F0;
extern OSIoMesg D_800E4DB0;
extern OSMesgQueue D_80017DFC;
extern struct unkD_800E4DD0 D_800E4DD0[];

// TODO different compiler
// void func_80061A58()
// {
//     OSMesg mesg;
//     if (D_800AAF64 != D_800AAF60)
//     {
//         u32 romAddr = D_800E4DD0[D_800AAF60].romAddr;
//         void *ramAddr = D_800E4DD0[D_800AAF60].ramAddr;
//         u32 size = D_800E4DD0[D_800AAF60].size;
//         osInvalDCache(ramAddr, size);
//         osPiStartDma(&D_800E4DB0, OS_MESG_PRI_NORMAL, OS_READ, romAddr, ramAddr, size, &D_80017DFC);
//         if (D_800AF5F0 != -1)
//         {
//             osRecvMesg(&D_80017DFC, &mesg, OS_MESG_BLOCK);
//             *D_800E4DD0[D_800AAF60].unkC = D_800E4DD0[D_800AAF60].ramAddr;
//             D_800E4DD0[D_800AAF60].unkC = 0;
//             D_800AAF60 = (D_800AAF60 + 1) % 5;
//         }
//         else
//         {
//             *D_800E4DD0[D_800AAF60].unkC = 0;
//         }
//     }
// }

INCLUDE_ASM(s32, "codeseg2/codeseg2_225", func_80061A58);
