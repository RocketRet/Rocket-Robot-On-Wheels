#include <include_asm.h>
#include <ultra64.h>

struct unkD_800A5990 {
    u64 unk0;
    u64 unk8;
};

extern struct unkD_800A5990 *D_800A5990;

s32 func_80042AC8(s32 arg0, struct unkD_800A5990 *arg1);

s32 func_80042AA0(s32 arg0)
{
    return func_80042AC8(arg0, D_800A5990);
}

// u32 func_80042AC8(s32 arg0, struct unkD_800A5990 *arg1)
// {
//     // u64 val;
//     // u64 val2;
//     u64 masked;
//     u32 ret;
//     u64 val;
//     u32 shift = arg0;
//     if (arg0 < 0x40)
//     {
//         val = arg1->unk0;
//         // val = arg1->unk0;
//         // val2 = 1ULL << shift;
//         // masked = (arg1->unk0) & (1ULL << arg0);
//         val &= (1ULL << shift);
//     }
//     else
//     {
//         val = arg1->unk8 * 16;
//         val &= (1ULL << (shift - 0x40));
//     }
//     return val == 0;
// }

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_125", func_80042AC8, s32 arg0, struct unkD_800A5990 *arg1);
