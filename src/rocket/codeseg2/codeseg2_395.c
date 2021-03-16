#include <include_asm.h>
#include <ultra64.h>
#include <audio.h>
#include <mus/libmus.h>
#include <PR/sched.h>

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_395", func_8008F9D0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_395", func_8008FA24);

struct unkD_800E5090 {
    s32 unk0;
    u32 handle;
    s32 time;
    s32 unkC;
};

// extern s32 D_800E5090[];
extern struct unkD_800E5090 D_800E5090[];

extern s32 D_800E598C;

extern s32 D_800AF4E4;

extern OSSched gScheduler;

extern char D_B09C01A0[];


extern s32 D_800AF328[];

void func_80061740();
void func_8008FC14();
void func_80091C98();

// void func_8008FA88()
// {
//     musConfig config;
//     void *volatile fxBank = &gAudioFxBank;
//     void *volatile ptrBank = &gAudioPtrBank;
//     s32 i = 0;
//     struct unkD_800E5090 *j;
//     while (i < 0x8f)
//     {
//         j = &D_800E5090[i], i++;// i++;
//         j->unkC = i;
//     }
//     D_800E598C = -1;

//     func_80061740(D_800AF328[0], fxBank, D_800AF328[1] - D_800AF328[0]);
//     func_80061740(D_800AF328[2], ptrBank, D_800AF328[3] - D_800AF328[2]);

//     bzero(&config, sizeof(musConfig));

//     config.channels = 48;
//     config.unk = 192;
//     config.sched = &gScheduler;
//     config.thread_priority = 12;

//     config.heap = gAudioHeapPtr;
//     config.heap_length = AUDIO_HEAP_SIZE;

//     config.fifo_length = 64;

//     config.syn_output_rate = AUDIO_SAMPLE_RATE;
//     config.syn_updates = 64;
//     config.syn_rsp_cmds = 4096;
//     config.syn_retraceCount = 1;
//     config.syn_num_dma_bufs = 64;
//     config.syn_dma_buf_size = 0x800;

//     MusInitialize(&config);
//     MusPtrBankInitialize(&gAudioPtrBank, D_B09C01A0);
//     MusFxBankInitialize(&gAudioFxBank);
//     MusFxBankSetPtrBank(&gAudioFxBank, &gAudioPtrBank);
//     MusSetMasterVolume(2, 0x5FFF);
//     MusSetMasterVolume(1, 0x7FFF);
//     MusFxBankSetSingle(&gAudioFxBank);
//     func_8008FC14(&D_800AF4E4);
//     func_80091C98();
// }

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_395", func_8008FA88);

void func_8008FC14(s32 *arg0) {

}


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_395", func_8008FC1C);

extern s32 D_800AF3F0;

void func_8008FD0C(s32 arg0)
{
    D_800AF3F0 = arg0;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_395", func_8008FD18);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_395", func_8008FEB4);
