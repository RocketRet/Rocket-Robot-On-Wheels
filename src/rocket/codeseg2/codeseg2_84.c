#include <include_asm.h>
#include <ultra64.h>

void func_80036300(s32 **arg0)
{
    func_8003B89C(arg0[1], arg0[1][0x79] + 0x134);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_84", func_80036328);

struct unkfunc_800364F8_sub8 {
    u8 padding[0x134];
    s32 unk134;
};

struct unkfunc_800364F8 {
    s32 unk0;
    s32 unk4;
    struct unkfunc_800364F8_sub8 *unk8;
};

void func_800364F8(struct unkfunc_800364F8 *arg0)
{
    func_8003B89C(arg0->unk4, &arg0->unk8->unk134);
}
