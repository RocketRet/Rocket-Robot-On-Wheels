#include <include_asm.h>
#include <ultra64.h>
#include "macros.h"
#include "types.h"

void func_800875E8(struct GameObject *arg0, u32 romAddr, u8 *dataPtr);

struct unkfunc_800454B0 {
    u8 pad[0x2B4];
    f32 unk2B4;
};

void func_800454B0(struct unkfunc_800454B0 *arg0, u32 romAddr, u8 *dataPtr)
{
    arg0->unk2B4 = FLT_MAX;
    func_800875E8((struct GameObject*) arg0, romAddr, dataPtr);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_138", func_800454D8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_138", func_80045580);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_138", func_80045628);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_138", func_8004570C);
