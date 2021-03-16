#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_234", func_800642D0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_234", func_8006432C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_234", func_800643B4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_234", func_8006459C);

struct unkfunc_80064758 {
    u8 padding[0x10];
    s32 unk10;
    u8 padding2[0x260 - 0x10 - 0x04];
    s32 unk260;
};

void func_80064758(struct unkfunc_80064758 *arg0)
{
    arg0->unk260 = arg0->unk10;
    func_800824A0();
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_234", func_8006477C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_234", func_80064848);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_234", func_80064958);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_234", func_800649C8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_234", func_80064A48);
