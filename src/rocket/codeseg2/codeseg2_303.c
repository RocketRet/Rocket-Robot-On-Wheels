#include <include_asm.h>
#include <ultra64.h>
#include <types.h>

extern struct TexturedMaterial *D_800AC1C8[0x44];

struct unkfunc_80075940_2 {
    s32 digit;
    s32 x;
    s32 y;
    s32 valid;
};

struct unkfunc_80075940 {
    s32 unk0;
    s32 unk4;
    s32 bufferLength;
    struct unkfunc_80075940_2* buffer;
};

struct unkfunc_80075940_2* func_80075940(struct unkfunc_80075940* arg0, struct unkfunc_80075940_2* arg1, s32 val) {
    struct TexturedMaterial* digitTexture;
    struct unkfunc_80075940_2* cur;
    struct unkfunc_80075940_2* end;
    s32 divisor;
    s32 x;
    s32 y;

    x = arg1->x;
    y = arg1->y;
    divisor = 1000;
    while ((val / divisor) == 0) {
        divisor /= 10;
        if (divisor <= 1) break;
    }
    do {
        arg1->digit = val / divisor;
        arg1->x = x;
        arg1->y = y;
        arg1->valid = 1;
        digitTexture = D_800AC1C8[arg1->digit];
        if (digitTexture) {
            x += (*digitTexture->textures)->header.width;
        }
        val = val % divisor;
        divisor /= 10;
        arg1++;
    } while (divisor != 0);
    end = &arg0->buffer[arg0->bufferLength];
    cur = arg1;
    while (cur < end) {
        cur->digit = -1;
        cur++;
    }
    return arg1;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_303", func_80075ABC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_303", func_80075BE8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_303", func_80075C24);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_303", func_80075CC8);
