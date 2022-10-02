#include <include_asm.h>
#include <ultra64.h>
#include <types.h>
#include <mus/libmus.h>

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_396", func_8008FF30);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_396", func_80090134);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_396", func_8009018C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_396", func_800901D4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_396", func_80090494);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_396", func_800904E4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_396", func_80090538);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_396", func_8009067C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_396", func_800907B0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_396", func_8009099C);


struct unkfunc_80091068
{
    s32 unk0;
    s32 unk4;
};

extern s32 D_800AF404[];

extern s32 D_800AF314;
extern s32 D_800AF318;
extern s32 D_800AF31C;
extern s32 D_800AF320;
extern s32 D_800AF3F0;

extern s32 D_800AF3FC;

struct unkD_800E5090 {
    s32 unk0;
    musHandle handle;
    s32 unk8;
    s32 unkC;
};

extern struct unkD_800E5090 D_800E5090[];
extern struct unkD_800E5090 D_800E5F90[]; // Is this the right struct?
extern s32 D_8009F094;

void func_80091024(s32 arg0, s32 arg1)
{
    D_800AF3FC = 1;
    func_8009099C(D_8009F094);
}

void func_80091054()
{
    D_800AF3FC = 0;
}

struct unkfunc_80091060
{
    u8 padding[0x38];
    float unk38;
};

void func_80091060(struct unkfunc_80091060 *arg0, float arg1)
{
    arg0->unk38 = arg1;
}

void func_80091068(struct unkfunc_80091068 *arg0, s32 arg1)
{
    arg0->unk4 = arg1;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_396", func_80091070);

s32 func_800911B0(s32 arg0)
{
    return D_800AF404[arg0];
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_396", func_800911CC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_396", func_80091220);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_396", func_800912A4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_396", func_80091304, s32);

void func_800913F0()
{
    func_80091304(-1);
}

void func_80091410(float arg0)
{
    if (D_800AF320)
    {
        MusHandleSetVolume(D_800E5F90[D_800AF320 - 1].handle, arg0 * 100.0f + 28.0f);
    }
}

void func_80091474(float arg0)
{
    MusSetMasterVolume(MUSFLAG_EFFECTS, arg0 * 32767.0f);
}

void func_800914A8(float arg0)
{
    MusSetMasterVolume(MUSFLAG_EFFECTS | MUSFLAG_SONGS, arg0 * 32767.0f);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_396", func_800914DC);

void func_80091AA8(musHandle handle, s32 arg1)
{
    if (handle)
    {
        s32 i;
        for (i = 0; i < 0x90; i++)
        {
            if (D_800E5090[i].handle == handle && D_800E5090[i].unk8 < 0)
            {
                D_800E5090[i].unk8 = arg1;
                D_800AF314++;
            }
        }
    }
}

musHandle play_sound(u32 number, s32 arg1, s32 volume, s32 pan)
{
    musHandle ret;
    if (number < 0xa2 &&D_800AF3F0 == 0 && volume != 0)
    {
        if (arg1 != 0)
        {
            if (D_800AF31C != -1)
            {
                struct unkD_800E5090 *unk;
                ret = MusStartEffect2(number, volume, pan, 0, -1);
                D_800E5090[D_800AF31C].handle = ret;
                if (ret == 0)
                {
                    return 0;
                }
                else
                {
                    unk = &D_800E5090[D_800AF31C];
                    D_800AF31C = unk->unkC;
                    unk->unk0 = 3;
                    unk->unk8 = -1;
                    D_800AF318++;
                }
            }
            else
            {
                return 0;
            }
        }
        else
        {
            ret = MusStartEffect2(number, volume, pan, 0, -1);
        }
    }
    else
    {
        return 0;
    }
    return ret;
}

// TODO is this really the same struct?
void func_80091BD4(struct unkfunc_80091F54 *arg0, s32 arg1)
{
    arg0->unk18[arg1] = 1;
}

void func_80091BE8(struct unkfunc_80091F54 *arg0, s32 arg1)
{
    arg0->unk318[arg1] = 1;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_396", func_80091BFC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_396", func_80091C98);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_396", func_80091CD8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_396", func_80091DD8);

void func_80091F2C(struct unkfunc_80091F54 *arg0, s32 arg1)
{
    arg0->unk18[arg1] = 1;
}
