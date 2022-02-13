#include <include_asm.h>
#include <ultra64.h>
#include <sounds.h>
#include <gameplay.h>

extern s32 gCurLevelTokens;

const float D_8001C950 = 1.0f;
const float D_8001C954 = 4.0f;

// This seems to draw tokens, changing D_8001C950 changes the size of tokens
INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_267", func_8006BDF0);

struct unkfunc_8006BEE4 {
    u8 padding[0xC];
    s32* unkC;
    u8 padding2[0x2C - 0xC - 0x4];
    s32 unk2C;
    s32 unk30;
    u8 padding3[0x71 - 0x30 - 0x4];
    u8 unk71;
};

void func_8009C5C8(s32, s32*, float, s32*);

void func_8006BEE4(struct unkfunc_8006BEE4* arg0) {
    s32 iVar1;
    func_8006B430(arg0, &arg0->unk30);
    iVar1 = arg0->unkC[0x51];
    if (iVar1 != 0) {
        func_8009C5C8(iVar1, &arg0->unk30, 0.5f, &arg0->unk2C);
    }
    arg0->unk71 = 0;
    return;
}

struct unkfunc_8006BF3C {
    u8 padding[0xC];
    s32 unkC;
    u8 padding2[0x3C - 0xC - 0x4];
    s32 unk3C;
};

void func_8006BF3C(struct unkfunc_8006BF3C* arg0, s32 arg1) {
    if (arg1 != arg0->unk3C) {
        if (arg0->unk3C == 0) {
            func_8008C590(arg0->unkC, arg0);
            arg0->unk3C = arg1;
        } else {
            arg0->unk3C = arg1;
        }
    }
}

void func_8006BF90(s32 *arg0)
{
    func_80042710(arg0[9]);
    if (gCurLevelTokens < LEVEL_TOKEN_COUNT)
    {
        play_sound(arg0[10] + SFX_GET_TOKEN_SILVER, 0, 0x80, 0x80);
    }
    else
    {
        play_sound(SFX_GET_TICKET, 0, 0x80, 0x80);
    }
}

struct unkfunc_8006BFFC {
    void (**unk0)(struct unkfunc_8006BFFC*);
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};

void func_8002ADE4(s32, s32*, float, float, float, struct unkfunc_8006BFFC*, s32*);

void func_8006BFFC(struct unkfunc_8006BFFC* arg0, s32 arg1, struct unkfunc_8006BFFC** arg2) {
    if (arg1 == 0x25) {
        struct unkfunc_8006BFFC* temp = arg2[1];
        if (temp == arg0) {
            func_8002ADE4(temp->unkC, &temp->unk18, 0.5f, -1.5f, 0.8f, arg2[0], &temp->unk18);
            if (temp->unk0[16]) {
               (temp->unk0[16])(temp);
            }
        }
    }
}

s32 func_8006C074(u32 arg0) {
    return (arg0 - 166) < 12;
}
