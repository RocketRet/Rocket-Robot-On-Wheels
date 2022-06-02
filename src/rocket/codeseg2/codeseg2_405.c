#include <include_asm.h>
#include <ultra64.h>
#include <types.h>
#include <mem.h>
#include <materials.h>

#include "codeseg2.h"

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

extern struct MaterialGfx *D_800AF4F8;

void func_80092094(struct MaterialGfx*);

void func_80092050(void) {
    struct MaterialGfx *material;

    material = D_800AF4F8;
    while (material != 0) {
        func_80092094(material);
        material = *material->unkC;
    }
}

INCLUDE_ASM(void, "rocket/codeseg2/codeseg2_405", func_80092094, struct MaterialGfx*);


// wip
// Gfx *func_800922C4(struct MaterialGfx *arg0, u32 arg1)
// {
//     Gfx var[0x80];
//     struct unkfunc_800922C4 var3;

//     var3.unk0 = sizeof(var);
//     var3.unk4 = var3.unk8 = var;

//     func_800926B8(&var3, arg0);
//     arg0->gfxCount = ((u32)var3.unk8 - (u32)var3.unk4) / sizeof(Gfx);

//     if (arg0 ||
//      0x80000000 != arg0->materialData & 0xF0000000) ||
//      arg0->materialData->unk16 ||
//      arg0->materialData->unk18 ||
//      arg0->materialData->unk1C) {
//         u8 *mem = main_alloc_bzero(0x1C);
//         arg0->unkC = mem;
//         D_800AAF80.unk4 += arg0->gfxCount;
//         arg0->unk8 = D_800AAF80.unk4 - arg0->gfxCount + 0x200000;


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
// creates a displaylist from a material (textured or solid)
// void func_800926B8(s32 arg0, struct MaterialGfx *arg1, s32 *arg2)
// {
//     gDPPipeSync(arg1->gfx++);
//     if ((*arg2 & 0xF0000000) == 0)
//     {
//         gDPSetCombineMode(arg1->gfx++, G_CC_SHADE, G_CC_SHADE);
//         gDPSetCombineLERP(arg1->gfx++, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, COMBINED, COMBINED, 0, PRIMITIVE, 0);
//         gSPSetGeometryMode(arg1->gfx++, G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
//         gSPTexture(arg1->gfx++, 0x0000, 0x0000, 0, G_TX_RENDERTILE, G_OFF);
//     }
//     else
//     {

//     }
//     gSPEndDisplayList(arg1->gfx++);
// }

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_405", func_800926B8);

extern struct MaterialGfx *materialTable;

static inline struct unkfunc_80093DDC unk_inline_func_80093DDC() {
    struct unkfunc_80093DDC ret;

    ret.unk0_0 = 2;
    ret.unk0_4 = 1;
    ret.unk1 = 1;
    ret.unk2 = 1;
    ret.unk3 = unk_parse_struct_unkfunc_80093DDC(ret);
    
    return ret;
}

static inline struct unkfunc_80093DDC unk_inline_func_80093DDC2() {
    struct unkfunc_80093DDC ret;

    ret = unk_inline_func_80093DDC();

    return ret;
}

struct unkfunc_80093DDC *func_80093DDC(struct unkfunc_80093DDC *arg0, s32 arg1) {
    struct unkfunc_80093DDC sp10;
    struct MaterialGfx *materialGfx;
    struct TexturedMaterial *materialData;

    materialGfx = &materialTable[arg1];
    
    if (!IS_VIRTUAL_ADDRESS(materialTable[arg1].materialData)) {
        sp10 = unk_inline_func_80093DDC2();
    } else {
        materialData = get_material_data(materialGfx);
        sp10 = materialData->header.unk4;
    }
    
    *arg0 = sp10;
    return arg0;
}

void texture_handler_copy(u32 assetAddress, UNUSED struct TextureCompressionHeader *header, struct Texture *asset)
{
    dma_read(assetAddress, asset->imageData, asset->header.imageBytes);
}
