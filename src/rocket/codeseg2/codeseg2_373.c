#include <include_asm.h>
#include <ultra64.h>
#include <types.h>

extern struct MaterialGfx *materialTable;

Gfx *func_800922C4(struct MaterialGfx *, s32);

void func_80086310(void *arg0, s32 arg1, Gfx *arg2)
{
    if (arg1 != -1)
    {
        struct MaterialGfx *tmp = &materialTable[arg1];
        Gfx *g = tmp->gfx;
        if (g == 0)
        {
            g = func_800922C4(tmp, 0);
        }
        gSPDisplayList(arg2, g);
    }
}
