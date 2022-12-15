#include <include_asm.h>
#include <ultra64.h>
#include "gfx.h"

extern s32 D_8009F098;
extern s32 D_8009F170;
extern s32 D_800A5874;

void func_800914A8(float);
void func_80095440(s32, s32, s32, s32);
void func_8007F1F4(struct unkD_8009F094* arg0);
void func_8007F368(struct unkD_8009F094* arg0, u32 arg1);
void func_80039C34(void* arg0);
void update_gfx_context();
void clear_depth_buffer();
void schedule_gfx_task();
void func_80037E60(void *, s32);
void func_80099F18(s32, f32);
void func_8003B298(void*);
void func_8008B594(s32, void*);
void func_80046D58();
void func_8003B358(void*);
void func_8008B694(s32, void*);
void func_80075ABC();

void func_8007F1D0()
{
    func_8007F1F4(&D_8009F094);
}

void func_8007F1F4(struct unkD_8009F094* arg0) {
    func_80039C34(arg0 + 1);
    func_8007F368(arg0, 0);
}

void func_8007F22C(struct unkD_8009F094* arg0) {
    f32 temp_f20;
    struct unkD_8009F094_inner* temp_a0;
    struct unkD_8009F094_inner* temp_a0_2;

    temp_a0 = arg0->unk0;
    temp_f20 = D_8009FE10.unk4;
    if ((temp_a0 != NULL) && (D_8009F170 != 0)) {
        func_80099F18((s32) temp_a0, temp_f20);
        func_80037E60(&D_8009FE10, 2);
        temp_f20 = D_8009FE10.unk4;
    }
    update_gfx_context();
    if (arg0->unk0 != NULL) {
        func_8003B298(&D_8009F098);
        func_8008B594((s32) arg0->unk0, &D_8009F098);
    }
    func_80046D58();
    if (arg0->unk0 != NULL) {
        func_8003B358(&D_8009F098);
        clear_depth_buffer();
        func_8008B694((s32) arg0->unk0, &D_8009F098);
    } else {
        draw_rectangle(0x40, 0, 0x40, 0xFF, 0x12, 0xE, 0x12D, 0xE1);
    }
    func_80075ABC();
    schedule_gfx_task();
    temp_a0_2 = arg0->unk0;
    if (temp_a0_2 != NULL) {
        func_80099F18((s32) temp_a0_2, temp_f20);
    }
}

void func_8007F368(struct unkD_8009F094* arg0, u32 arg1)
{
    D_8009FE10.unk0 = arg1 < 1;
}

void func_8007F378() {
    func_800914A8(0.0f);
    func_80095440(0, D_800A5874, -1, -1);
}
