#include <include_asm.h>
#include <ultra64.h>
#include <types.h>

void func_8002E440(struct unkfunc_8009C28C *arg0, s32 arg1)
{
    // index[array] again
    arg0->unk324++[arg0->unk328] = arg1;
}

struct unkfunc_8002E45C {
    u8 padding[0x240];
    s32 unk240;
};

void func_8002E45C(struct unkfunc_8002E45C *arg0, s32 arg1, u8 *dataPtr)
{
    arg0->unk240 = 0xC7;
    func_800875E8(arg0, arg1, dataPtr);
}
