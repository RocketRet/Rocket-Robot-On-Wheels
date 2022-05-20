#include <include_asm.h>
#include <ultra64.h>
#include <types.h>


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_56", func_8002D8B0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_56", func_8002D958);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_56", func_8002DA8C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_56", func_8002DB74);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_56", func_8002DD0C);


s32 func_8002DB74(void*, void*);                    /* extern */
void func_8007A2BC(void*, s32, s32, void*, s32);                 /* extern */
extern struct {
    f32 unk0;
} D_8009FE14;
extern s32 D_800A59A0;

struct unkD_800ABAE0 {
    u8 pad[0x10];
    void (*unk10)(void*, float);
};

extern struct unkD_800ABAE0* D_800ABAE0;
extern u32 D_800ABB30;

#define D_800C00A0 _bssEnd
extern u32 D_800C00A0;

struct unkfunc_8002DF50_inner {
    u8 pad[0xA8];
    void (*unkA8)(void*, float);
};

struct unkfunc_8002DF50 {
    struct unkfunc_8002DF50_inner* unk0;
    u8 pad[0x344];
    s32 unk348;
    f32 unk34C;
    u32 unk350;
    u32 unk354;
    u32 unk358;
    s32 unk35C;
};

s32 func_800830D0(struct unkfunc_8002DF50*, void*);

void func_8002DF50(struct unkfunc_8002DF50* arg0, s32 arg1, void** arg2) {
    s32 phi_s0;
    s32 phi_s2;
    s32 phi_s2_2;
    s32 phi_s0_2;
    s32 phi_s0_2_2;
    struct unkD_800C00A0* temp;

    if (arg1 != 2) {
        if (arg1 == 0x17) {
            phi_s0 = 0;
            if (func_8002DB74(arg0, arg2[0]) && func_800830D0(arg0, arg2[0])) {
                phi_s0 = 1;
            }
            if (phi_s0) {
                s32 phi_s0 = arg0->unk348 == 0;
                s32 phi_s2 = 1;
                if (arg0->unk348 != 1) {
                    if (phi_s0 && arg0->unk354 == 3) {
                        if (D_800A59A0 < arg0->unk35C) {
                            D_800C00A0 = arg0->unk35C;
                            func_8007A2BC(&D_800ABB30, 0xE6, 0, &D_800C00A0, 0);
                            phi_s0 = 0;
                        } else {
                            D_800ABAE0->unk10(&D_800ABAE0, 5.0f);
                        }
                    }
                    arg0->unk348 = phi_s2;
                    arg0->unk34C = D_8009FE14.unk0;
                    if (phi_s0) {
                        arg0->unk0->unkA8(arg0, 0);
                    }
                }
            }
        }
    } else if (func_8002DB74(arg0, arg2[0]) && (arg2[1] == arg0)) {
        s32 phi_s0 = arg0->unk348 == 0;
        s32 phi_s2 = 1;
        if (arg0->unk348 != 1) {
            if (phi_s0 && arg0->unk354 == 3) {
                if (D_800A59A0 < arg0->unk35C) {
                    D_800C00A0 = arg0->unk35C;
                    func_8007A2BC(&D_800ABB30, 0xE6, 0, &D_800C00A0, 0);
                    phi_s0 = 0;
                } else {
                    D_800ABAE0->unk10(&D_800ABAE0, 5.0f);
                }
            }
            arg0->unk348 = phi_s2;
            arg0->unk34C = D_8009FE14.unk0;
            if (phi_s0) {
                arg0->unk0->unkA8(arg0, 0);
            }
        }
    }
}

// INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_56", func_8002DF50);

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

struct unkfunc_8002E4E4 {
    u8 padding[0x244];
    f32 unk244;
    s32 unk248;
};

void func_8002E4E4(struct unkfunc_8002E4E4 *arg0, s32 arg1)
{
    if (arg1 != arg0->unk248)
    {
        arg0->unk248 = arg1;
        arg0->unk244 = D_8009FE14.unk0;
    }
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_56", func_8002E504);
