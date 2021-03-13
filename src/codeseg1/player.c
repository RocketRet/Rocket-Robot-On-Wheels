#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "codeseg1/player", __MusIntMain);

INCLUDE_ASM(s32, "codeseg1/player", __MusIntGetNewNote);

INCLUDE_ASM(s32, "codeseg1/player", __MusIntFlushPending);

INCLUDE_ASM(s32, "codeseg1/player", __MusIntSetVolumeAndPan);

INCLUDE_ASM(s32, "codeseg1/player", __MusIntSetPitch);

INCLUDE_ASM(s32, "codeseg1/player", __MusIntInitEnvelope);

INCLUDE_ASM(s32, "codeseg1/player", __MusIntProcessEnvelope);

INCLUDE_ASM(s32, "codeseg1/player", __MusIntInitSweep);

INCLUDE_ASM(s32, "codeseg1/player", __MusIntProcessSweep);

INCLUDE_ASM(s32, "codeseg1/player", __MusIntProcessWobble);

INCLUDE_ASM(s32, "codeseg1/player", __MusIntProcessVibrato);

INCLUDE_ASM(s32, "codeseg1/player", __MusIntProcessContinuousVolume);

INCLUDE_ASM(s32, "codeseg1/player", __MusIntProcessContinuousPitchBend);

INCLUDE_ASM(s32, "codeseg1/player", __MusIntPowerOf2);

INCLUDE_ASM(s32, "codeseg1/player", __MusIntRemapPtrBank);

INCLUDE_ASM(s32, "codeseg1/player", __MusIntRandom);

INCLUDE_ASM(s32, "codeseg1/player", __MusIntInitialiseChannel);

INCLUDE_ASM(s32, "codeseg1/player", __MusIntFindChannel);

INCLUDE_ASM(s32, "codeseg1/player", __MusIntRemapPtrs);

INCLUDE_ASM(s32, "codeseg1/player", __MusIntStartEffect);

INCLUDE_ASM(s32, "codeseg1/player", __MusIntFindChannelAndStart);

INCLUDE_ASM(s32, "codeseg1/player", __MusIntStartSong);

INCLUDE_ASM(s32, "codeseg1/player", __MusIntHandleSetFlag);
