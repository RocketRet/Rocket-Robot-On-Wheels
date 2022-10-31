#include <include_asm.h>
#include <ultra64.h>
#include "types.h"

struct unkfunc_8006B430 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};

void func_8001FDB4(struct GameObject *arg0, struct GameObject *arg1, Vec3f arg2, Vec3f arg3);

void func_8006B430(struct GameObject *arg0, Vec3f arg1)
{
    func_8001FDB4(arg0->unk10, 0, arg0->rotation[0], arg1);
}
