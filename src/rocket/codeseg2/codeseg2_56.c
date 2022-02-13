#include <include_asm.h>
#include <ultra64.h>
#include <types.h>


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_56", func_8002D8B0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_56", func_8002D958);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_56", func_8002DA8C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_56", func_8002DB74);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_56", func_8002DD0C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_56", func_8002DF50);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_56", func_8002E0C8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_56", func_8002E10C);

void func_8002E3D0(struct unkfunc_8009C28C *arg0, s32 arg1)
{
    arg0->unk234[arg0->unk230++] = arg1;
}

void func_8002E3EC(struct unkfunc_8009C28C *arg0, s32 arg1)
{
    arg0->unk2BC[arg0->unk2B8++] = arg1;
}

void func_8002E408(struct unkfunc_8009C28C *arg0, s32 arg1)
{
    arg0->unk2E0[arg0->unk2DC++] = arg1;
}

void func_8002E424(struct unkfunc_8009C28C *arg0, s32 arg1)
{
    arg0->unk304[arg0->unk300++] = arg1;
}

void func_8002E440(struct unkfunc_8009C28C *arg0, s32 arg1)
{
    arg0->unk328[arg0->unk324++] = arg1;
}

struct unkfunc_8002E45C {
    u8 padding[0x240];
    s32 unk240;
};

void func_8002E45C(struct unkfunc_8002E45C *arg0, s32 arg1, u8 *dataPtr)
{
    arg0->unk240 = 0xC7;
    func_800875E8(arg0, arg1, dataPtr);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_56", func_8002E480);

extern f32 D_8009FE14;

struct unkfunc_8002E4E4 {
    u8 padding[0x244];
    f32 unk244;
    s32 unk248;
};

// TODO reorder
// void func_8002E4E4(struct unkfunc_8002E4E4 *arg0, s32 arg1)
// {
//     if (arg1 != arg0->unk248)
//     {
//         arg0->unk248 = arg1;
//         arg0->unk244 = D_8009FE14;
//     }
// }

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_56", func_8002E4E4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_56", func_8002E504);
