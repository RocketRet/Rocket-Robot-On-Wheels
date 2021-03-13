#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "codeseg1/codeseg1_74", osContStartReadData);

INCLUDE_ASM(void, "codeseg1/codeseg1_74", osContGetReadData, OSContPad *);

INCLUDE_ASM(s32, "codeseg1/codeseg1_74", __osPackReadData);
