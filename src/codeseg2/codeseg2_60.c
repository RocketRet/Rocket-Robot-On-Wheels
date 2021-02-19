#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "codeseg2/codeseg2_60", func_8002E480);

extern f32 D_8009FE14;

struct unkfunc_8002E4E4 {
    u8 padding[0x244];
    f32 unk244;
    s32 unk248;
};

// TODO reorder
// void func_8002E4E4(struct unkfunc_8002E4E4 *arg0, s32 arg1)
// {
//     if (arg1 != arg0->unk248)
//     {
//         arg0->unk248 = arg1;
//         arg0->unk244 = D_8009FE14;
//     }
// }

INCLUDE_ASM(s32, "codeseg2/codeseg2_60", func_8002E4E4);

INCLUDE_ASM(s32, "codeseg2/codeseg2_60", func_8002E504);
