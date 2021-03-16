#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(void, "lib/codeseg1/codeseg1_209", alSynNew, ALSynth *s, ALSynConfig *config);

INCLUDE_ASM(Acmd *, "lib/codeseg1/codeseg1_209", alAudioFrame, Acmd *cmdList, s32 *cmdLen, s16 *outBuf, s32 outLen);

INCLUDE_ASM(s32, "lib/codeseg1/codeseg1_209", __allocParam);

INCLUDE_ASM(s32, "lib/codeseg1/codeseg1_209", __freeParam);
