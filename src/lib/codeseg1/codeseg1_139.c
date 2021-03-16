#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "lib/codeseg1/codeseg1_139", __osTimerServicesInit);

INCLUDE_ASM(s32, "lib/codeseg1/codeseg1_139", __osTimerInterrupt);
