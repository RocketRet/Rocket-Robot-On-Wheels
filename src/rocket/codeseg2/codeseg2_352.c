#include <include_asm.h>
#include <ultra64.h>
#include <types.h>


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_352", func_800830D0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_352", func_800831C8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_352", func_80083224);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_352", func_800833BC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_352", func_800834F4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_352", func_800835FC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_352", func_800836F0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_352", func_80083734);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_352", func_8008388C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_352", func_8008392C);

struct unkfunc_80083A10 {
    u8 padding[0x1E4];
    void *unk1E4;
    u8 padding2[0x22C - 4 - 0x1E4];
    s32 unk22C;
};

void func_80083A10(struct unkfunc_80083A10 *arg0, void **arg1)
{
    arg1[2] = arg0->unk1E4;
    arg0->unk1E4 = arg1;
    arg0->unk22C &= 0x7FFFFFFF;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_352", func_80083A34);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_352", func_80083A80);

struct unkfunc_800841C4 {
    u8 padding[0x170];
    s32 unk170;
    u8 padding2[0x22C - 0x170 - 0x04];
    s32 unk22C;
};

void func_80084030(struct unkfunc_800841C4 *arg0, s32 arg1)
{
    arg0->unk170 = arg1;
    arg0->unk22C |= 0x00800000;
}

void func_80084048(struct unkfunc_800841C4 *arg0)
{
    arg0->unk22C |= 0x00080000;
}

void func_8008408C(s32, Vec3f);

void func_8008405C(s32 arg0, f32 arg1)
{
    Vec3f vec;
    vec[2] = arg1;
    vec[1] = arg1;
    vec[0] = 0;
    func_8008408C(arg0, vec);
}

INCLUDE_ASM(void, "rocket/codeseg2/codeseg2_352", func_8008408C, s32, Vec3f);

void func_80084140(s32, Vec3f);

void func_80084110(s32 arg0, f32 arg1)
{
    Vec3f vec;
    vec[2] = arg1;
    vec[1] = arg1;
    vec[0] = 0;
    func_80084140(arg0, vec);
}

INCLUDE_ASM(void, "rocket/codeseg2/codeseg2_352", func_80084140, s32, Vec3f);

void func_800841C4(struct unkfunc_800841C4 *arg0)
{
    arg0->unk22C |= 0x00040000;
}

void func_80084208(s32, Vec3f);

void func_800841D8(s32 arg0, f32 arg1)
{
    Vec3f vec;
    vec[2] = arg1;
    vec[1] = arg1;
    vec[0] = 0;
    func_80084208(arg0, vec);
}

INCLUDE_ASM(void, "rocket/codeseg2/codeseg2_352", func_80084208, s32, Vec3f);

void func_800842BC(s32, Vec3f);

void func_8008428C(s32 arg0, f32 arg1)
{
    Vec3f vec;
    vec[2] = arg1;
    vec[1] = arg1;
    vec[0] = 0;
    func_800842BC(arg0, vec);
}

INCLUDE_ASM(void, "rocket/codeseg2/codeseg2_352", func_800842BC, s32, Vec3f);

void func_80084340(s32 *arg0)
{
    arg0[0x6E] = 3;
    arg0[0x6A] = 3;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_352", func_80084350);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_352", func_800843B0);

void func_80084410(struct unkfunc_800841C4 *arg0)
{
    arg0->unk22C |= 0x00100000;
}

void func_80084424(struct unkfunc_800841C4 *arg0)
{
    arg0->unk22C &= ~0x00100000;
}

void func_8008443C(struct unkfunc_800841C4 *arg0)
{
    arg0->unk22C |= 0x00008000;
}

void func_8008444C(struct unkfunc_800841C4 *arg0)
{
    arg0->unk22C |= 0x00004000;
}

void func_8008445C(struct unkfunc_800841C4 *arg0)
{
    arg0->unk22C &= ~0x00004000;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_352", func_80084470);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_352", func_800844DC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_352", func_8008455C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_352", func_800845D8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_352", func_80084658);

// s32 func_800846D8(s32 *arg0, s32 arg1)
// {
//     // s32 ret;
//     if (arg0[0x50] <= 0 && (arg0[0x8B] & (1 << 23)) == 0)
//     {
//         // s32 val = arg0[0x8B] & (1 << 23);
//         // if (val)
//         // {
//             arg1 = 0;
//         // }
//     }
//     else
//     {
//         arg1 = 1;
//     }
//     return arg1;
// }

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_352", func_800846D8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_352", func_80084704);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_352", func_80084794);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_352", func_80084820);

void func_80084894(void) {

}


void func_8008489C(void) {

}

struct unkfunc_80084998 {
    u8 padding[0x22C];
    s32 unk22C;
};


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_352", func_800848A4);

void func_80084998(struct unkfunc_80084998 *arg0, u32 arg1)
{
    s32 val = (arg1 & 0x3) << 28;
    arg0->unk22C = (arg0->unk22C & ~(0x3 << 28)) | val;
}

void func_800849BC(struct unkfunc_80084998 *arg0, u32 arg1)
{
    s32 val = (arg1 & 0x7) << 25;
    arg0->unk22C = (arg0->unk22C & ~(0x7 << 25)) | val;
}
