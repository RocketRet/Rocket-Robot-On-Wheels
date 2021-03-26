#include <include_asm.h>
#include <ultra64.h>
#include <types.h>
#include <mus/libmus.h>

extern s32 D_800AF318;
extern s32 D_800AF31C;
extern s32 D_800AF320;
extern s32 D_800AF3F0;

extern f32 D_8001D808;
extern f32 D_8001D80C;

struct unkD_800E5090 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

extern struct unkD_800E5090 D_800E5090[];
extern struct unkD_800E5090 D_800E5F90[]; // Is this the right struct?

// const f64 D_8001D800 = 128.0;
// const f32 D_8001D808 = 100.0f;
// const f32 D_8001D80C = 28.0f;
// const f32 D_8001D810 = 32767.0f;
// const f32 D_8001D814 = 32767.0f;
// const f32 D_8001D818 = 3.0f;
// const f32 D_8001D81C = 1.5f;

extern f64 D_8001D800;
extern f32 D_8001D808;
extern f32 D_8001D80C;
extern f32 D_8001D810;
extern f32 D_8001D814;
extern f32 D_8001D818;
extern f32 D_8001D81C;

// Needed because text ends up in rodata with current splat setup
// __asm__(".section .text");

// TODO float load
// void func_80091410(f32 arg0) {
//     s32 ret = D_800AF320;
//     if (ret != 0) {
//         MusHandleSetVolume(D_800E5F90[ret - 1].unk4, (s32) ((arg0 * D_8001D808) + D_8001D80C));
//     }
//     return ret;
// }

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_403", func_80091410);

// TODO float load
// void func_80091474(f32 arg0) {
//     MusSetMasterVolume(MUSFLAG_EFFECTS, 32767 * arg0);
// }

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_403", func_80091474);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_403", func_800914A8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_403", func_800914DC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_403", func_80091AA8);

// TODO regalloc
// musHandle play_sound(u32 number, s32 arg1, s32 volume, s32 pan)
// {
//     musHandle ret;
//     if (number < 0xa2 &&D_800AF3F0 == 0 && volume != 0)
//     {
//         if (arg1 != 0)
//         {
//             if (D_800AF31C != -1)
//             {
//                 struct unkD_800E5090 *unk;
//                 ret = MusStartEffect2(number, volume, pan, 0, -1);
//                 unk = &D_800E5090[D_800AF31C];
//                 unk->unk4 = ret;
//                 if (ret == 0)
//                 {
//                     return 0;
//                 }
//                 else
//                 {
//                     D_800AF31C = unk->unkC;
//                     unk->unk0 = 3;
//                     unk->unk8 = -1;
//                     D_800AF318++;
//                 }
//             }
//             else
//             {
//                 return 0;
//             }
//         }
//         else
//         {
//             ret = MusStartEffect2(number, volume, pan, 0, -1);
//         }
//     }
//     else
//     {
//         return 0;
//     }
//     return ret;
// }

INCLUDE_ASM(musHandle, "rocket/codeseg2/codeseg2_403", play_sound, u32 number, s32 arg1, s32 volume, s32 pan);

// TODO is this really the same struct?
void func_80091BD4(struct unkfunc_80091F54 *arg0, s32 arg1)
{
    // index[array] again
    arg1[arg0->unk18] = 1;
}

void func_80091BE8(struct unkfunc_80091F54 *arg0, s32 arg1)
{
    // index[array] again
    arg1[arg0->unk318] = 1;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_403", func_80091BFC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_403", func_80091C98);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_403", func_80091CD8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_403", func_80091DD8);

void func_80091F2C(struct unkfunc_80091F54 *arg0, s32 arg1)
{
    // index[array] again
    arg1[arg0->unk18] = 1;
}
