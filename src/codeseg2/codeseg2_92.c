#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "codeseg2/codeseg2_92", func_80038630);

INCLUDE_ASM(s32, "codeseg2/codeseg2_92", func_800387E8);

INCLUDE_ASM(s32, "codeseg2/codeseg2_92", func_80038DC4);

INCLUDE_ASM(s32, "codeseg2/codeseg2_92", func_800390BC);

struct unkfunc_8003918C {
    u8 padding[0x254];
    u32 unk254;
};

void func_8003918C(struct unkfunc_8003918C *arg0)
{
    func_8004BB64(&arg0->unk254);
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_92", func_800391AC);

void func_800391EC(struct unkfunc_8003918C *arg0)
{
    func_8004C44C(&arg0->unk254);
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_92", func_8003920C);
