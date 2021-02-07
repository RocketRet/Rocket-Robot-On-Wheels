#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "codeseg1/codeseg1_102", __osException);

INCLUDE_ASM(s32, "codeseg1/codeseg1_102", send_mesg);

INCLUDE_ASM(s32, "codeseg1/codeseg1_102", __osEnqueueAndYield);

INCLUDE_ASM(s32, "codeseg1/codeseg1_102", __osEnqueueThread);

INCLUDE_ASM(s32, "codeseg1/codeseg1_102", __osPopThread);

INCLUDE_ASM(s32, "codeseg1/codeseg1_102", __osDispatchThread);
