#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_800841C4 {
    u8 padding[0x22C];
    s32 unk22C;
};

void func_80084410(struct unkfunc_800841C4 *arg0)
{
    arg0->unk22C |= 0x00100000;
}

void func_80084424(struct unkfunc_800841C4 *arg0)
{
    arg0->unk22C &= ~0x00100000;
}

void func_8008443C(struct unkfunc_800841C4 *arg0)
{
    arg0->unk22C |= 0x00008000;
}

void func_8008444C(struct unkfunc_800841C4 *arg0)
{
    arg0->unk22C |= 0x00004000;
}

void func_8008445C(struct unkfunc_800841C4 *arg0)
{
    arg0->unk22C &= ~0x00004000;
}
