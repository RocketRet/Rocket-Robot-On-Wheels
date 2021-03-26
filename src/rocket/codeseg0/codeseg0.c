#include <include_asm.h>
#include <ultra64.h>
#include <PR/sched.h>
#include <macros.h>
#include <types.h>
#include <libmus.h>

extern struct ControllerData gControllerData;
extern u32 D_800A638C;
extern u32 D_8009FE10;
extern u32 D_8009F094;
extern u32 D_800AB9C8;

// bss
static OSThread gThread1; // 0x800AF860
static OSThread D_800AFA10; // 0x800AFA10 // thread 6
static OSThread D_800AFBC0; // 0x800AFBC0 // thread 7
static u8 gIdleThreadStack[0x1000]; // 0x800AFD70
static u8 gThread6Stack[0x1000]; // 0x800B0D70
static u8 gThread7Stack[0x8000]; // 0x800B1D70
static OSMesg D_800B9D70[8]; // 0x800B9D70
static OSMesg D_800B9D90[200]; // 0x800B9D90
static OSMesgQueue D_800BA0B0; // 0x800BA0B0
static OSMesg D_800BA0C8; // 0x800BA0C8
static OSMesg D_800BA0CC; // 0x800BA0CC
static u8 gSchedStack[OS_SC_STACKSIZE]; // 0x800BA0D0
static OSScClient D_800BC0D0; // 0x800BC0D0
// end bss (0x800BC0D8, padded to 0x800BC0E0)

// data
u32 D_80017DE0 = 2; // 0x80017DE0
OSMesgQueue D_80017DE4 = {}; // 0x80017DE4
OSMesgQueue D_80017DFC = {}; // 0x80017DFC
OSMesgQueue *gSchedMesgQueue = NULL; // 0x80017E14
OSSched gScheduler = {}; // 0x80017E18
OSMesgQueue D_800180A0 = {}; // 0x800180A0
// end data (0x800180B8, padded to 0x800180C0)


extern u8 _bssStart[];
extern u8 _bssEnd[];
extern u8 D_800F6AA0[];
extern u8 _dataEndRom[];
extern u8 D_80100000[];

void thread1_idle(void *);

void func_80000DD0()
{
    s32 numBytes;
    s32 start;
    u8 *bssStart;
    u8 *oneMB;
    bzero(_bssEnd, D_800F6AA0 - _bssEnd);
    bssStart = _bssStart;
    oneMB = (u8 *)0x80100000;
    numBytes = bssStart - oneMB;
    start = (uintptr_t)_dataEndRom - numBytes;
    if (numBytes > 0)
    {
        osInvalDCache(oneMB, numBytes);
        osPiRawStartDma(0, start, oneMB, numBytes);
        while (osPiGetStatus() & (PI_STATUS_DMA_BUSY | PI_STATUS_ERROR));
    }
}

void game_init()
{
    s32 numBytes;
    s32 start;
    u8 *bssStart;
    u8 *oneMB;
    osInitialize();
    bzero(_bssEnd, D_800F6AA0 - _bssEnd);
    bssStart = _bssStart;
    oneMB = (u8 *)0x80100000;
    numBytes = bssStart - oneMB;
    start = (uintptr_t)_dataEndRom - numBytes;
    if (numBytes > 0)
    {
        osInvalDCache(oneMB, numBytes);
        osPiRawStartDma(0, start, oneMB, numBytes);
        while (osPiGetStatus() & (PI_STATUS_DMA_BUSY | PI_STATUS_ERROR));
    }
    osCreateThread(&gThread1, 1, thread1_idle, NULL, &gIdleThreadStack[0x1000], 10);
    osStartThread(&gThread1);
}

void thread6_unk(void *);

void thread1_idle(void *arg0)
{
    osCreatePiManager(0x96, &D_800BA0B0, D_800B9D90, 200);
    osCreateThread(&D_800AFA10, 6, thread6_unk, NULL, &gThread6Stack[0x1000], 9);
    osStartThread(&D_800AFA10);
    osSetThreadPri(NULL, 0);
    while (1);
}

void create_scheduler(void);
void func_80001248(void *arg0);

extern void *D_800AAF6C, *D_800AAF70;
extern s32 D_800AF5F0;

// TODO WIP
// void thread6_unk(void *arg0)
// {
//     OSMesg mesg;
//     u32 s2;
//     s32 s1;
//     s32 s6;
//     s32 s4;
//     s32 s3;
//     s32 outMesg[3];
//     create_scheduler();
//     s2 = 0;
//     s1 = 1;
//     s3 = 1;
//     osCreateMesgQueue(&D_800180A0, &D_800BA0CC, 1);
//     if (osTvType == OS_TV_PAL)
//     {
//         s4 = 1;
//     }
//     else
//     {
//         s4 = 0;
//     }
//     osCreateThread(&D_800AFBC0, 7, func_80001248, NULL, &gThread7Stack[0x2000], 8);
//     osStartThread(&D_800AFBC0);
//     while (1)
//     {
//         osRecvMesg(&D_80017DE4, &mesg, OS_MESG_BLOCK);
//         switch ((int)mesg)
//         {
//             case 2:
//                 s1--;
//                 break;
//             case 3:
//                 s2++;
//                 break;
//             case 4:
//                 func_80074C88(&D_800AB9C8, 5);
//                 MusStop(MUSFLAG_EFFECTS | MUSFLAG_SONGS, 0);
//                 s4 = 1;
//                 break;
//             case 0xFF:
//                 break;
//             case 0:
//                 if (s3 || !s1)
//                     continue;
//         }
//         if (s1 == 0)
//         {
//             if (s4)
//             {
//                 bzero(D_800AAF6C, 0x25800);
//                 osWritebackDCache(D_800AAF6C, 0x25800);
//                 bzero(D_800AAF70, 0x25800);
//                 osWritebackDCache(D_800AAF70, 0x25800);
//                 if (__osSpSetPc(0) == -1)
//                 {
//                     MusStop(MUSFLAG_EFFECTS | MUSFLAG_SONGS, 0);
//                 }
//             }
//             else if (!s3 && D_800AF5F0 != -1)
//             {
//                 outMesg[0] = 1;
//                 s3 = 1;
//                 osSendMesg(&D_800180A0, outMesg, OS_MESG_NOBLOCK);
//                 continue;
//             }
//         }
//         if (s2 < D_80017DE0 || 1 < s1 || s3 || D_800AF5F0 != NULL)
//         {
//             continue;
//         }
//         outMesg[0] = 0;
//         if (!s4)
//         {
//             s1++;
//         }
//         s3 = 1;
//         osSendMesg(&D_800180A0, outMesg, OS_MESG_NOBLOCK);
//     }
// }

INCLUDE_ASM(void, "rocket/codeseg0/codeseg0", thread6_unk, void *);

void func_8001DE00(void);
void func_80041908(void);
void func_800638EC(s32);
void func_800954FC(void);
void func_8008FC1C(void);

void func_80061C18(void);
void func_80099A34(void);

void read_controller_noblock(void);
void func_80046CBC(void);
void func_80037E60(void *, s32);
void func_8007F22C(void *);

void func_80075100(f32);
void func_80074ADC(void *, f32);
void func_8004ED04(void);
void func_8004E60C(void);



extern f32 D_80000500; // 1.0f / 6.0f

// TODO float load
// void func_80001248(void *arg0)
// {
//     f32 f20;
//     s16 sp10[2];
//     s32 *sp18; // OSMesg

//     func_8001DE00();
//     func_80041908();
//     func_800638EC(0);
//     sp10[0] = 0xFF;
//     osSendMesg(&D_80017DE4, &sp10, OS_MESG_BLOCK);
//     f20 = D_80000500;
//     while (1)
//     {
//         osRecvMesg(&D_800180A0, &sp18, OS_MESG_BLOCK);
//         if (sp18[0] != 0)
//         {
//             if (sp18[0] == 1)
//             {
//                 func_800954FC();
//             }
//         }
//         else
//         {
//             func_8008FC1C();
//             if (gControllerData.buttonHeld)
//             {
//                 func_80099A34();
//             }
//             func_80061C18();
//             if (sp18[2] == 0)
//             {
//                 read_controller_noblock();
//                 func_80046CBC();
//                 func_80037E60(&D_8009FE10, sp18[1]);
//                 func_8007F22C(&D_8009F094);
//             }
//             func_80075100(sp18[1] * f20);
//             func_80074ADC(&D_800AB9C8, sp18[1] * f20);
//             func_8004ED04();
//             func_8004E60C();
//         }
//         sp10[0] = 0xFF;
//         osSendMesg(&D_80017DE4, &sp10, OS_MESG_BLOCK);
//     }
//     return;
// }

INCLUDE_ASM(void, "rocket/codeseg0/codeseg0", func_80001248, void*);

void create_scheduler()
{
    s32 tmp;

    osCreateMesgQueue(&D_80017DFC, &D_800BA0C8, 1);
    osCreateMesgQueue(&D_80017DE4, D_800B9D70, 8);
    switch (osTvType)
    {
        case OS_TV_PAL:
            tmp = OS_VI_PAL_LAN1;
            break;
        case OS_TV_NTSC:
            tmp = OS_VI_NTSC_LAN1;
            break;
        default:
            tmp = OS_VI_MPAL_LAN1;
            break;
    }
    osCreateScheduler(&gScheduler, &gSchedStack[OS_SC_STACKSIZE], 0xf, tmp, 1);
    osScAddClient(&gScheduler, &D_800BC0D0, &D_80017DE4);
    gSchedMesgQueue = osScGetCmdQ(&gScheduler);
    return;
}

// INCLUDE_ASM(s32, "rocket/codeseg0/codeseg0", create_scheduler);
