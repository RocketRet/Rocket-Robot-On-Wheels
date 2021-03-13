#include <include_asm.h>
#include <ultra64.h>

// TODO libultra compiler
// u32 osPiGetStatus()
// {
//     return IO_READ(PI_STATUS_REG);
// }

INCLUDE_ASM(u32, "codeseg1/codeseg1_7", osPiGetStatus, void);
