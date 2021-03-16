#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "lib/codeseg1/codeseg1_74", osContStartReadData);

INCLUDE_ASM(void, "lib/codeseg1/codeseg1_74", osContGetReadData, OSContPad *);

INCLUDE_ASM(s32, "lib/codeseg1/codeseg1_74", __osPackReadData);
