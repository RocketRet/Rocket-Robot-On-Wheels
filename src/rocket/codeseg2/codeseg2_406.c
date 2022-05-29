#include <include_asm.h>
#include <ultra64.h>
#include <mem.h>

extern struct DecompressionParams compressionParamsTable[];

void texture_handler_decompress(u32 assetAddress, struct TextureCompressionHeader *header, struct Texture *asset)
{
    void *compressedData;

    push_second_heap_state();
    compressedData = (void *)alloc_second_heap(header->compressedLength);
    dma_read(assetAddress, compressedData, header->compressedLength);
    decompress(&compressionParamsTable[header->compressionParams], header->compressedLength,
               compressedData, asset->header.imageBytes, asset->imageData);
    pop_second_heap_state();
}

struct TexturedMaterial *load_textured_material(struct MaterialGfx *material) {
    uintptr_t curRomAddr;
    s32 curDimension;
    struct TexturedMaterial *textureGroup;
    s32 i;

    curRomAddr = material->materialData;
    textureGroup = (struct TexturedMaterial*)main_alloc_bzero(sizeof(struct TexturedMaterial));

    dma_read(curRomAddr, &textureGroup->header, sizeof(struct TextureGroupHeader));
    curRomAddr += sizeof(struct TextureGroupHeader);
    textureGroup->textures = main_alloc_bzero(textureGroup->header.numTextures * sizeof(struct Texture *));
    
    // Doesn't match as a for loop
    i = 0;
    while (1) {
        struct Texture *curTexture;
        struct Texture **curGroupTexturePointer;
        u16 curTextureIndex;
        if (i >= textureGroup->header.numTextures) {
            break;
        }
        dma_read(curRomAddr, &curTextureIndex, sizeof(curTextureIndex));
        curRomAddr += sizeof(curTextureIndex);
        
        // curGroupTexturePointer = &textureGroup->textures[i];
        curGroupTexturePointer = (struct Texture**)(i * 4 + (u32)textureGroup->textures); // Doesn't match as an array index or pointer arithmetic
        
        if ((((u32)textureTable[curTextureIndex]) & 0xF0000000) == 0x80000000) {
            curTexture = textureTable[curTextureIndex];
        } else {
            curTexture = load_texture(&textureTable[curTextureIndex]);
        }
        *curGroupTexturePointer = curTexture;
        i += 1;
    }

    curDimension = textureGroup->textures[0]->header.width - 1;
    while (curDimension != 0) {
        curDimension = curDimension >> 1;
        textureGroup->widthPower++;
    }
    curDimension = textureGroup->textures[0]->header.height - 1;
    while (curDimension != 0) {
        curDimension = curDimension >> 1;
        textureGroup->heightPower++;
    }
    textureGroup->unk22 = (textureGroup->header.unk8 & 2) ? 0 : 2;
    textureGroup->romAddress = material->materialData;
    material->materialData = (uintptr_t)textureGroup;
    return textureGroup;
}

struct Texture *load_texture(struct MaterialGfx *material)
{
    struct Texture *texture;
    struct TextureCompressionHeader compressionHeader;
    uintptr_t curRomAddr;

    curRomAddr = material->materialData;
    
    texture = (struct Texture*)main_alloc_bzero(sizeof(struct Texture));

    dma_read(curRomAddr, texture, sizeof(struct TextureHeader));
    curRomAddr += sizeof(struct TextureHeader);

    dma_read(curRomAddr, &compressionHeader, sizeof(struct TextureCompressionHeader));
    curRomAddr += sizeof(struct TextureCompressionHeader);

    texture->imageData = main_alloc_nozero(texture->header.imageBytes);
    textureHandlers[compressionHeader.handlerIndex](curRomAddr, &compressionHeader, texture);
    curRomAddr += compressionHeader.compressedLength;
    if (texture->header.paletteBytes > 0)
    {
        texture->paletteData = main_alloc_nozero(texture->header.paletteBytes);
        dma_read(curRomAddr, texture->paletteData, texture->header.paletteBytes);
    }
    return texture;
}

void adjust_texture_table(void)
{
    int iVar1;
    struct Texture **piVar2;
    int iVar3;

    textureTable = alloc_second_heap(textureTableLength * sizeof(struct Texture *));
    dma_read(textureTableAddress, textureTable, textureTableLength * sizeof(struct Texture *));
    piVar2 = textureTable;
    iVar1 = textureTableLength;
    for (iVar3 = 0; iVar3 < iVar1; iVar3++)
    {
        piVar2[iVar3] = (struct Texture *)((uintptr_t)piVar2[iVar3] + (uintptr_t)_assetsSegmentRomStart);
    }
}

void reset_texture_table()
{
    textureTable = NULL;
}
