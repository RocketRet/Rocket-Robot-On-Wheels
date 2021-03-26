#include <include_asm.h>
#include <ultra64.h>
#include <sounds.h>
#include <gameplay.h>

extern s32 gCurLevelTokens;

void func_8006BF90(s32 *arg0)
{
    func_80042710(arg0[9]);
    if (gCurLevelTokens < LEVEL_TOKEN_COUNT)
    {
        play_sound(arg0[10] + SFX_GET_TOKEN_SILVER, 0, 0x80, 0x80);
    }
    else
    {
        play_sound(SFX_GET_TICKET, 0, 0x80, 0x80);
    }
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_268", func_8006BFFC);

s32 func_8006C074(u32 arg0)
{
    return (arg0 - 166) < 12;
}
