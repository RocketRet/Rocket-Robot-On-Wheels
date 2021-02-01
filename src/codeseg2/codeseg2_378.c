#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_80088980 {
    u8 padding[0x16];
    s16 unk16;
};

void func_80088980(struct unkfunc_80088980 *arg0, s16 arg1)
{
    arg0->unk16 = arg1;
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_378", func_80088988);

INCLUDE_ASM(s32, "codeseg2/codeseg2_378", func_80088994);

INCLUDE_ASM(s32, "codeseg2/codeseg2_378", func_800889B8);

INCLUDE_ASM(s32, "codeseg2/codeseg2_378", func_80089D5C);

INCLUDE_ASM(s32, "codeseg2/codeseg2_378", func_80089F18);

INCLUDE_ASM(s32, "codeseg2/codeseg2_378", func_8008AAEC);
