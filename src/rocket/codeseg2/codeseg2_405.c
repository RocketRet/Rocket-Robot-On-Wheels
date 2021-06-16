#include <include_asm.h>
#include <ultra64.h>
#include <types.h>
#include <mem.h>


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_405", func_80092050);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_405", func_80092094);

struct unkfunc_800922C4 {
    u32 *unk0;
    Gfx *unk4;
    Gfx *unk8;
};

extern struct {
    u32 unk0;
    Gfx *unk4;
    Gfx *unk8;
} D_800AAF80;

extern struct unkD_800ADAD0 *D_800AF4F8;

// wip
// Gfx *func_800922C4(struct unkD_800ADAD0 *arg0, u32 arg1)
// {
//     Gfx var[0x80];
//     struct unkfunc_800922C4 var3;

//     var3.unk0 = sizeof(var);
//     var3.unk4 = var3.unk8 = var;

//     func_800926B8(&var3, arg0);
//     arg0->unk4 = ((u32)var3.unk8 - (u32)var3.unk4) / sizeof(Gfx);

//     if (arg0 ||
//      0x80000000 != (((u32)arg0->unk0) & 0xF0000000) ||
//      arg0->unk0->unk16 ||
//      arg0->unk0->unk18 ||
//      arg0->unk0->unk1C) {
//         u8 *mem = main_alloc_bzero(0x1C);
//         arg0->unkC = mem;
//         D_800AAF80.unk4 += arg0->unk4;
//         arg0->unk8 = D_800AAF80.unk4 - arg0->unk4 + 0x200000;


//         {
//             void *val2 = D_800AF4F8;
//             D_800AF4F8 = arg0;
//             arg0->unkC->unk0 = val2;
//         }
//         arg0->unk4 = arg1 == 0;

//         // arg0->unkC->unk0 = D_800AF4F8;
//         // D_800AF4F8 = arg0->unk0;

//     } else {
//         arg0->unk8 = main_alloc_copy(arg0->unk4 * sizeof(Gfx), val);
//     }
//     return arg0->unk8;
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

void asset_handler_copy(u32 assetAddress, UNUSED struct AssetHandlerHeader *header, struct Asset *asset)
{
    dma_read(assetAddress, asset->data1, asset->header.data1Len);
}
