#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "codeseg1/sched", osCreateScheduler);

INCLUDE_ASM(s32, "codeseg1/sched", osScAddClient);

INCLUDE_ASM(s32, "codeseg1/sched", osScRemoveClient);

s32 osScGetCmdQ(s32 arg0) {
    return arg0 + 0x78;
}

INCLUDE_ASM(s32, "codeseg1/sched", __scMain);

INCLUDE_ASM(s32, "codeseg1/sched", __scHandleRetrace);

INCLUDE_ASM(s32, "codeseg1/sched", __scHandleRSP);

INCLUDE_ASM(s32, "codeseg1/sched", __scHandleRDP);

INCLUDE_ASM(s32, "codeseg1/sched", __scTaskReady);

INCLUDE_ASM(s32, "codeseg1/sched", __scTaskComplete);

INCLUDE_ASM(s32, "codeseg1/sched", __scAppendList);

INCLUDE_ASM(s32, "codeseg1/sched", __scExec);

INCLUDE_ASM(s32, "codeseg1/sched", __scYield);

INCLUDE_ASM(s32, "codeseg1/sched", __scSchedule);
