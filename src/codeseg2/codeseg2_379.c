#include <include_asm.h>
#include <ultra64.h>

void func_8008ABA0(u16 *arg0, u16 arg1)
{
    arg0[10] &= ~arg1; // TODO probably a struct
}

void func_8008ABB4(u16 *arg0, u16 arg1)
{
    arg0[10] |= arg1; // TODO probably a struct
}

void func_8008ABC4(u16 *arg0, u16 arg1)
{
    arg0[10] &= ~4; // TODO probably a struct
}

void func_8008ABD4(u16 *arg0)
{
    arg0[10] |= 4; // TODO probably a struct
}

void func_8008ABE4(u8 *arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4)
{
    arg0[0x18] = arg1;
    arg0[0x19] = arg2;
    arg0[0x1A] = arg3;
    arg0[0x1B] = arg4;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_379", func_8008ABFC);
