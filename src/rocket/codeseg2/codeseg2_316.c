#include <include_asm.h>
#include <ultra64.h>
#include <types.h>

extern volatile struct unkD_800ADAD0 *D_800ADAD0;

struct unkfunc_80079CA0 {
    void *unk0;
    u8 padding[0x27C - 0x04];
    s32 unk27C;
};

// TODO close
// void func_80079CA0(struct unkfunc_80079CA0 *arg0, s32 arg1, Gfx *arg2)
// {
//     if (arg1 != -1)
//     {
//         u8 *ptr;
//         u32 masked;
//         ptr = D_800ADAD0[arg1].unk0;
//         masked = (u32)ptr & 0xF0000000;
//         if (masked)
//         {
//             if (masked != 0x80000000)
//             {
//                 ptr = func_80094004();
//             }
//             if (ptr[0x15] > 1)
//             {
//                 arg0->unk27C = (D_800ADAD0 + arg1)->unk0;
//                 gSPDisplayList(arg2, func_800922C4(&arg0->unk27C, 1));
//                 return;
//             }
//         }
//         func_80086310(arg0, arg1, arg2);
//     }
// }

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_316", func_80079CA0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_316", func_80079D6C);
