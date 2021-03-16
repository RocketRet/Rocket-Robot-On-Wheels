#include <include_asm.h>
#include <ultra64.h>

u32 func_80086400(u8 **arg0)
{
    u32 val1 = *((*arg0)++);
    u32 val2 = *((*arg0)++);
    return val2 | (val1 << 8);
}

f32 func_80086428(u8 **arg0)
{
    u8 *curByte;
    f32 ret;
    s32 i;

    curByte = (u8 *)&ret;
    for (i = 3; i != -1; i--)
    {
        *(curByte++) = *((*arg0)++);
    }
    return ret;
}

s32 func_80086468(u8 **arg0)
{
    u8 *curByte;
    s32 ret;
    s32 i;

    curByte = (u8 *)&ret;
    for (i = 3; i != -1; i--)
    {
        *(curByte++) = *((*arg0)++);
    }
    return ret;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_375", func_800864A8);

struct unkD_800AC7F0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    void (*unk10)();
};

extern struct unkD_800AC7F0 *D_800AC7F0[];

void *main_alloc_bzero(s32);

// TODO typing
struct unkD_800AC7F0 **func_800872F8(s32 arg0, s32 arg1, s32 arg2)
{
    struct unkD_800AC7F0 **ret;
    struct unkD_800AC7F0 *var;

    var = D_800AC7F0[arg0];
    ret = main_alloc_bzero(var->unkC);
    *ret = var;
    var->unk10(ret, arg1, arg2);
    return ret;
}

// TODO typing
struct unkD_800AC7F0 **func_80087374(s32 **arg0, s32 arg1, s32 arg2)
{
    struct unkD_800AC7F0 **ret;
    struct unkD_800AC7F0 *var;

    var = D_800AC7F0[(*arg0)[1]];
    ret = main_alloc_bzero(var->unkC);
    *ret = var;
    var->unk10(ret, arg1, arg2);
    (*ret)[3].unk10(ret, arg0);
    return ret;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_375", func_80087418);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_375", func_80087554);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_375", func_800875E8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_375", func_80087BF8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_375", func_80087D4C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_375", func_80087E88);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_375", func_80087F58);
