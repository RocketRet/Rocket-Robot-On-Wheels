#include <include_asm.h>
#include <ultra64.h>
#include "macros.h"

void func_80085094(s32*);
void func_80084A88(s32*);


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_71", func_80031FB0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_71", func_8003202C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_71", func_80032454);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_71", func_800324A8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_71", func_80032564);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_71", func_800325D8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_71", func_8003269C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_71", func_80032974);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_71", func_80032A20);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_71", func_80032C74);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_71", func_80032E24);

const u32 D_8001A8FC = 0xFF0000FF;
const u32 D_8001A900 = 0xFFFFFFFF;

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_71", func_80033468);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_71", func_800338B0);

struct unkfunc_800338D0 {
    u8 padding[0x258];
    s32 unk258;
};

void func_800338D0(s32 arg0, struct unkfunc_800338D0 *arg1)
{
    arg1->unk258 = 0;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_71", func_800338D8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_71", func_80033958);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_71", func_80033A24);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_71", func_80033FFC);

struct unkfunc_80034124 {
    u8 padding[0x2C8];
    s32 unk2C8;
};

void func_80034124(struct unkfunc_80034124 *arg0)
{
    func_80085094(&arg0->unk2C8);
}

void func_80034144(struct unkfunc_80034124 *arg0)
{
    func_80084A88(&arg0->unk2C8);
}

struct unkfunc_80034164 {
    u8 padding[0x278];
    s32 unk278;
};

void func_80034164(struct unkfunc_80034164 *arg0)
{
    func_80085094(&arg0->unk278);
}

void func_80034184(struct unkfunc_80034164 *arg0)
{
    func_80084A88(&arg0->unk278);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_71", func_800341A4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_71", func_80034294);
