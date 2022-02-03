#include "unpack.h"
#include "lite_pack.h"

float __lip_unpack_f32_data(uint8_t const buf[static 4])
{
    union
    {
        float f;
        uint32_t u;
    } v;
    v.u = host_endian(*((uint32_t *)buf));
    return v.f;
}

double __lip_unpack_f64_data(uint8_t const buf[static 8])
{
    union
    {
        double f;
        uint64_t u;
    } v;
    v.u = host_endian(*((uint64_t *)buf));
    return v.f;
}

unsigned lip_unpack_uint(uint8_t const buf[static 1])
{
    if (lip_format(buf) == LIP_FMT_POSITIVE_FIXINT)
    {
        return __lip_unpack_fix_uint(buf);
    }
    else if (lip_format(buf) == LIP_FMT_UINT_8)
    {
        return __lip_unpack_u8(buf + 1);
    }
    else if (lip_format(buf) == LIP_FMT_UINT_16)
    {
        return __lip_unpack_u16(buf + 1);
    }
    else if (lip_format(buf) == LIP_FMT_UINT_32)
    {
        return __lip_unpack_u32(buf + 1);
    }
    __LIP_BUG();
}

unsigned long lip_unpack_ulong(uint8_t const buf[static 1])
{
    if (lip_format(buf) == LIP_FMT_POSITIVE_FIXINT)
    {
        return __lip_unpack_fix_uint(buf);
    }
    else if (lip_format(buf) == LIP_FMT_UINT_8)
    {
        return __lip_unpack_u8(buf + 1);
    }
    else if (lip_format(buf) == LIP_FMT_UINT_16)
    {
        return __lip_unpack_u16(buf + 1);
    }
    else if (lip_format(buf) == LIP_FMT_UINT_32)
    {
        return __lip_unpack_u32(buf + 1);
    }
    else if (lip_format(buf) == LIP_FMT_UINT_64)
    {
        return __lip_unpack_u64(buf + 1);
    }
    __LIP_BUG();
}

char *lip_unpack_str(uint8_t const buf[static 1], char str[static 1])
{
    if (lip_format(buf) == LIP_FMT_FIXSTR)
    {
        __lip_unpack_fix_str(buf, str);
    }
    else if (lip_format(buf) == LIP_FMT_STR_8)
    {
        __lip_unpack_str8(buf + 1, str);
    }
    else if (lip_format(buf) == LIP_FMT_STR_16)
    {
        __lip_unpack_str16(buf + 1, str);
    }
    else if (lip_format(buf) == LIP_FMT_STR_32)
    {
        __lip_unpack_str32(buf + 1, str);
    }
    return str;
}

unsigned lip_unpack_map_length(uint8_t buf[static 1])
{
    if (lip_format(buf) == LIP_FMT_FIXMAP)
    {
        return (unsigned)__lip_format_fix_value(buf[0]);
    }
    else if (lip_format(buf) == LIP_FMT_MAP_16)
    {
        return __lip_unpack_u16(buf + 1);
    }
    else if (lip_format(buf) == LIP_FMT_MAP_32)
    {
        return __lip_unpack_u32(buf + 1);
    }
    __LIP_BUG();
}
