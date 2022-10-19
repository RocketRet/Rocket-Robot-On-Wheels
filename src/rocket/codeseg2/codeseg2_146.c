#include <include_asm.h>
#include <ultra64.h>
#include "codeseg2.h"

extern void* D_800A5C30[3];

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_146", func_80046370);

s32 func_8004667C(struct unkD_800A5C3C*, s32, void**, s32, s32, s32, s32, s32); /* extern */
void func_80088988(struct unkD_800A5C3C*, s32, s32);   /* extern */
void func_80089F18(struct unkD_800A5C3C*);             /* extern */
void func_8008ABE4(struct unkD_800A5C3C*, u8, u8, u8, u8); /* extern */
void func_8008ABFC(struct unkD_800A5C3C*, f32, f32);   /* extern */

s32 func_800463B4(struct GfxContext* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Gfx* temp_s4;
    s32 temp_s2;

    temp_s4 = arg0->dlHead;
    temp_s2 = func_8004667C(&D_800A5C3C, arg1, D_800A5C30, D_800C0440.unk8, D_800C0440.unkC, arg2, arg3, arg4);
    func_80088988(&D_800A5C3C, D_800C0440.unk0, D_800C0440.unk4);
    func_8008ABE4(&D_800A5C3C, D_800C0440.unk18, D_800C0440.unk19, D_800C0440.unk1A, D_800C0440.unk1B);
    func_8008ABFC(&D_800A5C3C, D_800C0440.unk10, D_800C0440.unk14);
    D_800A5C3C.unk3C = temp_s4;
    D_800A5C3C.unk38 = temp_s4;
    D_800A5C3C.unk2A = ((uintptr_t)arg0->unkC - (uintptr_t)arg0->dlHead) / sizeof(Gfx);
    func_80089F18(&D_800A5C3C);
    arg0->dlHead = D_800A5C3C.unk3C - 1;
    return temp_s2;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_146", func_800464AC);
