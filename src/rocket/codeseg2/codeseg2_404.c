#include <include_asm.h>
#include <ultra64.h>
#include <types.h>

extern s32 D_800A3190;

extern s32 D_800AF310;
extern s32 D_800AF320;

extern s32 D_800AF44C[4];
extern s32 D_800AF45C[33];
extern s32 D_800AF4E0;

void func_80091F40(struct unkfunc_80091F54 *arg0, s32 arg1)
{
    arg0->unk318[arg1] = 1;
}

void func_80091F54(s32 arg0)
{
    struct unkfunc_80091F54 var;
    struct unkfunc_80091F54 *tmp;
    u32 i;

    if (D_800AF320 != 1)
    {
        arg0 = 0;
    }

    if (arg0 != D_800AF4E0)
    {
        if (D_800AF310)
        {
            if (arg0)
            {
                bzero(&var, sizeof(var));

                var.unk0 = &D_800A3190;

                for (i = 0; i < 4; i++)
                {
                    var.unk18[D_800AF44C[i]] = 1;
                }

                i = 0;
                while (1)
                {
                    if (i >= 0x21)
                        break;
                    var.unk318[D_800AF45C[i++]] = 1;
                }

                func_80091BFC(&var);
            }
            else
            {
                func_80091BFC(D_800AF310);
            }
        }
        D_800AF4E0 = arg0;
    }
}
