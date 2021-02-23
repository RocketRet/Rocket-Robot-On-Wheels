#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_80037EC0 {
    s32 unk0;
    s32 unk4;
};

void func_80037EC0(struct unkfunc_80037EC0 *arg0, s32 arg1)
{
    arg0->unk4 = arg1;
}

void func_80037EC8(s32 *arg0, s32 arg1)
{
    *arg0 = arg1;
    if (arg1 == 0)
    {
        func_8004EC70();
    }
}
