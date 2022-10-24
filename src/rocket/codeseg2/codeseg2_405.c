#include <include_asm.h>
#include <ultra64.h>
#include "types.h"
#include "mem.h"
#include "materials.h"
#include "macros.h"

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
extern RGBA32 D_800A5398;
extern RGBA32 D_800A539C;

void func_80092094(struct MaterialGfx*);
f32 positive_fmodf(f32, f32);

void func_80092050(void) {
    struct MaterialGfx *material;

    material = D_800AF4F8;
    while (material != 0) {
        func_80092094(material);
        material = material->scrollParams->unk0;
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

INCLUDE_ASM(void, "rocket/codeseg2/codeseg2_405", func_800923E8, void*, void*, s32, s32, s32, s32, s32);

#define MAKE_COMBINER(a, b, c, d, Aa, Ab, Ac, Ad) \
    ({ tempParams = (CombinerParams) {{ G_CCMUX_##a, G_CCMUX_##b, G_CCMUX_##c, G_CCMUX_##d}, {G_ACMUX_##Aa, G_ACMUX_##Ab, G_ACMUX_##Ac, G_ACMUX_##Ad}}; tempParams; })

void func_800926B8(struct unkfunc_800926B8 *arg0, struct MaterialGfx* arg1, s32* arg2) {
    uintptr_t materialValue;

    gDPPipeSync(NEXT_GFX(arg0->unk8));
    materialValue = arg1->materialData.raw;
    
    if (IS_SOLID_COLOR(materialValue)) {
        RGBA32_pad8 diffuseColor;
        RGBA32_pad8 ambientColor;
        
        gDPSetCombineLERP(NEXT_GFX(arg0->unk8), 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, COMBINED, COMBINED, 0, PRIMITIVE, 0)
        gSPSetGeometryMode(NEXT_GFX(arg0->unk8), G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
        gSPTexture(NEXT_GFX(arg0->unk8), 0x0000, 0x0000, 0, G_TX_RENDERTILE, G_OFF)
        diffuseColor.colors.r = (arg1->materialData.color.r * D_800A539C.colors.r) / 256.0f;
        diffuseColor.colors.g = (arg1->materialData.color.g * D_800A539C.colors.g) / 256.0f;
        diffuseColor.colors.b = (arg1->materialData.color.b * D_800A539C.colors.b) / 256.0f;
        diffuseColor.colors.a = 0xFF;
        ambientColor.colors.r = (arg1->materialData.color.r * D_800A5398.colors.r) / 256.0f;
        ambientColor.colors.g = (arg1->materialData.color.g * D_800A5398.colors.g) / 256.0f;
        ambientColor.colors.b = (arg1->materialData.color.b * D_800A5398.colors.b) / 256.0f;
        ambientColor.colors.a = 0xFF;
        gSPLightColor(NEXT_GFX(arg0->unk8), LIGHT_1, *&diffuseColor.rgba32);
        gSPLightColor(NEXT_GFX(arg0->unk8), LIGHT_2, *&ambientColor.rgba32);
    } else {
        CombinerParams cycle1 ALIGNED(8); // Align so that a u64 comparison is safe later
        CombinerParams unused;
        CombinerParams cycle2 ALIGNED(8);
        CombinerParams tempParams;
        s32 baseTextureIndex;
        s32 tileIndex;
        s32 tmemAddress;
        s32 paletteIndex;
        s32 loadedTextureIndex;
        s16 scrollScaleS;
        s16 scrollScaleT;
        f32 scrollSpeedT;
        f32 scrollSpeedS;
        s32 textureScaleT;
        s32 textureScaleS;
        s32 lodLevel;
        s16 tileScrollS;
        s16 tileScrollT;
        f32 materialTextureHeight;
        f32 materialTextureWidth;
        s16 tileHighS;
        s16 tileHighT;
        struct TileScrollParams* tileScrollParams;
        struct TexturedMaterial *material;
        struct Texture* baseTexture;
        struct Texture* curTexture;
        
        // Set up a textured material
        material = arg1->materialData.texturedMaterial;

        // Load the material if it hasn't been loaded yet
        if (!IS_K0_ADDRESS(material)) {
            material = load_textured_material(arg1);
        }
        tileScrollParams = arg1->scrollParams;
        
        baseTextureIndex = tileScrollParams ? tileScrollParams->unk8 : 0;

        lodLevel = 0;
        tileIndex = 0;
        tmemAddress = 0;
        paletteIndex = 0;
        
        scrollSpeedS = tileScrollParams ? tileScrollParams->tile0SpeedS : 0.0f;
        scrollSpeedT = tileScrollParams ? tileScrollParams->tile0SpeedT : 0.0f;
        loop_41:
        {
            loadedTextureIndex = baseTextureIndex + lodLevel;
            curTexture = material->textures[loadedTextureIndex];

            // Set up load commands for the current texture
            func_800923E8(arg0, (void* ) material, baseTextureIndex, lodLevel, tmemAddress, paletteIndex, 0);

            // Configure the tile descriptor for the current texture
            gDPSetTile(NEXT_GFX(arg0->unk8), curTexture->header.imFormat, curTexture->header.imSize, curTexture->header.bytesPerRow / sizeof(u64), tmemAddress, 
                tileIndex, paletteIndex,
                material->header.clampWrapMirrorT, material->heightPower - lodLevel, lodLevel,
                material->header.clampWrapMirrorS, material->widthPower - lodLevel, lodLevel);
            
            materialTextureWidth  = material->header.baseTextureWidth;
            materialTextureHeight = material->header.baseTextureHeight;
            
            baseTexture = material->textures[baseTextureIndex];
            scrollScaleS = (materialTextureWidth  / 256.0f) * 4 * baseTexture->header.width;
            scrollScaleT = (materialTextureHeight / 256.0f) * 4 * baseTexture->header.height;
            
            tileHighS = (materialTextureWidth  / 256.0f) * 4 * (baseTexture->header.width - 1);
            tileHighT = (materialTextureHeight / 256.0f) * 4 * (baseTexture->header.height - 1);
            
            tileScrollS = tileScrollT = material->unk22;
            if (scrollSpeedS != 0.0f) {
                tileScrollS += (s32)(positive_fmodf(scrollSpeedS, 1.0f) * scrollScaleS);
            }
            if (scrollSpeedT != 0.0f) {
                tileScrollT += (s32)(positive_fmodf(scrollSpeedT, 1.0f) * scrollScaleT);
            }
            
            gDPSetTileSize(NEXT_GFX(arg0->unk8), tileIndex, tileScrollS, tileScrollT, tileScrollS + tileHighS, tileScrollT + tileHighT);

            if (material->header.flags & MATERIAL_FLAG_MIPMAPPED) {
                if (loadedTextureIndex < (material->header.numTextures - 1)) {
                    tmemAddress += curTexture->header.imageBytes / sizeof(u64);
                    if (curTexture->header.imSize == G_IM_SIZ_4b) {
                        paletteIndex += 1;
                    }
                    lodLevel += 1;
                    tileIndex += 1;
                    // continue;
                    goto loop_41;
                }
                tileIndex = 0;
                loadedTextureIndex = 0;
                curTexture = material->textures[0];
            }
            // If there are more textures to process, continue to do so
            if ((material->header.flags & MATERIAL_FLAG_MULTITEXTURE_MIX) && loadedTextureIndex < (material->header.numTextures - 1)) {
                // Increment the tmem address by the size of the loaded texture in tmem words (8 bytes each)
                tmemAddress += (u32) curTexture->header.imageBytes >> 3;
                // Advance the palette index for 4-bit textures, since only they can have multiple palettes
                if (curTexture->header.imSize == G_IM_SIZ_4b) {
                    paletteIndex += 1;
                }
                baseTextureIndex += 1;
                tileIndex += 1;
                if (tileScrollParams != NULL) {
                    scrollSpeedS = tileScrollParams->tile1SpeedS;
                    scrollSpeedT = tileScrollParams->tile1SpeedT;
                }
                goto loop_41;
            } else {
                // break;
                goto after;
            }
        }
        after:

        textureScaleS = 0x200;
        textureScaleT = 0x200;
        if (material->header.clampWrapMirrorS & G_TX_MIRROR) {
            textureScaleS *= 2;
        }
        if (material->header.clampWrapMirrorT & G_TX_MIRROR) {
            textureScaleT *= 2;
        }
        textureScaleS = textureScaleS * (s32) ((f32) curTexture->header.width  * material->header.baseTextureWidth / 256.0f);
        textureScaleT = textureScaleT * (s32) ((f32) curTexture->header.height * material->header.baseTextureHeight / 256.0f);
        if (textureScaleS > 0xFFFF) {
            textureScaleS = 0xFFFF;
        }
        if (textureScaleT > 0xFFFF) {
            textureScaleT = 0xFFFF;
        }
        
        gSPTexture(NEXT_GFX(arg0->unk8),
            textureScaleS, textureScaleT, lodLevel - 1, G_TX_RENDERTILE, G_ON);
        gDPSetEnvColor(NEXT_GFX(arg0->unk8),
            material->header.envColorR, material->header.envColorG, material->header.envColorB, material->header.envColorA);

        // Pick a combiner based on material flags
        switch (material->header.flags & 0x3CC) {
            case 0:
            default:
                // Opaque Shaded Texture
                cycle1 = MAKE_COMBINER( SHADE, 0, TEXEL0, 0,  0, 0, 0, 1 );
                cycle2 = cycle1;
                break;
            case 4:
                // Shaded Texture with Texture Alpha
                cycle1 = MAKE_COMBINER( SHADE, 0, TEXEL0, 0,  0, 0, 0, TEXEL0 );
                cycle2 = cycle1;
                break;
            case 8:
                // Shaded Texture with Vertex Alpha
                cycle1 = MAKE_COMBINER( SHADE, 0, TEXEL0, 0,  0, 0, 0, SHADE );
                cycle2 = cycle1;
                break;
            case 0xC:
                // Shaded Texture with Texture and Vertex Alpha
                cycle1 = MAKE_COMBINER( SHADE, 0, TEXEL0, 0,  TEXEL0, 0, SHADE, 0 );
                cycle2 = cycle1;
                break;
            case 0x108:
                // Shaded Texture with Environment Alpha
                cycle1 = MAKE_COMBINER( SHADE, 0, TEXEL0, 0,  0, 0, 0, ENVIRONMENT );
                cycle2 = cycle1;
                break;
            case 0x10C:
                // Shaded Texture with Texture and Environment Alpha
                cycle1 = MAKE_COMBINER( SHADE, 0, TEXEL0, 0,  TEXEL0, 0, ENVIRONMENT, 0 );
                cycle2 = cycle1;
                break;
            case 0x200:
                // Opaque Shade/Environment Mix Driven by Texture
                cycle1 = MAKE_COMBINER( SHADE, ENVIRONMENT, TEXEL0, ENVIRONMENT,  0, 0, 0, 1 );
                cycle2 = cycle1;
                break;
            case 0x208:
            case 0x20C:
                // Shade/Environment Mix Driven by Texture with Texture and Vertex Alpha
                cycle1 = MAKE_COMBINER( SHADE, ENVIRONMENT, TEXEL0, ENVIRONMENT,  TEXEL0, 0, SHADE, 0 );
                cycle2 = cycle1;
                break;
            case 0x308:
            case 0x30C:
                // Environment/Shade Mix Driven by Texture with Texture and Environment Alpha
                cycle1 = MAKE_COMBINER( ENVIRONMENT, SHADE, TEXEL0, SHADE,  TEXEL0, 0, ENVIRONMENT, 0 );
                cycle2 = cycle1;
                break;
            // 2 cycle modes
            // (This is where they start getting complicated)
            case MATERIAL_FLAG_MULTITEXTURE_MIX:
            case MATERIAL_FLAG_MULTITEXTURE_MIX | 0x8:
            case MATERIAL_FLAG_MULTITEXTURE_MIX | 0x108:
                // Shaded Multitexture Mix Driven by Vertex Alpha
                // with Environment Alpha and Multitexture Mix Alpha Driven by Vertex Alpha
                cycle1 = MAKE_COMBINER( TEXEL1, TEXEL0, SHADE_ALPHA, TEXEL0,  TEXEL1, TEXEL0, SHADE, TEXEL0 );
                cycle2 = MAKE_COMBINER( SHADE, 0, COMBINED, 0,  COMBINED, 0, ENVIRONMENT, 0 );
                break;
            case MATERIAL_FLAG_MULTITEXTURE_MIX | 0x200:
            case MATERIAL_FLAG_MULTITEXTURE_MIX | 0x208:
                // Shade/Environment Mix Driven by Multitexture Mix Driven by Vertex Alpha
                // with Primitive Alpha and Multitexture Mix Alpha Driven by Vertex Alpha
                cycle1 = MAKE_COMBINER( TEXEL1, TEXEL0, SHADE_ALPHA, TEXEL0,  TEXEL1, TEXEL0, SHADE, TEXEL0 );
                cycle2 = MAKE_COMBINER( SHADE, ENVIRONMENT, COMBINED, ENVIRONMENT,  COMBINED, 0, PRIMITIVE, 0 );
                break;
            case MATERIAL_FLAG_MULTITEXTURE_MIX | 0x308:
                // Environment/Shade Mix Driven by Multitexture Mix Driven by Vertex Alpha
                // with Environment Alpha and Multitexture Mix Alpha Driven by Vertex Alpha
                cycle1 = MAKE_COMBINER( TEXEL1, TEXEL0, SHADE_ALPHA, TEXEL0,  TEXEL1, TEXEL0, SHADE, TEXEL0 );
                cycle2 = MAKE_COMBINER( ENVIRONMENT, SHADE, COMBINED, SHADE,  COMBINED, 0, ENVIRONMENT, 0 );
                break;
            case MATERIAL_FLAG_MIPMAPPED:
                // Shaded Mipmapped Texture with Primitive Alpha
                cycle1 = MAKE_COMBINER( TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0 );
                cycle2 = MAKE_COMBINER( SHADE, 0, COMBINED, 0,  0, 0, 0, PRIMITIVE );
                break;
            case MATERIAL_FLAG_MIPMAPPED | 0x4:
            case MATERIAL_FLAG_MIPMAPPED | 0x8:
                // Shaded Mipmapped Texture with Texture and Primitive Alpha
                cycle1 = MAKE_COMBINER( TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0 );
                cycle2 = MAKE_COMBINER( SHADE, 0, COMBINED, 0,  COMBINED, 0, PRIMITIVE, 0 );
                break;
            case MATERIAL_FLAG_MIPMAPPED | 0x200:
                // Shade/Environment Mix Driven by Mipmapped Texture with Primitive Alpha
                cycle1 = MAKE_COMBINER( TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0 );
                cycle2 = MAKE_COMBINER( SHADE, ENVIRONMENT, COMBINED, ENVIRONMENT,  0, 0, 0, PRIMITIVE );
                break;
            case MATERIAL_FLAG_MIPMAPPED | 0x208:
                // Shade/Environment Mix Driven by Mipmapped Texture with Mipmapped Texture and Vertex Alpha
                cycle1 = MAKE_COMBINER( TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0 );
                cycle2 = MAKE_COMBINER( SHADE, ENVIRONMENT, COMBINED, ENVIRONMENT,  COMBINED, 0, SHADE, 0 );
                break;
            case MATERIAL_FLAG_MIPMAPPED | 0x108:
                // Shaded Mipmapped Texture with Primitive and Environment Alpha
                cycle1 = MAKE_COMBINER( TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0 );
                cycle2 = MAKE_COMBINER( SHADE, 0, COMBINED, 0,  PRIMITIVE, 0, ENVIRONMENT, 0 );
                break;
            case MATERIAL_FLAG_MIPMAPPED | 0x308:
                // Shade/Environment Mix Driven by Mipmapped Texture with Mipmapped Texture and Primitive Alpha
                cycle1 = MAKE_COMBINER( TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,  TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0 );
                cycle2 = MAKE_COMBINER( SHADE, ENVIRONMENT, COMBINED, ENVIRONMENT,  COMBINED, 0, ENVIRONMENT, 0 );
                break;
        }

        // If the two combiner cycles are configured the same but this is a 2-cycle material, replace the second cycle with:
        // color: Combined
        // alpha: Combined * Primitive
        if ((material->header.unk4.unk0_0) == 0x02 && ((u32*)cycle1.color)[0] == ((u32*)cycle2.color)[0] && ((u32*)cycle1.color)[1] == ((u32*)cycle2.color)[1]) {
            cycle2 = MAKE_COMBINER( 0, 0, 0, COMBINED,  COMBINED, 0, PRIMITIVE, 0 );
        }
    
        gDPSetCombineLERP_custom(NEXT_GFX(arg0->unk8),
            cycle1.color[0], cycle1.color[1], cycle1.color[2], cycle1.color[3],
            cycle1.alpha[0], cycle1.alpha[1], cycle1.alpha[2], cycle1.alpha[3],
            cycle2.color[0], cycle2.color[1], cycle2.color[2], cycle2.color[3],
            cycle2.alpha[0], cycle2.alpha[1], cycle2.alpha[2], cycle2.alpha[3]
        );

        gSPSetGeometryMode(NEXT_GFX(arg0->unk8), G_SHADE | G_SHADING_SMOOTH);
        
        if (arg1->materialData.texturedMaterial->header.flags & MATERIAL_FLAG_TWO_SIDED) {
            gSPClearGeometryMode(NEXT_GFX(arg0->unk8), G_CULL_BACK);
        } else {
            gSPSetGeometryMode(NEXT_GFX(arg0->unk8), G_CULL_BACK);
        }
        gDPSetTextureFilter(NEXT_GFX(arg0->unk8), (material->header.flags & MATERIAL_FLAG_POINT_FILTERED) ? G_TF_POINT : G_TF_BILERP);
        gDPSetTextureLOD(NEXT_GFX(arg0->unk8), (material->header.flags & MATERIAL_FLAG_MIPMAPPED) ? G_TL_LOD : G_TL_TILE);
        gSPLightColor(NEXT_GFX(arg0->unk8), LIGHT_1, *&D_800A539C.rgba32);
        gSPLightColor(NEXT_GFX(arg0->unk8), LIGHT_2, *&D_800A5398.rgba32);
    }
    gSPEndDisplayList(NEXT_GFX(arg0->unk8));
    return;
}

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

struct TextureGroupHeader *func_80093DDC(struct TextureGroupHeader *arg0, s32 arg1) {
    struct unkfunc_80093DDC sp10;
    struct MaterialGfx *materialGfx;
    struct TexturedMaterial *materialData;

    materialGfx = &materialTable[arg1];
    
    if (IS_SOLID_COLOR(materialTable[arg1].materialData.raw)) {
        sp10 = unk_inline_func_80093DDC2();
    } else {
        materialData = get_material_data(materialGfx);
        sp10 = materialData->header.unk4;
    }
    
    arg0->unk4 = sp10;
    return arg0;
}

void texture_handler_copy(u32 assetAddress, UNUSED struct TextureCompressionHeader *header, struct Texture *asset)
{
    dma_read(assetAddress, asset->imageData, asset->header.imageBytes);
}
