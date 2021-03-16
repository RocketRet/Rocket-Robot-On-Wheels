#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(void, "lib/codeseg1/codeseg1_147", guMtxCatF, float m[4][4], float n[4][4], float r[4][4]);

INCLUDE_ASM(void, "lib/codeseg1/codeseg1_147", guMtxXFMF, float mf[4][4], float x, float y, float z, float *ox, float *oy, float *oz);
