#include <include_asm.h>
#include <ultra64.h>
#include <types.h>
#include <mem.h>

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_309", func_80077A50);

extern s32 D_800AC2D8;
extern struct MaterialGfx *materialTable;
extern s32 D_800ABCD8;
extern struct TexturedMaterial *D_800AC1C8[0x44];

#define ARRAY_LEN(x) (s32)(sizeof(x) / sizeof((x)[0]))

// single instruction out of order
#ifdef NON_MATCHING
void func_80077B24(s32 arg0, s32 arg1) {
    struct MaterialGfx *temp_a0;
    struct TexturedMaterial *phi_a0;
    struct TexturedMaterial **s0;
    u32 maskedAddress;
    u32 asdf;

    if (D_800AC2D8 < ARRAY_LEN(D_800AC1C8) && ((D_800AC2D8 < 0x3A) || (D_800ABCD8 < 4))) {
        asdf = D_800AC2D8;
        temp_a0 = &materialTable[arg1];
        s0 = &D_800AC1C8[asdf];

        if (((u32)temp_a0->materialData & 0xF0000000) == 0x80000000) {
            phi_a0 = temp_a0->materialData;
        } else {
            phi_a0 = load_textured_material(temp_a0);
        }

        asdf = D_800AC2D8;
        *s0 = phi_a0;
        D_800AC2D8 = asdf + 1;
    }
}
#else
INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_309", func_80077B24);
#endif

void func_80077BD0(s32 *arg0)
{
    arg0[4] = -1;
    func_80078170(arg0, 0);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_309", func_80077BF8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_309", func_80077C6C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_309", func_80077CCC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_309", func_80077F0C);
