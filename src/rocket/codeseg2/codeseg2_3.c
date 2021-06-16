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
    func_80050868();
    arg0->unk110 |= 0xC00000;
    arg0->unk110 |= 0x300000;
    *(s8 *)&arg0->unk110 = 0xff; // what?
    arg0->unkE0 = 0x10;
    arg0->unk104 = D_80019FB0;
    arg0->unk108 = 0x7fffffff;
    arg0->unk110 |= 0x4000;
}

struct unkfunc_8001E044 {
    struct unkfunc_8001E044_inner *unk0;
    u8 padding[0x18 - 0x04];
    s32 unk18;
    u8 padding2[0x3C - 0x18 - 0x04];
    s32 unk3C;
    u8 padding3[0xF4 - 0x3C - 0x04];
    void *unkF4;
    s32 unkF8;
};

struct unkfunc_8001E044_inner {
    u8 padding[0x40];
    void (*unk40)(struct unkfunc_8001E044*);
    u8 padding2[0x68 - 0x40 - 0x04];
    void (*unk68)(struct unkfunc_8001E044*, s32, void*, s32);
};

void *main_alloc_copy(s32 size, u8 *src);

extern s32 compressionParamsTable;

void *alloc_second_heap(s32);
void decompress(s32 *, s32, s32 *, s32, void*);

// TODO function call load order
// void func_8001E044(struct unkfunc_8001E044 *arg0, s32 arg1, s32 *arg2, s32 arg3)
// {
//     s32 s0;
//     void *s1;
//     s32 s2;
//     s32 s3;
//     void *s5;

//     func_80085D04(&arg2, &arg0->unk3C, &arg0->unk18);
//     func_80085C68(&arg2, arg0);
//     push_second_heap_state();
//     s5 = alloc_second_heap(0x5000);

//     arg0->unkF4 = s5;

//     arg2 = (s32*)ALIGN(arg2, 4);
//     arg2 += 1;
//     s3 = *(arg2 - 1);
//     arg2 += 1;
//     s0 = *(arg2 - 1);
//     arg2 += 1;
//     s2 = *(arg2 - 1);

//     s1 = alloc_second_heap(s0);

//     decompress(&compressionParamsTable, s2, arg2, s0, s1);

//     arg0->unk0->unk68(arg0, s0, s1, s3);

//     arg2 = (s32*)((u8*)arg2 + s2);

//     if (arg0->unkF8 > 0)
//     {
//         arg0->unkF4 = main_alloc_copy(arg0->unkF8 * 40, s5);
//     }

//     pop_second_heap_state();
//     pop_second_heap_state();

//     if (arg0->unk0->unk40)
//     {
//         arg0->unk0->unk40(arg0);
//     }
// }

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001E044);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001E198);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001E248);
