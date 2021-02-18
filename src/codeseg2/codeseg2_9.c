#include <include_asm.h>
#include <ultra64.h>

struct s32_3 {
    s32 a;
    s32 b;
    s32 c;
};

struct unkfunc_8001FBB0 {
    u8 padding[0x84];
    struct s32_3 unk84;
};

void func_8001FD30();

void func_8001FBB0(struct unkfunc_8001FBB0 *param_1,struct s32_3 *param_2)
{
    param_1->unk84 = *param_2;
    func_8001FD30();
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_9", func_8001FBE8);

INCLUDE_ASM(s32, "codeseg2/codeseg2_9", func_8001FC1C);
