#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_8002C154 {
    u8 padding[0x230];
    u32 unk230;
    f32 unk234;
};

extern f32 D_8009FE14;

INCLUDE_ASM(s32, "codeseg2/codeseg2_49", func_8002C120);

// TODO reordering
// void func_8002C154(struct unkfunc_8002C154 *arg0, s32 arg1)
// {
//     if (arg1 != arg0->unk230)
//     {
//         arg0->unk230 = arg1;
//         arg0->unk234 = D_8009FE14;
//     }
// }

INCLUDE_ASM(s32, "codeseg2/codeseg2_49", func_8002C154);

INCLUDE_ASM(s32, "codeseg2/codeseg2_49", func_8002C174);

INCLUDE_ASM(s32, "codeseg2/codeseg2_49", func_8002C25C);
