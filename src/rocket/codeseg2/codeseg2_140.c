#include <include_asm.h>
#include <ultra64.h>
#include "macros.h"
#include "types.h"

struct unkfunc_80045810 {
    u8 padding[0x230];
    s32 unk230;
    s32 unk234;
    s32 pad238;
    f32 unk23C;
};

void func_800875E8(struct GameObject *arg0, u32 romAddr, u8 *dataPtr);

void func_80045810(struct unkfunc_80045810 *arg0, u32 romAddr, u8 *dataPtr)
{
    arg0->unk234 = 3;
    func_800875E8((struct GameObject*) arg0, romAddr, dataPtr);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_140", func_80045834);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_140", func_800458E4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_140", func_80045A54);

struct unkfunc_80045B60 {
    u8 pad[0x23C];
    f32 unk23C;
};

void func_80045B60(struct unkfunc_80045810 *arg0, u32 romAddr, u8 *dataPtr)
{
    arg0->unk23C = FLT_MAX;
    func_800875E8((struct GameObject*) arg0, romAddr, dataPtr);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_140", func_80045B88);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_140", func_80045BE0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_140", func_80045C40);

void func_80045D78(struct unkfunc_80045810 *arg0, u32 romAddr, u8 *dataPtr)
{
    arg0->unk230 = -1;
    func_800875E8((struct GameObject*) arg0, romAddr, dataPtr);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_140", func_80045D9C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_140", func_80045E14);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_140", func_80045ED8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_140", func_80045F54);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_140", func_8004612C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_140", func_80046198);
