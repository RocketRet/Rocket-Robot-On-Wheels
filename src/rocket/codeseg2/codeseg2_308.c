#include <include_asm.h>
#include <ultra64.h>
#include <types.h>
#include <macros.h>
#include <mem.h>

#include <materials.h>


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_308", func_800777B0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_308", func_80077A50);

extern s32 D_800AC2D8;
extern struct MaterialGfx *materialTable;
extern s32 D_800ABCD8;
extern struct TexturedMaterial *D_800AC1C8[0x44];

#define ARRAY_LEN(x) (s32)(sizeof(x) / sizeof((x)[0]))

// This is probably not the actual inline function used, but there definitely was an inline function used here
static inline struct TexturedMaterial **func_80077B24_inline_0(struct TexturedMaterial **table) {
    return &table[D_800AC2D8];
}

void func_80077B24(UNUSED s32 arg0, s32 arg1) {
    struct MaterialGfx *materialGfx;
    struct TexturedMaterial *materialData;
    struct TexturedMaterial **materialPtr;
    s32 index;

    if (D_800AC2D8 < ARRAY_LEN(D_800AC1C8) && ((D_800AC2D8 < 0x3A) || (D_800ABCD8 < 4))) {
        // Some of these temps are not real and are instead probably symptoms of more inline functions being used
        materialGfx = &materialTable[arg1];
        materialPtr = func_80077B24_inline_0(D_800AC1C8);
        
        materialData = get_material_data(materialGfx);

        index = D_800AC2D8;
        *materialPtr = materialData;
        D_800AC2D8 = index + 1;
    }
}

void func_80077BD0(s32 *arg0)
{
    arg0[4] = -1;
    func_80078170(arg0, 0);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_308", func_80077BF8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_308", func_80077C6C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_308", func_80077CCC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_308", func_80077F0C);

