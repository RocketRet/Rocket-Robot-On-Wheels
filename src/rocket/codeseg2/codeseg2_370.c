#include <include_asm.h>
#include <ultra64.h>
#include <types.h>
#include <mem.h>

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_370", func_80085530);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_370", func_80085584);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_370", func_8008561C);

extern u8 _dataEndRom[];

extern u32 D_800ADAC8;
extern u32 D_800ADACC;
extern u32 D_800ADAD0;
extern u32 D_800ADAD4;
extern u32 D_800ADAD8;
extern u32 D_800ADADC;

struct unkfunc_800856AC {
    u32 unk0;
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u16 unkA;
    u32 unkC;
};

// void func_800856AC()
// {
//     struct {
//         u32 unk0;
//         u32 unk4;
//     } buffer;
//     u32 addr0 = _dataEndRom;
//     u32 addr;
//     struct unkfunc_800856AC *stuff;
//     push_second_heap_state();
//     addr = ALIGN((u32)_dataEndRom + 4, 4);
//     dma_read(addr, &buffer, 8);
//     buffer.unk4 -= 8;
//     addr += 8;
//     stuff = alloc_second_heap(buffer.unk4);
//     dma_read(addr, stuff, buffer.unk4);
//     if (stuff->unk0 != 0x121)
//     {
//         D_800ADACC = 0;
//         textureTableLength = 0;
//         D_800ADAD4 = 0;
//         D_800ADAD0 = NULL;
//         D_800ADAC8 = NULL;
//         textureTableAddress = 0;
//     }
//     else
//     {
//         u32 x;
//         void *temp_a0_2;
//         D_800ADAD4 = stuff->unk4;
//         D_800ADADC = stuff->unk6;
//         D_800ADACC = stuff->unk8;
//         x = addr - 4;
//         textureTableAddress = x + stuff->unkC;
//         textureTableLength = stuff->unkA;

//         temp_a0_2 = func_800613F8(D_800ADAD4 * 0x10);
//         D_800ADAD0 = temp_a0_2;
//         bzero(temp_a0_2, D_800ADAD4 * 0x10);
        
//         temp_a0_2 = func_800613F8(D_800ADADC * 0x8);
//         D_800ADAD8 = temp_a0_2;
//         bzero(temp_a0_2, D_800ADAD8 * 0x8);
        
//         // wip
//         D_800ADAC8 = func_800613F8(D_800ADACC * 8);
//     }
//     pop_second_heap_state();
// }

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_370", func_800856AC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_370", func_80085978);

void func_80085C68(u8 **dataPtrPtr, struct Model *arg1)
{
    u8 *curPtr;

    *dataPtrPtr = ALIGN_PTR(*dataPtrPtr, 4);
    *dataPtrPtr += 4;
    curPtr = *dataPtrPtr + READ_VALUE(*dataPtrPtr, u32) - 8;
    while (curPtr != *dataPtrPtr) {
        u16 val;
        *dataPtrPtr = ALIGN_PTR(*dataPtrPtr, 2);
        val = READ_VALUE(*dataPtrPtr, u16);
        func_80085978(val, dataPtrPtr, arg1);
    }
}

void mtx3f_axis_angle(Vec3f, Mtx3f);

void func_80085D04(u8 **dataPtrPtr, Vec3f arg1, Mtx3f arg2)
{
    Vec3f vec;
    read_vec3f(dataPtrPtr, arg1);
    read_vec3f(dataPtrPtr, vec);
    mtx3f_axis_angle(vec, arg2);
}
