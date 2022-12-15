#include <include_asm.h>
#include <ultra64.h>
#include <mem.h>
#include <types.h>
#include <macros.h>
#include "codeseg2.h"
#include "gfx.h"

extern Vec3f D_800AF794;
void alloc_vertex_data_storage(struct GameObject *model);
void custom_memmove(void *dst, void *src, s32 count);
struct RenderParams func_80093DDC(s32 arg1);

#define VEC2S_COPY(dst, src) __builtin_memcpy((dst), (src), sizeof(s16) * 2);
#define VEC3S_COPY(dst, src) __builtin_memcpy((dst), (src), sizeof(s16) * 3);

struct ModelData {
    u32 unk0;
    Gfx *unk4;
    Gfx *unk8;
    Gfx *unkC;
    u8 *dataPtr;
};

inline struct Submodel* create_submodel(struct GameObject *arg0, struct ModelData* curModel, struct RenderParams rp) {
    struct Submodel* ret = &arg0->submodels[arg0->numSubmodels++]; // size 0x28 bytes
    ret->unk0 = curModel->unk8;
    ret->unk4 = rp;
    ret->unk10 = arg0->unk100;
    VEC3F_COPY(ret->unk14, D_800AF794);
    ret->unk24 = 0x40000000;
    ret->unk8 = FLT_MAX;
    ret->unkC = FLT_MAX;
    ret->unk20 = 0;
    ret->unk21 = 0;
    ret->unk22 = arg0->unk110.bitfield.unk110_0;

    return ret;
}

// FIXME These two functions should be the same function
inline s32 read_s16_unaligned_(u8 **dataPtr) {
    u8 val1 = *(*dataPtr)++;
    u8 val2 = *(*dataPtr)++;
    return val2 | (val1 << 8);
}

static inline s16 read_s16_unaligned(u8** dataPtr) {
    u32 val1 = *((*dataPtr)++);
    u32 val2 = *((*dataPtr)++);
    return val2 | (val1 << 8);
}

inline f32 read_f32_unaligned(u8** dataPtr) {
    s32 i;
    f32 ret;
    u8 *curPtr = (u8*)&ret;
    for (i = 3; i != -1; i--) {
        *(curPtr)++ = *(*dataPtr)++;
    }
    return ret;
}

inline s32 read_s32_unaligned(u8** dataPtr) {
    s32 i;
    s32 ret;
    u8 *curPtr = (u8*)&ret;
    for (i = 3; i != -1; i--) {
        *(curPtr)++ = *(*dataPtr)++;
    }
    return ret;
}

static inline void read_submodel_values(struct Submodel *submodel, u8** dataPtr) {    
    submodel->unk10    = read_f32_unaligned(dataPtr);
    submodel->unk14[0] = read_f32_unaligned(dataPtr);
    submodel->unk14[1] = read_f32_unaligned(dataPtr);
    submodel->unk14[2] = read_f32_unaligned(dataPtr);
    submodel->unk24    = read_s32_unaligned(dataPtr);
}

static inline void copy_submodel_values(struct Submodel *dst, struct Submodel *src) {
    dst->unk10 = src->unk10;
    VEC3F_COPY(dst->unk14, src->unk14);
    dst->unk24 = src->unk24;
}

static inline u8 read_u8(u8** dataPtr) {
    return *(*dataPtr)++;
}

static inline struct RenderParams inline_build_model_gfx_make_RenderParams(s32 materialIndex) { 
    struct RenderParams sp38 = func_80093DDC(materialIndex);
    return sp38;
}

static inline void inline_build_model_gfx_cmd_12(struct GameObject *arg0, u8** dataPtr) {
    arg0->submodels[arg0->numSubmodels - 1].unk22 = *(*dataPtr)++;
    arg0->unk110.bitfield.unk110_19 = 1;
}

void build_model_gfx(struct GameObject *arg0, s32 modelDataSize, u8 *modelData, s32 modelAllocationFlags) {
    s32 vertexCount;
    Vtx *vertexBuffer;
    struct ModelData curModel; 
    u8 *gfxBuffer;
    s32 vertexIndex;
    Vtx *curVertex;
    s32 numVertexPositions;
    s32 numVertexColors;
    s32 materialIndex;
    s16 *textureCoordBuffer;
    s16 *positionIndexBuffer;
    s32 numTextureCoords;
    u8 (*vertexColors)[3];
    s16 *vertexPositions;
    s16 *textureCoords;
    u32 curByteCount;

    vertexPositions = NULL;
    textureCoords = NULL;
    vertexColors = NULL;
    positionIndexBuffer = NULL;
    textureCoordBuffer = NULL;
    vertexBuffer = NULL;
    curModel.dataPtr = modelData;
    if (modelDataSize != 0) {
        push_second_heap_state();
        numVertexPositions = read_s16_unaligned(&curModel.dataPtr);
        arg0->unkE0 =  read_s16_unaligned(&curModel.dataPtr);
        arg0->unk100 = read_f32_unaligned(&curModel.dataPtr);
        
        // Read vertex positions
        if (numVertexPositions > 0) {
            curByteCount = numVertexPositions * (3 * sizeof(s16));
            if ((modelAllocationFlags & 1) == 0) {
                vertexPositions = alloc_second_heap(curByteCount);
            } else {
                alloc_vertex_data_storage(arg0); // alloc if needed
                arg0->vertexDataStorage->unkC = numVertexPositions;
                vertexPositions = main_alloc_nozero(curByteCount);
                arg0->vertexDataStorage->unk10 = vertexPositions;
            }
            custom_memmove(vertexPositions, curModel.dataPtr, curByteCount);
            curModel.dataPtr += curByteCount;
        }
        // Read texture coords
        numTextureCoords = read_s16_unaligned(&curModel.dataPtr);
        if (numTextureCoords > 0) {
            curByteCount = numTextureCoords * (2 * sizeof(s16));
            if ((modelAllocationFlags & 4) == 0) {
                textureCoords = alloc_second_heap(curByteCount);
            } else {
                alloc_vertex_data_storage(arg0); // alloc if needed
                arg0->vertexDataStorage->unk18 = numTextureCoords;
                textureCoords = main_alloc_nozero(curByteCount);
                arg0->vertexDataStorage->unk1C = textureCoords;
            }
            custom_memmove(textureCoords, curModel.dataPtr, curByteCount);
            curModel.dataPtr += curByteCount;
        }
        // Read vertex colors/normals
        numVertexColors = read_s16_unaligned(&curModel.dataPtr);
        if (numVertexColors > 0) {
            curByteCount = numVertexColors * (3 * sizeof(s8));
            if ((modelAllocationFlags & 0x02) == 0) {
                vertexColors = alloc_second_heap(curByteCount);
            } else {
                alloc_vertex_data_storage(arg0); // alloc if needed
                arg0->vertexDataStorage->unk4 = numVertexColors;
                vertexColors = main_alloc_nozero(curByteCount);
                arg0->vertexDataStorage->unk8 = vertexColors;
            }
            custom_memmove(vertexColors, curModel.dataPtr, curByteCount);
            curModel.dataPtr += curByteCount;
        }
        vertexCount = read_s16_unaligned(&curModel.dataPtr);
        vertexBuffer = main_alloc_nozero(vertexCount * sizeof(Vtx));
        if (modelAllocationFlags & 0x01) {
            arg0->vertexDataStorage->unk14 = main_alloc_nozero(vertexCount * sizeof(s16));
            positionIndexBuffer = arg0->vertexDataStorage->unk14;
        }
        if (modelAllocationFlags & 0x04) {
            if (numTextureCoords > 0) {
                arg0->vertexDataStorage->unk20 = main_alloc_nozero(vertexCount * sizeof(s16));
                textureCoordBuffer = arg0->vertexDataStorage->unk20;
            }
        }
        if (modelAllocationFlags & 0x10) {
            alloc_vertex_data_storage(arg0); // alloc if needed
            arg0->vertexDataStorage->unk0 = main_alloc_nozero(vertexCount);
            bzero(arg0->vertexDataStorage->unk0, vertexCount);
        }
        vertexIndex = 0;
        // Construct vertices
        while (1) {
            s32 positionIndex;
            s32 vertexFlag;
            s16 *flagPtr;
            u8 *dataPtr;
            if (vertexIndex >= vertexCount) break;
            // Copy position
            positionIndex = read_s16_unaligned(&curModel.dataPtr);
            VEC3S_COPY(vertexBuffer[vertexIndex].v.ob, &vertexPositions[positionIndex * 3]);
            flagPtr = &vertexBuffer[vertexIndex].v.ob[3];
            if (positionIndexBuffer != NULL) {
                *positionIndexBuffer = positionIndex;
                positionIndexBuffer++;
            }
            // Copy texture coords
            vertexBuffer[vertexIndex].v.tc[1] = 0;
            vertexBuffer[vertexIndex].v.tc[0] = 0;
            if (numTextureCoords > 0) {
                s32 textureCoordIndex = read_s16_unaligned(&curModel.dataPtr);
                if (textureCoordIndex != -1) {
                    VEC2S_COPY(vertexBuffer[vertexIndex].v.tc, &textureCoords[textureCoordIndex * 2]);
                }
                if (textureCoordBuffer != NULL) {
                    *textureCoordBuffer = textureCoordIndex;
                    textureCoordBuffer++;
                }
            }
            // Copy vertex colors/normals
            vertexFlag = read_s16_unaligned(&curModel.dataPtr);
            dataPtr = curModel.dataPtr;
            *flagPtr = vertexFlag;
            if (vertexFlag == -1) {
                vertexBuffer[vertexIndex].v.cn[0] = *dataPtr;
                curModel.dataPtr = dataPtr + 1;
                vertexBuffer[vertexIndex].v.cn[1] = *curModel.dataPtr++;
                vertexBuffer[vertexIndex].v.cn[2] = *curModel.dataPtr++;
                vertexBuffer[vertexIndex].v.cn[3] = 0xFF;
            } else { 
                u8* col = vertexColors[vertexFlag];
                vertexBuffer[vertexIndex].v.cn[0] = col[0];
                vertexBuffer[vertexIndex].v.cn[1] = col[1];
                vertexBuffer[vertexIndex].v.cn[2] = col[2];
                vertexBuffer[vertexIndex].v.cn[3] = *curModel.dataPtr++;
            }
            vertexIndex++;
        }
        curVertex = &vertexBuffer[0];
        // read two bytes dictating how many gfx commands to allocate
        {
            s16 displaylistLength = read_s16_unaligned(&curModel.dataPtr);
            curModel.unk0 = displaylistLength * sizeof(Gfx);
            // allocate the gfx commands
            gfxBuffer = main_alloc_nozero(curModel.unk0);
        }
        curModel.unk4 = (Gfx*)gfxBuffer;
        curModel.unk8 = (Gfx*)gfxBuffer;
        curModel.unkC = (Gfx*)((u8*)gfxBuffer + curModel.unk0);
        while (1) {
            struct ModelData *md = &curModel;
            s32 curCommand = read_u8(&curModel.dataPtr);
            if (curCommand == 0xD) break;
            switch (curCommand) {
                case 0:
                    {
                        struct Submodel* curSubmodel;
                        if (arg0->numSubmodels > 0) {
                            gSPEndDisplayList(NEXT_GFX(md->unk8));
                        }
                        curSubmodel = create_submodel(arg0, &curModel, unk_make_RenderParams(0, 0, 0, 0));
                        read_submodel_values(curSubmodel, &curModel.dataPtr);
                    }
                    break;
                case 1:
                    {
                        u8 sp58[256];
                        s32 i;
                        s32 curByte;
                        for (i = 0;; i++) {
                            curByte = sp58[i] = *curModel.dataPtr++;
                            if (!curByte) {
                                break;
                            }
                        }
                    }
                    break;
                case 2:
                    arg0->submodels[arg0->numSubmodels - 1].unk8 = read_f32_unaligned(&curModel.dataPtr);
                    break;
                case 3:
                    arg0->submodels[arg0->numSubmodels - 1].unkC = read_f32_unaligned(&curModel.dataPtr);
                    break;
                case 4:
                    arg0->submodels[arg0->numSubmodels - 1].unk20 = *curModel.dataPtr++;
                    break;
                case 12:
                    inline_build_model_gfx_cmd_12(arg0, &curModel.dataPtr);
                    break;
                case 8:
                    {
                        s32 v0 = read_u8(&curModel.dataPtr);
                        s32 v1 = read_u8(&curModel.dataPtr);
                        gSPVertex(NEXT_GFX(md->unk8), curVertex, v0, v1);
                        curVertex += v0;
                    }
                    break;
                case 7:
                    {
                        struct RenderParams sp28;
                        struct RenderParams sp30;
                        materialIndex = read_s16_unaligned(&curModel.dataPtr);
                        sp28 = arg0->submodels[arg0->numSubmodels - 1].unk4; // 4 byte struct copy
                        sp30 = inline_build_model_gfx_make_RenderParams(materialIndex);
                        if (sp28.cycleType != 0 && sp28.unk0_4 != 0 && sp28.unk1 != 0 && sp28.unk2 != 0) {
                            if (!unk_compare_RenderParams(sp28, sp30)) {
                                struct Submodel* curSubmodel;
                                if (arg0->numSubmodels > 0) {
                                    gSPEndDisplayList(NEXT_GFX(md->unk8));
                                }
                                curSubmodel = create_submodel(arg0, &curModel, sp30);
                                copy_submodel_values(curSubmodel, curSubmodel - 1);
                            } else {
                                arg0->submodels[arg0->numSubmodels - 1].unk4 = sp30; // 4 byte struct copy
                            }
                        } else {
                            arg0->submodels[arg0->numSubmodels - 1].unk4 = sp30; // 4 byte struct copy
                        }
                    }
                    {
                        Gfx *g = md->unk8;
                        md->unk8++;
                        arg0->unk0->unk6C(arg0, materialIndex, g);
                    }
                    break;
                case 9:
                    {
                        s32 i, j;
                        s32 arr[2][3];
                        s32 numTriangles = *curModel.dataPtr++;
                        if (numTriangles & 1) {
                            s32 triangleIndices;
                            numTriangles--;
                            triangleIndices = read_s16_unaligned(&curModel.dataPtr);
                            for (j = 0; j < 3; j++, triangleIndices >>= 5) {
                                arr[0][j] = triangleIndices & 0x1F;
                            }
                            gSP1Triangle(NEXT_GFX(md->unk8), arr[0][0], arr[0][1], arr[0][2], 0);
                        }
                        numTriangles = numTriangles >> 1;
                        while (1) {
                            s32 triangleIndices;
                            if (numTriangles-- <= 0) break;
                            // Doesn't match as a for loop
                            // for (i = 0; i < 2; i++) {
                            i = 0;
                            while (1) {
                                if (i >= 2) {
                                    break;
                                }
                                triangleIndices = read_s16_unaligned(&curModel.dataPtr);
                                for (j = 0; j < 3; j++, triangleIndices >>= 5) {
                                    arr[i][j] = triangleIndices & 0x1F;
                                }
                                i++;
                            }
                            gSP2Triangles(NEXT_GFX(md->unk8), arr[0][0], arr[0][1], arr[0][2], 0, arr[1][0], arr[1][1], arr[1][2], 0);
                        }
                    }
                    break;
                case 5: // Set lighting
                    gSPSetGeometryMode(NEXT_GFX(md->unk8), G_LIGHTING);
                    break;
                case 6: // Clear lighting
                    gSPClearGeometryMode(NEXT_GFX(md->unk8), G_LIGHTING);
                    break;
                case 10:
                    curModel.dataPtr += 2;
                    break;
                case 11:
                    arg0->submodels[arg0->numSubmodels - 1].unk21 = 1;
                    break;
            }
        }
        {
            struct ModelData* g = &curModel;
            gSPEndDisplayList(NEXT_GFX(g->unk8));
        }
        pop_second_heap_state();
        {
            arg0->unkF0 = curModel.unk4;
            arg0->unkE8 = vertexBuffer;
            arg0->unkE4 = vertexCount;
        }
    }
}

extern struct unkfunc_8001E044_inner *D_800AC7F0[];

struct GameObject *func_800872F8(s32 arg0, void *arg1, s32 arg2)
{
    struct GameObject *ret;
    struct unkfunc_8001E044_inner *var;

    var = D_800AC7F0[arg0];
    ret = main_alloc_bzero(var->unkC);
    ret->unk0 = var;
    ret->unk0->unk10(ret, arg1, arg2);
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
    ret->unk0->unk10(ret, arg1, arg2);
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

void func_80085978(s32, u8**, struct unkfunc_80087D4C *);

static inline void read_pos_rot(u8** dataPtrPtr, Vec3f arg0, Mtx3f arg2) {
    Vec3f axis;
    read_vec3f(dataPtrPtr, arg0);
    read_vec3f(dataPtrPtr, axis);
    mtx3f_axis_angle(axis, arg2);
}

void func_80087D4C(struct unkfunc_80087D4C *arg0, s32 arg1, u8 *dataPtr) {
    u8 *endPtr;

    read_pos_rot(&dataPtr, arg0->unk18, arg0->unk24);

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
        dataPtr = (u8*)ALIGN(dataPtr, 2);
        func_80085978(READ_VALUE(&dataPtr, u16), &dataPtr, arg0);
    }
    pop_second_heap_state();
}

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

