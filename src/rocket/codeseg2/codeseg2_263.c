#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_263", func_8006B4B0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_263", func_8006B560);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_263", func_8006B648);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_263", func_8006B700);

//INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_263", func_8006B76C);

s32 func_8008C590(s32, void*);                        /* extern */

typedef struct
{
    u8 pad0[0xC];
    s32 unkC;
    u8 pad1[0x104];
    s32 unk114;
} struct_func_8006B76C;

void func_8006B76C(struct_func_8006B76C* arg0, s32 arg1)
{
    s32 temp_v0;

    temp_v0 = arg0->unk114;
    if (arg1 != temp_v0) {
        if (temp_v0 == 0) {
            func_8008C590(arg0->unkC, arg0);
        }
        arg0->unk114 = arg1;
    }
}
