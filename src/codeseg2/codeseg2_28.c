#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_800261B0 {
    u8 padding[0x18];
    s32 unk18;
    s32 unk1C[8]; // TODO real array length
};

void func_800261B0(struct unkfunc_800261B0 *arg0, s32 arg1)
{
    // index[array] again
    arg0->unk18++[arg0->unk1C] = arg1;
}
