#include <include_asm.h>
#include <ultra64.h>
#include <mem.h>

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
    Mtx3f unk18;
    Vec3f unk3C;
    u8 padding3[0xF4 - 0x3C - 0x0C];
    void *unkF4;
    s32 unkF8;
};

struct unkfunc_8001E044_inner {
    u8 padding[0x40];
    void (*unk40)(struct unkfunc_8001E044*);
    u8 padding2[0x68 - 0x40 - 0x04];
    void (*unk68)(struct unkfunc_8001E044*, s32, void*, s32);
};

void func_80085D04(u8 **dataPtrPtr, Vec3f arg1, Mtx3f arg2);

// TODO function call load order
// void func_8001E044(struct unkfunc_8001E044 *arg0, s32 arg1, u8 *dataPtr, s32 arg3)
// {
//     s32 decompressedSize;
//     void *decompressedBytes;
//     s32 compressedSize;
//     s32 s3;
//     void *s5;

//     func_80085D04(&dataPtr, &arg0->unk3C, &arg0->unk18);
//     func_80085C68(&dataPtr, arg0);
//     push_second_heap_state();
//     s5 = alloc_second_heap(0x5000);

//     arg0->unkF4 = s5;

//     dataPtr = (u8*)ALIGN(dataPtr, 4);
//     s3 = read_u32(&dataPtr);
//     decompressedSize = read_u32(&dataPtr);
//     compressedSize = read_u32(&dataPtr);

//     decompressedBytes = alloc_second_heap(decompressedSize);

//     decompress(&compressionParamsTable[0], compressedSize, dataPtr, decompressedSize, decompressedBytes);

//     arg0->unk0->unk68(arg0, decompressedSize, decompressedBytes, s3); // always func_800864A8 from testing, which calls push_second_heap_state

//     dataPtr += compressedSize;

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
