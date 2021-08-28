#include "librocket.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define ROM_PATH_ARG 1
#define MESH_ADDR_ARG 2
#define OUTPUT_FILE_ARG 3

struct VertexData {
    int16_t positionIndex;
    int16_t texCoordIndex;
    int16_t colorIndex;
    uint8_t color[3]; // Only used if colorIndex is -1
    uint8_t alpha;
};

struct MeshData {
    float vec0[3]; // ?
    float vec1[3]; // Axis-angle rotation
    int16_t numPositions;
    int16_t numTexCoords;
    int16_t numColors;
    int16_t numVertices;
    int16_t (*positions)[3];
    int16_t (*texCoords)[2];
    uint8_t (*colors)[3];
    struct VertexData *vertices;
    uint32_t commandBytes;
};

#define SWAP16(field) { (field) = __builtin_bswap16(field); }
#define SWAP32(field) { (field) = __builtin_bswap32(field); }

#define SWAP(field) { \
    if (sizeof(field) == sizeof(uint32_t)) { SWAP32(field); } \
    else if (sizeof(field) == sizeof(uint16_t)) { SWAP16(field); } \
}

#define READ_AND_SWAP(var, dataPtr) { \
    __builtin_memcpy(&(var), *dataPtr, sizeof(var)); \
    *dataPtr += sizeof(var); \
    SWAP(var); \
}

#define READ_AND_SWAP_FLOAT(var, dataPtr) { \
    uint32_t __tmp_float_holder; \
    __builtin_memcpy(&__tmp_float_holder, *dataPtr, sizeof(uint32_t)); \
    *dataPtr += sizeof(uint32_t); \
    SWAP32(__tmp_float_holder); \
    (var) = *(float*)&__tmp_float_holder; \
}

void read_vertex_data(struct VertexData *vtx, uint8_t **dataPtr)
{
    memcpy(vtx, *dataPtr, 3 * sizeof(int16_t));
    *dataPtr += 6;
    SWAP16(vtx->positionIndex);
    SWAP16(vtx->texCoordIndex);
    SWAP16(vtx->colorIndex);
    if (vtx->colorIndex == -1)
    {
        memcpy(&vtx->color[0], *dataPtr, sizeof(vtx->color));
        *dataPtr += 3;
    }
    else
    {
        memset(&vtx->color[0], 0, sizeof(vtx->color));
        vtx->alpha = **dataPtr;
        *dataPtr += 1;
    }
}

struct RecordHeader {
    uint32_t type;
    uint32_t length;
};

// Reads a record header, returns the remaining number of bytes after the header
uint32_t read_record(struct RecordHeader *header, uint8_t **dataPtr)
{
    memcpy(header, *dataPtr, sizeof(struct RecordHeader));
    *dataPtr += sizeof(struct RecordHeader);
    SWAP(header->type);
    SWAP(header->length);
    return header->length - sizeof(struct RecordHeader);
}

// Reads a type 5 data record (???)
// Just skips the data for now
int read_record_5(struct MeshData *mesh, uint8_t **dataPtr)
{
    struct RecordHeader header;
    uint32_t remaining = read_record(&header, dataPtr);

    if (header.type == 5)
    {
        *dataPtr += remaining;
        return 0;
    }
    else
    {
        return 1;
    }
}

int read_mesh_bytecode(struct MeshData *mesh, uint8_t *bytecode)
{
    int cmd;
    uint8_t **dataPtr = &bytecode;
    while (1)
    {
        cmd = **dataPtr;
        *dataPtr += 1;
        if (cmd == 0xD)
        {
            break;
        }
        switch (cmd)
        {
            case 0x00:
                break;
            case 0x01:
                break;
            case 0x02:
                break;
            case 0x03:
                break;
        }
    }

    return 0;
}

int read_mesh_inner(struct MeshData *mesh, uint8_t *innerMeshData)
{
    __attribute__((unused)) int16_t unkOffset4;
    __attribute__((unused)) float unkOffset8;
    size_t curLength;
    uint8_t **dataPtr = &innerMeshData;
    int i;

    READ_AND_SWAP(mesh->numPositions, dataPtr);
    READ_AND_SWAP(unkOffset4, dataPtr);
    READ_AND_SWAP_FLOAT(unkOffset8, dataPtr);

    curLength = sizeof(mesh->positions[0]) * mesh->numPositions;
    mesh->positions = malloc(curLength);
    memcpy(mesh->positions, *dataPtr, curLength);
    *dataPtr += curLength;

    for (i = 0; i < mesh->numPositions; i++)
    {
        SWAP16(mesh->positions[i][0]);
        SWAP16(mesh->positions[i][1]);
        SWAP16(mesh->positions[i][2]);
    }

    READ_AND_SWAP(mesh->numTexCoords, dataPtr);
    
    curLength = sizeof(mesh->texCoords[0]) * mesh->numTexCoords;
    mesh->texCoords = malloc(curLength);
    memcpy(mesh->texCoords, *dataPtr, curLength);
    *dataPtr += curLength;

    for (i = 0; i < mesh->numTexCoords; i++)
    {
        SWAP16(mesh->texCoords[i][0]);
        SWAP16(mesh->texCoords[i][1]);
    }
    
    READ_AND_SWAP(mesh->numColors, dataPtr);

    curLength = sizeof(mesh->colors[0]) * mesh->numColors;
    mesh->colors = malloc(curLength);
    memcpy(mesh->colors, *dataPtr, curLength);
    *dataPtr += curLength;
    
    READ_AND_SWAP(mesh->numVertices, dataPtr);

    curLength = sizeof(mesh->vertices[0]) * mesh->numVertices;
    mesh->vertices = malloc(curLength);
    for (i = 0; i < mesh->numVertices; i++)
    {
        struct VertexData *curVertex = &mesh->vertices[i];
        read_vertex_data(curVertex, dataPtr);
    }

    uint16_t numCommands;
    READ_AND_SWAP(numCommands, dataPtr);
    mesh->commandBytes = numCommands * 8;

    int ret = read_mesh_bytecode(mesh, *dataPtr);

    return ret;
}

int read_mesh_data(struct MeshData *mesh, uint8_t **dataPtr)
{
    struct RecordHeader header;
    int i;

    __attribute__((unused)) uint32_t unkMeshField0; // Seems to be an index of some handler in an array at 800AC7F0
    __attribute__((unused)) uint32_t unkMeshField4;
    __attribute__((unused)) uint32_t vertexStorageFlags;

    READ_AND_SWAP(unkMeshField0, dataPtr);
    READ_AND_SWAP(unkMeshField4, dataPtr);

    // the following code may need to be different for values of unkMeshField0 besides 0x81
    if (unkMeshField0 == 0x81)
    {
        
    }
    for (i = 0; i < 3; i++)
    {
        READ_AND_SWAP_FLOAT(mesh->vec0[i], dataPtr);
    }
    for (i = 0; i < 3; i++)
    {
        READ_AND_SWAP_FLOAT(mesh->vec1[i], dataPtr);
    }

    int readError = read_record_5(mesh, dataPtr);
    if (readError)
    {
        fprintf(stderr, "No type 5 record found\n");
        return 1;
    }

    READ_AND_SWAP(vertexStorageFlags, dataPtr);

    uint32_t uncompressedLength, compressedLength;

    READ_AND_SWAP(uncompressedLength, dataPtr);
    READ_AND_SWAP(compressedLength, dataPtr);

    printf("0x%08X 0x%08X\n", unkMeshField0, unkMeshField4);
    printf("%5.2f %5.2f %5.2f\n", mesh->vec0[0], mesh->vec0[1], mesh->vec0[2]);
    printf("%5.2f %5.2f %5.2f\n", mesh->vec1[0], mesh->vec1[1], mesh->vec1[2]);
    printf("0x%08X 0x%08X\n", uncompressedLength, compressedLength);

    uint8_t *uncompressed = malloc(uncompressedLength);

    decompress(&decompressionParamsTable[0], compressedLength, *dataPtr, uncompressedLength, uncompressed);

    int ret = read_mesh_inner(mesh, &uncompressed[0]);

    free(uncompressed);

    return ret;
}

void init_mesh(struct MeshData *mesh)
{
    memset(mesh, 0, sizeof(struct MeshData));
}

static inline void free_and_zero(void **ptr)
{
    if (*ptr != NULL)
    {
        free(*ptr);
        *ptr = NULL;
    }
}

void free_mesh(struct MeshData *mesh)
{
    free_and_zero((void**)&mesh->positions);
    mesh->numPositions;
    
    free_and_zero((void**)&mesh->texCoords);
    mesh->numTexCoords = 0;
    
    free_and_zero((void**)&mesh->colors);
    mesh->numColors = 0;
    
    free_and_zero((void**)&mesh->vertices);
    mesh->numVertices = 0;
}

#define RECORD_TYPE_MESH 4

int main(int argc, char **argv)
{
    // Check if the mesh rom address was provided
    if (argc < 4)
    {
        printf("Usage: %s [path/to/rom] [mesh rom address] [output file]\n", argv[0]);
        return EXIT_SUCCESS;
    }
    const char *romPath = argv[ROM_PATH_ARG];
    const char *meshAddrArg = argv[MESH_ADDR_ARG];
    const char *outputFilePath = argv[OUTPUT_FILE_ARG];
    
    // Parse the mesh address string into a long
    char *endptr;
    long romAddress = strtol(argv[MESH_ADDR_ARG], &endptr, 0);

    // Check if the end pointer is the end of the texture index string
    // If it isn't, then the string contained invalid characters
    if (endptr != (strlen(meshAddrArg) + meshAddrArg))
    {
        fprintf(stderr, "Invalid index given: %s\n", meshAddrArg);
        return EXIT_FAILURE;
    }

    // Attempt to open the provided rom
    FILE *romFile = fopen(romPath, "rb");
    if (romFile == NULL)
    {
        fprintf(stderr, "Failed to open rom file: %s\n", romPath);
        return EXIT_FAILURE;
    }

    fseek(romFile, 0, SEEK_END);
    long romLength = ftell(romFile);
    if (romLength != ROCKET_ROM_SIZE)
    {
        fprintf(stderr, "Rom is not 12MB, not a valid rom (real length 0x%lX)\n", romLength);
        return EXIT_FAILURE;
    }
    fseek(romFile, 0, SEEK_SET);

    struct RecordHeader meshHeader;
    struct MeshData mesh;
    uint8_t buffer[sizeof(struct RecordHeader)];
    uint8_t *dataPtr = buffer;

    fseek(romFile, romAddress, SEEK_SET);
    size_t readLength = fread(buffer, sizeof(struct RecordHeader), 1, romFile);

    if (readLength < 1)
    {
        fprintf(stderr, "Could not read mesh header from rom\n");
        return EXIT_FAILURE;
    }
    
    uint32_t meshRomLength = read_record(&meshHeader, &dataPtr);

    if (meshHeader.type != RECORD_TYPE_MESH)
    {
        fprintf(stderr, "Mesh not present at provided address\n");
        return EXIT_FAILURE;
    }

    uint8_t *romBuffer = malloc(meshRomLength);
    readLength = fread(romBuffer, meshRomLength, 1, romFile);

    if (readLength < 1)
    {
        fprintf(stderr, "Could not read mesh from rom\n");
        return EXIT_FAILURE;
    }

    dataPtr = &romBuffer[0];
    init_mesh(&mesh);

    if (read_mesh_data(&mesh, &dataPtr))
    {
        fprintf(stderr, "Error reading mesh\n");
        free(romBuffer);
        free_mesh(&mesh);
        return EXIT_FAILURE;
    }
    
    int i;
    printf("Positions:\n");
    for (i = 0; i < mesh.numPositions; i++)
    {
        printf("  %-6d %-6d %-6d\n", mesh.positions[i][0], mesh.positions[i][1], mesh.positions[i][2]);
    }
    printf("Tex Coords:\n");
    for (i = 0; i < mesh.numTexCoords; i++)
    {
        printf("  %-6d %-6d\n", mesh.texCoords[i][0], mesh.texCoords[i][1]);
    }
    printf("Vertex colors/normals:\n");
    for (i = 0; i < mesh.numColors; i++)
    {
        printf("  0x%2X 0x%2X 0x%2X\n", mesh.colors[i][0], mesh.colors[i][1], mesh.colors[i][2]);
    }
    printf("Vertex data:\n");
    for (i = 0; i < mesh.numVertices; i++)
    {
        struct VertexData *curVertex = &mesh.vertices[i];
        printf("  %04X %04X %04X %02X %02X %02X %02X\n",
            (uint16_t)curVertex->positionIndex, (uint16_t)curVertex->texCoordIndex, (uint16_t)curVertex->colorIndex,
            curVertex->color[0], curVertex->color[1], curVertex->color[2], curVertex->alpha);
    }

    free_mesh(&mesh);
    free(romBuffer);
}
