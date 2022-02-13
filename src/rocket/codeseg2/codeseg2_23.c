#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_23", func_800221F0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_23", func_8002243C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_23", func_800227FC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_23", func_80022928);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_23", func_800229A0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_23", func_80022A1C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_23", func_80022B6C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_23", func_80022CE8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_23", func_80022D38);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_23", func_80023008);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_23", func_80023084);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_23", func_800233B8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_23", func_80023418);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_23", func_800234DC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_23", func_80023554);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_23", func_800235DC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_23", func_80024314);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_23", func_80024410);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_23", func_80024508);

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

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_23", func_80024938);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_23", func_800249EC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_23", func_80024A7C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_23", func_80024B0C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_23", func_80024BF8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_23", func_80024C80);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_23", func_80024D74);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_23", func_80024DB8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_23", func_8002504C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_23", func_800251D8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_23", func_8002526C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_23", func_80025AFC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_23", func_80025DDC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_23", func_80025E98);

void func_8002603C()
{

}
