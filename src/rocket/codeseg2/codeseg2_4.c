#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_4", func_8001E330);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_4", func_8001E504);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_4", func_8001E69C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_4", func_8001E824);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_4", func_8001E954);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_4", func_8001EA18);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_4", func_8001ECEC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_4", func_8001F128);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_4", func_8001F2A4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_4", func_8001F36C);

struct unkfunc_8001F4DC{
    u8 padding[0xEC];
    void *unkEC;
};

void *main_alloc_bzero(s32);

void func_8001F4DC(struct unkfunc_8001F4DC *arg0)
{
    if (arg0->unkEC == NULL)
    {
        arg0->unkEC = main_alloc_bzero(0x30);
    }
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_4", func_8001F518);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_4", func_8001F7A4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_4", func_8001F82C);
