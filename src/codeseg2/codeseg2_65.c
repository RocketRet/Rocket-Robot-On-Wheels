#include <include_asm.h>
#include <ultra64.h>
#include <types.h>


INCLUDE_ASM(s32, "codeseg2/codeseg2_65", func_8002F0C0);

INCLUDE_ASM(s32, "codeseg2/codeseg2_65", func_8002F60C);

void func_8002F674(struct unkfunc_8009C28C *arg0, s32 arg1)
{
    // index[array] again
    arg0->unk3A8++[arg0->unk3AC] = arg1;
}
