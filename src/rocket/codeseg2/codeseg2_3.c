#include <include_asm.h>
#include <ultra64.h>
#include <mem.h>
#include <types.h>

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

void func_80085D04(u8 **dataPtrPtr, Vec3f arg1, Mtx3f arg2);

void func_8001E044(struct Model *arg0, s32 arg1, u8 *dataPtr)
{
    s32 decompressedSize;
    void *decompressedBytes;
    s32 compressedSize;
    s32 vertexStorageFlags;
    struct Submodel *submodelBuffer;
    u8 **dataPtrPtr = &dataPtr; // Needed for matching, can't just reference directly
    // The use of a pointer to dataPtr to match seems to be a recurring theme

    func_80085D04(dataPtrPtr, &arg0->unk3C, &arg0->unk18);
    func_80085C68(dataPtrPtr, arg0);
    push_second_heap_state();
    submodelBuffer = alloc_second_heap(512 * sizeof(struct Submodel));

    arg0->submodels = submodelBuffer;

    *dataPtrPtr = ALIGN_PTR(*dataPtrPtr, 4);
    vertexStorageFlags = READ_VALUE(*dataPtrPtr, u32);
    decompressedSize = READ_VALUE(*dataPtrPtr, u32);
    compressedSize = READ_VALUE(*dataPtrPtr, u32);

    decompressedBytes = alloc_second_heap(decompressedSize);

    decompress(&compressionParamsTable[0], compressedSize, *dataPtrPtr, decompressedSize, decompressedBytes);

    arg0->unk0->unk68(arg0, decompressedSize, decompressedBytes, vertexStorageFlags); // always func_800864A8 from testing

    *dataPtrPtr += compressedSize;

    if (arg0->numSubmodels > 0)
    {
        arg0->submodels = main_alloc_copy(arg0->numSubmodels * sizeof(struct Submodel), submodelBuffer);
    }

    pop_second_heap_state();
    pop_second_heap_state();

    if (arg0->unk0->unk40)
    {
        arg0->unk0->unk40(arg0);
    }
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001E198);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_3", func_8001E248);
