#include <include_asm.h>
#include <ultra64.h>
#include <types.h>
#include <macros.h>


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_214", func_8005C0F0);

struct unkfunc_8005C210 {
    u8 pad1[0x268];
    struct GameObject* unk268;
    struct GameObject* unk26C;
    struct GameObject* unk270;
    u8 pad2[0x2A0 - 0x274];
    struct GameObject* unk2A0;
    u8 pad3[0x7D0 - 0x2A4];
    f32 unk7D0;
};

void obj_set_rotation_axis_angle_xyz(struct GameObject *obj, f32 x, f32 y, f32 z);
void obj_rotate_axis_angle_xyz(struct GameObject* obj, f32 x, f32 y, f32 z);
void obj_translate(struct GameObject* obj, Vec3f translation);
void func_8001FDB4(struct GameObject *arg0, struct GameObject *arg1, Vec3f arg2, Vec3f arg3);
void func_800605A4(struct unkfunc_8005C210*, f32*, f32*);

// TODO some types seem wrong here, as a Mtx3f is being passed to a Vec3f argument
void func_8005C210(struct unkfunc_8005C210* arg0) {
    Vec3f sp10;
    Vec3f sp20;
    Vec3f sp30;
    f32 sp40;
    f32 sp44;

    func_800605A4(arg0, &sp40, &sp44);
    arg0->unk26C->unk0->unk58(arg0->unk26C, arg0->unk268->position);
    obj_set_rotation_axis_angle_xyz(arg0->unk26C, 0.0f, -sp40, 0.0f);
    func_8001FDB4(arg0->unk2A0->unk10, (struct GameObject* ) arg0, arg0->unk2A0->rotation[0], sp10);
    arg0->unk270->unk0->unk58(arg0->unk270, sp10);
    obj_set_rotation_axis_angle_xyz(arg0->unk270, 0.0f, -sp44, 0.0f);
    obj_rotate_axis_angle_xyz(arg0->unk26C, 0.0f, arg0->unk7D0, 0.0f);
    func_8001FDB4(arg0->unk2A0->unk10, (struct GameObject* ) arg0, arg0->unk2A0->rotation[0], sp20);
    VEC3F_SUB(sp30, sp10, sp20);
    obj_translate(arg0->unk26C, sp30);
}


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_214", func_8005C338);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_214", func_8005C868);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_214", func_8005CC70);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_214", func_8005CF48);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_214", func_8005E2A4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_214", func_8005E8A0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_214", func_8005EA60);
