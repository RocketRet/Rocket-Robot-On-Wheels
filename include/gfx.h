#ifndef __GFX_H__
#define __GFX_H__

#include "types.h"
#include "materials.h"

#define NEXT_GFX(gfx) (++gfx - 1)

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define FRAMEBUFFER_BYTES ((SCREEN_WIDTH) * (SCREEN_HEIGHT) * sizeof(u16))

struct unkD_8009F094_inner {
    u8 pad[0xC4];
    Lights1 *light;
    u8 pad2[0x128 - 0xC8];
    s32 unk128[1];
};

struct unkD_8009F094 {
    struct unkD_8009F094_inner *unk0;
};

extern struct unkD_8009F094 D_8009F094;

extern RGBA32 D_800A5398;
extern RGBA32 D_800A539C;

#endif
