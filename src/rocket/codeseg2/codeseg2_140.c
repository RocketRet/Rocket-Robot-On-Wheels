#include <include_asm.h>
#include <ultra64.h>
#include "macros.h"

struct unkfunc_80045810 {
    u8 padding[0x234];
    u32 unk234;
};

void func_80045810(struct unkfunc_80045810 *arg0, s32 arg1, u8 *dataPtr)
{
    arg0->unk234 = 3;
    func_800875E8(arg0, arg1, dataPtr);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_140", func_80045834);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_140", func_800458E4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_140", func_80045A54);

void func_80045B60(f32 *arg0, s32 arg1, u8 *dataPtr)
{
    arg0[0x8F] = FLT_MAX;
    func_800875E8(arg0, arg1, dataPtr);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_140", func_80045B88);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_140", func_80045BE0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_140", func_80045C40);

void func_80045D78(s32 *arg0, s32 arg1, u8 *dataPtr)
{
    arg0[0x8C] = -1;
    func_800875E8(arg0, arg1, dataPtr);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_140", func_80045D9C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_140", func_80045E14);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_140", func_80045ED8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_140", func_80045F54);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_140", func_8004612C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_140", func_80046198);
