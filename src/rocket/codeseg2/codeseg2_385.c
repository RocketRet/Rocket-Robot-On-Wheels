#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_8008CB60 {
    u8 padding[0x34];
    u32 unk34;
};

void func_8008CB60(struct unkfunc_8008CB60 *arg0, s32 arg1)
{
    arg0->unk34 = arg1;
}

// TODO are these really the same struct?
void func_8008CB68(struct unkfunc_8008CB60 *arg0, s32 arg1)
{
    arg0->unk34 = 0;
}
