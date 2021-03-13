#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(void, "codeseg1/codeseg1_75", osSetEventMesg, OSEvent, OSMesgQueue *, OSMesg);
