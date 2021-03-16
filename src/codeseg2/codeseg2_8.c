#include <include_asm.h>
#include <ultra64.h>
#include <macros.h>
#include <types.h>

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

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_8", func_8001FAF4);

struct unkfunc_8001FB44 {
    u8 padding[0x78];
    Vec3f unk1E;
};

void func_8001FD30();

void func_8001FB44(struct unkfunc_8001FB44 *arg0, Vec3f arg1)
{
    VEC3F_COPY(&arg0->unk1E, arg1);
    func_8001FD30();
}

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
