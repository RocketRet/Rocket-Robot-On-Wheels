#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_80045810 {
    u8 padding[0x234];
    u32 unk234;
};

void func_80045810(struct unkfunc_80045810 *arg0, s32 arg1, u8 *dataPtr)
{
    arg0->unk234 = 3;
    func_800875E8(arg0, arg1, dataPtr);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_140", func_80045834);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_140", func_800458E4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_140", func_80045A54);
