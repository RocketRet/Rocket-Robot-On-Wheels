#ifndef __ROCKET_H__
#define __ROCKET_H__

#include <stdint.h>
#include <stdio.h>

#define ROCKET_ROM_SIZE 0xC00000

#define ROM_CONTENT_START 0xB0460
#define ASSET_TABLE_ADDR 0x2F3F2A
#define ASSET_TABLE_LEN 0x798

struct TextureHeader {
    uint16_t width;
    uint16_t height;
    uint8_t imSize;   // G_IM_SIZ_x
    uint8_t imFormat; // G_IM_FMT_x
    uint16_t bytesPerRow;
    uint32_t imageBytes;
    uint16_t paletteBytes;
    uint16_t unkE;
};

struct Texture {
    struct TextureHeader header;
    void *imageData;
    void *paletteData;
};

struct TextureCompressionHeader {
    uint8_t handlerIndex;
    uint8_t compressionParams;
    uint8_t unk2;
    uint8_t unk3;
    uint32_t compressedLength;
};

struct DecompressionParams {
    uint32_t lengthOffset;
    uint32_t negativeShift;
    uint32_t shift;
    uint32_t mask;
};

extern struct DecompressionParams decompressionParamsTable[2];
int compress(struct DecompressionParams *params, uint32_t decompressedSize, uint8_t *src, uint8_t **dst, int lookahead);
void decompress(struct DecompressionParams *params, uint32_t compressedSize, uint8_t *src, uint32_t uncompressedSize, uint8_t *dst);
unsigned int get_texture_address(FILE *romFile, unsigned int assetIndex);
void read_texture_headers(FILE *romFile, struct Texture *asset, struct TextureCompressionHeader *handlerHeader, unsigned int assetIndex);
void read_texture(void *data, void *data2, FILE *romFile, unsigned int assetIndex);
void swap_words(void *data, unsigned int numBytes, unsigned int bytesPerRow);
void flip_rows(void *data, unsigned int height, unsigned int bytesPerRow);

#endif
