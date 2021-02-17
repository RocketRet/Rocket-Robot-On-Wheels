#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "codeseg2/codeseg2_302", func_80075100);

struct unkD_800A5DA8 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

extern struct unkD_800A5DA8 D_800A5DA8;

#define MACRO_FUNC_800751D8(x) (((x) + 0xF < 0) ? (x) + 0x1E : (x) + 0xF)

// TODO regalloc
// void func_800751D8(s32 **arg0, s32 arg1)
// {
//     s32 *s1;
//     s32 *s2;
//     func_80061574();
//     s1 = &D_800A5DA8.unk0;
//     s2 = &D_800A5DA8.unk8;
//     func_80046268(s2);
//     func_80046354(0xFF, 0x80, 0, 0xFF);
//     func_8004632C(arg0[4], arg0[5]);
//     func_80046318(arg0[1][2], MACRO_FUNC_800751D8(arg0[1][3]) >> 4);
//     func_800463B4(s1, arg1, 0, 0, 0);
//     func_800462E4(s2);
//     func_800615D4();
// }

INCLUDE_ASM(s32, "codeseg2/codeseg2_302", func_800751D8);

INCLUDE_ASM(s32, "codeseg2/codeseg2_302", func_8007529C);

struct unkfunc_80075348 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

void func_80075348(struct unkfunc_80075348 *arg0, s32 arg1)
{
    s32 s0 = arg1;
    struct unkfunc_80075348 *s1 = arg0;
    bzero(s1, s0 * sizeof(struct unkfunc_80075348));
    for (s0--; s0 >= 0; s1++, s0--)
    {
        s1->unk0 = -1;
        s1->unk4 = 0;
        s1->unk8 = 0;
        s1->unkC = 1;
    }
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_302", func_800753B4);

INCLUDE_ASM(s32, "codeseg2/codeseg2_302", func_80075458);

INCLUDE_ASM(s32, "codeseg2/codeseg2_302", func_80075884);
