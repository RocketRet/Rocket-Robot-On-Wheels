#include <include_asm.h>
#include <ultra64.h>
#include <types.h>

extern struct unkD_800ADAD0 *D_800ADAD0;

Gfx *func_800922C4(struct unkD_800ADAD0 *, s32);

void func_80086310(s32 arg0, s32 arg1, Gfx *arg2)
{
    if (arg1 != -1)
    {
        struct unkD_800ADAD0 *tmp = &D_800ADAD0[arg1];
        Gfx *g = tmp->unk8;
        if (g == 0)
        {
            g = func_800922C4(tmp, 0);
        }
        gSPDisplayList(arg2, g);
    }
}
