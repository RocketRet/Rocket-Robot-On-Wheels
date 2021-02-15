#include <include_asm.h>
#include <ultra64.h>

struct unkD_800A63C0 {
    u8 padding[0x14];
    s32 unk14;
    s32 unk18;
    struct unkD_800A63C0 *unk1C;
};

extern struct unkD_800A63C0 *D_800A63C0;
extern s32 D_800A63C4;

void func_8004EC70()
{
    struct unkD_800A63C0 *cur = D_800A63C0;
    while (cur)
    {
        cur->unk14 = 0;
        cur = cur->unk1C;
    }
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_171", func_8004EC98);

INCLUDE_ASM(s32, "codeseg2/codeseg2_171", func_8004ED04);

// TODO different compiler
// void func_8004EE5C()
// {
//     D_800A63C4 = 0;
//     func_8007F378(0);
// }

INCLUDE_ASM(s32, "codeseg2/codeseg2_171", func_8004EE5C);

// TODO different compiler
// void func_8004EE84(s32 arg0)
// {
//     D_800A63C4 |= arg0 & ~0x4000;
//     if (arg0 & 0x4000)
//     {
//         func_8007F378(0);
//     }
// }

INCLUDE_ASM(s32, "codeseg2/codeseg2_171", func_8004EE84);

INCLUDE_ASM(s32, "codeseg2/codeseg2_171", func_8004EEC4);
