#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "lib/codeseg1/aud_thread", __MusIntAudManInit);

INCLUDE_ASM(s32, "lib/codeseg1/aud_thread", __MusIntThreadProcess);
