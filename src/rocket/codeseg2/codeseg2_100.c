#include <include_asm.h>
#include <ultra64.h>
#include <types.h>

extern struct GfxContext D_800A5DA8;

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_100", func_80039F80);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_100", func_8003A468);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_100", func_8003AA04);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_100", func_8003ACD4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_100", func_8003ADFC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_100", func_8003AF94);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_100", func_8003B068);

struct unkD_8009F094 {
    u8 padding[0xC4];
    Lights1 *light;
};

extern struct unkD_8009F094 D_8009F094;

// void func_8003B144(s32 arg0)
// {
//     gSPSetLights1(D_800A5DA8.dlHead++, (*D_8009F094.light));
// }

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_100", func_8003B144);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_100", func_8003B298);

void func_8003B358(s32 arg0)
{
    func_8003ACD4();
    func_8003B144(arg0);
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_100", func_8003B388);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_100", func_8003B544);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_100", func_8003B674);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_100", func_8003B6BC);
