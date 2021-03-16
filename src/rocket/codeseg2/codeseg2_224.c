#include <include_asm.h>
#include <ultra64.h>

extern u32 D_800E4DA0;
extern u32 D_800E4DA4;
extern u32 D_800E4DA8;

void do_dma_read(u32 romAddr, void *ramAddr, s32 length);

// Not even close yet
// void func_80061740(u32 arg0, u32 arg1, s32 arg2)
// {
//     s32 s1;
//     while (1)
//     {
//         if (arg0 >= D_800E4DA4 && arg0 < D_800E4DA8)
//         {
//             u32 v0 = arg0 - D_800E4DA4;
//             if (v0 < 100)
//             {
//                 if ((D_800E4DA0 + v0) & 0x03 == arg1 & 0x03)
//                     break;
//             }
//         }
//         else
//         {
            
//             do_dma_read(arg0, arg1, s1);

//             D_800E4DA4 = D_800E4DA8 & 0xFFFFFFFE;
//             D_800E4DA8 = D_800E4DA4 + 0x400;
//             do_dma_read(D_800E4DA4, D_800E4DA0, 0x400);
//         }
//     }
// }

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_224", func_80061740);
