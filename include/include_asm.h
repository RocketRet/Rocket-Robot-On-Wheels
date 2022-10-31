#ifndef __INCLUDE_ASM_H__
#define __INCLUDE_ASM_H__

#define NONMATCHING_SUFFIX "_NONMATCHING"

#if !defined(SPLAT) && !defined(__CTX__) && !defined(KMC) && !defined(PERMUTER)
#ifndef INCLUDE_ASM
#define INCLUDE_ASM(TYPE, FOLDER, NAME, ARGS...) \
  TYPE NAME(ARGS);\
  \
  asm ( \
      "\t.text\n" \
      "\t.set noat\n" \
      "\t.set noreorder\n" \
      "\t.global " #NAME NONMATCHING_SUFFIX "\n" \
      "\t.equiv " #NAME NONMATCHING_SUFFIX ", 0\n" \
      "\t.ent " #NAME "\n" \
      "\t.type " #NAME ", @function\n" \
      "\t.include \"asm/nonmatchings/"FOLDER"/"#NAME".s\"\n" \
      "\t.end " #NAME "\n" \
      "\t.set reorder\n" \
      "\t.set at\n" \
  );
#endif
// __asm__( ".include \"include/macro.inc\"\n");
#else
#define INCLUDE_ASM(TYPE, FOLDER, NAME, ARGS...)
#endif

#endif