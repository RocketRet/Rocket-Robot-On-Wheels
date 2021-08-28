#include <include_asm.h>
#include <ultra64.h>
#include <mem.h>

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_377", func_80088150);

void pop_second_heap_state();
void push_second_heap_state();
extern struct unkfunc_8001E044_inner *D_800AC7F0[];
extern s32 D_800ADAE4;
extern s32 D_800B0008;

struct DataAndHeader {
    u8 *dataPtr;
    u32 pad;
    u32 header[2];
};

// Minor regalloc
#ifdef NON_MATCHING
void func_800882B8(struct unkfunc_800882B8 *arg0, u32 romAddr, s32 arg2) {
    struct DataAndHeader sp10;
    s32 s5;
    s32 s7;
    u32 dataLen;
    s32 phi_v1;
    s32 phi_s3;

    s7 = D_800ADAE4;
    D_800ADAE4 = 0;
    push_second_heap_state();
    romAddr = ALIGN(romAddr, 4);
    dma_read(romAddr, sp10.header, 8);
    romAddr += 8;
    dataLen = sp10.header[1] - 8;
    sp10.dataPtr = alloc_second_heap(dataLen);
    dma_read(romAddr, sp10.dataPtr, dataLen);
    romAddr += dataLen;
    s5 = READ_VALUE(sp10.dataPtr, s32);
    if (arg2 != 0) {
        s32 phi_a0_2;
        u8 *a;
        // Need to use a instead of directly using dataPtr for some reason to match
        a = sp10.dataPtr;
        sp10.dataPtr += sizeof(s32);
        phi_a0_2 = READ_VALUE(a, s32);
        sp10.dataPtr += sizeof(s32);
        arg0->unk134 = phi_a0_2;
        arg0->unk138 = READ_VALUE(a, s32);
        if (arg0->unk138 > 0) {
            s32 *phi_a0;
            phi_a0 = main_alloc_nozero(arg0->unk138 * 4);
            phi_v1 = arg0->unk138 - 1;
            arg0->unk13C = phi_a0;
            while (phi_v1 >= 0) {
                *phi_a0 = READ_VALUE(sp10.dataPtr, s32);
                phi_a0++;
                phi_v1--;
            }
        }
    } else {
        s32 toSkip;
        sp10.dataPtr += sizeof(s32);
        sp10.dataPtr += READ_VALUE(sp10.dataPtr, s32)* sizeof(s32);
    }

    pop_second_heap_state();
    phi_s3 = 0;
    while (1) {
        struct DataAndHeader sp20;
        struct Model *curModel;
        struct unkfunc_8001E044_inner *temp_s1;
        u8 **dataPtr = &sp20.dataPtr;
        u32 dataLen2;
        s32 temp_s2;
        if (phi_s3 >= s5) {
            break;
        }
        push_second_heap_state();
        romAddr = ALIGN(romAddr, 4);
        dma_read(romAddr, sp20.header, 8);
        romAddr += 8;
        dataLen2 = sp20.header[1] - 8;
        *dataPtr = alloc_second_heap(dataLen2);
        dma_read(romAddr, *dataPtr, dataLen2);
        romAddr += dataLen2;
        temp_s1 = D_800AC7F0[READ_VALUE(*dataPtr, s32)];
        temp_s2 = READ_VALUE(*dataPtr, s32);
        curModel = main_alloc_bzero(temp_s1->unkC);
        curModel->unk0 = temp_s1;
        curModel->unk0->unk10(curModel, arg0, 0);
        curModel->unk8 = arg0->unk38++;
        curModel->unk4 = temp_s2;
        curModel->unk0->unk20(curModel, &romAddr, *dataPtr); // func_8001E044 potentially
        phi_s3++;
    }
    D_800ADAE4 = s7;
}
#else
INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_377", func_800882B8);
#endif

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_377", func_80088524);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_377", func_80088934);
