#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "codeseg2/codeseg2_272", func_8006C870);

extern s32 D_800AB6C4;
extern s32 D_800AB6C8[];

void func_8006C968(s32 arg0)
{
    D_800AB6C8[D_800AB6C4++] = arg0;
}
