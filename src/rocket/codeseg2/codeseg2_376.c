#include <include_asm.h>
#include <ultra64.h>


struct unkD_800ADAC8 {
    s32 id;
    u32 romAddress;
};

extern s32 D_800AC790[];
extern s32 D_800AC7E4[];
extern struct unkD_800ADAC8 *D_800ADAC8;
extern s32 D_800ADACC;
extern s32 D_800AAF7C;

extern struct unkD_800AAF80 {
    u32 unk0;
    u32 unk4;
    Gfx *unk8;
} D_800AAF80;

s32 func_80087FA0(s32 id) {
    s32 remaining;
    struct unkD_800ADAC8 *curEntry;

    remaining = D_800ADACC;
    remaining--;
    curEntry = D_800ADAC8;

    while (remaining >= 0) {
        if (curEntry->id == id) {
            return (D_800ADACC - remaining) - 1;
        }
        remaining--;
        curEntry++;
    }
    return -1;
}

// TODO reorder
#ifdef NON_MATCHING
void func_80087FEC(struct unkfunc_800882B8* arg0) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 phi_a0;
    u32 romAddress;
    s32 i;
    s32 i2;
    struct unkD_800ADAC8 *test;

    adjust_texture_table();
    D_800AAF80.unk4 = NULL;
    D_800AAF7C = 0;
    D_800AAF80.unk4 = 0x18;
    arg0->unkC4 = 0x01000000;
    arg0->unk130 = -1;
    arg0->unk38 = 0;
    phi_a0 = D_800ADACC;
    phi_a0--;
    test = D_800ADAC8;
    while (1) {
        if (phi_a0 >= 0) {
            if (test->id == 0) {
                romAddress = test->romAddress;
                break;
            }
            test++;
            phi_a0--;
        }
        if (phi_a0 < 0) {
            romAddress = 0;
            break;
        }
    }
    func_800882B8(arg0, romAddress, 0);
    func_8008C590(arg0, func_8008BE8C(arg0, 0x53));
    for (i = 0; i < 21; i++) {
        temp_v0 = func_8008BE8C(arg0, D_800AC790[i]);
        if (temp_v0 != 0) {
            arg0->unkC8[i] = temp_v0;
            func_80050D5C(temp_v0);
        }
    }
    for (i2 = 0; i2 < 3; i2++) {
        temp_v0_2 = func_8008BE8C(arg0, D_800AC7E4[i2]);
        if (temp_v0_2 != 0) {
            arg0->unk11C[i2] = temp_v0_2;
            func_80050D5C(temp_v0_2);
        }
    }
    func_80074A80(&D_800AB9C8);
}
#else
INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_376", func_80087FEC);
#endif
