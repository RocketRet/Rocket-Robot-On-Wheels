#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_8001FAF4_sub0 {
    u8 padding[0x5C];
    void (*unk5C)(void *, s32);
};

struct unkfunc_8001FAF4 {
    struct unkfunc_8001FAF4_sub0 *unk0;
};

void func_8001FAB0(struct unkfunc_8001FAF4 *arg0, s32 *arg1)
{
    s32 auStack48[10];

    func_800570D0(arg1, auStack48);
    arg0->unk0->unk5C(arg0, auStack48);
    return;
}

// TODO minor diff
// void func_8001FAF4(struct unkfunc_8001FAF4 *arg0, s32 arg1, s32 arg2, s32 arg3)
// {
//     s32 auStack48 [14];

//     auStack48[0] = arg1;
//     auStack48[1] = arg2;
//     auStack48[2] = arg3;
//     func_800570D0(auStack48 + 0,auStack48 + 4);
//     arg0->unk0->unk5C(arg0, auStack48 + 3); // changing this to be 4 messes everything up, but should be correct
// }

INCLUDE_ASM(s32, "codeseg2/codeseg2_8", func_8001FAF4);

// TODO different compiler
// void func_8001FB44(s32 *arg0, s32 *arg1)
// {
//     s32 sVar1;
//     s32 sVar2;

//     sVar1 = arg1[1];
//     sVar2 = arg1[2];
//     arg0[0x1e] = arg1[0];
//     arg0[0x1f] = sVar1;
//     arg0[0x20] = sVar2;
//     func_8001FD30(arg0, arg1);
//     return;
// }

INCLUDE_ASM(s32, "codeseg2/codeseg2_8", func_8001FB44);

struct unkfunc_8001FB7C {
    struct unkfunc_8001FB7C_sub0 *unk0;
};

struct unkfunc_8001FB7C_sub0 {
    u8 padding[0x60];
    void (*unk60)(void *, void *);
};

void func_8001FB7C(struct unkfunc_8001FB7C *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    s32 arr[3];

    arr[0] = arg1;
    arr[1] = arg2;
    arr[2] = arg3;
    arg0->unk0->unk60(arg0, arr);
}
