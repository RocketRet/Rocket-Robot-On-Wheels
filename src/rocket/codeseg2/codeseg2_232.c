#include <include_asm.h>
#include <ultra64.h>

extern s32 D_800AC2E0;
extern u16 D_800A58F0;

void func_80078244(s32, s32, f32);
void func_80041A54();
void func_80041F08(s32);
void func_80041AD0(s32);
void func_80078170(void*, s32);
u32 func_80042A50(s32 arg0, u16 *arg1);
void func_8007F378(s32);
void func_80043EF0();
void func_800625D8(void*, s32);
void func_8002A86C(s32, s32);

void func_80063840(s32 arg0)
{
    func_80041A54();
    func_80041F08(arg0);
    if (arg0 >= 0)
    {
        s32 tmp;
        func_80041AD0(arg0);
        func_80078170(&D_800AC2E0, 0);
        if (func_80042A50(0, &D_800A58F0))
        {
            tmp = 5;
        }
        else
        {
            tmp = 7;
        }
        func_80078244(tmp, -1, 0.3f);
    }
    else
    {
        func_8007F378(0);
    }
}

void func_800638CC()
{
    func_80043EF0();
}

struct unkD_800ABC90 {
    u8 padding[0x48];
    s32 unk48;
};

extern struct unkD_800ABC90 D_800ABC90;

void func_80041A54(void);
void func_80078244(s32, s32, f32);

void func_800638EC()
{
    func_80041A54();
    D_800ABC90.unk48 = -1;
    func_800625D8(&D_800ABC90, 0);
    func_80078244(2, -1, 1.0f);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_232", func_80063934);

void func_80063A88(s32 arg0)
{
    func_8002A86C(arg0, 0xC);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_232", func_80063AA8);
