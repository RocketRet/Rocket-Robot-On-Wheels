#include <include_asm.h>
#include <ultra64.h>
#include <mem.h>

u32 func_80086400(u8 **arg0)
{
    u32 val1 = *((*arg0)++);
    u32 val2 = *((*arg0)++);
    return val2 | (val1 << 8);
}

f32 func_80086428(u8 **arg0)
{
    u8 *curByte;
    f32 ret;
    s32 i;

    curByte = (u8 *)&ret;
    for (i = 3; i != -1; i--)
    {
        *(curByte++) = *((*arg0)++);
    }
    return ret;
}

s32 func_80086468(u8 **arg0)
{
    u8 *curByte;
    s32 ret;
    s32 i;

    curByte = (u8 *)&ret;
    for (i = 3; i != -1; i--)
    {
        *(curByte++) = *((*arg0)++);
    }
    return ret;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_375", func_800864A8);

struct unkD_800AC7F0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    void (*unk10)();
};

extern struct unkD_800AC7F0 *D_800AC7F0[];

// TODO typing
struct unkD_800AC7F0 **func_800872F8(s32 arg0, s32 arg1, s32 arg2)
{
    struct unkD_800AC7F0 **ret;
    struct unkD_800AC7F0 *var;

    var = D_800AC7F0[arg0];
    ret = main_alloc_bzero(var->unkC);
    *ret = var;
    var->unk10(ret, arg1, arg2);
    return ret;
}

// TODO typing
struct unkD_800AC7F0 **func_80087374(s32 **arg0, s32 arg1, s32 arg2)
{
    struct unkD_800AC7F0 **ret;
    struct unkD_800AC7F0 *var;

    var = D_800AC7F0[(*arg0)[1]];
    ret = main_alloc_bzero(var->unkC);
    *ret = var;
    var->unk10(ret, arg1, arg2);
    (*ret)[3].unk10(ret, arg0);
    return ret;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_375", func_80087418);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_375", func_80087554);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_375", func_800875E8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_375", func_80087BF8);

struct unkfunc_80087D4C {
    u8 padding[0x18];
    Vec3f unk18;
    Mtx3f unk24;
    u32 unk48;
    u32 unk4C;
    f32 unk50[6];
};

// TODO couple instructions out of order
#ifdef NON_MATCHING
void func_80087D4C(struct unkfunc_80087D4C *arg0, s32 arg1, u8 *dataPtr) {
    Vec3f axis;
    u8 *endPtr;

    read_vec3f(&dataPtr, arg0->unk18);
    read_vec3f(&dataPtr, axis);
    mtx3f_axis_angle(axis, arg0->unk24);
    // arg2 = arg2 + 2;
    // arg2 = temp_v1 + 4;
    arg0->unk48 = READ_VALUE(dataPtr, s16);
    dataPtr = ALIGN_PTR(dataPtr, 4);
    // arg2 = arg2 + 8;
    arg0->unk50[0] = READ_VALUE(dataPtr, f32);
    arg0->unk50[1] = READ_VALUE(dataPtr, f32);
    arg0->unk50[2] = READ_VALUE(dataPtr, f32);
    arg0->unk50[3] = READ_VALUE(dataPtr, f32);
    arg0->unk50[4] = READ_VALUE(dataPtr, f32);
    arg0->unk50[5] = READ_VALUE(dataPtr, f32);
    dataPtr = ALIGN_PTR(dataPtr, 4) + 4;
    endPtr = &dataPtr[READ_VALUE(dataPtr, u32)] - 8;
    while (endPtr != dataPtr) {
        dataPtr = ALIGN(dataPtr, 2);
        func_80085978(READ_VALUE(dataPtr, u16), &dataPtr, arg0);
    }
    pop_second_heap_state();
}
#else
INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_375", func_80087D4C);
#endif

void func_80087E88(struct unkfunc_80087D4C *arg0, s32 arg1, u8 *dataPtr) {
    f32 *vecPtr;
    s32 i;
    u8 *endPtr;

    dataPtr = ALIGN_PTR(dataPtr, 4);

    vecPtr = arg0->unk18;
    
    for (i = 0; i < 3; i++) {
        vecPtr[i] = READ_VALUE(dataPtr, f32);
    }

    dataPtr = ALIGN_PTR(dataPtr, 4) + 4;
    endPtr = dataPtr + READ_VALUE(dataPtr, u32) - 8;
    while (endPtr != dataPtr) {
        dataPtr = ALIGN_PTR(dataPtr, 2);
        func_80085978(READ_VALUE(dataPtr, u16), &dataPtr, arg0);
    }
    pop_second_heap_state();
}

extern s32 *D_800ADAC8;
extern s32 D_800ADACC;

s32 func_80087F58(s32 arg0) {
    s32 phi_v1 = D_800ADACC;
    s32 *phi_a1 = D_800ADAC8;

    while (--phi_v1 >= 0) {
        if (phi_a1[0] == arg0) {
            return phi_a1[1];
        }
        phi_a1 += 2;
    }
    return 0;
}

