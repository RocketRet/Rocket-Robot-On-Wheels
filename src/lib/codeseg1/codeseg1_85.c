#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(void, "lib/codeseg1/codeseg1_85", osCreateViManager, OSPri);

INCLUDE_ASM(s32, "lib/codeseg1/codeseg1_85", viMgrMain);
