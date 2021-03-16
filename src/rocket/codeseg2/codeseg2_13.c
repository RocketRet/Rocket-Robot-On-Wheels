#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_80020730 {
    u8 padding[0xD8];
    u32 unkD8;
};

void func_80020730(struct unkfunc_80020730 *arg0, s32 arg1)
{
    arg0->unkD8 = arg1;
}

struct unkfunc_8002075C {
    u8 padding[0x110];
    s32 unk110;
};

void func_80020738(struct unkfunc_8002075C *arg0, u32 arg1)
{
    s32 val = (arg1 & 0x3) << 22;
    arg0->unk110 = (arg0->unk110 & ~(0x3 << 22)) | val;
}

void func_8002075C(struct unkfunc_8002075C *arg0, u32 arg1)
{
    s32 val = (arg1 & 0x3) << 20;
    arg0->unk110 = (arg0->unk110 & ~(0x3 << 20)) | val;
}

