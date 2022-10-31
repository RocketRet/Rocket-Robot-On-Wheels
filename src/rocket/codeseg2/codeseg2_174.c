#include <include_asm.h>
#include <ultra64.h>

void func_80084A88(s32*);

struct unkfunc_8004F6D0 {
    u8 pad[0x290];
    s32 unk290;
};

void func_8004F6D0(struct unkfunc_8004F6D0 *arg0)
{
    func_80084A88(&arg0->unk290);
}
