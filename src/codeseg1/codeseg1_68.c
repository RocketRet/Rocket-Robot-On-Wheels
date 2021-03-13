#include <include_asm.h>
#include <ultra64.h>


INCLUDE_ASM(void, "codeseg1/codeseg1_68", guTranslateF, float mf[4][4], float x, float y, float z);

INCLUDE_ASM(void, "codeseg1/codeseg1_68", guTranslate, Mtx *m, float x, float y, float z);
