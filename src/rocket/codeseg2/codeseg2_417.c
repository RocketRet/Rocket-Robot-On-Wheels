#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_80095D70 {
    u8 padding[0x264];
    s32 unk264;
};

void func_80095D70(struct unkfunc_80095D70 *arg0, s32 arg1)
{
    arg0->unk264 = arg1;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_417", func_80095D78);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_417", func_80095DB0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_417", func_80095DF4);

void func_80095E64()
{
    func_80096290();
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_417", func_80095E84);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_417", func_80096058);

INCLUDE_ASM(void, "rocket/codeseg2/codeseg2_417", func_80096290);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_417", func_800962D4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_417", func_8009631C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_417", func_80096388);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_417", func_80096444);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_417", func_800966C8);
