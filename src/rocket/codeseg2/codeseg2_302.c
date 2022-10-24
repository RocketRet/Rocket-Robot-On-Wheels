#include <include_asm.h>
#include <ultra64.h>
#include <types.h>


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_302", func_80075100);

extern struct GfxContext gGfxContext; // 0x10 bytes

#define MACRO_FUNC_800751D8(x) (((x) + 0xF < 0) ? (x) + 0x1E : (x) + 0xF)

int push_second_heap_state();
int func_80046268();
int func_80046354();
int func_8004632C();
int func_80046318();
int func_800463B4();
int func_800462E4();
int pop_second_heap_state();

void func_800751D8(s32 **arg0, s32 arg1)
{
    struct GfxContext *s1;
    Gfx **s2;
    s32 var4;
    push_second_heap_state();
    s1 = &gGfxContext;
    s2 = &gGfxContext.dlHead;
    func_80046268(s2);
    func_80046354(0xFF, 0x80, 0, 0xFF);
    func_8004632C(arg0[4], arg0[5]);
    var4 = MACRO_FUNC_800751D8(arg0[1][3]);
    func_80046318(arg0[1][2], var4 >> 4);
    func_800463B4(s1, arg1, 0, 0, 0);
    func_800462E4(s2);
    pop_second_heap_state();
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_302", func_8007529C);

struct unkfunc_80075348 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

void func_80075348(struct unkfunc_80075348 *arg0, s32 arg1)
{
    s32 s0 = arg1;
    struct unkfunc_80075348 *s1 = arg0;
    bzero(s1, s0 * sizeof(struct unkfunc_80075348));
    for (s0--; s0 >= 0; s1++, s0--)
    {
        s1->unk0 = -1;
        s1->unk4 = 0;
        s1->unk8 = 0;
        s1->unkC = 1;
    }
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_302", func_800753B4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_302", func_80075458);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_302", func_80075884);
