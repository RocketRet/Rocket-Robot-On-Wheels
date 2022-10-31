#include <include_asm.h>
#include <ultra64.h>
#include <mem.h>
#include <types.h>
#include <macros.h>

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_375", func_80086370);

u32 func_80086400(u8 **arg0)
{
    u32 val1 = *((*arg0)++);
    u32 val2 = *((*arg0)++);
    return val2 | (val1 << 8);
}

f32 func_80086428(u8 **arg0)
{
    u8 *curByte;
    f32 ret;
    s32 i;

    curByte = (u8 *)&ret;
    for (i = 3; i != -1; i--)
    {
        *(curByte++) = *((*arg0)++);
    }
    return ret;
}

s32 func_80086468(u8 **arg0)
{
    u8 *curByte;
    s32 ret;
    s32 i;

    curByte = (u8 *)&ret;
    for (i = 3; i != -1; i--)
    {
        *(curByte++) = *((*arg0)++);
    }
    return ret;
}


struct ModelData {
    u32 unk0;
    Gfx *unk4;
    Gfx *unk8;
    Gfx *unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18[2][3];
};

extern Vec3f D_800AF794;

static inline s16 read_unaligned_s16(u8 **dataPtr)
{
    s32 b1, b2;
    s16 x;
    b1 = *(*dataPtr)++;
    b2 = *(*dataPtr)++;
    x = b1 << 8 | b2;
    return x;
}

static inline f32 read_unaligned_f32(u8 **dataPtr)
{
    f32 ret;
    s32 i;
    u8 *curPtr = (u8*)&ret;
    u8 *curDataPtr = *dataPtr;
    for (i = 3; i != -1; i--)
    {
        *(curPtr)++ = *(curDataPtr)++;
        *dataPtr = curDataPtr;
    }
    return ret;
}

// static inline s32 read_unaligned_u8(u8 **dataPtr)
// {
//     s32 ret = **dataPtr;
//     *dataPtr++;// = *dataPtr + 1;
//     return ret;
// }



#define read_unaligned_u8(dataPtr) \
    ({s32 ret = **(&dataPtr); (*(&dataPtr))++; ret; })

#define read_u8_out(out, dataPtr) \
    {(out) = **(&dataPtr); (*(&dataPtr))++; }

#define read_f32_out(out, dataPtr) { \
    f32 ret; \
    s32 i; \
    u8 *curPtr = (u8*)&out; \
    for (i = 3; i != -1; i--) \
    { \
        *(curPtr)++ = *(*(&dataPtr))++; \
    } \
    out = ret; \
}

#define VEC2S_COPY(dst, src) __builtin_memcpy((dst), (src), sizeof(s16) * 2);
#define VEC3S_COPY(dst, src) __builtin_memcpy((dst), (src), sizeof(s16) * 3);

struct DataPtr {
    u8 *ptr;
};
void func_800864A8(struct GameObject *arg0, s32 decompressedSize, u8 *decompressedBytes, s32 arg3);

#ifdef NON_MATCHING
void func_800864A8(struct GameObject *arg0, s32 decompressedSize, u8 *decompressedBytes, s32 arg3) {
    Vtx *vertexBuffer;
    s32 vertexCount;
    u8 sp58[4];
    s32 iCmd1;
    struct unkfunc_80093DDC sp48;
    struct unkfunc_80093DDC sp40;
    struct unkfunc_80093DDC sp3C;
    struct unkfunc_80093DDC sp38;
    struct unkfunc_80093DDC sp30;
    struct unkfunc_80093DDC sp28;
    u8 *dataPtr;
    struct ModelData curModel;
    f32 temp_f20;
    s32 curByteCmd1;
    s32 v0Cmd8;
    s32 v1Cmd8;
    s32 numTriangles;
    u32 curCommand;
    u8 *gfxBuffer;
    struct Submodel *curSubmodelCmd7;
    struct Submodel *prevSubmodelCmd7;
    struct Submodel *curSubmodelCmd0;
    s32 vertexIndex;
    Vtx *curVertex;
    s8 phi_v1;
    s32 phi_a0_7;
    s32 num2Triangles;
    s32 numVertexPositions;
    s32 numVertexColors;
    u32 s1;
    s16 *textureCoordBuffer;
    s16 *positionIndexBuffer;
    s32 numTextureCoords;
    u8 (*vertexColors)[3];
    s16 *vertexPositions;
    s16 *textureCoords;

    vertexPositions = NULL;
    textureCoords = NULL;
    vertexColors = NULL;
    positionIndexBuffer = NULL;
    textureCoordBuffer = NULL;
    vertexBuffer = NULL;
    dataPtr = decompressedBytes;
    if (decompressedSize != 0) {
        push_second_heap_state();
        numVertexPositions = read_unaligned_s16(&dataPtr); // vertex position count
        arg0->unkE0 =  read_unaligned_s16(&dataPtr);
        read_f32_out(arg0->unk100, dataPtr);
        // arg0->unk100 = read_unaligned_f32(&dataPtr);
        // Read vertex positions
        if (numVertexPositions > 0) {
            u32 vertexPositionBytes;
            vertexPositionBytes = numVertexPositions * (3 * sizeof(s16));
            if ((arg3 & 1) == 0) {
                vertexPositions = alloc_second_heap(vertexPositionBytes);
            } else {
                alloc_vertex_data_storage(arg0); // alloc if needed
                arg0->vertexDataStorage->unkC = numVertexPositions;
                vertexPositions = main_alloc_nozero(vertexPositionBytes);
                arg0->vertexDataStorage->unk10 = vertexPositions;
            }
            custom_memmove(vertexPositions, dataPtr, vertexPositionBytes);
            dataPtr += vertexPositionBytes;
        }
        // Read texture coords
        numTextureCoords = read_unaligned_s16(&dataPtr);
        if (numTextureCoords > 0) {
            u32 textureCoordBytes;
            textureCoordBytes = numTextureCoords * (2 * sizeof(s16));
            if ((arg3 & 4) == 0) {
                textureCoords = alloc_second_heap(textureCoordBytes);
            } else {
                alloc_vertex_data_storage(arg0); // alloc if needed
                arg0->vertexDataStorage->unk18 = numTextureCoords;
                textureCoords = main_alloc_nozero(textureCoordBytes);
                arg0->vertexDataStorage->unk1C = textureCoords;
            }
            custom_memmove(textureCoords, dataPtr, textureCoordBytes);
            dataPtr += textureCoordBytes;
        }
        // Read vertex colors/normals
        numVertexColors = read_unaligned_s16(&dataPtr);
        if (numVertexColors > 0) {
            u32 vertexColorBytes;
            vertexColorBytes = numVertexColors * (3 * sizeof(s8));
            if ((arg3 & 0x02) == 0) {
                vertexColors = alloc_second_heap(vertexColorBytes);
            } else {
                alloc_vertex_data_storage(arg0); // alloc if needed
                arg0->vertexDataStorage->unk4 = numVertexColors;
                vertexColors = main_alloc_nozero(vertexColorBytes);
                arg0->vertexDataStorage->unk8 = vertexColors;
            }
            custom_memmove(vertexColors, dataPtr, vertexColorBytes);
            dataPtr += vertexColorBytes;
        }
        vertexCount = read_unaligned_s16(&dataPtr);
        vertexBuffer = main_alloc_nozero(vertexCount * sizeof(Vtx));
        if (arg3 & 0x01) {
            arg0->vertexDataStorage->unk14 = main_alloc_nozero(vertexCount * sizeof(s16));
            positionIndexBuffer = arg0->vertexDataStorage->unk14;
        }
        if (arg3 & 0x04) {
            if (numTextureCoords > 0) {
                arg0->vertexDataStorage->unk20 = main_alloc_nozero(vertexCount * sizeof(s16));
                textureCoordBuffer = arg0->vertexDataStorage->unk20;
            }
        }
        if (arg3 & 0x10) {
            alloc_vertex_data_storage(arg0); // alloc if needed
            arg0->vertexDataStorage->unk0 = main_alloc_nozero(vertexCount);
            bzero(arg0->vertexDataStorage->unk0, vertexCount);
        }
        vertexIndex = 0;
        // Construct vertices
        while (1) {
            s32 positionIndex;
            s16 *temp_v0_7;
            s32 vertexFlag;
            u16 *flagPtr;
            if (vertexIndex >= vertexCount) break;
            // Copy position
            positionIndex = read_unaligned_s16(&dataPtr);
            temp_v0_7 = &vertexPositions[positionIndex * 3];
            VEC3S_COPY(vertexBuffer[vertexIndex].v.ob, temp_v0_7);
            flagPtr = &vertexBuffer[vertexIndex].v.ob[0] + 3;
            if (positionIndexBuffer != NULL) {
                *positionIndexBuffer = positionIndex;
                positionIndexBuffer++;
            }
            // Copy texture coords
            vertexBuffer[vertexIndex].v.tc[1] = 0;
            vertexBuffer[vertexIndex].v.tc[0] = 0;
            if (numTextureCoords > 0) {
                s16 textureCoordIndex;
                textureCoordIndex = read_unaligned_s16(&dataPtr);
                if (textureCoordIndex != -1) {
                    VEC2S_COPY(vertexBuffer[vertexIndex].v.tc, &textureCoords[textureCoordIndex * 2]);
                }
                if (textureCoordBuffer != NULL) {
                    *textureCoordBuffer = textureCoordIndex;
                    textureCoordBuffer++;
                }
            }
            // Copy vertex colors/normals
            vertexFlag = read_unaligned_s16(&dataPtr);
            // vertexBuffer[vertexIndex].v.flag = vertexFlag;
            *flagPtr = vertexFlag;
            if (vertexFlag == -1) {
                u8 *ptr = dataPtr;
                vertexBuffer[vertexIndex].v.cn[0] = ptr[1]; //read_unaligned_u8(&dataPtr);
                dataPtr = ptr + 2;
                vertexBuffer[vertexIndex].v.cn[1] = ptr[2]; //read_unaligned_u8(&dataPtr);
                dataPtr = ptr + 3;
                vertexBuffer[vertexIndex].v.cn[2] = ptr[3]; //read_unaligned_u8(&dataPtr);
                dataPtr = ptr + 4;
                vertexBuffer[vertexIndex].v.cn[3] = 0xFF;
            } else { 
                // *flagPtr = vertexFlag;
                vertexBuffer[vertexIndex].v.cn[0] = vertexColors[vertexFlag][0];
                vertexBuffer[vertexIndex].v.cn[1] = vertexColors[vertexFlag][1];
                vertexBuffer[vertexIndex].v.cn[2] = vertexColors[vertexFlag][2];
                vertexBuffer[vertexIndex].v.cn[3] = *dataPtr++; //read_unaligned_u8(&dataPtr);
            }
            vertexIndex++;
        }
        curVertex = &vertexBuffer[0];
        // read two bytes dictating how many gfx commands to allocate
        curModel.unk0 = read_unaligned_s16(&dataPtr) * sizeof(Gfx);
        // allocate the gfx commands
        gfxBuffer = main_alloc_nozero(curModel.unk0);
        temp_f20 = D_8001D6C4;
        curModel.unk4 = (Gfx*)gfxBuffer;
        curModel.unk8 = (Gfx*)gfxBuffer;
        curModel.unkC = (Gfx*)((u8*)gfxBuffer + curModel.unk0);
        while (1) {
            struct ModelData *md = &curModel;
            read_u8_out(curCommand, dataPtr);
            // curCommand = **(&dataPtr);
            // (*(&dataPtr))++; // god
            if (curCommand == 0xD) break;
            switch (curCommand) {
                case 0:
                    if (arg0->numSubmodels > 0) {
                        gSPEndDisplayList(md->unk8++);
                    }
                    sp40.unk0_4 = 0;
                    sp40.unk0_0 = 0;
                    sp40.unk1 = 0;
                    sp40.unk2 = 0;
                    sp48 = sp40;
                    // if (sp48.unk2 == 5) {
                    //     phi_v1 = 7;
                    // } else if (sp48.unk2 == 3) {
                    //     phi_v1 = 5;
                    // } else if (sp48.unk2 == 4) {
                    //     phi_v1 = 6;
                    // } else if (sp48.unk0_4 == 2) {
                    //     phi_v1 = 4;
                    // } else if (sp48.unk2 == 2) {
                    //     phi_v1 = 3;
                    // } else if (sp48.unk1 == 2) {
                    //     phi_v1 = 2;
                    // } else {
                    //     phi_v1 = sp48.unk2 == 1;
                    // }
                    //         if (sp28.unk2 == 5) {
                    if (sp48.unk2 == 5) {
                        phi_v1 = 7;
                    } else if (sp48.unk2 == 3) {
                        phi_v1 = 5;
                    } else if (sp48.unk2 == 4) {
                        phi_v1 = 6;
                    } else if (sp48.unk0_4 == 2) {
                        phi_v1 = 4;
                    } else if (sp48.unk2 == 1) {
                        phi_v1 = 3;
                    } else if (sp48.unk1 == 2) {
                        phi_v1 = 2;
                    } else {
                        phi_v1 = sp48.unk1 == 1;
                    }
                    sp40.unk3 = phi_v1;
                    sp38 = sp40;
                    curSubmodelCmd0 = &arg0->submodels[arg0->numSubmodels]; // size 0x28 bytes
                    curSubmodelCmd0->unk0 = md->unk8;
                    curSubmodelCmd0->unk4 = sp38;
                    curSubmodelCmd0->unk10 = arg0->unk100;
                    VEC3F_COPY(curSubmodelCmd0->unk14, D_800AF794);
                    // curSubmodelCmd0->unk14[0] = D_800AF794[0];
                    // curSubmodelCmd0->unk14[1] = D_800AF794[1];
                    // curSubmodelCmd0->unk14[2] = D_800AF794[2];
                    *(u32*)(&curSubmodelCmd0->unk24) = 0x40000000;
                    curSubmodelCmd0->unk8 = temp_f20;
                    curSubmodelCmd0->unkC = temp_f20;
                    curSubmodelCmd0->unk20 = 0;
                    curSubmodelCmd0->unk21 = 0;
                    curSubmodelCmd0->unk22 = arg0->unk110.val;
                    curSubmodelCmd0->unk10 = read_unaligned_f32(&dataPtr);
                    curSubmodelCmd0->unk14[0] = read_unaligned_f32(&dataPtr);
                    curSubmodelCmd0->unk14[1] = read_unaligned_f32(&dataPtr);
                    curSubmodelCmd0->unk14[2] = read_unaligned_f32(&dataPtr);
                    curSubmodelCmd0->unk24 = read_unaligned_f32(&dataPtr);
                    break;
                case 1:
                    iCmd1 = 0;
                    do {
                        curByteCmd1 = *dataPtr++;
                        sp58[iCmd1++] = curByteCmd1;
                    } while (curByteCmd1 != 0);
                    break;
                case 2:
                    arg0->submodels[arg0->numSubmodels - 1].unk8 = read_unaligned_f32(&dataPtr);
                    break;
                case 3:
                    arg0->submodels[arg0->numSubmodels - 1].unkC = read_unaligned_f32(&dataPtr);
                    break;
                case 4:
                    arg0->submodels[arg0->numSubmodels - 1].unk20 = *dataPtr++;
                    break;
                case 12:
                    arg0->submodels[arg0->numSubmodels - 1].unk22 = *dataPtr++;
                    arg0->unk110.val |= 0x1000;
                    break;
                case 8:
                    v0Cmd8 = *dataPtr++;
                    v1Cmd8 = *dataPtr++;
                    gSPVertex(curModel.unk8++, curVertex, v0Cmd8, v1Cmd8);
                    curVertex += v0Cmd8;
                    break;
                case 7:
                    sp28 = arg0->submodels[arg0->numSubmodels - 1].unk4; // 4 byte struct copy
                    s1 = read_unaligned_s16(&dataPtr);
                    func_80093DDC(&sp38, s1);
                    sp30 = sp38; // 4 byte struct copy
                    if (sp28.unk0_0 != 0 && sp28.unk0_4 != 0 && sp28.unk1 != 0 && sp28.unk2 != 0) {
                        sp38 = sp28; // 4 byte struct copy
                        sp3C = sp30; // 4 byte struct copy
                        phi_a0_7 = 0;
                        if (sp38.unk0_0 == sp3C.unk0_0) {
                            phi_a0_7 = sp38.unk3 == sp3C.unk3;
                        }
                        if (phi_a0_7 == 0) {
                            if (arg0->numSubmodels > 0) {
                                gSPEndDisplayList(curModel.unk8++);
                            }
                            sp40 = sp30; // 4 byte struct copy
                            curSubmodelCmd7 = &arg0->submodels[arg0->numSubmodels++]; // size 0x28 bytes
                            curSubmodelCmd7->unk0 = curModel.unk8;
                            curSubmodelCmd7->unk4 = sp40; // 4 byte struct copy
                            curSubmodelCmd7->unk10 = arg0->unk100;
                            VEC3F_COPY(curSubmodelCmd7->unk14, D_800AF794);
                            *(u32*)(&curSubmodelCmd7->unk24) = 0x40000000; // gross
                            curSubmodelCmd7->unk8 = temp_f20;
                            curSubmodelCmd7->unkC = temp_f20;
                            curSubmodelCmd7->unk20 = 0;
                            curSubmodelCmd7->unk21 = 0;
                            curSubmodelCmd7->unk22 = arg0->unk110.val;
                            prevSubmodelCmd7 = curSubmodelCmd7 - 1; // size 0x28 bytes
                            curSubmodelCmd7->unk10 = prevSubmodelCmd7->unk10;
                            VEC3F_COPY(curSubmodelCmd7->unk14, prevSubmodelCmd7->unk14);
                            *(u32*)(&curSubmodelCmd7->unk24) = *(u32*)(&prevSubmodelCmd7->unk24);
                        } else {
                            arg0->submodels[arg0->numSubmodels - 1].unk4 = sp30; // 4 byte struct copy
                        }
                    } else {
                        arg0->submodels[arg0->numSubmodels - 1].unk4 = sp30; // 4 byte struct copy
                    }
                    arg0->unk0->unk6C(arg0, s1, curModel.unk8++);
                    break;
                case 9:
                    numTriangles = *dataPtr++;
                    if (numTriangles & 1) {
                        s32 i;
                        s32 triangleIndices;
                        numTriangles--;
                        triangleIndices = read_unaligned_s16(&dataPtr);
                        for (i = 0; i < 3; i++, triangleIndices >>= 5) {
                            curModel.unk18[0][i] = triangleIndices & 0x1F;
                        }
                        gSP1Triangle(curModel.unk8++, curModel.unk18[0][0], curModel.unk18[0][1], curModel.unk18[0][2], 0);
                    }
                    num2Triangles = numTriangles / 2;
                    while (1) {
                        s32 i, j;
                        i = 0;
                        if (num2Triangles <= 0) break;
                        for (i = 0; i < 2; i++) {
                            s32 triangleIndices = read_unaligned_s16(&dataPtr);
                            for (j = 0; j < 3; j++, triangleIndices >>= 5) {
                                curModel.unk18[i][j] = triangleIndices & 0x1F;
                            }
                        }
                        gSP2Triangles(curModel.unk8++, curModel.unk18[0][0], curModel.unk18[0][1], curModel.unk18[0][2], 0, curModel.unk18[1][0], curModel.unk18[1][1], curModel.unk18[1][2], 0);
                        num2Triangles--;
                    }
                    break;
                case 5: // Set lighting
                    gSPSetGeometryMode(curModel.unk8++, G_LIGHTING);
                    break;
                case 6: // Clear lighting
                    gSPClearGeometryMode(curModel.unk8++, G_LIGHTING);
                    break;
                case 11:
                    arg0->submodels[arg0->numSubmodels - 1].unk21 = 1;
                    break;
                case 10:
                    dataPtr += 2;
                    break;
            }
        }
        after:
        gSPEndDisplayList(curModel.unk8++);
        pop_second_heap_state();
        arg0->unkE8 = vertexBuffer;
        arg0->unkE4 = vertexCount;
        arg0->unkF0 = curModel.unk4;
    }
}
#else
INCLUDE_ASM(void, "rocket/codeseg2/codeseg2_375", func_800864A8, struct GameObject *arg0, s32 decompressedSize, u8 *decompressedBytes, s32 arg3);
#endif

extern struct unkfunc_8001E044_inner *D_800AC7F0[];

struct GameObject *func_800872F8(s32 arg0, void *arg1, s32 arg2)
{
    struct GameObject *ret;
    struct unkfunc_8001E044_inner *var;

    var = D_800AC7F0[arg0];
    ret = main_alloc_bzero(var->unkC);
    ret->unk0 = var;
    var->unk10(ret, arg1, arg2);
    return ret;
}

// TODO arg0 typing
struct GameObject *func_80087374(s32 **arg0, void *arg1, s32 arg2)
{
    struct GameObject *ret;
    struct unkfunc_8001E044_inner *var;

    var = D_800AC7F0[(*arg0)[1]];
    ret = main_alloc_bzero(var->unkC);
    ret->unk0 = var;
    var->unk10(ret, arg1, arg2);
    ret->unk0->unk4C(ret, arg0);
    return ret;
}

struct DataAndHeader {
    u8 *dataPtr;
    struct {
        u32 signature;
        u32 dataLength;
    } header __attribute__((aligned(8)));
};

struct GameObject *func_80087418(u32 *romPtr, struct unkfunc_800882B8 *arg1, s32 arg2) {
    struct DataAndHeader sp10;
    s32 temp_s4;
    s32 dataLen;
    struct unkfunc_8001E044_inner *handler;
    struct GameObject *model;
    u8 **dataPtrPtr = &sp10.dataPtr;

    push_second_heap_state();
    *romPtr = ALIGN(*romPtr, 4);
    dma_read(*romPtr, &sp10.header, 8);
    *romPtr += 8;
    dataLen = sp10.header.dataLength - 8;
    sp10.dataPtr = alloc_second_heap(dataLen);
    dma_read(*romPtr, sp10.dataPtr, dataLen);
    *romPtr += dataLen;
    handler = D_800AC7F0[READ_VALUE(dataPtrPtr, s32)];
    temp_s4 = READ_VALUE(dataPtrPtr, s32);
    model = main_alloc_bzero(handler->unkC);
    model->unk0 = handler;
    handler->unk10(model, arg1, arg2);
    model->unk8 = arg1->unk38++;
    model->unk4 = temp_s4;
    model->unk0->unk20(model, romPtr, *dataPtrPtr);
    return model;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_375", func_80087554);

#ifdef NON_MATCHING
void func_800875E8(struct GameObject *arg0, u32 romAddr, u8 *dataPtr) {
    // Do I think they used a union? No
    // Can I match it without one? Also no
    // union {
        Vec3f vec;
        struct DataAndHeader data;
    // } sp18;
    f32 temp_f0;
    s32 temp_s3;
    s32 temp_s5_2;
    s32 temp_fp;
    s32 temp_s3_3;
    s32 temp_v0_10;
    s32 temp_v1_4;
    u32 temp_s0_2;
    u32 temp_s2;
    u8 *temp_s0;
    u8 *temp_s1;
    s32 *temp_s0_3;
    s32 *temp_s3_2;
    struct Submodel *temp_s5;
    s32 phi_a3;
    s32 phi_a1_2;
    s32 phi_a2_3;
    s32 phi_s5;
    s32 val;
    u32 *romPtr;

    romPtr = &romAddr;
    temp_fp = READ_VALUE(&dataPtr, s32);
    read_vec3f(&dataPtr, arg0->unk3C);
    read_vec3f(&dataPtr, vec);
    mtx3f_axis_angle(vec, arg0->unk18);
    dataPtr = ALIGN_PTR(dataPtr, 4);
    dataPtr += 4; // skip record type
    temp_s0 = dataPtr + READ_VALUE(&dataPtr, u32) - 8; // read record length
    while (dataPtr != temp_s0) {
        s32 val;
        dataPtr = ALIGN_PTR(dataPtr, 2);
        val = READ_VALUE(&dataPtr, u16);
        func_80085978(val, &dataPtr, arg0);
    }
    push_second_heap_state();
    // submodelBuffer = alloc_second_heap(512 * sizeof(struct Submodel));
    temp_s5 = alloc_second_heap(512 * sizeof(struct Submodel));
    arg0->submodels = temp_s5;
    dataPtr = ALIGN_PTR(dataPtr, 4);
    val = READ_VALUE(&dataPtr, s16);
    arg0->unk110 = val;
    temp_s3 = READ_VALUE(&dataPtr, s16);
    temp_s0_2 = READ_VALUE(&dataPtr, s32);
    temp_s2 = READ_VALUE(&dataPtr, s32);
    temp_s1 = alloc_second_heap(temp_s0_2);
    decompress(compressionParamsTable, temp_s2, dataPtr, temp_s0_2, temp_s1);
    arg0->unk0->unk68(arg0, temp_s0_2, temp_s1, temp_s3);
    temp_v1_4 = arg0->numSubmodels;
    dataPtr += temp_s2;
    if (temp_v1_4 > 0) {
        arg0->submodels = main_alloc_copy(temp_v1_4 * sizeof(struct Submodel), (u8 *) temp_s5);
    } else {
        arg0->submodels = NULL;
    }
    pop_second_heap_state();
    dataPtr = ALIGN_PTR(dataPtr, 2);
    if (READ_VALUE(&dataPtr, s16) != 0) {
        struct unkVertexDataStorage28 *phi_a2;
        alloc_vertex_data_storage(arg0);
        arg0->vertexDataStorage->unk28 = main_alloc_nozero(arg0->numSubmodels * sizeof(struct unkVertexDataStorage28));
        phi_a2 = arg0->vertexDataStorage->unk28;
        for (phi_a3 = 0; phi_a3 < arg0->numSubmodels; phi_a3++) {
            phi_a2->unk0 = 0;
            phi_a2->unk4 = READ_VALUE(&dataPtr, s16);
            phi_a2->unk8 = READ_VALUE(&dataPtr, s16);
            phi_a2->unkC = READ_VALUE(&dataPtr, s16);
            phi_a2++;
        }
    }
    dataPtr = ALIGN_PTR(dataPtr, 4);
    if (((u32*)dataPtr)[0] == 0xF) {
        dataPtr += 8;
        dataPtr = ALIGN_PTR(dataPtr, 4);
        arg0->unk124 = READ_VALUE(&dataPtr, f32);
        arg0->unk128 = READ_VALUE(&dataPtr, f32);
        arg0->unk12C = READ_VALUE(&dataPtr, f32);
        arg0->unk120 = READ_VALUE(&dataPtr, f32);
    }
    dataPtr = ALIGN_PTR(dataPtr, 4);
    if (((u32*)dataPtr)[1] >= 9) {
        dataPtr += 0x8;
        temp_s0_3 = &arg0->unk140;
        temp_s3_2 = &arg0->unk158;
        arg0->unk112_7 = READ_VALUE(&dataPtr, s16);
        temp_s5_2 = READ_VALUE(&dataPtr, s16);
        dataPtr = ALIGN_PTR(dataPtr, 4);
        temp_v0_10 = READ_VALUE(&dataPtr, s32);
        arg0->unk140 = temp_v0_10;
        arg0->unk144 = main_alloc_nozero(temp_v0_10 * sizeof(Vec3f));
        dataPtr = ALIGN_PTR(dataPtr, 4);
        for (phi_a2_3 = 0; phi_a2_3 < *temp_s0_3; phi_a2_3++) {
            for (phi_a1_2 = 0; phi_a1_2 < 3; phi_a1_2++) {
                arg0->unk144[phi_a2_3][phi_a1_2] = READ_VALUE(&dataPtr, f32);
            }
        }
        func_80085E90(&dataPtr, temp_s0_3);
        if (arg0->unk112_7) {
            __builtin_memcpy(&temp_s3_2[0], &temp_s0_3[0], 4 * sizeof(s32));
            __builtin_memcpy(&temp_s3_2[4], &temp_s0_3[4], 2 * sizeof(s32));
        } else {
            func_80046AAC(temp_s3_2, temp_s0_3);
        }
        func_800861A8(&dataPtr, &arg0->unk158, &arg0->unk178, &arg0->unk17C, &arg0->unk180);
        if (temp_s5_2 != 0) {
            alloc_vertex_data_storage(arg0);
            arg0->vertexDataStorage->unk24 = main_alloc_copy(arg0->unk178 * 2, dataPtr);
            dataPtr += arg0->unk178 * 2;
        }
        dataPtr = ALIGN_PTR(dataPtr, 4);
        temp_f0 = READ_VALUE(&dataPtr, f32);
        arg0->unk170 = temp_f0;
        arg0->unk174 = temp_f0;
    }
    pop_second_heap_state();
    if (arg0->unk0->unk40 != 0) {
        arg0->unk0->unk40(arg0);
    }
    VEC3F_COPY(arg0->unk134, arg0->unk6C);
    if (arg0->unk10 == 0) {
        func_80026FB4(arg0->unkC, arg0);
    }
    phi_s5 = 0;
    while (1) {
        // struct DataAndHeader sp18_;
        struct GameObject *curModel;
        struct unkfunc_8001E044_inner *temp_s1_2;
        u32 dataLen2;
        struct unkfunc_800882B8 * temp_s2_2;
        u8 **test = &data.dataPtr;
        if (phi_s5 >= temp_fp) {
            break;
        }
        temp_s2_2 = arg0->unkC;
        push_second_heap_state();
        *romPtr = ALIGN(*romPtr, 4);
        dma_read(*romPtr, &data.header, 8);
        *romPtr += 8;
        dataLen2 = data.header.dataLength - 8;
        *test = alloc_second_heap(dataLen2);
        dma_read(*romPtr, *test, dataLen2);
        *romPtr += dataLen2;
        temp_s1_2 = D_800AC7F0[READ_VALUE(test, s32)];
        temp_s3_3 = READ_VALUE(test, s32);
        curModel = main_alloc_bzero(temp_s1_2->unkC);
        curModel->unk0 = temp_s1_2;
        curModel->unk0->unk10(curModel, temp_s2_2, arg0);
        curModel->unk8 = temp_s2_2->unk38++;
        curModel->unk4 = temp_s3_3;
        curModel->unk0->unk20(curModel, romPtr, *test); // func_8001E044 potentially
        phi_s5++;
    }
}
#else
INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_375", func_800875E8);
#endif

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_375", func_80087BF8);

void mtx3f_axis_angle(Vec3f, Mtx3f);
void read_vec3f(u8**, Vec3f);

// TODO couple instructions out of order
#ifdef NON_MATCHING
void func_80087D4C(struct unkfunc_80087D4C *arg0, s32 arg1, u8 *dataPtr) {
    Vec3f axis;
    u8 *endPtr;

    read_vec3f(&dataPtr, arg0->unk18);
    read_vec3f(&dataPtr, axis);
    mtx3f_axis_angle(axis, arg0->unk24);

    arg0->unk48 = READ_VALUE(&dataPtr, s16);
    dataPtr = ALIGN_PTR(dataPtr, 4);

    arg0->unk50[0] = READ_VALUE(&dataPtr, f32);
    arg0->unk50[1] = READ_VALUE(&dataPtr, f32);
    arg0->unk50[2] = READ_VALUE(&dataPtr, f32);
    arg0->unk50[3] = READ_VALUE(&dataPtr, f32);
    arg0->unk50[4] = READ_VALUE(&dataPtr, f32);
    arg0->unk50[5] = READ_VALUE(&dataPtr, f32);
    dataPtr = ALIGN_PTR(dataPtr, 4) + 4;
    endPtr = &dataPtr[READ_VALUE(&dataPtr, u32)] - 8;
    while (endPtr != dataPtr) {
        dataPtr = ALIGN(dataPtr, 2);
        func_80085978(READ_VALUE(&dataPtr, u16), &dataPtr, arg0);
    }
    pop_second_heap_state();
}
#else
INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_375", func_80087D4C);
#endif

void func_80085978(s32, u8**, struct unkfunc_80087D4C *);

void func_80087E88(struct unkfunc_80087D4C *arg0, s32 arg1, u8 *dataPtr) {
    f32 *vecPtr;
    s32 i;
    u8 *endPtr;

    dataPtr = ALIGN_PTR(dataPtr, 4);

    vecPtr = arg0->unk18;
    
    for (i = 0; i < 3; i++) {
        vecPtr[i] = READ_VALUE(&dataPtr, f32);
    }

    dataPtr = ALIGN_PTR(dataPtr, 4) + 4;
    endPtr = dataPtr + READ_VALUE(&dataPtr, u32) - 8;
    while (endPtr != dataPtr) {
        dataPtr = ALIGN_PTR(dataPtr, 2);
        func_80085978(READ_VALUE(&dataPtr, u16), &dataPtr, arg0);
    }
    pop_second_heap_state();
}

struct unkD_800ADAC8 {
    s32 id;
    u32 romAddress;
};

extern struct unkD_800ADAC8 *D_800ADAC8;
extern s32 D_800ADACC;

u32 func_80087F58(s32 id) {
    s32 remaining = D_800ADACC;
    struct unkD_800ADAC8 *curEntry = D_800ADAC8;

    while (--remaining >= 0) {
        if (curEntry->id == id) {
            return curEntry->romAddress;
        }
        curEntry++;
    }
    return 0;
}

