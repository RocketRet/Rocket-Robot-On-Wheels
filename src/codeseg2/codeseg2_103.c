#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_8003CBD0 {
    u8 padding[0x230];
    f32 unk230;
};

extern f32 D_8001AE90;

// TODO float load
// void func_8003CBD0(struct unkfunc_8003CBD0 *arg0)
// {
//     func_800263B4();
//     arg0->unk230 = D_8001AE90;    
// }

INCLUDE_ASM(s32, "codeseg2/codeseg2_103", func_8003CBD0);

INCLUDE_ASM(s32, "codeseg2/codeseg2_103", func_8003CC04);
