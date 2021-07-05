#include <include_asm.h>
#include <ultra64.h>
#include <mem.h>
#include <types.h>

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

void func_800864A8(struct Model *arg0, s32 decompressedSize, u8 *decompressedBytes, s32 arg3);

struct ModelData {
    u32 unk0;
    Gfx *unk4;
    Gfx *unk8;
    Gfx *unkC;
};

extern f32 D_8001D6C4;
extern Vec3f D_800AF794;

#ifdef NON_MATCHING
void func_800864A8(struct unkfunc_8001E044 *arg0, s32 decompressedSize, u8 *decompressedBytes, s32 arg3) {
    Vtx *vertexBuffer;
    u32 vertexCount;
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
    u8 curByteCmd1;
    u8 v0Cmd8;
    u8 numTriangles;
    u8 curCommand;
    u8 *gfxBuffer;
    void *curSubmodelCmd7;
    void *prevSubmodelCmd7;
    void *curSubmodelCmd0;
    s32 vertexIndex;
    Vtx *curVertex;
    s8 phi_v1;
    s32 phi_a0_7;
    s32 num2Triangles;
    s16 numVertexPositions;
    s16 numVertexColors;
    u32 s1;
    s16 *textureCoordBuffer;
    s16 *positionIndexBuffer;
    s16 numTextureCoords;
    u8 *vertexColors;
    s16 *vertexPositions;
    void *textureCoords;

    vertexPositions = NULL;
    textureCoords = NULL;
    vertexColors = NULL;
    positionIndexBuffer = NULL;
    vertexBuffer = NULL;
    dataPtr = decompressedBytes;
    if (decompressedSize != 0) {
        push_second_heap_state();
        numVertexPositions = read_unaligned_s16(dataPtr); // vertex position count
        arg0->unkE0 =  read_unaligned_s16(dataPtr);
        arg0->unk100 = read_unaligned_f32(dataPtr);
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
            memmove(vertexPositions, dataPtr, vertexPositionBytes);
            dataPtr += vertexPositionBytes;
        }
        // Read texture coords
        numTextureCoords = read_unaligned_s16(dataPtr);
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
            memmove(textureCoords, dataPtr, textureCoordBytes);
            dataPtr += textureCoordBytes;
        }
        // Read vertex colors/normals
        numVertexColors = read_unaligned_s16(dataPtr);
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
            memmove(vertexColors, dataPtr, vertexColorBytes);
            dataPtr += vertexColorBytes;
        }
        vertexCount = read_unaligned_s16(dataPtr);
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
        curVertex = &vertexBuffer[0];
        vertexIndex = 0;
        // Construct vertices
        while (vertexIndex < vertexCount) {
            s16 positionIndex;
            s16 *temp_v0_7;
            s16 vertexFlag;
            // Copy position
            positionIndex = read_unaligned_s16(dataPtr);
            temp_v0_7 = &vertexPositions[positionIndex * 3];
            VEC3S_COPY(curVertex->v.ob, temp_v0_7);
            if (positionIndexBuffer != NULL) {
                *positionIndexBuffer = positionIndex;
                positionIndexBuffer += 2;
            }
            // Copy texture coords
            curVertex->v.tc[1] = 0;
            curVertex->v.tc[0] = 0;
            if (numTextureCoords > 0) {
                s16 textureCoordIndex;
                textureCoordIndex = read_unaligned_s16(dataPtr);
                if (textureCoordIndex != -1) {
                    VEC2S_COPY(curVertex->v.tc, &textureCoords[textureCoordIndex * 2]);
                }
                if (textureCoordBuffer != NULL) {
                    *textureCoordBuffer = textureCoordIndex;
                    textureCoordBuffer += 2;
                }
            }
            // Copy vertex colors/normals
            vertexFlag = read_unaligned_s16(dataPtr);
            curVertex->v.flag = vertexFlag;
            if (vertexFlag == -1) {
                curVertex->v.cn[0] = *dataPtr++;
                curVertex->v.cn[1] = *dataPtr++;
                curVertex->v.cn[2] = *dataPtr++;
                curVertex->v.cn[3] = 0xFF;
            } else {
                curVertex->v.cn[0] = vertexColors[vertexFlag * 3 + 0];
                curVertex->v.cn[1] = vertexColors[vertexFlag * 3 + 1];
                curVertex->v.cn[2] = vertexColors[vertexFlag * 3 + 2];
                curVertex->v.cn[3] = *dataPtr++;
            }
            vertexIndex++;
            curVertex++;
        }
        // read two bytes dictating how many gfx commands to allocate
        curModel.unk0 = read_unaligned_s16(dataPtr) * sizeof(Gfx);
        // allocate the gfx commands
        gfxBuffer = main_alloc_nozero(curModel.unk0);
        temp_f20 = D_8001D6C4;
        curModel.unk4 = gfxBuffer;
        curModel.unk8 = gfxBuffer;
        curModel.unkC = (Gfx*)((u8*)gfxBuffer + curModel.unk0);
        while ((curCommand = *dataPtr++) != 0xD) {
            curCommand = *dataPtr++;
            switch (curCommand) {
                case 0:
                    if (arg0->numSubmodels > 0) {
                        gSPEndDisplayList(curModel.unk8++);
                    }
                    sp40.unk0_4 = 0;
                    sp40.unk0_0 = 0;
                    sp40.unk1 = 0;
                    sp40.unk2 = 0;
                    sp48 = sp40;
                    if (sp48.unk2 == 5) {
                        phi_v1 = 7;
                    } else if (sp48.unk2 == 3) {
                        phi_v1 = 5;
                    } else if (sp48.unk2 == 4) {
                        phi_v1 = 6;
                    } else if (sp48.unk0_4 == 2) {
                        phi_v1 = 4;
                    } else if (sp48.unk2 == 2) {
                        phi_v1 = 3;
                    } else {
                        phi_v1 = 2;
                        if (sp48.unk1 != 2) {
                            phi_v1 = sp48.unk2 == 1;
                        }
                    }
                    sp40.unk3 = phi_v1;
                    sp38 = sp40;
                    curSubmodelCmd0 = &arg0->submodels[arg0->numSubmodels]; // size 0x28 bytes
                    curSubmodelCmd0->unk0 = curModel.unk8;
                    curSubmodelCmd0->unk4 = sp38;
                    curSubmodelCmd0->unk10 = arg0->unk100;
                    curSubmodelCmd0->unk14 = D_800AF794[0];
                    curSubmodelCmd0->unk18 = D_800AF794[1];
                    curSubmodelCmd0->unk1C = D_800AF794[2];
                    curSubmodelCmd0->unk24 = 2.0f;
                    curSubmodelCmd0->unk8 = temp_f20;
                    curSubmodelCmd0->unkC = temp_f20;
                    curSubmodelCmd0->unk20 = 0;
                    curSubmodelCmd0->unk21 = 0;
                    curSubmodelCmd0->unk22 = arg0->unk110;
                    curSubmodelCmd0->unk10 = read_unaligned_f32(dataPtr);
                    curSubmodelCmd0->unk14 = read_unaligned_f32(dataPtr);
                    curSubmodelCmd0->unk18 = read_unaligned_f32(dataPtr);
                    curSubmodelCmd0->unk1C = read_unaligned_f32(dataPtr);
                    curSubmodelCmd0->unk24 = read_unaligned_f32(dataPtr);
                    break;
                case 1:
                    iCmd1 = 0;
                    do {
                        curByteCmd1 = *dataPtr++;
                        sp58[iCmd1++] = curByteCmd1;
                    } while (curByteCmd1 != 0);
                    break;
                case 2:
                    arg0->submodels[arg0->numSubmodels - 1].unk8 = read_unaligned_f32(dataPtr);
                    break;
                case 3:
                    arg0->submodels[arg0->numSubmodels - 1].unkC = read_unaligned_f32(dataPtr);
                    break;
                case 4:
                    arg0->submodels[arg0->numSubmodels - 1].unk20 = *dataPtr++;
                    break;
                case 5: // Set lighting
                    gSPSetGeometryMode(curModel.unk8++, G_LIGHTING);
                    break;
                case 6: // Clear lighting
                    gSPClearGeometryMode(curModel.unk8++, G_LIGHTING);
                    break;
                case 7:
                    sp28 = arg0->submodels[arg0->numSubmodels - 1].unk4; // 4 byte struct copy
                    s1 = read_unaligned_s16(dataPtr);
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
                            curSubmodelCmd7->unk14 = D_800AF794.unk0;
                            curSubmodelCmd7->unk18 = D_800AF794.unk4;
                            curSubmodelCmd7->unk1C = D_800AF794.unk8;
                            curSubmodelCmd7->unk24 = 0x40000000;
                            curSubmodelCmd7->unk8 = temp_f20;
                            curSubmodelCmd7->unkC = temp_f20;
                            curSubmodelCmd7->unk20 = 0;
                            curSubmodelCmd7->unk21 = 0;
                            curSubmodelCmd7->unk22 = arg0->unk110;
                            prevSubmodelCmd7 = curSubmodelCmd7 - 1; // size 0x28 bytes
                            curSubmodelCmd7->unk10 = prevSubmodelCmd7->unk10;
                            curSubmodelCmd7->unk14 = prevSubmodelCmd7->unk14;
                            curSubmodelCmd7->unk18 = prevSubmodelCmd7->unk18;
                            curSubmodelCmd7->unk1C = prevSubmodelCmd7->unk1C;
                            curSubmodelCmd7->unk24 = prevSubmodelCmd7->unk24;
                        } else {
                            arg0->submodels[arg0->numSubmodels - 1].unk4 = sp30; // 4 byte struct copy
                        }
                    } else {
                        arg0->submodels[arg0->numSubmodels - 1].unk4 = sp30; // 4 byte struct copy
                    }
                    arg0->unk0->unk6C(arg0, s1, curModel.unk8++);
                    break;
                case 8:
                    v0Cmd8 = *dataPtr++;
                    gSPVertex(curModel.unk8++, vertexBuffer, v0Cmd8, *dataPtr++);
                    break;
                case 9:
                    numTriangles = *dataPtr++;
                    if (numTriangles & 1) {
                        s32 i;
                        s32 triangleIndices;
                        triangleIndices = read_unaligned_s16(dataPtr);
                        i = 0;
                        do {
                            curModel.unk18[i] = triangleIndices & 0x1F;
                            triangleIndices >>= 5;
                            i++;
                        } while (i < 3);
                        gSP1Triangle(curModel.unk8++, curModel.unk18[0], curModel.unk18[1], curModel.unk18[2]);
                        numTriangles--;
                    }
                    num2Triangles = numTriangles / 2;
                    while (num2Triangles > 0) {
                        s32 i, j;
                        i = 0;
                        while (i < 2) {
                            s32 triangleIndices = read_unaligned_s16(dataPtr);
                            j = 0;
                            do {
                                curModel.unk18[3 & i + j] = triangleIndices & 0x1F;
                                triangleIndices >>= 5;
                                j++;
                            } while (j < 3);
                            i += 1;
                        }
                        gSP2Triangles(curModel.unk8++, curModel.unk18[0], curModel.unk18[1], curModel.unk18[2], 0, curModel.unk18[3], curModel.unk18[4], curModel.unk18[5]);
                        num2Triangles--;
                    }
                    break;
                case 10:
                    dataPtr += 2;
                    break;
                case 11:
                    arg0->submodels[arg0->numSubmodels - 1].unk21 = 1;
                    break;
                case 12:
                    arg0->submodels[arg0->numSubmodels - 1].unk22 = *dataPtr++;
                    arg0->unk110 |= 0x1000;
                    break;
            }
        }
        gSPEndDisplayList(curModel.unk8++);
        pop_second_heap_state();
        arg0->unkE8 = vertexBuffer;
        arg0->unkE4 = vertexCount;
        arg0->unkF0 = curModel.unk4;
    }
}
#else
INCLUDE_ASM(void, "rocket/codeseg2/codeseg2_375", func_800864A8, struct Model *arg0, s32 decompressedSize, u8 *decompressedBytes, s32 arg3);
#endif

struct unkD_800AC7F0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    void (*unk10)();
};

extern struct unkD_800AC7F0 *D_800AC7F0[];

// TODO typing
struct unkD_800AC7F0 **func_800872F8(s32 arg0, s32 arg1, s32 arg2)
{
    struct unkD_800AC7F0 **ret;
    struct unkD_800AC7F0 *var;

    var = D_800AC7F0[arg0];
    ret = main_alloc_bzero(var->unkC);
    *ret = var;
    var->unk10(ret, arg1, arg2);
    return ret;
}

// TODO typing
struct unkD_800AC7F0 **func_80087374(s32 **arg0, s32 arg1, s32 arg2)
{
    struct unkD_800AC7F0 **ret;
    struct unkD_800AC7F0 *var;

    var = D_800AC7F0[(*arg0)[1]];
    ret = main_alloc_bzero(var->unkC);
    *ret = var;
    var->unk10(ret, arg1, arg2);
    (*ret)[3].unk10(ret, arg0);
    return ret;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_375", func_80087418);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_375", func_80087554);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_375", func_800875E8);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_375", func_80087BF8);

struct unkfunc_80087D4C {
    u8 padding[0x18];
    Vec3f unk18;
    Mtx3f unk24;
    u32 unk48;
    u32 unk4C;
    f32 unk50[6];
};

// TODO couple instructions out of order
#ifdef NON_MATCHING
void func_80087D4C(struct unkfunc_80087D4C *arg0, s32 arg1, u8 *dataPtr) {
    Vec3f axis;
    u8 *endPtr;

    read_vec3f(&dataPtr, arg0->unk18);
    read_vec3f(&dataPtr, axis);
    mtx3f_axis_angle(axis, arg0->unk24);
    // arg2 = arg2 + 2;
    // arg2 = temp_v1 + 4;
    arg0->unk48 = READ_VALUE(dataPtr, s16);
    dataPtr = ALIGN_PTR(dataPtr, 4);
    // arg2 = arg2 + 8;
    arg0->unk50[0] = READ_VALUE(dataPtr, f32);
    arg0->unk50[1] = READ_VALUE(dataPtr, f32);
    arg0->unk50[2] = READ_VALUE(dataPtr, f32);
    arg0->unk50[3] = READ_VALUE(dataPtr, f32);
    arg0->unk50[4] = READ_VALUE(dataPtr, f32);
    arg0->unk50[5] = READ_VALUE(dataPtr, f32);
    dataPtr = ALIGN_PTR(dataPtr, 4) + 4;
    endPtr = &dataPtr[READ_VALUE(dataPtr, u32)] - 8;
    while (endPtr != dataPtr) {
        dataPtr = ALIGN(dataPtr, 2);
        func_80085978(READ_VALUE(dataPtr, u16), &dataPtr, arg0);
    }
    pop_second_heap_state();
}
#else
INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_375", func_80087D4C);
#endif

void func_80087E88(struct unkfunc_80087D4C *arg0, s32 arg1, u8 *dataPtr) {
    f32 *vecPtr;
    s32 i;
    u8 *endPtr;

    dataPtr = ALIGN_PTR(dataPtr, 4);

    vecPtr = arg0->unk18;
    
    for (i = 0; i < 3; i++) {
        vecPtr[i] = READ_VALUE(dataPtr, f32);
    }

    dataPtr = ALIGN_PTR(dataPtr, 4) + 4;
    endPtr = dataPtr + READ_VALUE(dataPtr, u32) - 8;
    while (endPtr != dataPtr) {
        dataPtr = ALIGN_PTR(dataPtr, 2);
        func_80085978(READ_VALUE(dataPtr, u16), &dataPtr, arg0);
    }
    pop_second_heap_state();
}

extern s32 *D_800ADAC8;
extern s32 D_800ADACC;

s32 func_80087F58(s32 arg0) {
    s32 phi_v1 = D_800ADACC;
    s32 *phi_a1 = D_800ADAC8;

    while (--phi_v1 >= 0) {
        if (phi_a1[0] == arg0) {
            return phi_a1[1];
        }
        phi_a1 += 2;
    }
    return 0;
}

