
/*********************************************************

  aud_samples.h : Nintendo 64 Music Tools Programmers Library
  (c) Copyright 1997/1998, Software Creations (Holdings) Ltd.
  
  Version 3.14

  Music library frame sample calculations.

**********************************************************/

#ifndef _LIBMUS_AUD_SAMPLES_H_
#define _LIBMUS_AUD_SAMPLES_H_


u32 __MusIntSamplesInit		(float retrace_count, float output_rate, float vsyncs_per_sec, int extra_rate);
u32 __MusIntSamplesCurrent	();


#endif /* _LIBMUS_AUD_SAMPLES_H_ */

/* end of file */
