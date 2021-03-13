#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(s32, "codeseg1/player_commands", Fstop);

INCLUDE_ASM(s32, "codeseg1/player_commands", Fwave);

INCLUDE_ASM(s32, "codeseg1/player_commands", Fport);

s32 Fportoff(u8 *arg0, s32 arg1)
{
    arg0[0xB8] = 0; // TODO probably a struct
    return arg1;
}

INCLUDE_ASM(s32, "codeseg1/player_commands", Fdefa);

INCLUDE_ASM(s32, "codeseg1/player_commands", Ftempo);

INCLUDE_ASM(s32, "codeseg1/player_commands", Fendit);

INCLUDE_ASM(s32, "codeseg1/player_commands", Fcutoff);

INCLUDE_ASM(s32, "codeseg1/player_commands", Fvibup);

INCLUDE_ASM(s32, "codeseg1/player_commands", Fvibdown);

INCLUDE_ASM(s32, "codeseg1/player_commands", Fviboff);

INCLUDE_ASM(s32, "codeseg1/player_commands", Flength);

s32 Fignore(u8 *arg0, s32 arg1)
{
    arg0[0xB7] = 1; // TODO probably a struct
    return arg1;
}

u8 *Ftrans(u8 *arg0, u8 *arg1)
{
    arg0[0xB9] = *arg1; // TODO probably a struct
    return arg1 + 1;
}

s32 Fignore_trans(u8 *arg0, s32 arg1)
{
    arg0[0xBA] = 1; // TODO probably a struct
    return arg1;
}

INCLUDE_ASM(s32, "codeseg1/player_commands", Fdistort);

INCLUDE_ASM(s32, "codeseg1/player_commands", Fenvelope);

INCLUDE_ASM(s32, "codeseg1/player_commands", Fenvoff);

s32 Fenvon(u8 *arg0, s32 arg1)
{
    arg0[0xD6] = 0; // TODO probably a struct
    return arg1;
}

INCLUDE_ASM(s32, "codeseg1/player_commands", Ftroff);

s32 Ftron(u8 *arg0, s32 arg1)
{
    arg0[0xD7] = 0; // TODO probably a struct
    return arg1;
}

INCLUDE_ASM(s32, "codeseg1/player_commands", Ffor);

INCLUDE_ASM(s32, "codeseg1/player_commands", Fnext);

INCLUDE_ASM(s32, "codeseg1/player_commands", Fwobble);

s32 Fwobbleoff(u8 *arg0, s32 arg1)
{
    arg0[0xCE] = 0; // TODO probably a struct
    return arg1;
}

INCLUDE_ASM(s32, "codeseg1/player_commands", Fvelon);

s32 Fveloff(u8 *arg0, s32 arg1)
{
    arg0[0xD2] = 0; // TODO probably a struct
    return arg1;
}

INCLUDE_ASM(s32, "codeseg1/player_commands", Fvelocity);

INCLUDE_ASM(s32, "codeseg1/player_commands", Fpan);

s32 Fstereo(s32 arg0, s32 arg1)
{
    return arg1 + 2; // TODO probably a struct
}

INCLUDE_ASM(s32, "codeseg1/player_commands", Fdrums);

s32 Fdrumsoff(s32 *arg0, s32 arg1)
{
    arg0[0x21] = 0; // TODO probably a struct
    return arg1;
}

s32 Fprint(s32 arg0, s32 arg1)
{
    return arg1 + 1;
}

INCLUDE_ASM(s32, "codeseg1/player_commands", Fgoto);

u8 *Freverb(u8 *arg0, u8 *arg1)
{
    arg0[0xCA] = *arg1; // TODO probably a struct
    return arg1 + 1;
}

INCLUDE_ASM(s32, "codeseg1/player_commands", FrandNote);

INCLUDE_ASM(s32, "codeseg1/player_commands", FrandVolume);

INCLUDE_ASM(s32, "codeseg1/player_commands", FrandPan);

u8 *Fvolume(u8 *arg0, u8 *arg1)
{
    arg0[0xBC] = *arg1; // TODO probably a struct
    return arg1 + 1;
}

INCLUDE_ASM(s32, "codeseg1/player_commands", Fstartfx);

INCLUDE_ASM(s32, "codeseg1/player_commands", Fbendrange);

u8 *Fsweep(u8 *arg0, u8 *arg1)
{
    arg0[0xD4] = *arg1; // TODO probably a struct
    return arg1 + 1;
}

INCLUDE_ASM(s32, "codeseg1/player_commands", Fchangefx);

INCLUDE_ASM(s32, "codeseg1/player_commands", Fmarker);

s32 Flength0(s16 *arg0, s32 arg1)
{
    arg0[0x56] = 0; // TODO probably a struct
    return arg1;
}

INCLUDE_ASM(s32, "codeseg1/player_commands", func_8000516C);

INCLUDE_ASM(s32, "codeseg1/player_commands", func_80005180);
