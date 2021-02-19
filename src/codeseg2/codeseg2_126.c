#include <include_asm.h>
#include <ultra64.h>

extern u8 *D_800A5994;



u32 func_80042BA0(u32 arg0)
{
    return (*D_800A5994) & (1 << arg0);
}

u32 func_80042BBC(u32 arg0)
{
    return (((*D_800A5994) & 0x7F) ^ 0x7F) < 1;
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_126", func_80042BD8);

u8 func_80042C04()
{
    return *D_800A5994 & 0x80;
}

extern u32 D_800A5970;

INCLUDE_ASM(s32, "codeseg2/codeseg2_126", func_80042C18);

u32 func_80042C48(u32 arg0)
{
    s32 v1 = (D_800A5970 >> 0xB) & 0xFFF;
    return v1 & (1 << arg0);
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_126", func_80042C68);

INCLUDE_ASM(s32, "codeseg2/codeseg2_126", func_80042CA4);

INCLUDE_ASM(s32, "codeseg2/codeseg2_126", func_80042D1C);

INCLUDE_ASM(s32, "codeseg2/codeseg2_126", func_8004303C);
