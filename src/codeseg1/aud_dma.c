#include <include_asm.h>
#include <ultra64.h>

INCLUDE_ASM(s32, "lib/codeseg1/aud_dma", __MusIntDmaInit);

INCLUDE_ASM(s32, "lib/codeseg1/aud_dma", __MusIntDmaProcess);

void __CallBackDmaProcess();

void *__CallBackDmaNew()
{
    return __CallBackDmaProcess;
}

INCLUDE_ASM(void, "lib/codeseg1/aud_dma", __CallBackDmaProcess);

INCLUDE_ASM(s32, "lib/codeseg1/aud_dma", __MusIntDmaSample);
