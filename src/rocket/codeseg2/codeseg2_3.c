#include <include_asm.h>
#include <ultra64.h>
#include <mem.h>
#include <types.h>
#include <macros.h>

struct unkfunc_8001DFD0 {
    u8 padding[0xE0];
    u16 unkE0;
    u16 unkE2;
    u32 unkE4;
    u32 unkE8;
    u32 unkEC;
    u32 unkF0;
    u32 unkF4;
    u32 unkF8;
    u32 unkFC;
    u32 unk100;
    f32 unk104;
    u32 unk108;
    u32 unk10C;
    s32 unk110_0 : 8;
    s32 unk110_8 : 2;
    s32 unk110_10 : 2;
    s32 unk110_12 : 5;
    s32 unk110_17 : 1;
};

extern f32 D_80019FB0;

void func_8001DFD0(struct unkfunc_8001DFD0 *arg0)
{
    func_80050868();
    arg0->unk110_8 = 3;
    arg0->unk110_10 = 3;
    arg0->unk110_0 = 0xff;
    arg0->unkE0 = 0x10;
    arg0->unk104 = D_80019FB0;
    arg0->unk108 = 0x7fffffff;
    arg0->unk110_17 = 1;
}

void func_80085D04(u8 **dataPtrPtr, Vec3f arg1, Mtx3f arg2);

void func_8001E044(struct Model *arg0, s32 arg1, u8 *dataPtr)
{
    s32 decompressedSize;
    void *decompressedBytes;
    s32 compressedSize;
    s32 vertexStorageFlags;
    struct Submodel *submodelBuffer;

    func_80085D04(&dataPtr, &arg0->unk3C, &arg0->unk18);
    func_80085C68(&dataPtr, arg0);
    push_second_heap_state();
    submodelBuffer = alloc_second_heap(512 * sizeof(struct Submodel));

    arg0->submodels = submodelBuffer;

    dataPtr = ALIGN_PTR(dataPtr, 4);
    vertexStorageFlags = READ_VALUE(&dataPtr, u32);
    decompressedSize = READ_VALUE(&dataPtr, u32);
    compressedSize = READ_VALUE(&dataPtr, u32);

    decompressedBytes = alloc_second_heap(decompressedSize);

    decompress(&compressionParamsTable[0], compressedSize, dataPtr, decompressedSize, decompressedBytes);

    arg0->unk0->unk68(arg0, decompressedSize, decompressedBytes, vertexStorageFlags); // always func_800864A8 from testing

    dataPtr += compressedSize;

    if (arg0->numSubmodels > 0)
    {
        arg0->submodels = main_alloc_copy(arg0->numSubmodels * sizeof(struct Submodel), submodelBuffer);
    }

    pop_second_heap_state();
    pop_second_heap_state();

    if (arg0->unk0->unk40)
    {
        arg0->unk0->unk40(arg0);
    }
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001E198);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001E248);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001E330);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001E504);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001E69C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001E824);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001E954);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001EA18);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001ECEC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001F128);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001F2A4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001F36C);

void alloc_vertex_data_storage(struct Model *model)
{
    if (model->vertexDataStorage == NULL)
    {
        model->vertexDataStorage = main_alloc_bzero(sizeof(struct VertexDataStorage));
    }
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001F518);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001F7A4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001F82C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001F860);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001F8B8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001F920);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001F9B4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001F9FC);

struct unkfunc_8001FA50 {
    struct unkfunc_8001FA50_2 *unk0;
    u8 padding[0x14];
    Mtx3f unk18;
};

struct unkfunc_8001FA50_2 {
    u8 padding[0x5C];
    void (*unk5C)(struct unkfunc_8001FA50 *, Mtx3f);
};

void mtx3f_axis_angle(Vec3f, Mtx3f);
void mtx3f_concat(Mtx3f, Mtx3f, Mtx3f);

// void func_8001FA50(struct unkfunc_8001FA50 *arg0, f32 arg1, f32 arg2, f32 arg3)
// {
//     Vec3f vec;
//     Mtx3f a, b;
//     vec[0] = arg1;
//     vec[1] = arg2;
//     vec[2] = arg3;
//     mtx3f_axis_angle(vec, a);
//     mtx3f_concat(a, arg0->unk18, b);
//     arg0->unk0->unk5C(arg0, b);
// }

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001FA50);

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

    mtx3f_axis_angle(arg1, auStack48);
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
//     mtx3f_axis_angle(auStack48 + 0,auStack48 + 4);
//     arg0->unk0->unk5C(arg0, auStack48 + 3); // changing this to be 4 messes everything up, but should be correct
// }

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001FAF4);

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

struct s32_3 {
    s32 a;
    s32 b;
    s32 c;
};

struct unkfunc_8001FBB0 {
    u8 padding[0x84];
    struct s32_3 unk84;
};

void func_8001FD30();

void func_8001FBB0(struct unkfunc_8001FBB0 *param_1,struct s32_3 *param_2)
{
    param_1->unk84 = *param_2;
    func_8001FD30();
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001FBE8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001FC1C);

INCLUDE_ASM(void, "rocket/codeseg2/codeseg2_3", func_8001FD30);

struct unkfunc_8001FDB4 {
    u8 padding[0x48];
    Mtx3f unk48;
    Vec3f unk6C;
};

void vec3f_rotate();
void vec3f_transpose_rotate();

// TODO almost
// void func_8001FDB4(struct unkfunc_8001FDB4 *arg0, struct unkfunc_8001FDB4 *arg1, Vec3f arg2, Vec3f arg3)
// {
//     Vec3f sp10;
//     Vec3f sp20;
//     f32 *src = arg2;
//     if (arg0 != arg1)
//     {
//         if (arg0 != 0)
//         {
//             vec3f_rotate(arg0->unk48, arg2, sp10);
//             VEC3F_ADD(sp10, arg0->unk6C, sp10);
//             src = sp10;
//         }
//         if (arg1 != 0)
//         {
//             VEC3F_SUB(sp20, src, arg1->unk6C);
//             src = arg1;
//             vec3f_transpose_rotate(arg1->unk48, sp20, arg1);
//             return;
//         }
//     }
//     VEC3F_COPY(arg3, src);
// }

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001FDB4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001FEA0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001FF38);

// Plays the sound for warping in or out of an area
INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_80020050);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_800200F4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_80020134);

struct unkD_8009F400 {
    u8 padding[24];
};

extern struct unkD_8009F400 D_8009F400[];

struct unkD_8009F400 *func_80020714(s32 arg0)
{
    return &D_8009F400[arg0];
}

struct unkfunc_80020730 {
    u8 padding[0xD8];
    u32 unkD8;
};

void func_80020730(struct unkfunc_80020730 *arg0, s32 arg1)
{
    arg0->unkD8 = arg1;
}

struct unkfunc_8002075C {
    u8 padding[0x110];
    s32 unk110;
};

void func_80020738(struct unkfunc_8002075C *arg0, u32 arg1)
{
    s32 val = (arg1 & 0x3) << 22;
    arg0->unk110 = (arg0->unk110 & ~(0x3 << 22)) | val;
}

void func_8002075C(struct unkfunc_8002075C *arg0, u32 arg1)
{
    s32 val = (arg1 & 0x3) << 20;
    arg0->unk110 = (arg0->unk110 & ~(0x3 << 20)) | val;
}

void func_80020780(s32 *arg0)
{
    s32 val = arg0[0x44];
    val &= ~(12 << 20);
    val &= ~(3 << 20);
    val |= (1 << 20);
    arg0[0x44] = val;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_800207AC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8002085C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8002090C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8002095C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_800209BC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_80020A20);

void func_80020A84(s32 **arg0)
{
    arg0[0x3F][4] = 1; // TODO probably a struct
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_80020A94);
