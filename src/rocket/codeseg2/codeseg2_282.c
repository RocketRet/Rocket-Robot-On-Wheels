#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_8006FD50 {
    u8 padding[0xAC];
    u32 unkAC;
};

void func_80087554();

void func_8006FD50(struct unkfunc_8006FD50 *arg0)
{
    arg0->unkAC = -1;
    func_80087554();
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_282", func_8006FD74);
