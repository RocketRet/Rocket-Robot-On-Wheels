#include <include_asm.h>
#include <ultra64.h>
#include <types.h>
#include <mem.h>


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_312", func_800782D0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_312", func_800783A0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_312", func_8007844C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_312", func_8007855C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_312", func_80078790);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_312", func_800789A8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_312", func_800795B8);

void func_8007982C(s32 *arg0)
{
    if (arg0[0x98] != 0x0A)
    {
        func_8008392C();
    }
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_312", func_8007985C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_312", func_800798D0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_312", func_80079AA4);

void func_80079B84(s32 *arg0, s32 arg1)
{
    if (arg1 == 8)
    {
        arg0[0x4B] = 0;
    }
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_312", func_80079B98);

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
        prevTextureGroup = temp_a0->materialData.texturedMaterial;
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

const s32 D_8001D11C[] = { 0x45, 0x45, 0x45, 0x45, 0x47, 0x4B, 0x4B, 0x4B, 0x58, 0x5B, 0x60, 0x60, 0x60, 0x66 };

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_312", func_80079D6C);
