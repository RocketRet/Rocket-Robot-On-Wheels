#include <include_asm.h>
#include <ultra64.h>

INCLUDE_ASM(s32, "codeseg1/player_api", MusInitialize);

INCLUDE_ASM(s32, "codeseg1/player_api", MusSetMasterVolume);

INCLUDE_ASM(s32, "codeseg1/player_api", MusStartSong);

INCLUDE_ASM(s32, "codeseg1/player_api", MusStartSongFromMarker);

INCLUDE_ASM(s32, "codeseg1/player_api", MusStartEffect);

INCLUDE_ASM(s32, "codeseg1/player_api", MusStartEffect2);

INCLUDE_ASM(s32, "codeseg1/player_api", MusStop);

INCLUDE_ASM(s32, "codeseg1/player_api", MusAsk);

INCLUDE_ASM(s32, "codeseg1/player_api", MusHandleStop);

INCLUDE_ASM(s32, "codeseg1/player_api", MusHandleAsk);

INCLUDE_ASM(s32, "codeseg1/player_api", MusHandleSetVolume);

INCLUDE_ASM(s32, "codeseg1/player_api", MusHandleSetPan);

INCLUDE_ASM(s32, "codeseg1/player_api", MusHandleSetFreqOffset);

// IDO?

struct unkMusPtrBankSetCurrent {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
};

extern struct unkMusPtrBankSetCurrent *D_800BD2F8; // mus_default_bank
extern s32 D_800BD304;
extern s32 D_800BD308;

INCLUDE_ASM(s32, "codeseg1/player_api", MusHandleSetTempo);

INCLUDE_ASM(s32, "codeseg1/player_api", MusHandleSetReverb);

INCLUDE_ASM(s32, "codeseg1/player_api", MusPtrBankInitialize);

INCLUDE_ASM(s32, "codeseg1/player_api", MusPtrBankSetSingle);

void MusPtrBankSetCurrent(struct unkMusPtrBankSetCurrent *arg0)
{
    if (arg0 && arg0->unk10 < 0)
    {
        D_800BD2F8 = arg0;
    }
}

void *MusPtrBankGetCurrent()
{
    return D_800BD2F8;
}

INCLUDE_ASM(s32, "codeseg1/player_api", MusHandleGetPtrBank);

struct unkMusHandleUnPause {
    u8 unk0;
    u32 unk4;
};

int __MusIntFifoAddCommand(struct unkMusHandleUnPause *);

int MusHandlePause(s32 arg0)
{
    struct unkMusHandleUnPause sp10;
    sp10.unk0 = 0;
    sp10.unk4 = arg0;
    return __MusIntFifoAddCommand(&sp10);
}

void MusHandleUnPause(s32 arg0)
{
    struct unkMusHandleUnPause sp10;
    sp10.unk0 = 1;
    sp10.unk4 = arg0;
    __MusIntFifoAddCommand(&sp10);
}

INCLUDE_ASM(s32, "codeseg1/player_api", MusSetFxType);

INCLUDE_ASM(s32, "codeseg1/player_api", MusSetSongFxChange);

INCLUDE_ASM(s32, "codeseg1/player_api", MusFxBankInitialize);

s32 MusFxBankNumberOfEffects(s32 *arg0)
{
    return arg0[1];
}

void MusFxBankSetCurrent(s32 arg0)
{
    D_800BD304 = arg0;
}

void MusFxBankSetSingle(s32 arg0)
{
    D_800BD308 = arg0;
}

extern s32 D_800BD304;

s32 MusFxBankGetCurrent()
{
    return D_800BD304;
}

struct unkMusFxBankSetPtrBank {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
};

void MusFxBankSetPtrBank(struct unkMusFxBankSetPtrBank *arg0, s32 arg1)
{
    arg0->unk10 = arg1;
}

s32 MusFxBankGetPtrBank(struct unkMusFxBankSetPtrBank *arg0)
{
    return arg0->unk10;
}

extern struct unkMusFxBankSetPtrBank *D_8001988C;

void MusSetScheduler(struct unkMusFxBankSetPtrBank *arg0)
{
    D_8001988C = arg0;
}

INCLUDE_ASM(s32, "codeseg1/player_api", MusHandleWaveCount);

INCLUDE_ASM(s32, "codeseg1/player_api", MusHandleWaveAddress);

extern s32 D_800BD30C;

void MusSetMarkerCallback(s32 arg0)
{
    D_800BD30C = arg0;
}
