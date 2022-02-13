#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_346", func_80081D60);

struct unkfunc_80081E20 {
    u8 padding[0x64];
    void (*unk64)(struct unkfunc_80081E20 **, s32 *);
};

void func_80081E20(struct unkfunc_80081E20 **arg0, s32 arg1, s32 arg2, s32 arg3)
{
    s32 var[3];
    var[0] = arg1;
    var[1] = arg2;
    var[2] = arg3;

    (*arg0)->unk64(arg0, var);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_346", func_80081E54);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_346", func_80081F04);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_346", func_80081FB8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_346", func_8008208C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_346", func_80082414);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_346", func_800824A0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_346", func_80082838);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_346", func_800829B0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_346", func_80082A78);

void func_80082DD8(void) {

}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_346", func_80082DE0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_346", func_8008302C);
