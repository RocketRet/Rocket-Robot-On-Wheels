#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_80063B70 {
    u8 padding[0x1A8];
    s32 unk1A8;
    s32 unk1AC;
    s32 unk1B0;
    s32 unk1B4;
    s32 unk1B8;
};

void func_80063B70(struct unkfunc_80063B70 *arg0)
{
    func_8007F580();
    arg0->unk1A8 = 3;
    arg0->unk1B8 = 3;
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_233", func_80063BA4);

INCLUDE_ASM(s32, "codeseg2/codeseg2_233", func_80063C84);

INCLUDE_ASM(s32, "codeseg2/codeseg2_233", func_80063D58);

INCLUDE_ASM(s32, "codeseg2/codeseg2_233", func_80063E0C);

INCLUDE_ASM(s32, "codeseg2/codeseg2_233", func_80063F64);

INCLUDE_ASM(s32, "codeseg2/codeseg2_233", func_80063FE4);

INCLUDE_ASM(s32, "codeseg2/codeseg2_233", func_8006409C);

INCLUDE_ASM(s32, "codeseg2/codeseg2_233", func_8006424C);

INCLUDE_ASM(s32, "codeseg2/codeseg2_233", func_80064294);
