#include <include_asm.h>
#include <ultra64.h>
#include <macros.h>
#include <types.h>

const float D_8001D500 = -0.02f;
const float D_8001D504 = -0.02f;
const float D_8001D508 = 0.5f;

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_343", func_800818D0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_343", func_800819FC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_343", func_80081B10);

void func_80081CA0(struct GameObject* obj, Vec3f velocity) {
    Vec3f sp10;
    s32 phi_v0;

    obj_setter_velocity(obj, velocity);

    VEC3F_SUB(sp10, velocity, obj->velocity);
    
    phi_v0 = 0;
    if (!(fabsf(sp10[0]) < 0.02f && fabsf(sp10[1]) < 0.02f && fabsf(sp10[2]) < 0.02f)) {
        phi_v0 = 1;
    }
    if (phi_v0 != 0) {
        func_80026D78(obj->unkC, obj, 2);
    }
}
