#include <include_asm.h>
#include <ultra64.h>
#include <types.h>
#include <mem.h>

extern struct unkD_800ADAD0 *D_800ADAD0;

struct unkfunc_80079CA0 {
    void *unk0;
    u8 padding[0x27C - 0x04];
    struct unkD_800ADAD0 unk27C;
};

Gfx *func_800922C4(struct unkD_800ADAD0 *, s32);

void func_80079CA0(struct unkfunc_80079CA0 *arg0, s32 arg1, Gfx *arg2) {
    struct unkD_800ADAD0 *temp_a0;
    s32 maskedAddress;
    struct TextureGroup *prevTextureGroup;
    struct TextureGroup *textureGroup;

    if (arg1 != -1) {
        temp_a0 = &D_800ADAD0[arg1];
        prevTextureGroup = temp_a0->textureGroup;
        maskedAddress = (u32)prevTextureGroup & 0xF0000000;
        if (maskedAddress != 0) {
            if (maskedAddress == 0x80000000) {
                textureGroup = prevTextureGroup;
            } else {
                textureGroup = load_texture_group(temp_a0);
            }
            if (textureGroup->header.numTextures > 1) {
                arg0->unk27C.textureGroup = D_800ADAD0[arg1].textureGroup;
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
