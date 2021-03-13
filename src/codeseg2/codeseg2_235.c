#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "codeseg2/codeseg2_235", func_80064A90);

void func_80064E48(s32, s32);
void func_800912A4(s32, s32);
void func_8006409C(s32 *, s32);

void func_80064DC8(s32 *arg0,s32 arg1)
{
    if (arg1 != arg0[0x8c]) {
        if (arg1 == 2) {
            arg0[0x8f] = -1;
            func_80064E48(arg0,1);
            func_800912A4(9,0xffffffff);
            arg0[0x90] = 1;
        }
        else {
            func_80064E48(arg0,0);
        }
    }
    func_8006409C(arg0,arg1);
}

INCLUDE_ASM(void, "codeseg2/codeseg2_235", func_80064E48, s32, s32);
