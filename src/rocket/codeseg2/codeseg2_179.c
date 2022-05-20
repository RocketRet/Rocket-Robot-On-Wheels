#include <include_asm.h>
#include <ultra64.h>

#include "codeseg2.h"

s32 func_80050860(s32 arg0) {
    return arg0;
}

void func_80050868(struct unkfunc_8001DFD0* arg0, void* arg1, void* arg2) {
    arg0->unk4 = 0;
    arg0->unkC = arg1;
    arg0->unk10 = arg2;
    arg0->unk8 = -1;
    func_8008C148(arg1, arg0);
}

s32 func_800508A4()
{
    return 0;
}

s32 func_800508AC()
{
    return 0;
}

struct unkfunc_800508B4 {
    u8 padding[0x10];
    struct unkfunc_800508B4 *unk10;
};

s32 func_800508B4(struct unkfunc_800508B4 *arg0)
{
    while (arg0->unk10)
    {
        arg0 = arg0->unk10;
    }
    return arg0;
}

s32 func_800508D8(struct unkfunc_800508B4 *arg0, struct unkfunc_800508B4 *arg1)
{
    while (arg0)
    {
        if (arg0 == arg1)
        {
            return 1;
        }
        arg0 = arg0->unk10;
    }
    return 0;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_179", func_800508FC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_179", func_80050948);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_179", func_8005098C);
