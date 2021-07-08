#include <include_asm.h>
#include <ultra64.h>


struct unkfunc_800824A0 {
    u8 padding[0x10];
    s32 unk10;
    u8 padding2[0x268 - 0x04 - 0x10];
    s32 unk268;
};

void func_80065170(struct unkfunc_800824A0 *arg0)
{
    arg0->unk268 = arg0->unk10;
    func_800824A0();
}

struct unkfunc_80065194 {
    u8 unk0[0x244];
    f32 unk244;
    u32 unk248;
    struct unkfunc_80065194 *unk24C[6];
    u32 unk264;
    struct unkfunc_80065194 *unk268;
};

extern const f32 D_8001C574;

// float load
#ifdef NON_MATCHING
void func_80065194(struct unkfunc_80065194 *arg0)
{
    s32 var;
    func_80083734();
    // index[array] again
    arg0->unk264[arg0->unk268->unk24C] = arg0;
    var = 6;
    if (arg0->unk264 & 1)
    {
        var = 5;
    }
    func_800652F4(arg0, var);
    arg0->unk244 = D_8001C574;
}
#else
INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_237", func_80065194);
#endif

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_237", func_800651F8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_237", func_800652F4);

struct unkfunc_800654D4 {
    u8 padding[0x10];
    s32 unk10;
    u8 padding2[0x238 - 0x04 - 0x10];
    s32 unk238;
};

void func_800654D4(struct unkfunc_800654D4 *arg0)
{
    arg0->unk238 = arg0->unk10;
    func_800824A0();
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_237", func_800654F8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_237", func_80065544);
