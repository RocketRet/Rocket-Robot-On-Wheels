#include <include_asm.h>
#include <ultra64.h>

void osSpTaskYield(void)
{
    __osSpSetStatus(SP_SET_YIELD);
}

