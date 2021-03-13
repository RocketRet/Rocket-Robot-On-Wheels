#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(void, "codeseg1/codeseg1_10", osCreateThread, OSThread *, OSId, void (*)(void *), void *, void *, OSPri);
