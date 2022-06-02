#include <include_asm.h>
#include <ultra64.h>
#include <mem.h>
#include <types.h>
#include <macros.h>

#include "codeseg2.h"

void func_80085D04(u8 **dataPtrPtr, Vec3f arg1, Mtx3f arg2);
void func_8001E248(struct GameObject* arg0);
void func_8008CCE8(struct unkfunc_800882B8*, void (*)(struct GameObject*), struct GameObject*, s32, s32);
void func_80024508(void*, struct GameObject*, s32, f32, f32);
f32 vec3f_safe_normalize(Vec3f in, Vec3f out);
void vec3f_scale(f32, Vec3f, Vec3f);
f32 vec3f_normalize(Vec3f vec);
void mtx3f_axis_angle(Vec3f, Mtx3f);
void mtx3f_concat(Mtx3f, Mtx3f, Mtx3f);
void vec3f_scale_add(float aScale, Vec3f a, float bScale, Vec3f b, Vec3f out);
f32 vec3f_magnitude(Vec3f);
void mtx3f_rotate_axis(f32 angle, Vec3f arg1, Mtx3f out);
struct unkfunc_8001E248* func_8008BE8C();

extern Vec3f D_800AF794;

void func_8001DFD0(struct unkfunc_8001DFD0 *arg0, void* arg1, void* arg2)
{
    func_80050868(arg0, arg1, arg2);
    arg0->unk110_8 = 3;
    arg0->unk110_10 = 3;
    arg0->unk110_0 = 0xff;
    arg0->unkE0 = 0x10;
    arg0->unk104 = FLT_MAX;
    arg0->unk108 = INT_MAX;
    arg0->unk110_17 = 1;
}


void func_8001E044(struct GameObject *arg0, s32 arg1, u8 *dataPtr)
{
    s32 decompressedSize;
    void *decompressedBytes;
    s32 compressedSize;
    s32 vertexStorageFlags;
    struct Submodel *submodelBuffer;

    func_80085D04(&dataPtr, arg0->position, arg0->rotation);
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

void func_8001E198(struct GameObject* arg0) {
    struct GameObjectUnkFC* temp_v1;

    MTX3F_COPY(arg0->unkB4, arg0->rotation);
    VEC3F_COPY(arg0->unkA8, arg0->position);

    temp_v1 = arg0->unkFC;
    if ((temp_v1 != 0) && ((temp_v1->unk0 != 0) || (temp_v1->unk4 != -1))) {
        func_8008CCE8(arg0->unkC, func_8001E248, arg0, 0, 0);
    }
}

void func_8001E248(struct GameObject* arg0) {
    Vec3f sp18;
    f32 sp28;
    struct GameObjectUnkFC* temp_s0;
    struct unkfunc_8001E248* temp_v0;
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
            func_80024DB8(phi_s1, arg0, arg0->position, &sp28, sp18);
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

void func_8001E330(struct GameObject* arg0, f32 dt) {
    Vec3f rotation_delta_vector;
    Mtx3f rotation_delta;
    Mtx3f rotation;
    struct GameObject* temp_v0;

    temp_v0 = arg0->unk10;
    if (temp_v0 != NULL && (temp_v0->unk110.val & 0x80000)) {
        return;
    }
    if (temp_v0 != NULL || (arg0->unk110.val & 0x30000)) {
        if ((arg0->unk110.val & 0x4000) == 0) {
            vec3f_scale_add(1.0f, arg0->position, dt, arg0->velocity, arg0->position);
            vec3f_scale(dt, arg0->angular_velocity, rotation_delta_vector);
            mtx3f_axis_angle(rotation_delta_vector, rotation_delta);
            mtx3f_concat(rotation_delta, arg0->rotation, rotation);
            MTX3F_COPY(arg0->rotation, rotation);
            if (arg0->unk0->unk40 != 0) {
                arg0->unk0->unk40(arg0);
            }
        }
        if (arg0->unkD8 != NULL && (arg0->unkD8->unk74 & (0x10000000 | 0x20000000))) {
            if ((arg0->unkD8->unk74 & 0x20000000) != 0) {
                VEC3F_COPY(arg0->position, arg0->unkD8->unk8);
            }
            if ((arg0->unkD8->unk74 & 0x10000000) != 0) {
                MTX3F_COPY(arg0->rotation, arg0->unkD8->unk20);
            }
            if (arg0->unk0->unk40 != 0) {
                arg0->unk0->unk40(arg0);
            }
        }
    }
}


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001E504);

// TODO float regalloc
#ifdef NON_MATCHING
void func_8001E69C(struct GameObject* arg0, f32 dt, Mtx3f out) {
    Vec3f sp18;
    Vec3f rotation_axis;
    Mtx3f rotation_delta;
    f32 magnitude;
    float angle;

    // sp18 = arg0->angular_velocity + 0.5 * dt * arg0->angular_acceleration
    vec3f_scale_add(
        1.0f, arg0->angular_velocity,
        0.5f * dt, arg0->angular_acceleration, sp18);
    magnitude = vec3f_magnitude(sp18);
    if (magnitude > 0.0001f) {
        vec3f_scale(1.0f / magnitude, sp18, rotation_axis);
        angle =
            VEC3F_DOT(arg0->angular_velocity, rotation_axis) * dt +
            VEC3F_DOT(arg0->angular_acceleration, rotation_axis) * 0.5f * dt * dt; // <-- here
        mtx3f_rotate_axis(angle, rotation_axis, rotation_delta);
        mtx3f_concat(rotation_delta, arg0->unk18, out);
        return;
    } else {
        MTX3F_COPY(out, arg0->unk18);
    }
}
#else
asm(".section .rdata");
const f32 D_80019FC0 = 0.5f;
const f32 D_80019FC4 = 1.0f;
const f32 D_80019FC8 = 0.0001f;

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001E69C);
#endif

asm(".section .rdata");
const f32 D_80019FCC = 1.0f;

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001E824);

asm(".section .rdata");
const f32 D_80019FD0 = 1.0f;
const f32 D_80019FD4 = 0.0f;

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001E954);


#ifdef NON_MATCHING
Mtx* func_8001EA18(struct GameObject* arg0, struct Submodel* arg1, f32* arg2, f32 (*arg3)[3], f32 arg4) {
    Mtx3f sp10;
    Mtx3f sp38;
    Mtx4f sp60;
    Mtx4f spA0;
    Mtx4f spE0;
    Mtx4f sp120;
    Mtx4f sp160;
    Vec3f sp1A0;
    Mtx3f sp1B0;
    Mtx* temp_a1;
    Mtx* temp_s0;
    f32 temp_f20;
    s32 temp_v1;
    s8 temp_v0;
    s32 phi_v1;
    f32 (*phi_s4)[3];

    temp_v0 = arg1->unk20;
    switch (temp_v0) {
    case 1:
        phi_s4 = gCurGfxTask->unkFC;
        break;
    case 2:
        phi_s4 = gCurGfxTask->unkD8;
        break;
    case 3:
        VEC3F_COPY(sp1B0[0], arg0->unk48[0]);
        vec3f_cross_product(sp1B0[0], gCurGfxTask->unkFC[0], sp1B0[2]);
        vec3f_safe_normalize(sp1B0[2], arg0->unk48[2]);
        vec3f_cross_product(sp1B0[2], sp1B0[0], sp1B0[1]);
        phi_s4 = &sp1B0[0];
        break;
    case 4: // rodata + 0xc
        VEC3F_COPY(sp1B0[1], arg0->unk48[1]);
        vec3f_cross_product(sp1B0[1], gCurGfxTask->unkFC[0], sp1B0[0]);
        vec3f_safe_normalize(sp1B0[0], arg0->unk48[0]);
        vec3f_cross_product(sp1B0[0], sp1B0[1], sp1B0[2]);
        phi_s4 = &sp1B0[0];
        break;
    case 5: // rodata + 0x10
        VEC3F_COPY(sp1B0[2], arg0->unk48[2]);
        vec3f_cross_product(sp1B0[2], gCurGfxTask->unkFC[0], sp1B0[1]);
        vec3f_safe_normalize(sp1B0[1], arg0->unk48[1]);
        vec3f_cross_product(sp1B0[1], sp1B0[2], sp1B0[0]);
        phi_s4 = &sp1B0[0];
        break;
    }
    // .text + 0x1a4
    func_80056BD0(sp10);
    for (phi_v1 = 0; phi_v1 < 3; phi_v1++) {
        sp10[phi_v1][phi_v1] = arg4;
    }
    vec3f_scale(-16.0f, arg1->unk14, sp1A0);
    mtx4f_compose(sp1A0, sp10, sp60);
    func_80057778(arg3, phi_s4, sp38);
    vec3f_scale(16.0f, arg1->unk14, sp1A0);
    mtx4f_compose(sp1A0, sp38, spA0);
    mtx4f_concat(spA0, sp60, spE0);
    vec3f_scale(16.0f, arg2, sp1A0);
    mtx4f_compose(sp1A0, arg3, sp120);
    mtx4f_concat(sp120, spE0, sp160);
    temp_s0 = gGfxContext.unkC - 1;
    gGfxContext.unkC = temp_s0;
    mtxf_to_mtx(sp160, temp_s0);
    return temp_s0;
}
#else
s32 func_8001EA18();

asm(".section .rdata");
const uintptr_t jtbl_80019FD8[] = {
    0x8001EA88 - 0x8001EA18 + (uintptr_t)func_8001EA18,
    0x8001EA98 - 0x8001EA18 + (uintptr_t)func_8001EA18,
    0x8001EAA8 - 0x8001EA18 + (uintptr_t)func_8001EA18,
    0x8001EB00 - 0x8001EA18 + (uintptr_t)func_8001EA18,
    0x8001EB5C - 0x8001EA18 + (uintptr_t)func_8001EA18};
const f32 D_80019FEC = -16.0f;
const f32 D_80019FF0 = 16.0f;

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001EA18);
#endif

asm(".section .rdata");
const f32 D_80019FF4 = FLT_MAX;
const f32 D_80019FF8 = 2.1474836e9f;
const f32 D_80019FFC = 16.0f;
const f32 D_8001A000 = 255.0f;
const f32 D_8001A004 = 0.0f;


struct unkfunc_8001F128 {
    u8 padding[0x10C];
    f32 unk10C;
};

INCLUDE_ASM(void, "rocket/codeseg2/codeseg2_3", func_8001ECEC, s32, struct unkfunc_8001F128*, Vec3f, Vec3f, Mtx3f, f32, f32, f32);

void func_8001F128(s32 arg0, struct unkfunc_8001F128* arg1, Vec3f arg2, Vec3f arg3, Vec3f arg4, f32 arg5, f32 arg6) {
    Mtx3f sp20;
    Vec3f sp48;
    float* row0 = sp20[0];
    float* row1 = sp20[1];
    float* row2 = sp20[2];

    sp20[2][0] = arg4[0] - arg3[0]; // Why can't row2 be used here?
    row2[1] = arg4[1] - arg3[1];
    row2[2] = arg4[2] - arg3[2];
    sp48[0] = arg3[0] - arg2[0];
    sp48[1] = arg3[1] - arg2[1];
    sp48[2] = arg3[2] - arg2[2];
    vec3f_cross_product(sp48, row2, row1);
    if (vec3f_safe_normalize(row1, D_800AF794) > 0.01) {
        vec3f_cross_product(row1, row2, row0);
        vec3f_normalize(row0);
        vec3f_scale(arg5, row1, row1);
        
        func_8001ECEC(arg0, arg1, arg2, arg3, sp20, 0.0f, 1.0f, arg1 ? arg1->unk10C * arg6 : arg6);
    }
}

// asm(".section .rdata");
// const f64 D_8001A008 = 0.01;
// const f32 D_8001A010 = 1.0f;

// INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001F128);

asm(".section .rdata");
const f32 D_8001A014 = 1.0f;

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001F2A4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001F36C);

void alloc_vertex_data_storage(struct GameObject *model)
{
    if (model->vertexDataStorage == NULL)
    {
        model->vertexDataStorage = main_alloc_bzero(sizeof(struct VertexDataStorage));
    }
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001F518);

void obj_setter_position(struct GameObject* obj, Vec3f position) {
    struct {
        struct GameObject* unk0;
        Vec3f unk4;
    } sp10;
    sp10.unk0 = obj;
    VEC3F_COPY(sp10.unk4, obj->unk6C);
    VEC3F_COPY(obj->position, position);
    
    if (obj->unk0->unk40) {
        obj->unk0->unk40(obj);
    }
    
    obj->unk0->unk54(obj, 6, &sp10);
}

void obj_set_position_xyz(struct GameObject* obj, f32 x, f32 y, f32 z) {
    Vec3f new_position;

    new_position[0] = x;
    new_position[1] = y;
    new_position[2] = z;
    obj->unk0->unk58(obj, new_position);
}

void obj_translate(struct GameObject* obj, Vec3f translation) {
    Vec3f new_position;

    VEC3F_ADD(new_position, obj->position, translation);
    obj->unk0->unk58(obj, new_position);
}

void obj_translate_xyz(struct GameObject* obj, f32 x, f32 y, f32 z) {
    Vec3f translation;

    translation[0] = x;
    translation[1] = y;
    translation[2] = z;
    obj_translate(obj, translation);
}

void obj_setter_rotation(struct GameObject* obj, Mtx3f rotation_matrix) {
    MTX3F_COPY(obj->rotation, rotation_matrix);
    
    if (obj->unk0->unk40) {
        obj->unk0->unk40(obj);
    }
    
    obj->unk0->unk54(obj, 7, obj);
}

void obj_rotate_matrix(struct GameObject* obj, Mtx3f rotation_matrix) {
    Mtx3f new_rotation;

    mtx3f_concat(rotation_matrix, obj->rotation, new_rotation);
    obj->unk0->unk5C(obj, new_rotation);
}

void obj_rotate_axis_angle(struct GameObject* obj, Vec3f rotation_vector) {
    Mtx3f rotation_matrix;

    mtx3f_axis_angle(rotation_vector, rotation_matrix);
    obj_rotate_matrix(obj, rotation_matrix);
}

void obj_rotate_axis_angle_xyz(struct GameObject* obj, f32 x, f32 y, f32 z) {
    Vec3f rotation_vector;

    rotation_vector[0] = x;
    rotation_vector[1] = y;
    rotation_vector[2] = z;
    obj_rotate_axis_angle(obj, rotation_vector);
}

void obj_set_rotation_axis_angle(struct GameObject *obj, Vec3f rotation_vector) {
    Mtx3f new_rotation;

    mtx3f_axis_angle(rotation_vector, new_rotation);
    obj->unk0->unk5C(obj, new_rotation);
}

void obj_set_rotation_axis_angle_xyz(struct GameObject *obj, f32 x, f32 y, f32 z) {
    Vec3f vec;

    vec[0] = x;
    vec[1] = y;
    vec[2] = z;
    obj_set_rotation_axis_angle(obj, vec);
}

void obj_update_sleeping(struct GameObject *);

void obj_setter_velocity(struct GameObject *obj, Vec3f velocity) {
    VEC3F_COPY(obj->velocity, velocity);
    obj_update_sleeping(obj);
}

void obj_set_velocity_xyz(struct GameObject *arg0, f32 x, f32 y, f32 z) {
    Vec3f vec;

    vec[0] = x;
    vec[1] = y;
    vec[2] = z;
    arg0->unk0->unk60(arg0, vec);
}

void obj_setter_angular_velocity(struct GameObject *obj, Vec3f arg1)
{
    VEC3F_COPY(obj->angular_velocity, arg1);
    obj_update_sleeping(obj);
}

void obj_set_angular_velocity_xyz(struct GameObject *obj, f32 x, f32 y, f32 z) {
    Vec3f vec;

    vec[0] = x;
    vec[1] = y;
    vec[2] = z;

    obj->unk0->unk64(obj, vec);
}

asm(".section .rdata");
const f32 D_8001A018 = 2500.0f;
const f32 D_8001A01C = 50.0f;
const f32 D_8001A020 = 50.0f;
const f32 D_8001A024 = 0.0004f;

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001FC1C);

void obj_update_sleeping(struct GameObject* obj) {
    s32 sleeping;

    sleeping = 0;
    if (VEC3F_MAG_SQUARED(obj->velocity) < SQUARED(0.02f) && VEC3F_MAG_SQUARED(obj->angular_velocity) < SQUARED(0.02f)) {
        sleeping = 1;
    }
    obj->unk110.bitfield.unk110_17 = sleeping;
}

void vec3f_rotate();
void vec3f_transpose_rotate();

void func_8001FDB4(struct GameObject *arg0, struct GameObject *arg1, Vec3f arg2, Vec3f arg3)
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

void func_8001FEA0(struct GameObject* arg0, struct GameObject* arg1, Vec3f arg2, Vec3f arg3) {
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

void func_8001FF38(struct GameObject* arg0, struct GameObject* arg1, Mtx3f arg2, Mtx3f arg3) {
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

void func_80020A84(struct GameObject *obj)
{
    obj->unkFC->unk10 = 1;
}

asm(".section .rdata");
const f32 D_8001A050 = 3.4028235e38f;
const f32 D_8001A054 = 0.0f;
const f32 D_8001A058 = 0.0f;
const f32 D_8001A05C = 0.0f;

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_80020A94);
