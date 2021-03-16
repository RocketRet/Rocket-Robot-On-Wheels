#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_25", func_80024410);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_25", func_80024508);

struct unkfunc_8002490C {
    u8 padding[0x40];
    struct unkfunc_8002490C *unk40;
};

struct unkfunc_8002490C_2 {
    s32 unk0;
    s32 unk4;
    u8 padding[0x30 - 0x08];
    struct unkfunc_8002490C_2 *unk30;
};

struct unkfunc_8002490C_2 *func_8002490C(struct unkfunc_8002490C *arg0, s32 arg1)
{
    struct unkfunc_8002490C_2 *v1 = arg0->unk40;
    while (v1)
    {
        if (v1->unk4 == arg1)
            return v1;
        v1 = v1->unk30;
    }
    return NULL;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_25", func_80024938);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_25", func_800249EC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_25", func_80024A7C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_25", func_80024B0C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_25", func_80024BF8);
