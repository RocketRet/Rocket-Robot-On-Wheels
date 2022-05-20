#include <include_asm.h>
#include <ultra64.h>
#include <mem.h>
#include <types.h>
#include <macros.h>

#include "codeseg2.h"

void func_8001DFD0(struct unkfunc_8001DFD0 *arg0)
{
    func_80050868();
    arg0->unk110_8 = 3;
    arg0->unk110_10 = 3;
    arg0->unk110_0 = 0xff;
    arg0->unkE0 = 0x10;
    arg0->unk104 = FLT_MAX;
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

    func_80085D04(&dataPtr, arg0->unk3C, arg0->unk18);
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
        arg0->submodels = main_alloc_copy(arg0->numSubmodels * sizeof(struct Submodel), (void*)submodelBuffer);
    }

    pop_second_heap_state();
    pop_second_heap_state();

    if (arg0->unk0->unk40)
    {
        arg0->unk0->unk40(arg0);
    }
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001E198);

void func_80024508(void*, struct Model*, s32, f32, f32);

void func_8001E248(struct Model* arg0) {
    Vec3f sp18;
    f32 sp28;
    struct ModelUnkInner* temp_s0;
    void* temp_v0;
    struct unkfunc_8001E248* phi_s1;
    f32* phi_v0;
    f32 phi_f0;

    temp_s0 = arg0->unkFC;
    temp_v0 = temp_s0->unk0;
    if (temp_v0 == 0) {
        phi_s1 = func_8008BE8C(arg0->unkC, temp_s0->unk4);
    } else {
        phi_s1 = temp_v0;
    }
    if (phi_s1 != 0) {
        if (temp_s0->unk10 != 0) {
            func_80024DB8(phi_s1, arg0, arg0->unk3C, &sp28, sp18);
        } else {
            sp28 = temp_s0->unk8;
        }

        if (temp_s0->unkC == FLT_MAX) {
            phi_f0 = 1.0f;
            if (phi_s1->unk28 == 3) {
                phi_f0 = 0.0f;
            }
            temp_s0->unkC = phi_f0;
        }
        func_80024508(phi_s1, arg0, phi_s1->unk24, sp28, temp_s0->unkC);
    }
}

asm(".section .rdata");
const f32 D_80019FBC = 1.0f;

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001E330);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001E504);

asm(".section .rdata");
const f32 D_80019FC0 = 0.5f;
const f32 D_80019FC4 = 1.0f;
const f32 D_80019FC8 = 0.0001f;

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001E69C);

asm(".section .rdata");
const f32 D_80019FCC = 1.0f;

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001E824);

asm(".section .rdata");
const f32 D_80019FD0 = 1.0f;
const f32 D_80019FD4 = 0.0f;

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001E954);


s32 func_8001EA18();
asm(".section .rdata");
const u32 D_80019FD8[] = {0x8001EA88, 0x8001EA98, 0x8001EAA8, 0x8001EB00, 0x8001EB5C};

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001EA18);

asm(".section .rdata");
const f32 D_80019FEC = -16.0f;
const f32 D_80019FF0 = 16.0f;
const f32 D_80019FF4 = FLT_MAX;
const f32 D_80019FF8 = 2.1474836e9f;
const f32 D_80019FFC = 16.0f;
const f32 D_8001A000 = 255.0f;
const f32 D_8001A004 = 0.0f;

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001ECEC);

asm(".section .rdata");
const f64 D_8001A008 = 0.01;
const f32 D_8001A010 = 1.0f;

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001F128);

asm(".section .rdata");
const f32 D_8001A014 = 1.0f;

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
    void (*unk5C)(void *, Mtx3f);
};

struct unkfunc_8001FAF4 {
    struct unkfunc_8001FAF4_sub0 *unk0;
};

void func_8001FAB0(struct unkfunc_8001FAF4 *arg0, Vec3f arg1)
{
    Mtx3f matrix;

    mtx3f_axis_angle(arg1, matrix);
    arg0->unk0->unk5C(arg0, matrix);
    return;
}

// TODO minor diff
// void func_8001FAF4(struct unkfunc_8001FAF4 *arg0, f32 x, f32 y, f32 z)
// {
//     Vec3f vec;
//     Mtx3f matrix;

//     vec[0] = x;
//     vec[1] = y;
//     vec[2] = z;
//     mtx3f_axis_angle(vec, matrix);
//     arg0->unk0->unk5C(arg0, &matrix[1]); // changing this to just be matrix messes everything up, but should be correct
// }

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001FAF4);

void func_8001FD30(struct unkfunc_8001DFD0 *);

void func_8001FB44(struct unkfunc_8001DFD0 *arg0, Vec3f arg1)
{
    VEC3F_COPY(arg0->unk78, arg1);
    func_8001FD30(arg0);
}

struct unkfunc_8001FB7C {
    struct unkfunc_8001FB7C_sub0 *unk0;
};

struct unkfunc_8001FB7C_sub0 {
    u8 padding[0x60];
    void (*unk60)(struct unkfunc_8001FB7C *, Vec3f);
};

void func_8001FB7C(struct unkfunc_8001FB7C *arg0, f32 x, f32 y, f32 z)
{
    Vec3f vec;

    vec[0] = x;
    vec[1] = y;
    vec[2] = z;
    arg0->unk0->unk60(arg0, vec);
}

struct unkfunc_8001FBB0 {
    u8 padding[0x84];
    Vec3f unk84;
};

void func_8001FBB0(struct unkfunc_8001FBB0 *arg0, Vec3f arg1)
{
    VEC3F_COPY(arg0->unk84, arg1);
    func_8001FD30(arg0);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001FBE8);

asm(".section .rdata");
const f32 D_8001A018 = 2500.0f;
const f32 D_8001A01C = 50.0f;
const f32 D_8001A020 = 50.0f;
const f32 D_8001A024 = 0.0004f;

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001FC1C);

// TODO matched, but need to migrate rodata
void func_8001FD30(struct unkfunc_8001DFD0* arg0) {
    s32 phi_a1;

    phi_a1 = 0;
    if (VEC3F_MAG_SQUARED(arg0->unk78) < SQUARED(0.02f) && VEC3F_MAG_SQUARED(arg0->unk84) < SQUARED(0.02f)) {
        phi_a1 = 1;
    }
    arg0->unk110_17 = phi_a1;
}

// INCLUDE_ASM(void, "rocket/codeseg2/codeseg2_3", func_8001FD30, struct unkfunc_8001DFD0*);

struct unkfunc_8001FDB4 {
    u8 padding[0x48];
    Mtx3f unk48;
    Vec3f unk6C;
};

void vec3f_rotate();
void vec3f_transpose_rotate();

void func_8001FDB4(struct unkfunc_8001FDB4 *arg0, struct unkfunc_8001FDB4 *arg1, Vec3f arg2, Vec3f arg3)
{
    Vec3f sp10;
    Vec3f sp20;
    f32 *src = arg2;
    if (arg0 != arg1)
    {
        if (arg0 != 0)
        {
            vec3f_rotate(arg0->unk48, arg2, sp10);
            VEC3F_ADD(sp10, arg0->unk6C, sp10);
            src = sp10;
        }
        if (arg1 != 0)
        {
            VEC3F_SUB(sp20, src, arg1->unk6C);
            vec3f_transpose_rotate(arg1->unk48, sp20, arg3);
            return;
        }
    }
    VEC3F_COPY(arg3, src);
}

void func_8001FEA0(struct unkfunc_8001FDB4* arg0, struct unkfunc_8001FDB4* arg1, Vec3f arg2, Vec3f arg3) {
    Vec3f sp10;
    Vec3f sp20;
    f32* src;

    src = arg2;
    if (arg0 != arg1) {
        if (arg0 != 0) {
            vec3f_rotate(arg0->unk48, arg2, sp10);
            src = sp10;
        }
        if (arg1 != 0) {
            vec3f_transpose_rotate(arg1->unk48, src, sp20);
            VEC3F_COPY(arg3, sp20);
            return;
        }
    }
    VEC3F_COPY(arg3, src);
}

void func_8001FF38(struct unkfunc_8001FDB4* arg0, struct unkfunc_8001FDB4* arg1, Mtx3f arg2, Mtx3f arg3) {
    Mtx3f sp10;
    Mtx3f sp38;
    f32 (*src)[3];

    src = arg2;
    if (arg0 == arg1) {
        MTX3F_COPY(arg3, arg2);
        return;
    }
    if (arg0 != 0) {
        mtx3f_concat(arg0->unk48, arg2, sp10);
        src = sp10;
    }
    if (arg1 != 0) {
        func_80057778(arg1->unk48, src, sp38);
        MTX3F_COPY(arg3, sp38);
        return;
    }
    MTX3F_COPY(arg3, src);
}

// Plays the sound for warping in or out of an area
INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_80020050);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_800200F4);

asm(".section .rdata");
const f32 D_8001A02C = 0.0625f;
const f32 D_8001A030 = 1.0f;
const f32 D_8001A034 = 2.1474836e9f;

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

asm(".section .rdata");
const f32 D_8001A038 = 0.0004f;

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_800207AC);

asm(".section .rdata");
const f32 D_8001A03C = 0.0004f;

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8002085C);

asm(".section .rdata");
const f32 D_8001A040 = 3.4028235e38f;

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8002090C);

asm(".section .rdata");
const f32 D_8001A044 = 3.4028235e38f;

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8002095C);

asm(".section .rdata");
const f32 D_8001A048 = 3.4028235e38f;

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_800209BC);

asm(".section .rdata");
const f32 D_8001A04C = 3.4028235e38f;

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_80020A20);

void func_80020A84(s32 **arg0)
{
    arg0[0x3F][4] = 1; // TODO probably a struct
}

asm(".section .rdata");
const f32 D_8001A050 = 3.4028235e38f;
const f32 D_8001A054 = 0.0f;
const f32 D_8001A058 = 0.0f;
const f32 D_8001A05C = 0.0f;

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_80020A94);
