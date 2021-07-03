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

struct TextureGroupHeader {
    u32 unk4;
    u16 unk8;
    u16 unkA;
    u32 unkC;
    u32 unk10;
    u8 unk14;
    u8 numTextures;
    u8 unk16;
    u8 unk17;
    u32 unk18;
    u32 unk1C;
};

struct TextureGroup {
    u32 romAddress;
    struct TextureGroupHeader header;
    u8 widthPower;  // Width as a power of two (rounded up)
    u8 heightPower; // Height as a power of two (rounded up)
    u16 unk22; // probably just alignment padding
    struct Texture **textures;
};

struct Texture *load_texture(struct Texture **param_1);

struct TextureGroup *load_texture_group(u32 *arg0) {
    u32 curRomAddr;
    s32 curDimension;
    struct TextureGroup *textureGroup;
    s32 i;

    curRomAddr = *arg0;
    textureGroup = main_alloc_bzero(sizeof(struct TextureGroup));

    dma_read(curRomAddr, (void*)((u32)textureGroup + 4), sizeof(struct TextureGroupHeader));
    curRomAddr += sizeof(struct TextureGroupHeader);
    textureGroup->textures = main_alloc_bzero(textureGroup->header.numTextures * sizeof(struct Texture *));
    
    // Doesn't match as a for loop
    i = 0;
    while (1) {
        struct Texture *curTexture;
        struct Texture **curGroupTexturePointer;
        u16 curTextureIndex;
        if (i >= textureGroup->header.numTextures) break;
        dma_read(curRomAddr, &curTextureIndex, sizeof(curTextureIndex));
        curRomAddr += sizeof(curTextureIndex);
        
        // curGroupTexturePointer = &s0->textures[i];
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
    textureGroup->unk22 = (s16) (((textureGroup->header.unk8 & 2) == 0) * 2);
    textureGroup->romAddress = *arg0;
    *arg0 = (u32)textureGroup;
    return textureGroup;
}

struct Texture *load_texture(struct Texture **param_1)
{
    struct Texture *asset;
    struct TextureCompressionHeader compressionHeader;
    u32 curRomAddr;

    curRomAddr = (u32)*param_1;
    
    asset = main_alloc_bzero(sizeof(struct Texture));

    dma_read(curRomAddr, asset, sizeof(struct TextureHeader));
    curRomAddr += sizeof(struct TextureHeader);

    dma_read(curRomAddr, &compressionHeader, sizeof(struct TextureCompressionHeader));
    curRomAddr += sizeof(struct TextureCompressionHeader);

    asset->imageData = main_alloc_nozero(asset->header.imageBytes);
    textureHandlers[compressionHeader.handlerIndex](curRomAddr, &compressionHeader, asset);
    curRomAddr += compressionHeader.compressedLength;
    if (asset->header.paletteBytes > 0)
    {
        asset->paletteData = main_alloc_nozero(asset->header.paletteBytes);
        dma_read(curRomAddr, asset->paletteData, asset->header.paletteBytes);
    }
    return asset;
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
        piVar2[iVar3] = (struct Texture *)((u32)piVar2[iVar3] + (u32)_dataEndRom);
    }
}

void reset_texture_table()
{
    textureTable = NULL;
}
