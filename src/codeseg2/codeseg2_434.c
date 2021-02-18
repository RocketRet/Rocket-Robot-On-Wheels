#include <include_asm.h>
#include <ultra64.h>

// TODO different assember (nops after c.lt.s)
// f32 func_80099C00(f32 *arg0, f32 arg1)
// {
//     float f0;
//     s32 comp;
//     f0 = arg0[0];
//     if (!(f0 > arg1))
//     {
//         f0 = arg0[1];
//         if (!(f0 < arg1))
//         {
//             f0 = arg1;
//         }
//     }
//     return f0;
// }

INCLUDE_ASM(s32, "codeseg2/codeseg2_434", func_80099C00);
