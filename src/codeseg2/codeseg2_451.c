#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "codeseg2/codeseg2_451", func_8009DC20);

struct unkfunc_8009DC84 {
    u8 padding[0x26C];
    s8 unk26C;
};

void func_8009DC84(struct unkfunc_8009DC84 *arg0)
{
    arg0->unk26C = 0;
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_451", func_8009DC8C);

INCLUDE_ASM(s32, "codeseg2/codeseg2_451", func_8009DD38);

extern s32 D_800AF838;

void func_8009DE1C(s32 arg0)
{
    func_80050E24(arg0, 1, &D_800AF838);
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_451", func_8009DE44);
