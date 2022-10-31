#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_8007F580 {
    u8 padding[0x25C];
    s32 unk25C;
};

void func_8007F580(struct unkfunc_8007F580*);

void func_80020C20(struct unkfunc_8007F580 *arg0)
{
    func_8007F580(arg0);
    arg0->unk25C = -1;
}
