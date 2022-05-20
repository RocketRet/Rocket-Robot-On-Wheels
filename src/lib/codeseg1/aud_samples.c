
/*************************************************************

  aud_samples.c : Nintendo 64 Music Tools Programmers Library
  (c) Copyright 1997/1998, Software Creations (Holdings) Ltd.

  Version ???

  Music library frame sample calculations.

**************************************************************/

/* include configuartion */
#include "libmus_config.h"

/* include system headers */
#include <ultra64.h>

/* include current header file */
#include "aud_samples.h"

/* internal macros */
#define N_SAMPLES    184

/* internal workspace */
static int frame_samples;
static int frame_samples_min;


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
  [EXTERNAL FUNCTION]
  __MusIntSamplesInit(retrace_count, output_rate, vsyncs_per_sec, extra_rate)

  [Parameters]
  retrace_count		number of vsyncs per vsync message
  output_rate		audio libary output rate value
  vsyncs_per_sec	number of vsyncs per second
  extra_rate		ratio of extra samples to download

  [Explanation]
  Calculate constants for the number of samples required per frame.

  [Return value]
  Maximum number of samples downloaded per frame
*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef SUPPORT_NAUDIO
u32 __MusIntSamplesInit(u32 retrace_count, u32 output_rate, u32 vsyncs_per_sec, u32 extra_rate)
{
	u32 calc;

	calc = (retrace_count*output_rate + vsyncs_per_sec - 1)/vsyncs_per_sec;
	frame_samples = ((calc/16) + 1)*16;
	frame_samples_min = frame_samples-16;
	extra_samples = frame_samples*extra_rate/100;
	return (frame_samples+16+extra_samples);
}
#else    /* SUPPORT_NAUDIO */
u32 __MusIntSamplesInit(float retrace_count, float output_rate, float vsyncs_per_sec, int extra_rate)
{
	float calc;

	calc = (retrace_count*output_rate + vsyncs_per_sec - 1.0)/vsyncs_per_sec;
	frame_samples = (((int)calc/N_SAMPLES) + 1) * N_SAMPLES;
	if (frame_samples - calc < extra_rate) {
		frame_samples += N_SAMPLES;
	}
	frame_samples_min = frame_samples-N_SAMPLES;
	return (frame_samples);
}
#endif   /* SUPPORT_NAUDIO */

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
  [EXTERNAL FUNCTION]
  __MusIntSamplesCurrent()

  [Explanation]
  Calculate number of samples required per frame.

  [Return value]
  Number of samples currently required
*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef SUPPORT_NAUDIO
u32 __MusIntSamplesCurrent(u32 samples)
{
	samples = (frame_samples+extra_samples+16-samples)&(~15);
	if (samples<frame_samples_min)
		return (frame_samples_min);
	return (samples);
}
#else    /* SUPPORT_NAUDIO */
u32 __MusIntSamplesCurrent()
{
    static u32 only_one_flag=0;
    int samples = osAiGetLength() / 4;

    if (samples > N_SAMPLES)
    {
	if (only_one_flag)
	{
	    only_one_flag = 0;
	    return (frame_samples_min);
	}
	else
	{
	    only_one_flag = 1;
	}
    }
    else
    {
	only_one_flag = 1;
    }
    return (frame_samples);
}
#endif   /* SUPPORT_NAUDIO */



/* end of file */
