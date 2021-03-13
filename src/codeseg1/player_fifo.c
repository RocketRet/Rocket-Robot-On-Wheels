#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "codeseg1/player_fifo", __MusIntFifoOpen);

INCLUDE_ASM(s32, "codeseg1/player_fifo", __MusIntFifoProcess);

INCLUDE_ASM(s32, "codeseg1/player_fifo", __MusIntFifoProcessCommand);

INCLUDE_ASM(s32, "codeseg1/player_fifo", __MusIntFifoAddCommand);
