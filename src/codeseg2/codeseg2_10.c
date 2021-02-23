#include <include_asm.h>
#include <ultra64.h>
#include <types.h>
#include <macros.h>

INCLUDE_ASM(s32, "codeseg2/codeseg2_10", func_8001FD30);

struct unkfunc_8001FDB4 {
    u8 padding[0x48];
    Mtx3f unk48;
    Vec3f unk6C;
};

void vec3f_rotate();
void vec3f_transpose_rotate();

// TODO almost
// void func_8001FDB4(struct unkfunc_8001FDB4 *arg0, struct unkfunc_8001FDB4 *arg1, Vec3f arg2, Vec3f arg3)
// {
//     Vec3f sp10;
//     Vec3f sp20;
//     f32 *src = arg2;
//     if (arg0 != arg1)
//     {
//         if (arg0 != 0)
//         {
//             vec3f_rotate(arg0->unk48, arg2, sp10);
//             VEC3F_ADD(sp10, arg0->unk6C, sp10);
//             src = sp10;
//         }
//         if (arg1 != 0)
//         {
//             VEC3F_SUB(sp20, src, arg1->unk6C);
//             src = arg1;
//             vec3f_transpose_rotate(arg1->unk48, sp20, arg1);
//             return;
//         }
//     }
//     VEC3F_COPY(arg3, src);
// }

INCLUDE_ASM(s32, "codeseg2/codeseg2_10", func_8001FDB4);
