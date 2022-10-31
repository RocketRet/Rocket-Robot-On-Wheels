#include <include_asm.h>
#include <ultra64.h>

s32 func_80041A30(s32 arg0)
{
    s32 ret;
    if (arg0 < 80)
    {
        ret = 1;
    }
    else if (arg0 < 96)
    {
        ret = 5;
    }
    else
    {
        ret = 10;
    }
    return ret;
}

extern u8 D_800A58F0[0x88];
extern s32 D_800A63C4;

void func_8007A158();

void func_80041A54()
{
    bzero(D_800A58F0, sizeof(D_800A58F0));
    func_8007A158();
    D_800A63C4 = 0;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_118", func_80041A88);
