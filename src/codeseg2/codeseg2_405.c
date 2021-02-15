#include <include_asm.h>
#include <ultra64.h>
#include <types.h>


INCLUDE_ASM(s32, "codeseg2/codeseg2_405", func_80092050);

INCLUDE_ASM(s32, "codeseg2/codeseg2_405", func_80092094);

// wip
// Gfx *func_800922C4(struct unkD_800ADAD0 *arg0, s32 arg1)
// {
//     u8 var[1024];
//     func_800926B8(var, arg0);
// }

INCLUDE_ASM(s32, "codeseg2/codeseg2_405", func_800922C4);

INCLUDE_ASM(s32, "codeseg2/codeseg2_405", func_800923E8);

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

INCLUDE_ASM(s32, "codeseg2/codeseg2_405", func_800926B8);

INCLUDE_ASM(s32, "codeseg2/codeseg2_405", func_80093DDC);

INCLUDE_ASM(s32, "codeseg2/codeseg2_405", func_80093F48);
