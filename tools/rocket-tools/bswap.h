#ifndef __BSWAP_HPP__
#define __BSWAP_HPP__

#include <cstdint>
#include <cstring>
#include <bit>

// Wrapper for various compiler's byteswap intrinsics
inline uint32_t bswap32(uint32_t in) noexcept
{
#ifdef _MSC_VER
    return _byteswap_ulong(in);
#else
    return __builtin_bswap32(in);
#endif
}

inline uint16_t bswap16(uint16_t in) noexcept
{
#ifdef _MSC_VER
    return _byteswap_ushort(in);
#else
    return __builtin_bswap16(in);
#endif
}

// Swaps between N64 endianness and host endianness
inline uint32_t swap_endianness(uint32_t in) noexcept
{
    if constexpr (std::endian::native == std::endian::big)
    {
        return in;
    }
    else
    {
        return bswap32(in);
    }
}

inline int32_t swap_endianness(int32_t in) noexcept
{
    if constexpr (std::endian::native == std::endian::big)
    {
        return in;
    }
    else
    {
        return bswap32(in);
    }
}

inline float swap_endianness(float in) noexcept
{
    if constexpr (std::endian::native == std::endian::big)
    {
        return in;
    }
    else
    {
        uint32_t in_bytes;
        float ret;
        memcpy(&in_bytes, &in, sizeof(float));
        in_bytes = bswap32(in_bytes);
        memcpy(&ret, &in_bytes, sizeof(float));
        return ret;
    }
}

inline uint16_t swap_endianness(uint16_t in) noexcept
{
    if constexpr (std::endian::native == std::endian::big)
    {
        return in;
    }
    else
    {
        return bswap16(in);
    }
}

inline int16_t swap_endianness(int16_t in) noexcept
{
    if constexpr (std::endian::native == std::endian::big)
    {
        return in;
    }
    else
    {
        return bswap16(in);
    }
}

inline int8_t swap_endianness(int8_t in) noexcept
{
    return in;
}

inline uint8_t swap_endianness(uint8_t in) noexcept
{
    return in;
}

template <typename T>
inline void swap_endianness_inplace(T& in) noexcept
{
    in = ::swap_endianness(in);
}

#endif
