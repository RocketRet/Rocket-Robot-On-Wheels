#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "codeseg2/codeseg2_453", func_8009E1B0);

INCLUDE_ASM(s32, "codeseg2/codeseg2_453", func_8009E5EC);

INCLUDE_ASM(s32, "codeseg2/codeseg2_453", func_8009E6D4);

INCLUDE_ASM(s32, "codeseg2/codeseg2_453", func_8009E7CC);

extern f32 D_8009FE14;

struct unkfunc_8009E84C {
    u8 padding[0x18];
    s32 unk18;
    f32 unk1C;
};

// TODO reorder
// void func_8009E84C(struct unkfunc_8009E84C *arg0, s32 arg1)
// {
//     if (arg1 != arg0->unk18)
//     {
//         arg0->unk18 = arg1;
//         arg0->unk1C = D_8009FE14;
//     }
// }

INCLUDE_ASM(s32, "codeseg2/codeseg2_453", func_8009E84C);

INCLUDE_ASM(s32, "codeseg2/codeseg2_453", func_8009E86C);

INCLUDE_ASM(s32, "codeseg2/codeseg2_453", func_8009E9B4);
