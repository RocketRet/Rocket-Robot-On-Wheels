#include <include_asm.h>
#include <ultra64.h>

u8 *func_80004AC0(u8 *arg0, u8 *arg1)
{
    arg0[0xB9] = *arg1; // TODO probably a struct
    return arg1 + 1;
}
