#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "codeseg2/codeseg2_257", func_8006A430);

INCLUDE_ASM(s32, "codeseg2/codeseg2_257", func_8006A5D8);

struct unkfunc_8006A654 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

void func_8006A654(s32 arg0, struct unkfunc_8006A654 *arg1)
{
    arg0--;
    while (arg0 >= 0)
    {
        arg1->unk0 = -1;
        arg0--;
        arg1++;
    }
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_257", func_8006A67C);
