#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_364", func_80084820);

void func_80084894(void) {

}


void func_8008489C(void) {

}

struct unkfunc_80084998 {
    u8 padding[0x22C];
    s32 unk22C;
};


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_364", func_800848A4);

void func_80084998(struct unkfunc_80084998 *arg0, u32 arg1)
{
    s32 val = (arg1 & 0x3) << 28;
    arg0->unk22C = (arg0->unk22C & ~(0x3 << 28)) | val;
}

void func_800849BC(struct unkfunc_80084998 *arg0, u32 arg1)
{
    s32 val = (arg1 & 0x7) << 25;
    arg0->unk22C = (arg0->unk22C & ~(0x7 << 25)) | val;
}

