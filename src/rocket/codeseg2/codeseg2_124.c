#include <include_asm.h>
#include <ultra64.h>

u32 func_80042A50(s32 arg0, u16 *arg1) {
    return (arg1[6] & 0xfff) & (1ULL << arg0);
}
