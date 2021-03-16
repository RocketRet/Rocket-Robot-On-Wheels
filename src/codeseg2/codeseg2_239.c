#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_239", func_80065FF0);

struct unkfunc_80066038 {
    u8 padding[0x238];
    struct unkfunc_80066038_2 *unk238;
};

struct unkfunc_80066038_2 {
    u8 padding[0x278];
    s32 unk278;
};

void func_80066038(struct unkfunc_80066038 *arg0)
{
    func_80083734(arg0);
    arg0->unk238->unk278 = arg0;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_239", func_80066068);

extern f32 D_8009FE14;

struct unkfunc_800660F8 {
    u8 padding[0x230];
    s32 unk230;
    f32 unk234;
};

// TODO reorder
// void func_800660F8(struct unkfunc_800660F8 *arg0, s32 arg1)
// {
//     if (arg1 != arg0->unk230)
//     {
//         arg0->unk230 = arg1;
//         arg0->unk234 = D_8009FE14;
//     }
// }

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_239", func_800660F8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_239", func_80066118);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_239", func_80066154);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_239", func_8006625C);
