#include <include_asm.h>
#include <ultra64.h>
#include <types.h>
#include <mem.h>

extern struct MaterialGfx *materialTable;

struct unkfunc_80079CA0 {
    void *unk0;
    u8 padding[0x27C - 0x04];
    struct MaterialGfx unk27C;
};

Gfx *func_800922C4(struct MaterialGfx *, s32);

void func_80079CA0(struct unkfunc_80079CA0 *arg0, s32 arg1, Gfx *arg2) {
    struct MaterialGfx *temp_a0;
    s32 maskedAddress;
    struct TexturedMaterial *prevTextureGroup;
    struct TexturedMaterial *materialData;

    if (arg1 != -1) {
        temp_a0 = &materialTable[arg1];
        prevTextureGroup = temp_a0->materialData;
        maskedAddress = (u32)prevTextureGroup & 0xF0000000;
        if (maskedAddress != 0) {
            if (maskedAddress == 0x80000000) {
                materialData = prevTextureGroup;
            } else {
                materialData = load_textured_material(temp_a0);
            }
            if (materialData->header.numTextures > 1) {
                arg0->unk27C.materialData = materialTable[arg1].materialData;
                gSPDisplayList(arg2, func_800922C4(&arg0->unk27C, 1));
            } else {
                func_80086310(arg0, arg1, arg2);
            }
        } else {
            func_80086310(arg0, arg1, arg2);
        }
    }
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_316", func_80079D6C);
