#ifndef __INCLUDE_ASM_H__
#define __INCLUDE_ASM_H__

#if !defined(SPLAT) && !defined(__CTX__) && !defined(KMC) && !defined(PERMUTER)
#ifndef INCLUDE_ASM
#define INCLUDE_ASM(TYPE, FOLDER, NAME, ARGS...) \
  TYPE NAME(ARGS);\
  __asm__( ".include \"asm/nonmatchings/"FOLDER"/"#NAME".s\"\nglabel "#NAME"_end\n.set reorder\n.set at");
#endif
__asm__( ".include \"include/macro.inc\"\n");
#else
#define INCLUDE_ASM(TYPE, FOLDER, NAME, ARGS...)
#endif

// TODO this with guards to prevent issues in context generation/etc
#define UNUSED

#endif