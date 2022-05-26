#include <include_asm.h>
#include <ultra64.h>
#include <types.h>

void vec3f_scale(f32, Vec3f, Vec3f);
f32 vec3f_magnitude(Vec3f);

struct unkfunc_8003CBD0 {
    u8 padding[0x230];
    f32 unk230;
};

void func_8003CBD0(struct unkfunc_8003CBD0 *arg0) {
    func_800263B4(arg0);
    arg0->unk230 = 1.0;    
}

struct unkfunc_8003CC04 {
    u8 pad[0x24];
    Vec3f unk24;
    u8 pad2[0x230 - 0x24 - 0xC];
    f32 unk230;
};

struct unkfunc_8003CC04_2_inner {
    Vec3f unk0;
    u8 pad[0x18 - 0xC];
    Vec3f unk18;
    u8 pad2[0x30 - 0x18 - 0xC];
};

struct unkfunc_8003CC04_2 {
    struct unkfunc_8003CC04_2_inner unk0[2];
    u32 unk60;
    Vec3f unk64;
};

void func_8003CC04(struct unkfunc_8003CC04* arg0, struct unkfunc_8003CC04_2* arg1, s32 arg2) {
    Vec3f sp10;
    struct unkfunc_8003CC04_2_inner* temp_s0;
    f32 phi_f0;

    vec3f_cross_product(arg0->unk24, arg1->unk64, sp10);
    phi_f0 = vec3f_magnitude(sp10);

    if (phi_f0 < 0.01f) {
        return;
    }

    if (arg2 == 1) {
        phi_f0 = -phi_f0;
    }

    temp_s0 = &arg1->unk0[arg2];
    vec3f_scale(arg0->unk230 / phi_f0, sp10, sp10);
    temp_s0->unk18[0] = temp_s0->unk18[0] - sp10[0];
    temp_s0->unk18[1] = temp_s0->unk18[1] - sp10[1];
    temp_s0->unk18[2] = temp_s0->unk18[2] - sp10[2];
}
