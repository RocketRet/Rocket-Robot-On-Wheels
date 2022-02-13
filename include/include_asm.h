#ifndef __INCLUDE_ASM_H__
#define __INCLUDE_ASM_H__

#define NONMATCHING_SUFFIX "_NONMATCHING"

#if !defined(SPLAT) && !defined(__CTX__) && !defined(KMC) && !defined(PERMUTER)
#ifndef INCLUDE_ASM
#define INCLUDE_ASM(TYPE, FOLDER, NAME, ARGS...) \
  TYPE NAME(ARGS);\
  \
  asm ( \
      "\t.text\r\n" \
      "\t.set noat\r\n" \
      "\t.set noreorder\r\n" \
      "\t.global " #NAME NONMATCHING_SUFFIX "\r\n" \
      "\t.ent " #NAME NONMATCHING_SUFFIX "\r\n" \
      "\t" #NAME NONMATCHING_SUFFIX ":\r\n" \
      "\t.end " #NAME NONMATCHING_SUFFIX "\r\n" \
      "\t.include \"asm/nonmatchings/"FOLDER"/"#NAME".s\"\r\n" \
      "\t.set reorder\r\n" \
      "\t.set at\r\n" \
  );
#endif
// __asm__( ".include \"include/macro.inc\"\n");
#else
#define INCLUDE_ASM(TYPE, FOLDER, NAME, ARGS...)
#endif

// TODO this with guards to prevent issues in context generation/etc
#define UNUSED

#endif