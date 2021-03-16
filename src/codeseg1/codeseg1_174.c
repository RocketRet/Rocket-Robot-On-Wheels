#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(void, "lib/codeseg1/codeseg1_174", alInit, ALGlobals *glob, ALSynConfig *c);

INCLUDE_ASM(void, "lib/codeseg1/codeseg1_174", alClose, ALGlobals *glob);

INCLUDE_ASM(void, "lib/codeseg1/codeseg1_174", alLink, ALLink *element, ALLink *after);

INCLUDE_ASM(void, "lib/codeseg1/codeseg1_174", alUnlink, ALLink *element);
