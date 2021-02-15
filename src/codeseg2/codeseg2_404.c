#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "codeseg2/codeseg2_404", func_80091F40);

extern s32 D_800A3190;

extern s32 D_800AF310;
extern s32 D_800AF320;

extern s32 D_800AF44C[4];
extern s32 D_800AF45C[33];
extern s32 D_800AF4E0;

struct unkfunc_80091F54 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18[0xC0];
    u32 unk318[0xC1];
};

// void func_80091F54(s32 arg0)
// {
//     struct unkfunc_80091F54 var;
//     struct unkfunc_80091F54 *tmp;
//     u32 i;

//     if (D_800AF320 != 1)
//     {
//         arg0 = 0;
//     }

//     if (arg0 != D_800AF4E0)
//     {
//         if (D_800AF310)
//         {
//             if (arg0)
//             {
//                 bzero(&var, sizeof(var));

//                 var.unk0 = &D_800A3190;

//                 for (i = 0; i < 4; i++)
//                 {
//                     D_800AF44C[i][var.unk18] = 1;
//                 }

//                 i = 0;
//                 while (1)
//                 {
//                     if (i >= 0x21)
//                         break;
//                     D_800AF45C[i++][var.unk318] = 1;
//                 }

//                 func_80091BFC(&var);
//             }
//             else
//             {
//                 func_80091BFC(D_800AF310);
//             }
//         }
//         D_800AF4E0 = arg0;
//     }
// }

INCLUDE_ASM(s32, "codeseg2/codeseg2_404", func_80091F54);
