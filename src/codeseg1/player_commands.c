#include <include_asm.h>
#include <ultra64.h>
#include <mus/player.h>

#define static

/* Fstop - stop data processing   
 * Format: <cmd>
 */
static unsigned char *Fstop(channel_t *cp, unsigned char *ptr)
{
  cp->pvolume = NULL;
  cp->ppitchbend = NULL;
  cp->song_addr = NULL;
   cp->fx_addr = NULL;
  cp->handle = 0;
  cp->pending = NULL;
  return (NULL);
}

/* Fwave - set wave number to be played
 * Format: <cmd> <wave> or <cmd> <wave&0x7F00> <wave&0xFF)
 */
static unsigned char *Fwave(channel_t *cp, unsigned char *ptr)
{
  unsigned short wave;

  wave = *ptr++;
  if(wave&0x80)
  {
    wave &= 0x7f;
    wave <<= 8;
    wave |= *ptr++;
  }
  cp->wave = wave;
  return (ptr);
}

/* Fport - enable portamento
 * Format: <cmd> <portamento>
 */
static unsigned char *Fport(channel_t *cp, unsigned char *ptr)
{
  int val = *ptr++;
  cp->port = val;
  if (val)
    cp->port_base = cp->base_note;
  return (ptr);
}

/* Fportoff - disable portamento
 * Format: <cmd>
 */
static unsigned char *Fportoff(channel_t *cp, unsigned char *ptr)
{
  cp->port = 0;
  return (ptr);
}

INCLUDE_ASM(s32, "codeseg1/player_commands", Fdefa);

INCLUDE_ASM(s32, "codeseg1/player_commands", Ftempo);

/* Ftempo - set endit value
 * Format: <cmd> <endit>
 */
static unsigned char *Fendit(channel_t *cp, unsigned char *ptr)
{
  cp->endit=*ptr++;
  cp->cutoff=0;
  return (ptr);
}

/* Fcutoff - set cutoff value
 * Format: <cmd> <cutoff&0xFF00> <cutoff&0xFF>
 */
static unsigned char *Fcutoff(channel_t *cp, unsigned char *ptr)
{
  short tmp;

  tmp = (*ptr++)<<8;
  tmp |= *ptr++;

  cp->cutoff = tmp;
  cp->endit = 0;
  return (ptr);
}

extern f64 D_80000518; // 50.0
extern f64 D_80000520; // (2*3.1415926)

/* Fvibup - set positive vibrato
 * Format: <cmd> <delay> <speed> <amount>
 */
static unsigned char *Fvibup(channel_t *cp, unsigned char *ptr)
{

  cp->vib_delay = *ptr++;
  cp->vib_speed = *ptr++;
  cp->vib_amount = ((float)*ptr++)/D_80000518;
  cp->vib_precalc = D_80000520/(float)cp->vib_speed;
  return (ptr);
}

extern f64 D_80000528; // 50.0
extern f64 D_80000530; // (2*3.1415926)

/* Fvibdown - set negative vibrato
 * Format: <cmd> <delay> <speed> <amount>
 */
static unsigned char *Fvibdown(channel_t *cp, unsigned char *ptr)
{
  cp->vib_delay = *ptr++;
  cp->vib_speed = *ptr++;
  cp->vib_amount = (-((float)*ptr++))/D_80000528;
  cp->vib_precalc = D_80000530/(float)cp->vib_speed;
  return (ptr);
}

/* Fviboff - disable vibrato
 * Format: <cmd>
 */
static unsigned char *Fviboff(channel_t *cp, unsigned char *ptr)
{
  cp->vib_speed=0;
  cp->vibrato=0;        // if its been switched off you want it back to a normal note
  return (ptr);
}

/* Flength - set fixed length
 * Format: <cmd> <length> or <cmd> <length&0x7F00> <length&0xFF)
 */
static unsigned char *Flength(channel_t *cp, unsigned char *ptr)
{
	int length;

	length = *ptr++;
	if (length>=0x80)
	{
		length &= 0x7f;
		length <<= 8;
		length |= *ptr++;
	}
	cp->fixed_length = length;
   return (ptr);
}

/* Fignore - set ignore length flag
 * Format: <cmd>
 */
static unsigned char *Fignore(channel_t *cp, unsigned char *ptr)
{
  cp->ignore = 1;
  return (ptr);
}

/* Ftranspose - set transpose value
 * Format: <cmd> <transpose>
 */
static unsigned char *Ftrans(channel_t *cp, unsigned char *ptr)
{
  cp->transpose = *ptr++;
  return (ptr);
}

/* Fignore_trans - set ignore transpose flag
 * Format: <cmd>
 */
static unsigned char *Fignore_trans(channel_t *cp, unsigned char *ptr)
{
  cp->ignore_transpose = 1;
  return (ptr);
}

extern f64 D_80000538; // 100.0

/* Fdistort - set distortion value
 * Format: <cmd> <distort>
 */
static unsigned char *Fdistort(channel_t *cp, unsigned char *ptr)
{
  int c;
  float f;
  
  c = (int)(*ptr++);
  if(c&0x80)
    c |= 0xffffff00;	// signed chars don't work
  f = (float)(c)/D_80000538;

  cp->freqoffset -= cp->distort;
  cp->freqoffset += f;
  cp->distort = f;
  return (ptr);
}

/* Fenvelope - set envelope from envelope table
 * Format: <cmd> <index> or <cmd> <index&0x7F00> <index&0xFF)
 */
static unsigned char *Fenvelope(channel_t *cp, unsigned char *ptr)
{
  int tmp;

  tmp = *ptr++;
  if(tmp&0x80)
  {
    tmp &= 0x7f;
    tmp <<= 8;
    tmp |= *ptr++;
  }
  (void)Fdefa(cp, &cp->song_addr->env_table[tmp*7]);
  return (ptr);
}

/* Fenvoff - disable envelopes
 * Format: <cmd>
 */
static unsigned char *Fenvoff(channel_t *cp, unsigned char *ptr)
{
  cp->env_trigger_off = 1;
  return (ptr);
}

/* Fenvoff - enable envelopes
 * Format: <cmd>
 */
static unsigned char *Fenvon(channel_t *cp, unsigned char *ptr)
{
  cp->env_trigger_off = 0;
  return (ptr);
}

/* Ftroff - disable triggering
 * Format: <cmd>
 */
static unsigned char *Ftroff(channel_t *cp, unsigned char *ptr)
{
  cp->trigger_off = 1;
  return (ptr);
}

/* Ftron - enable triggering
 * Format: <cmd>
 */
static unsigned char *Ftron(channel_t *cp, unsigned char *ptr)
{
  cp->trigger_off = 0;
  return (ptr);
}

INCLUDE_ASM(s32, "codeseg1/player_commands", Ffor);

INCLUDE_ASM(s32, "codeseg1/player_commands", Fnext);

/* Fwobble - define wobble settings
 * Format: <cmd> <amount> <on speed> <off speed>
 */
static unsigned char *Fwobble(channel_t *cp, unsigned char *ptr)
{
  cp->wobble_amount = *ptr++;
  cp->wobble_on_speed = *ptr++;
  cp->wobble_off_speed = *ptr++;
  return(ptr);
}

/* Fwobble - disable wobble
 * Format: <cmd>
 */
static unsigned char *Fwobbleoff(channel_t *cp, unsigned char *ptr)
{
  cp->wobble_on_speed = 0;
  return (ptr);
}

/* Fvelon - enable velocity mode
 * Format: <cmd>
 */
static unsigned char *Fvelon(channel_t *cp, unsigned char *ptr)
{  
  cp->velocity_on = 1;
  return (ptr);
}

/* Fvelon - disable velocity mode
 * Format: <cmd>
 */
static unsigned char *Fveloff(channel_t *cp, unsigned char *ptr)
{
  cp->velocity_on = 0;
  return (ptr);
}

/* Fvelon - enable default velocity mode
 * Format: <cmd> <default velocity>
 */

/* default velocity map */
static unsigned char *Fvelocity(channel_t *cp, unsigned char *ptr)
{
  cp->default_velocity 	= *ptr++;
  cp->velocity_on = 0;
  return (ptr);
}

/* Fpan - set pan position
 * Format: <cmd> <pan*2>
 */
static unsigned char *Fpan(channel_t *cp, unsigned char *ptr)
{
  cp->pan = (*ptr++)/2;
  return (ptr);
}

/* Fstereo - OUTDATED
 * Format: <cmd> <ignored> <ignored>
 */
static unsigned char *Fstereo(channel_t *cp, unsigned char *ptr)
{
  return (ptr+2);
}

/* Fdrums - enable drum data
 * Format: <cmd> <index>
 * Format: <cmd> <index> or <cmd> <index&0x7F00> <index&0xFF)
 */


static unsigned char *Fdrums(channel_t *cp, unsigned char *ptr)
{
	int index;

	index = *ptr++;
	if (index>=0x80)
	{
		index &=0x7f;
		index <<=8;
		index |= *ptr++;
	}
   cp->pdrums = &cp->song_addr->drum_table[index];
  return (ptr);
}

/* Fdrumsoff - disable drum data
 * Format: <cmd>
 */
static unsigned char *Fdrumsoff(channel_t *cp, unsigned char *ptr)
{
  cp->pdrums = NULL;
  return (ptr);
}

/* Fprint - display debugging info (DEBUG MODE ONLY!!!)
 * Format: <cmd> <data to print>
 */
static unsigned char *Fprint(channel_t *cp, unsigned char *ptr)
{
#ifdef _AUDIODEBUG
  osSyncPrintf("PLAYER_COMMANDS.C: Fprint() -  %d (channel frame=%d)\n", *ptr++,  cp->channel_frame);
  return (ptr);
#else
  ptr++;
  return (ptr);
#endif
}

/* Fgoto - sound data ptr relative jump
 * Format: <cmd> <song data offset&0xFF00> <song data offset&0xFF>
 *               <volume data offset&0xFF00> <volume data offset&0xFF>
 *               <pitchbend data offset&0xFF00> <pitchbend data offset&0xFF>
 */
static unsigned char *Fgoto(channel_t *cp, unsigned char *ptr)
{
  int off, off1;

  /* 2 bytes for song offset */
  off1 = *ptr++<<8;
  off1 += *ptr++;

  /* get volume offset BEFORE updating pointer */
  /* 2 bytes for volume offset (never inside a run length bit) */
  off = *ptr++<<8;
  off += *ptr++;
  cp->pvolume = cp->pvolumebase+off;
  cp->cont_vol_repeat_count = 1;
  
  /* get pitchbend offset BEFORE updating pointer */
  /* 2 bytes for pitchbend offset (never inside a run length bit) */
  off = *ptr++<<8;
  off += *ptr++;
  cp->ppitchbend = cp->ppitchbendbase+off;
  cp->cont_pb_repeat_count = 1;
  
  return (cp->pbase+off1);
}

/* Freverb - set reverb value
 * Format: <cmd> <reverb>
 */
static unsigned char *Freverb(channel_t *cp, unsigned char *ptr)
{
  cp->reverb = *ptr++;
  return (ptr);
}

/* FrandNote - set random transpose (within a range)
 * Format: <cmd> <range> <offset>
 */
static unsigned char *FrandNote(channel_t *cp, unsigned char *ptr)
{	
  // rand_amount,rand_base  -- 20,-3 would give -3 to 16 as the value
  cp->transpose = __MusIntRandom(*ptr++);
  cp->transpose += *ptr++;
  return (ptr);
}

/* FrandVolume - set random volume level
 * Format: <cmd> <range> <offset>
 */
static unsigned char *FrandVolume(channel_t *cp, unsigned char *ptr)
{
  // rand_amount,base
  cp->volume = __MusIntRandom(*ptr++);
  cp->volume += *ptr++;
  return (ptr);
}

/* FrandPan - set random pan position
 * Format: <cmd> <range> <offset>
 */
static unsigned char *FrandPan(channel_t *cp, unsigned char *ptr)
{
  // rand_amount,base
  cp->pan = __MusIntRandom(*ptr++);
  cp->pan += *ptr++;
  return (ptr);
}

/* Fvolume - set volume level
 * Format: <cmd> <volume>
 */
static unsigned char *Fvolume(channel_t *cp, unsigned char *ptr)
{
  cp->volume = *ptr++;
  return (ptr);
}

INCLUDE_ASM(s32, "codeseg1/player_commands", Fstartfx);

extern f64 D_80000548; // (1.0/64.0)

/* Fbendrange - set bend range
 * Format: <cmd> <bend range>
 */
static unsigned char *Fbendrange(channel_t *cp, unsigned char *ptr)
{
  cp->bendrange = (float)(*ptr++)*D_80000548;
  cp->pitchbend_precalc = cp->pitchbend*cp->pitchbend;
  return (ptr);
}

/* Command : Setup pan sweeping
   Format  : Csweep, speed */
static unsigned char *Fsweep(channel_t *cp, unsigned char *ptr)
{
  cp->sweep_speed = *ptr++;
  return (ptr);
}

#define SUPPORT_FXCHANGE
#define mus_songfxchange_flag D_800BD2FC

extern musBool D_800BD2FC;

/* Command : Change FX type
   Format  : Cchangefx, fxtype */
static unsigned char *Fchangefx(channel_t *cp, unsigned char *ptr)
{
  int fxtype;

  fxtype = *ptr++;
#ifdef SUPPORT_FXCHANGE
  if (mus_songfxchange_flag==MUSBOOL_ON)
  {
    ChangeCustomEffect(fxtype);
  }
#endif

  return (ptr);
}

#define marker_callback D_800BD30C
extern LIBMUScb_marker D_800BD30C;

/* Command : Marker definition
	Format  : Cmarker, number, <rest length> or Cmarker, number, <rest&0x7f00>, <rest&0xff> */
static unsigned char *Fmarker(channel_t *cp, unsigned char *ptr)
{
  int rest;
  int number;

  number = *ptr++; /* marker number */
  rest = *ptr++;
  if(rest&0x80)
  {
    rest &= 0x7f;
    rest <<= 8;
    rest |= *ptr++;
  }
  /* if not going to a marker but marker is found on the mastertrack try callback */
  if ((cp->channel_flag&CHFLAG_MASTERTRACK) && !(cp->channel_flag&CHFLAG_PAUSE))
  {
		if (marker_callback)
			marker_callback(cp->handle, number);
  }
  return (ptr);
}

/* Command : Disable fixed length mode (replaces Clength,0)
   Format  : Clength0 */
static unsigned char *Flength0(channel_t *cp, unsigned char *ptr)
{
	cp->fixed_length = 0;
	return (ptr);
}

extern unsigned char *D_800BD2D0;

void func_8000516C(s32 arg0, unsigned char arg1)
{
    D_800BD2D0[arg0] = arg1;
}

INCLUDE_ASM(s32, "codeseg1/player_commands", func_80005180);
