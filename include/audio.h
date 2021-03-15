#ifndef __AUDIO_H__
#define __AUDIO_H__

#include <PR/ultratypes.h>

#define AUDIO_HEAP_SIZE 0x39800
#define AUDIO_SAMPLE_RATE 22500

extern void *gAudioHeapPtr;

extern u8 gAudioFxBank[];
extern u8 gAudioPtrBank[];

#endif
