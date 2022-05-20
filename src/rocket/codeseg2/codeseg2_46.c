#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_46", func_8002B5A0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_46", func_8002B604);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_46", func_8002B734);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_46", func_8002B78C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_46", func_8002B7D4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_46", func_8002BA34);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_46", func_8002BB84);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_46", func_8002BFE4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_46", func_8002C064);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_46", func_8002C0A0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_46", func_8002C0E0);

struct unkfunc_8002C154 {
    u8 padding[0x230];
    u32 unk230;
    f32 unk234;
};

extern struct {
    f32 unk0;
} D_8009FE14;

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_46", func_8002C120);

void func_8002C154(struct unkfunc_8002C154 *arg0, s32 arg1)
{
    if (arg1 != arg0->unk230)
    {
        arg0->unk230 = arg1;
        arg0->unk234 = D_8009FE14.unk0;
    }
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_46", func_8002C174);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_46", func_8002C25C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_46", func_8002C320);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_46", func_8002C390);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_46", func_8002C468);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_46", func_8002C4F0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_46", func_8002C63C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_46", func_8002C77C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_46", func_8002CC44);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_46", func_8002CCCC);
