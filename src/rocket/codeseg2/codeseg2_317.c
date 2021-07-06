#include <include_asm.h>
#include <ultra64.h>

struct unkD_800ADAD8 {
    u16 unk0;
    u16 unk2;
    u32 unk4;
};

extern u32 D_800ADADC;
extern struct unkD_800ADAD8 *D_800ADAD8;

// Does a binary search through D_800ADAD8, but seems to be unused
s32 func_80079EA0(s32 arg0) {
    s32 temp_v0;
    s32 max;
    s32 min;

    max = D_800ADADC - 1;
    min = 0;
    while (1) {
        s32 midpoint;
        if (max < min) {
            break;
        }

        midpoint = (max + min) / 2;

        if (D_800ADAD8[midpoint].unk0 == arg0) {
            return midpoint;
        } else if (D_800ADAD8[midpoint].unk0 < arg0) {
            min = midpoint + 1;
        } else {
            max = midpoint - 1;
        }
    }
    return -1;
}

struct unkfunc_80079F08 {
    u8 padding[0x48];
    s32 unk48;
    u8 unk4C;
};

void func_80079F08(struct unkfunc_80079F08 *arg0)
{
    func_80050868();
    arg0->unk48 = -1;
    arg0->unk4C = 0;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_317", func_80079F3C);

struct unkD_800E4F70 {
    s32 unk0;
    s32 unk4;
};

extern struct unkD_800E4F70 D_800E4F70[0x20];
extern s32 D_800E5070;

void func_8007A158()
{
    s32 i ;
    for (i = 0x1F; i >= 0; i--)
    {
        D_800E4F70[i].unk4 = D_800E4F70[i].unk0 = -1;
    }

    D_800E5070 = 0;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_317", func_8007A18C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_317", func_8007A23C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_317", func_8007A2BC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_317", func_8007A568);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_317", func_8007A5CC);
