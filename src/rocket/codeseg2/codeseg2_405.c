#include <include_asm.h>
#include <ultra64.h>
#include <types.h>


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_405", func_80092050);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_405", func_80092094);

struct unkfunc_800922C4 {
    u32 *unk0;
    u8 *unk4;
    u8 *unk8;
    u32 unkC;
};

// wip
// Gfx *func_800922C4(struct unkD_800ADAD0 *arg0, s32 arg1)
// {
//     u8 var[0x400];
//     u32 var2;
//     struct unkfunc_800922C4 var3;

//     var3.unkC = sizeof(var);
//     var3.unk0 = &var2;
//     var3.unk4 = var3.unk8 = var;

//     func_800926B8(&var3, arg0);
//     arg0->unk4 = ((u32)var3.unk8 - (u32)var3.unkC) / 8;

//     if (arg0 ||
//         (u32)arg0->unk0 & 0xF0000000 == 0x80000000 ||
//         )
//     {

//     }
// }

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_405", func_800922C4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_405", func_800923E8);

// wip long function
// void func_800926B8(s32 arg0, struct unkD_800ADAD0 *arg1, s32 *arg2)
// {
//     gDPPipeSync(arg1->unk8++);
//     if ((*arg2 & 0xF0000000) == 0)
//     {
//         gDPSetCombineMode(arg1->unk8++, G_CC_SHADE, G_CC_SHADE);
//         gDPSetCombineLERP(arg1->unk8++, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, COMBINED, COMBINED, 0, PRIMITIVE, 0);
//         gSPSetGeometryMode(arg1->unk8++, G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
//         gSPTexture(arg1->unk8++, 0x0000, 0x0000, 0, G_TX_RENDERTILE, G_OFF);
//     }
//     else
//     {

//     }
//     gSPEndDisplayList(arg1->unk8++);
// }

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_405", func_800926B8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_405", func_80093DDC);

void func_80093F48(s32 arg0, s32 arg1, s32 *arg2)
{
    func_80061740(arg0, arg2[4], arg2[2]);
}
