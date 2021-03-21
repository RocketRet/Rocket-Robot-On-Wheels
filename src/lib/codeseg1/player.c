#include <include_asm.h>
#include <ultra64.h>
#include <PR/n_libaudio_s_to_n.h>
#include <PR/n_libaudio.h>
#include <mus/libmus.h>
#include <mus/player.h>

extern ALVoice *mus_voices;

INCLUDE_ASM(s32, "lib/codeseg1/player", __MusIntMain);

INCLUDE_ASM(s32, "lib/codeseg1/player", __MusIntGetNewNote);

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
  [INTERNAL FUNCTION]
  __MusIntFlushPending(cp,x)

  [Parameters]
  cp		address of music player channel
  x		channel number

  [Explanation]
  Start the sample waiting to play and, if necessary, stop the previous one.

  [Return value]
  NONE
*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

static void __MusIntFlushPending(channel_t *cp, int x)
{
  if (cp->playing)
    alSynStopVoice(&__libmus_alglobals.drvr, mus_voices+x);
  cp->playing = 1;
  /* start sample */
  alSynStartVoice(&__libmus_alglobals.drvr, mus_voices+x, cp->pending);
  cp->pending = NULL;
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
  [INTERNAL FUNCTION]
  __MusIntSetVolumeAndPan(cp,x)

  [Parameters]
  cp		address of music player channel
  x		channel number

  [Explanation]
  Output the volume level and pan position of the current channel to the hardware 
  (if necessary).

  [Return value]
  NONE
*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

// static void __MusIntSetVolumeAndPan(channel_t *cp, int x)
// {
//   u32	volume;

//   /* process volume */
//   volume = ((u32)(cp->volume)*(u32)(cp->env_current)*(u32)(cp->velocity)*(u32)(cp->volscale))>>13;
//   if (volume>32767)
//     volume = 32767;


//    if (!cp->fx_addr)
//     volume *= mus_master_volume_songs;
//   else
//     volume *= mus_master_volume_effects;
//   volume >>= 15;
//   if (cp->stopping != -1)
//     volume = (volume*cp->stopping)/cp->stopping_speed;

//   if (volume!=cp->old_volume)
//   {
//     cp->old_volume = volume;
//     alSynSetVol(&__libmus_alglobals.drvr, mus_voices+x, volume, mus_next_frame_time);

//   }

//   /* process pan */
//   volume = ((cp->pan*cp->panscale)>>7)&0x7f;
//   if (volume!=cp->old_pan)
//   {
//     cp->old_pan = volume;
//     alSynSetPan(&__libmus_alglobals.drvr, mus_voices+x, volume);
//   }
// }

INCLUDE_ASM(s32, "lib/codeseg1/player", __MusIntSetVolumeAndPan);

INCLUDE_ASM(s32, "lib/codeseg1/player", __MusIntSetPitch);

INCLUDE_ASM(s32, "lib/codeseg1/player", __MusIntInitEnvelope);

INCLUDE_ASM(s32, "lib/codeseg1/player", __MusIntProcessEnvelope);

INCLUDE_ASM(s32, "lib/codeseg1/player", __MusIntInitSweep);

INCLUDE_ASM(s32, "lib/codeseg1/player", __MusIntProcessSweep);

INCLUDE_ASM(s32, "lib/codeseg1/player", __MusIntProcessWobble);

INCLUDE_ASM(s32, "lib/codeseg1/player", __MusIntProcessVibrato);

INCLUDE_ASM(s32, "lib/codeseg1/player", __MusIntProcessContinuousVolume);

INCLUDE_ASM(s32, "lib/codeseg1/player", __MusIntProcessContinuousPitchBend);

INCLUDE_ASM(s32, "lib/codeseg1/player", __MusIntPowerOf2);

INCLUDE_ASM(s32, "lib/codeseg1/player", __MusIntRemapPtrBank);

INCLUDE_ASM(s32, "lib/codeseg1/player", __MusIntRandom);

INCLUDE_ASM(s32, "lib/codeseg1/player", __MusIntInitialiseChannel);

INCLUDE_ASM(s32, "lib/codeseg1/player", __MusIntFindChannel);

INCLUDE_ASM(s32, "lib/codeseg1/player", __MusIntRemapPtrs);

INCLUDE_ASM(s32, "lib/codeseg1/player", __MusIntStartEffect);

INCLUDE_ASM(s32, "lib/codeseg1/player", __MusIntFindChannelAndStart);

INCLUDE_ASM(s32, "lib/codeseg1/player", __MusIntStartSong);

INCLUDE_ASM(s32, "lib/codeseg1/player", __MusIntHandleSetFlag);
