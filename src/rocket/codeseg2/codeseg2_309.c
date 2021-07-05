#include <include_asm.h>
#include <ultra64.h>
#include <types.h>
#include <mem.h>

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_309", func_80077A50);

extern s32 D_800AC2D8;
extern struct unkD_800ADAD0 *D_800ADAD0;
extern s32 D_800ABCD8;
extern struct TextureGroup *D_800AC1C8[0x44];

#define ARRAY_LEN(x) (s32)(sizeof(x) / sizeof((x)[0]))

// single instruction out of order
#ifdef NON_MATCHING
void func_80077B24(s32 arg0, s32 arg1) {
    struct unkD_800ADAD0 *temp_a0;
    struct TextureGroup *phi_a0;
    struct TextureGroup **s0;
    u32 maskedAddress;
    u32 asdf;

    if (D_800AC2D8 < ARRAY_LEN(D_800AC1C8) && ((D_800AC2D8 < 0x3A) || (D_800ABCD8 < 4))) {
        asdf = D_800AC2D8;
        temp_a0 = &D_800ADAD0[arg1];
        s0 = &D_800AC1C8[asdf];

        if (((u32)temp_a0->textureGroup & 0xF0000000) == 0x80000000) {
            phi_a0 = temp_a0->textureGroup;
        } else {
            phi_a0 = load_texture_group(temp_a0);
        }

        asdf = D_800AC2D8;
        *s0 = phi_a0;
        D_800AC2D8 = asdf + 1;
    }
}
#else
INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_309", func_80077B24);
#endif
