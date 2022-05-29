#include <include_asm.h>
#include <ultra64.h>
#include <macros.h>
#include <audio.h>

extern void *gDepthBuffer;
extern u32 D_800F6ADF;
extern u32 D_800E48A4;
extern u32 D_800E48A0;
extern u32 D_803B5000;
extern u32 D_803DA800;
extern void *D_800AAF6C;
extern u32 D_800AAF70;
extern u32 D_800E48A8;
extern u32 D_800E48AC;
extern void *D_800E48B0;
extern void *D_800E48B4;
extern s32 D_800E48B8;
extern void *D_800E4DA0;

extern u8 D_800E4990[];
extern u8 _codeseg2SegmentBssEnd[];

// TODO different order?
// void func_80061300()
// {
//     gDepthBuffer = ALIGN(_codeseg2SegmentBssEnd, 64);
//     bzero(gDepthBuffer, FRAMEBUFFER_BYTES);
//     gAudioHeapPtr = D_800E48A4 = FRAMEBUFFER_BYTES + (s32)gDepthBuffer;
//     bzero(gAudioHeapPtr, AUDIO_HEAP_SIZE);
//     D_800E48A8 = D_800E48A4 = D_800E48AC = D_800E48A0 = AUDIO_HEAP_SIZE + (s32)gAudioHeapPtr;
//     D_800AAF70 = RAM_END - FRAMEBUFFER_BYTES;
//     D_800E48B0 = D_800E48B4 = D_800AAF6C = RAM_END - (2 * FRAMEBUFFER_BYTES);
//     D_800E48B8 = -1;
//     D_800E4DA0 = ALIGN(D_800E4990, 16);
// }

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_222", func_80061300);

u32 func_800613F8(u32 arg0)
{

    if (arg0 == 0)
    {
        return 0;
    }
    else
    {
        u32 iVar1 = D_800E48A0;
        D_800E48A4 = D_800E48A8 = D_800E48AC = D_800E48A0 = D_800E48A0 + ALIGN(arg0, 16);
        return iVar1;
    }
}
