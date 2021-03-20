#include <include_asm.h>

#include "libmus_config.h"
#include <ultra64.h>
#include <sched.h>
#include "player_fx.h"

extern N_ALSynth *n_syn;
#define n_syn n_syn

extern N_ALGlobals *D_80019930;
#define n_alGlobals D_80019930

#define gReverbFx D_800BEAE0

/* this global structure handles memory within the Audio Heap that is used by the Effect object */
extern REVERB_MEM gReverbFx;

/* internal util function prototypes */
static s32 GetFxMostSections(void);
static s32 GetFxLongest(void);
static void SetForCustom(ALSynConfig *c);

#ifdef SUPPORT_NAUDIO
#define alGlobals n_alGlobals
#endif

/* same as alInit(), but passes to CustomSynNew() */
void CustomInit(ALGlobals *g, ALSynConfig *c)
{
  if (!alGlobals)	/* already initialized? */
  {
    alGlobals = g;
#ifndef SUPPORT_NAUDIO
    SetForCustom(c);
    gReverbFx.synth = &alGlobals -> drvr;	// we'll need it later
    CustomSynNew(&alGlobals->drvr, c);
#else
    if(!n_syn)
    {
      SetForCustom(c);
      n_syn = gReverbFx.synth = &alGlobals -> drvr;	// we'll need it later
      CustomSynNew(c);
    }
#endif
  }
}

INCLUDE_ASM(void, "lib/codeseg1/player_fx", CustomSynNew, ALSynConfig *c);

void CustomFxNew();

// TODO different structs, index[array]
// ALFxRef CustomAllocFX(s16 bus, ALSynConfig *c, ALHeap *hp)
// {
//     CustomFxNew(&n_syn->auxBus->fx_array[bus], c, hp);
//     return(n_syn->auxBus->fx_array[bus]);
// }

INCLUDE_ASM(ALFxRef, "lib/codeseg1/player_fx", CustomAllocFX, s16 bus, ALSynConfig *c, ALHeap *hp);

/*
 *	create a new effect
 *
 *	this has been modified to keep the pointers to the used memory
 *	so we can modify and re-use later
 *	Because of this the actual setting of the filter etc. is done in CustomFxSet()
 */

#define RANGE 2.0
#define CONVERT 173123.404906676
#define LENGTH	(d->output - d->input)

#ifndef SUPPORT_NAUDIO
void CustomFxNew(ALFx *r, ALSynConfig *c, ALHeap *hp)
{
    ALFilter	*f = (ALFilter *)r;

    alFilterNew(f, 0, alFxParam, AL_FX);
    f->handler = alFxPull;
#else
void CustomFxNew(ALFx **fx_ar, ALSynConfig *c, ALHeap *hp)
{
    ALFx *r;

    *fx_ar = r = (ALFx *)alHeapAlloc(hp, 1, sizeof(ALFx));
#endif

    r->paramHdl = (ALSetFXParam)alFxParamHdl;

	/* allocate enough space for the biggest effect */
    gReverbFx.pDelay = alHeapAlloc(hp, GetFxMostSections(), sizeof(ALDelay));
    gReverbFx.pBase = alHeapAlloc(hp, GetFxLongest(), sizeof(s16));

	/* allocate some stuff used by the Delay Lines */
	gReverbFx.pResampler = alHeapAlloc(hp, 1, sizeof(ALResampler));
	gReverbFx.pResampleState = alHeapAlloc(hp, 1, sizeof(RESAMPLE_STATE));
	gReverbFx.pLowPass = alHeapAlloc(hp, 1, sizeof(ALLowPass));
	gReverbFx.pLpfState = alHeapAlloc(hp, 1, sizeof(POLEF_STATE));

	/* set it up */
	CustomFxSet(c->params);
}

extern s32 BigRoomParams[];
extern s32 EffectCount;
extern s32 *EffectList[];

INCLUDE_ASM(void, "lib/codeseg1/player_fx", CustomFxSet, s32 *);

/*
 *	find the most sections used by an effect
 *	this is used to allocate space for Delay Lines in the AlFX object
 *
 */

static void SetForCustom(ALSynConfig *c)
{
  c->fxType = AL_FX_CUSTOM;
  c->params = BigRoomParams;
}

static s32 GetFxMostSections(void)
{
	int i;
	s32 most = 0;

	for(i = 0; EffectList[i] != NULL; i++)
	{
		s32 *pFx = EffectList[i];

		/* the first s32 is the number of sections */
		if(pFx[0] > most)
		{
			most = pFx[0];
		}
	}

	return most;
}

/*
 *	find the length of the longest effect
 *	this is important as it means we only allocate once from the Audio Library Heap
 *	memory cannot be freed from an Audio Heap
 */

static s32 GetFxLongest(void)
{
	int i;
	s32 longest = 0;

	for(i = 0; EffectList[i] != NULL; i++)
	{
		s32 *pFx = EffectList[i];

		/* the second s32 is the length of the effect */
		if(pFx[1] > longest)
		{
			longest = pFx[1];
		}
	}

	return longest;
}

/*
 *	Change to a new effect setup
 *
 *	N.B. this needn't be called if you only set some parameters within an effect
 *		 there are library functions to do that, but the library functions
 *		 don't allow you to change length or number of sections within an effect
 *
 *		param is a list of s32 values, as per SGI documentation
 */

int ChangeCustomEffect(s32 type)
{
	/* IMPORTANT - the Audio Thread MUST NOT be generating any audio when this is called */
	/* e.g. call PcRomSilence(), then wait for retrace to make sure all audio is used up */

	if(type >= EffectCount)
		return(1);		/* index is larger than list */

	CustomFxSet(EffectList[type]);

	return(0);			/* done ok */
}

