#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_80091060
{
    u8 padding[0x38];
    f32 unk38;
};

void func_80091060(struct unkfunc_80091060 *arg0, f32 arg1)
{
    arg0->unk38 = arg1;
}

struct unkfunc_80091068
{
    s32 unk0;
    s32 unk4;
};

void func_80091068(struct unkfunc_80091068 *arg0, s32 arg1)
{
    arg0->unk4 = arg1;
}
