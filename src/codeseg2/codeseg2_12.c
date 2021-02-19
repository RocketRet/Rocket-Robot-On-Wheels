#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "codeseg2/codeseg2_12", func_80020050);

INCLUDE_ASM(s32, "codeseg2/codeseg2_12", func_800200F4);

INCLUDE_ASM(s32, "codeseg2/codeseg2_12", func_80020134);

struct unkD_8009F400 {
    u8 padding[24];
};

extern struct unkD_8009F400 D_8009F400[];

struct unkD_8009F400 *func_80020714(s32 arg0)
{
    return &D_8009F400[arg0];
}
