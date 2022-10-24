#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_80063B70 {
    u8 padding[0x1A8];
    s32 unk1A8;
    s32 unk1AC;
    s32 unk1B0;
    s32 unk1B4;
    s32 unk1B8;
};

void func_80063B70(struct unkfunc_80063B70 *arg0)
{
    func_8007F580();
    arg0->unk1A8 = 3;
    arg0->unk1B8 = 3;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_233", func_80063BA4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_233", func_80063C84);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_233", func_80063D58);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_233", func_80063E0C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_233", func_80063F64);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_233", func_80063FE4);

INCLUDE_ASM(void, "rocket/codeseg2/codeseg2_233", func_8006409C, s32 *, s32);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_233", func_8006424C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_233", func_80064294);
INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_233", func_800642D0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_233", func_8006432C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_233", func_800643B4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_233", func_8006459C);

struct unkfunc_80064758 {
    u8 padding[0x10];
    s32 unk10;
    u8 padding2[0x260 - 0x10 - 0x04];
    s32 unk260;
};

void func_80064758(struct unkfunc_80064758 *arg0)
{
    arg0->unk260 = arg0->unk10;
    func_800824A0();
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_233", func_8006477C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_233", func_80064848);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_233", func_80064958);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_233", func_800649C8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_233", func_80064A48);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_233", func_80064A90);

void func_80064E48(s32, s32);
void func_800912A4(s32, s32);
void func_8006409C(s32 *, s32);

void func_80064DC8(s32 *arg0,s32 arg1)
{
    if (arg1 != arg0[0x8c]) {
        if (arg1 == 2) {
            arg0[0x8f] = -1;
            func_80064E48(arg0,1);
            func_800912A4(9,0xffffffff);
            arg0[0x90] = 1;
        }
        else {
            func_80064E48(arg0,0);
        }
    }
    func_8006409C(arg0,arg1);
}

INCLUDE_ASM(void, "rocket/codeseg2/codeseg2_233", func_80064E48, s32, s32);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_233", func_80065110);

struct unkfunc_800824A0 {
    u8 padding[0x10];
    s32 unk10;
    u8 padding2[0x268 - 0x04 - 0x10];
    s32 unk268;
};

void func_80065170(struct unkfunc_800824A0 *arg0)
{
    arg0->unk268 = arg0->unk10;
    func_800824A0();
}

struct unkfunc_80065194 {
    u8 unk0[0x244];
    f32 unk244;
    u32 unk248;
    struct unkfunc_80065194 *unk24C[6];
    u32 unk264;
    struct unkfunc_80065194 *unk268;
};

void func_80065194(struct unkfunc_80065194 *arg0)
{
    s32 var;
    func_80083734();
    arg0->unk268->unk24C[arg0->unk264] = arg0;
    var = 6;
    if (arg0->unk264 & 1)
    {
        var = 5;
    }
    func_800652F4(arg0, var);
    arg0->unk244 = -1.0f;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_233", func_800651F8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_233", func_800652F4);

struct unkfunc_800654D4 {
    u8 padding[0x10];
    s32 unk10;
    u8 padding2[0x238 - 0x04 - 0x10];
    s32 unk238;
};

void func_800654D4(struct unkfunc_800654D4 *arg0)
{
    arg0->unk238 = arg0->unk10;
    func_800824A0();
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_233", func_800654F8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_233", func_80065544);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_233", func_80065620);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_233", func_80065754);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_233", func_80065808);

const s32 D_8001C5B8[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 0};

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_233", func_8006589C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_233", func_80065FF0);

struct unkfunc_80066038 {
    u8 padding[0x238];
    struct unkfunc_80066038_2 *unk238;
};

struct unkfunc_80066038_2 {
    u8 padding[0x278];
    s32 unk278;
};

void func_80066038(struct unkfunc_80066038 *arg0)
{
    func_80083734(arg0);
    arg0->unk238->unk278 = arg0;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_233", func_80066068);

extern struct {
    f32 unk0;
} D_8009FE14;

struct unkfunc_800660F8 {
    u8 padding[0x230];
    s32 unk230;
    f32 unk234;
};

void func_800660F8(struct unkfunc_800660F8 *arg0, s32 arg1)
{
    if (arg1 != arg0->unk230)
    {
        arg0->unk230 = arg1;
        arg0->unk234 = D_8009FE14.unk0;
    }
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_233", func_80066118);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_233", func_80066154);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_233", func_8006625C);
