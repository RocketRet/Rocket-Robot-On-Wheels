#include <include_asm.h>
#include <ultra64.h>
#include <types.h>

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_4", func_8001E330);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_4", func_8001E504);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_4", func_8001E69C);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_4", func_8001E824);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_4", func_8001E954);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_4", func_8001EA18);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_4", func_8001ECEC);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_4", func_8001F128);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_4", func_8001F2A4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_4", func_8001F36C);

void *main_alloc_bzero(s32);

void alloc_vertex_data_storage(struct Model *model)
{
    if (model->vertexDataStorage == NULL)
    {
        model->vertexDataStorage = main_alloc_bzero(sizeof(struct VertexDataStorage));
    }
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_4", func_8001F518);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_4", func_8001F7A4);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_4", func_8001F82C);
