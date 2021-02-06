#include <include_asm.h>
#include <ultra64.h>


void func_80046A90(s32 *arg0)
{
    arg0[0] = 0;
    arg0[1] = 0;
    arg0[2] = 0;
    arg0[3] = 0;
    arg0[4] = 0;
    arg0[5] = 0;
}

s32 func_800614BC(s32, s32);

// TODO different compiler
void func_80046AAC(s32 *arg0, s32 *arg1)
{  
    arg0[0] = arg1[0];
    arg0[1] = func_800614BC(arg1[0] * 12,arg1[1]);
    arg0[2] = arg1[2];
    arg0[3] = func_800614BC(arg1[2] * 24,arg1[3]);
    arg0[4] = arg1[4];
    arg0[5] = arg1[5];
}

// INCLUDE_ASM(s32, "codeseg2/codeseg2_148", func_80046AAC);
