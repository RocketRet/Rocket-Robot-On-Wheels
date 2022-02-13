#include <include_asm.h>
#include <ultra64.h>

extern s32 D_8009F094;
extern s32 D_800A5874;

void func_800914A8(float);
void func_80095440(s32, s32, s32, s32);
void func_8007F1F4(s32* arg0);
void func_8007F368(s32* arg0, u32 arg1);
void func_80039C34(s32* arg0);

void func_8007F1D0()
{
    func_8007F1F4(&D_8009F094);
}

void func_8007F1F4(s32* arg0) {
    func_80039C34(arg0 + 1);
    func_8007F368(arg0, 0);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_332", func_8007F22C);

extern s32 D_8009FE10;

void func_8007F368(s32* arg0, u32 arg1)
{
    D_8009FE10 = arg1 < 1;
}

void func_8007F378() {
    func_800914A8(0.0f);
    func_80095440(0, D_800A5874, -1, -1);
}
