#include <cstdlib>
#include <fstream>
#include <array>
#include <vector>

#include "fmt/core.h"
#include "librocket.h"
#include "bswap.h"

constexpr char invalid_file_error[] = "File {} is not a rom or asset archive\n";

enum class RocketFileType {
    ROM,
    archive,
    invalid
};

void print_usage(char* progname) {
    fmt::print("Lists the contents of the assets archive for Rocket: Robot on Wheels\n");
    fmt::print("  Usage: {} [Rocket: Robot ROM or asset archive file]\n", progname);
}

template <size_t multiple>
uint32_t round_up(uint32_t value) 
{
    return ((value + multiple - 1) / multiple) * multiple;
}

bool is_rom_magic_number(uint32_t value) {
    // N64 ROMs always start with this same number
    return value == 0x80371240;
}

bool is_asset_archive_size(uint32_t value, std::streampos file_len) {
    // Asset archives start with a 32-bit value that corresponds to the length of the archive
    // Account for padding during extraction by rounding up
    return round_up<0x10>(value) == file_len;
}

template <typename T, typename std::enable_if_t<std::is_integral_v<T>>* = nullptr>
T read_big_endian(std::ifstream& input_file) {
    T ret;

    // Read the bytes from the file
    input_file.read(reinterpret_cast<char*>(&ret), sizeof(T));

    // Swap endianness
    return swap_endianness(ret);
}

// Overload for non integral types
template <typename T, typename std::enable_if_t<!std::is_integral_v<T>>* = nullptr>
T read_big_endian(std::ifstream& input_file) {
    T ret;

    // Read the bytes from the file
    input_file.read(reinterpret_cast<char*>(&ret), sizeof(T));

    // Call the swap_endianness method of the input type
    ret.swap_endianness();

    return ret;
}

// Overload for memory buffers instead of files
template <typename T, typename std::enable_if_t<std::is_integral_v<T>>* = nullptr>
T read_big_endian(const char* input_data, int& offset) {
    T ret;

    // Read the bytes from the file
    std::copy_n(input_data + offset, sizeof(T), reinterpret_cast<char*>(&ret));

    // Increment the offset position by the size read
    offset += sizeof(T);

    // Swap endianness
    return ::swap_endianness(ret);
}

// Overload for non integral types and memory buffers instead of files
template <typename T, typename std::enable_if_t<!std::is_integral_v<T>>* = nullptr>
T read_big_endian(const char* input_data, int& offset) {
    T ret;

    // Read the bytes from the file
    std::copy_n(input_data + offset, sizeof(T), reinterpret_cast<char*>(&ret));

    // Call the swap_endianness method of the input type
    ret.swap_endianness();

    // Increment the offset position by the size read
    offset += sizeof(T);

    return ret;
}

RocketFileType get_file_type(std::ifstream& input_file, std::streampos& file_len) {
    std::array<char, 4> header_buffer;
    uint32_t header_value;
    RocketFileType ret = RocketFileType::invalid;
    
    // Seek to the end of the file
    input_file.seekg(0, std::ios::end);
    
    // Get the length of the file
    file_len = input_file.tellg();
    
    // Rewind to the start of the file
    input_file.seekg(0, std::ios::beg);

    // Make sure the file is at least 4 bytes long
    if (file_len >= sizeof(uint32_t)) {
        // Read the first u32 in the file
        header_value = read_big_endian<uint32_t>(input_file);

        // Check the various conditions to identify if this is a ROM or asset archive
        if (is_rom_magic_number(header_value)) {
            ret = RocketFileType::ROM;
        } else if (is_asset_archive_size(header_value, file_len)) {
            ret = RocketFileType::archive;
        }

        input_file.seekg(0, std::ios::beg);
    }
    return ret;
}

struct Color {
    uint8_t red, green, blue;
};

class Assets {
public:
    std::vector<Color> flat_color_materials;
    std::vector<uint32_t> material_offsets;
};

struct OffsetTableHeader {
    uint32_t signature; // Not sure, always 0x121 and expected to be by the game code
    uint16_t D_800ADAD4;
    uint16_t D_800ADADC;
    uint16_t D_800ADACC;
    uint16_t num_images;
    uint32_t image_table_offset;

    void swap_endianness() {
        ::swap_endianness_inplace(signature);
        ::swap_endianness_inplace(D_800ADAD4);
        ::swap_endianness_inplace(D_800ADADC);
        ::swap_endianness_inplace(D_800ADACC);
        ::swap_endianness_inplace(num_images);
        ::swap_endianness_inplace(image_table_offset);
    }
};

void read_file_table(Assets& assets, const char* data, uint32_t length) {
    int pos = sizeof(uint32_t) * 2; // Skip file type and size
    OffsetTableHeader header = read_big_endian<OffsetTableHeader>(data, pos);

    fmt::print("  Offset Table:\n"
               "    Signature: 0x{:X}\n"
               "    Images: {} at 0x{:08X}\n",
        header.signature,
        header.num_images, header.image_table_offset);

    // Read material table
    fmt::print("    Materials: {}\n", header.D_800ADAD4);
    for (int material_idx = 0; material_idx < header.D_800ADAD4; material_idx++) {
        uint32_t curMaterialData = read_big_endian<uint32_t>(data, pos);
        if (curMaterialData & 0x80000000) {
            uint8_t red   = (curMaterialData >> 16) & 0xFF;
            uint8_t green = (curMaterialData >>  8) & 0xFF;
            uint8_t blue  = (curMaterialData >>  0) & 0xFF;
            assets.flat_color_materials.emplace_back(Color{red, green, blue});
            // fmt::print("      Flat Colored: {:02X} {:02X} {:02X}\n", red, green, blue);
        } else {
            assets.material_offsets.push_back(curMaterialData);
            // fmt::print("      At offset: 0x{:08X}\n", curMaterialData);
        }
    }

    // Read text table
    fmt::print("    Text Entries: {}\n", header.D_800ADADC);
    for (int text_idx = 0; text_idx < header.D_800ADADC; text_idx++) {
        uint16_t entry_id = read_big_endian<uint16_t>(data, pos);
        uint16_t length = read_big_endian<uint16_t>(data, pos);
        uint32_t offset = read_big_endian<uint32_t>(data, pos);
        // fmt::print("      id: {: >3d}, 0x{:04X} bytes at 0x{:08X}\n", entry_id, length, offset);
    }

    // Read model table
    fmt::print("    Models: {}\n", header.D_800ADACC);
    for (int i = 0; i < header.D_800ADACC; i++) {
        int32_t a = read_big_endian<int32_t>(data, pos);
        uint32_t b = read_big_endian<uint32_t>(data, pos);
        fmt::print("      {: >4d} at {:08X}\n", a, b);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_SUCCESS;
    }

    // Open the file that the user specified
    char* input_file_path = argv[1];
    std::ifstream input_file(input_file_path, std::ios::binary);

    // Check if the file was opened correctly
    if (!input_file.is_open()) {
        fmt::print(stderr, "Failed to open file {}\n", input_file_path);
        return EXIT_FAILURE;
    }

    // Determine the type and length of the input file
    std::streampos file_len;
    RocketFileType file_type = get_file_type(input_file, file_len);

    std::streampos archive_start_pos;

    switch (file_type) {
        case RocketFileType::ROM:
            archive_start_pos = ROM_CONTENT_START;
            fmt::print("{} is a ROM\n", input_file_path);
            break;
        case RocketFileType::archive:
            archive_start_pos = 0;
            fmt::print("{} is an asset archive\n", input_file_path);
            break;
        default:
            fmt::print(stderr, invalid_file_error, input_file_path);
            return EXIT_FAILURE;
    }

    input_file.seekg(archive_start_pos);
    uint32_t assets_length = read_big_endian<uint32_t>(input_file);

    std::vector<char> asset_archive_buffer(assets_length);
    input_file.read(asset_archive_buffer.data() + sizeof(uint32_t), assets_length);
    input_file.close();

    int cur_archive_offset = sizeof(uint32_t);

    Assets assets;

    while (cur_archive_offset < assets_length) {
        uint32_t cur_file_start_pos = cur_archive_offset;
        uint32_t cur_file_type = read_big_endian<uint32_t>(asset_archive_buffer.data(), cur_archive_offset);
        uint32_t cur_file_size = read_big_endian<uint32_t>(asset_archive_buffer.data(), cur_archive_offset);

        fmt::print("File type 0x{:X} of size 0x{:08X} at position 0x{:04X}\n", cur_file_type, cur_file_size, cur_file_start_pos);

        switch (cur_file_type) {
            case 0xC: // file table
                read_file_table(assets, asset_archive_buffer.data() + cur_file_start_pos, cur_file_size);
                break;
            case 0x1: // materials, images, and image table
                break;
            case 0x2: // text entries
                break;
            case 0x3:
                break;
        }

        cur_archive_offset = round_up<4>(cur_file_start_pos + cur_file_size);
    }
}
