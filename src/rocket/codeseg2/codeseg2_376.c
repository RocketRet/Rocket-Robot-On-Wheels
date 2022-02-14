#include <include_asm.h>
#include <ultra64.h>

extern s32 D_800ADACC;
extern s32* D_800ADAC8;

s32 func_80087FA0(s32 arg0) {
    s32 var1 = D_800ADACC;
    s32 *var2 = D_800ADAC8;

    for (var1 = D_800ADACC - 1; var1 >= 0; var1--) {
        if (var2[0] == arg0) {
            return (D_800ADACC - var1) - 1;
        }
        var2 += 2;
    }
    return -1;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_376", func_80087FEC);
