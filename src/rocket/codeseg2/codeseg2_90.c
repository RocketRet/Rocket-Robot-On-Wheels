#include <include_asm.h>
#include <ultra64.h>
#include "types.h"

struct unkfunc_80037EF0 {
    u8 pad[0x3A8];
    s32 unk3A8;
};

void func_800875E8(struct GameObject *arg0, u32 romAddr, u8 *dataPtr);

void func_80037EF0(struct unkfunc_80037EF0 *arg0, u32 romAddr, u8 *dataPtr)
{
    arg0->unk3A8 = -1;
    func_800875E8((struct GameObject*) arg0, romAddr, dataPtr);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_90", func_80037F14);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_90", func_80038104);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_90", func_800382B0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_90", func_80038468);
