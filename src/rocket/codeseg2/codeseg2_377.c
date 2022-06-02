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
    struct {
        u32 signature;
        u32 dataLength;
    } header __attribute__((aligned(8)));
};

void func_800882B8(struct unkfunc_800882B8 *arg0, u32 romAddr, s32 arg2) {
    struct DataAndHeader fileInfo;
    u32 dataLen;
    s32 phi_s3;
    s32 s5;
    s32 s7;
    s32 a;

    s7 = D_800ADAE4;
    D_800ADAE4 = 0;
    push_second_heap_state();
    romAddr = ALIGN(romAddr, 4);
    dma_read(romAddr, &fileInfo.header, 8);
    romAddr += 8;
    dataLen = fileInfo.header.dataLength - 8;
    fileInfo.dataPtr = alloc_second_heap(dataLen);
    dma_read(romAddr, fileInfo.dataPtr, dataLen);
    romAddr += dataLen;
    s5 = READ_VALUE(&fileInfo.dataPtr, s32);
    if (arg2 != 0) {
        arg0->unk134 = a = READ_VALUE(&fileInfo.dataPtr, s32);
        arg0->unk138 = READ_VALUE(&fileInfo.dataPtr, s32);
        if (arg0->unk138 > 0) {
            s32 i;
            s32 *phi_a0 = arg0->unk13C = main_alloc_nozero(arg0->unk138 * sizeof(s32));
            
            for (i = arg0->unk138 - 1; i >= 0; i--) {
                *phi_a0++ = READ_VALUE(&fileInfo.dataPtr, s32);
            }
        }
    } else {
        READ_VALUE(&fileInfo.dataPtr, s32);
        a = READ_VALUE(&fileInfo.dataPtr, s32);
        fileInfo.dataPtr += a * sizeof(s32);
    }

    pop_second_heap_state();
    phi_s3 = 0;
    while (1) {
        struct DataAndHeader fileInfo2;
        struct GameObject *curModel;
        struct unkfunc_8001E044_inner *temp_s1;
        u32 dataLen2;
        s32 temp_s2;
        if (phi_s3 >= s5) {
            break;
        }
        push_second_heap_state();
        romAddr = ALIGN(romAddr, 4);
        dma_read(romAddr, &fileInfo2.header, 8);
        romAddr += 8;
        dataLen2 = fileInfo2.header.dataLength - 8;
        fileInfo2.dataPtr = alloc_second_heap(dataLen2);
        dma_read(romAddr, fileInfo2.dataPtr, dataLen2);
        romAddr += dataLen2;
        temp_s1 = D_800AC7F0[READ_VALUE(&fileInfo2.dataPtr, s32)];
        temp_s2 = READ_VALUE(&fileInfo2.dataPtr, s32);
        curModel = main_alloc_bzero(temp_s1->unkC);
        curModel->unk0 = temp_s1;
        curModel->unk0->unk10(curModel, arg0, 0);
        curModel->unk8 = arg0->unk38++;
        curModel->unk4 = temp_s2;
        curModel->unk0->unk20(curModel, &romAddr, *&fileInfo2.dataPtr); // func_8001E044 potentially
        phi_s3++;
    }
    D_800ADAE4 = s7;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_377", func_80088524);

extern s32 D_800AF310;

void func_800914A8(float);
void func_80095440(s32, s32, s32, s32);

void func_80088934(s32 arg0)
{
    D_800AF310 = 0;
    func_800914A8(0.0f);
    func_80095440(0, arg0, -1, -1);
}
