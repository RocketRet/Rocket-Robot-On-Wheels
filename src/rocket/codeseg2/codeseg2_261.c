#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_8006B430 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};

void func_8006B430(struct unkfunc_8006B430 *arg0, s32 arg1)
{
    func_8001FDB4(arg0->unk10, 0, &arg0->unk18, arg1);
}
