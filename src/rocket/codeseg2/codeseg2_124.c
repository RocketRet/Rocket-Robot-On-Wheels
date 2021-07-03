#include <include_asm.h>
#include <ultra64.h>

// Right instructions, but wrong branch opcode
#ifdef NON_MATCHING
u32 func_80042A50(s32 arg0, u16 *arg1) {
    return (arg1[6] & 0xfff) & (1ULL << arg0);
}
#else
INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_124", func_80042A50);
#endif
