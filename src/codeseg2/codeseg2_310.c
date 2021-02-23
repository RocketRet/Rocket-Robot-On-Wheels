#include <include_asm.h>
#include <ultra64.h>

void func_80077BD0(s32 *arg0)
{
    arg0[4] = -1;
    func_80078170(arg0, 0);
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_310", func_80077BF8);

INCLUDE_ASM(s32, "codeseg2/codeseg2_310", func_80077C6C);

INCLUDE_ASM(s32, "codeseg2/codeseg2_310", func_80077CCC);

INCLUDE_ASM(s32, "codeseg2/codeseg2_310", func_80077F0C);
