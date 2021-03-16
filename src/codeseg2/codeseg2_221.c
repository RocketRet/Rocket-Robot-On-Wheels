#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_221", func_8005FC10);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_221", func_8005FC44);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_221", func_800601A4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_221", func_800605A4);

void func_80060794(s32 arg0)
{
    func_8004C44C(arg0 + 0x3A4);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_221", func_800607B4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_221", func_8006096C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_221", func_80060DE4);

void func_80060E5C(void) {

}

struct unkfunc_80060E64_sub {
    u8 padding[0x2C];
    void (*unk2C)(s32, s32);
};

struct unkfunc_80060E64 {
    struct unkfunc_80060E64_sub *unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    u8 padding[0x230 - 0x10 - 0x04];
    s32 unk230;
};

// called by func_80050E24 via jalr with return address 0x80051050
// seems to get called on level load
// arg0->unk0->unk2C seems to always be func_800824A0
void func_80060E64(struct unkfunc_80060E64 *arg0)
{
    func_80083734(arg0);
    arg0->unk230 = arg0->unk10;
    arg0->unk0->unk2C(arg0, 0);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_221", func_80060EA8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_221", func_80061038);

s32 func_800611A4(s32 arg0, s32 *arg1)
{
    if (arg1[1] != 2)
    {
        return func_800800F0();
    }
    else
    {
        return 1;
    }    
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_221", func_800611D4);
