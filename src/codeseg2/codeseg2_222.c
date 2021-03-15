#include <include_asm.h>
#include <ultra64.h>
#include <macros.h>
#include <audio.h>

extern void *D_800AAF68;
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
extern u32 D_800E48B8;
extern void *D_800E4DA0;
extern s8 D_800E499F;

#define RAM_END 0x80400000
#define FRAMEBUFFER_BYTES ((SCREEN_WIDTH) * (SCREEN_HEIGHT) * 2)

// TODO different order?
// void func_80061300()
// {
//     D_800AAF68 = (s32)&D_800F6ADF & ~0x3F;
//     bzero(D_800AAF68, FRAMEBUFFER_BYTES);
//     gAudioHeapPtr = D_800E48A4 = FRAMEBUFFER_BYTES + (s32)D_800AAF68;
//     bzero(gAudioHeapPtr, AUDIO_HEAP_SIZE);
//     D_800AAF70 = RAM_END - FRAMEBUFFER_BYTES;
//     D_800E48AC = AUDIO_HEAP_SIZE + (s32)gAudioHeapPtr;
//     D_800E48A4 = AUDIO_HEAP_SIZE + (s32)gAudioHeapPtr;
//     D_800E48A0 = AUDIO_HEAP_SIZE + (s32)gAudioHeapPtr;
//     D_800E48A8 = AUDIO_HEAP_SIZE + (s32)gAudioHeapPtr;
//     D_800E48B0 = D_800E48B4 = D_800AAF6C = RAM_END - (2 * FRAMEBUFFER_BYTES);
//     D_800E48B8 = 0xffffffff;
//     D_800E4DA0 = (s32)&D_800E499F & ~0xF;
// }

INCLUDE_ASM(s32, "codeseg2/codeseg2_222", func_80061300);

INCLUDE_ASM(s32, "codeseg2/codeseg2_222", func_800613F8);
