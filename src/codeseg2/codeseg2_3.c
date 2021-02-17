#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_8001DFD0 {
    u8 padding[0xE0];
    u16 unkE0;
    u16 unkE2;
    u32 unkE4;
    u32 unkE8;
    u32 unkEC;
    u32 unkF0;
    u32 unkF4;
    u32 unkF8;
    u32 unkFC;
    u32 unk100;
    f32 unk104;
    u32 unk108;
    u32 unk10C;
    u32 unk110;
};

extern f32 D_80019FB0;

void func_8001DFD0(struct unkfunc_8001DFD0 *arg0)
{
    s32 v0;
    func_80050868();
    v0 = arg0->unk110 | 0xC00000;
    arg0->unk110 = v0 | 0x300000;
    *(s8 *)&arg0->unk110 = 0xff; // what?
    arg0->unkE0 = 0x10;
    arg0->unk104 = D_80019FB0;
    arg0->unk108 = 0x7fffffff;
    arg0->unk110 = arg0->unk110 | 0x4000;
    return;
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_3", func_8001E044);

INCLUDE_ASM(s32, "codeseg2/codeseg2_3", func_8001E198);

INCLUDE_ASM(s32, "codeseg2/codeseg2_3", func_8001E248);
