#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_388", func_8008CCA0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_388", func_8008CCE8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_388", func_8008CD78);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_388", func_8008CE0C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_388", func_8008CE9C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_388", func_8008CEF4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_388", func_8008CFB4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_388", func_8008D0BC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_388", func_8008D0F8);

// TODO types
void func_8008D18C(s32 *arg0, s32 **arg1)
{
    arg0[2] = *arg1;
    arg0[3] = 0;
    if (*arg1)
    {
        (*arg1)[3]  = arg0;
    }
    *arg1 = arg0;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_388", func_8008D1AC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_388", func_8008D20C);
