#include "unpack.h"
#include "lite_pack.h"
#include "load.h"

unsigned lip_unpack_uint(uint8_t const buf[static 1])
{
    if (lip_format(buf) == LIP_FMT_POSITIVE_FIXINT)
    {
        return __lip_load_pfix_int(buf);
    }
    else if (lip_format(buf) == LIP_FMT_UINT_8)
    {
        return __lip_load_u8(buf);
    }
    else if (lip_format(buf) == LIP_FMT_UINT_16)
    {
        return __lip_load_u16(buf);
    }
    else if (lip_format(buf) == LIP_FMT_UINT_32)
    {
        return __lip_load_u32(buf);
    }
    __LIP_BUG();
}

unsigned long lip_unpack_ulong(uint8_t const buf[static 1])
{
    if (lip_format(buf) == LIP_FMT_POSITIVE_FIXINT)
    {
        return __lip_load_pfix_int(buf);
    }
    else if (lip_format(buf) == LIP_FMT_UINT_8)
    {
        return __lip_load_u8(buf);
    }
    else if (lip_format(buf) == LIP_FMT_UINT_16)
    {
        return __lip_load_u16(buf);
    }
    else if (lip_format(buf) == LIP_FMT_UINT_32)
    {
        return __lip_load_u32(buf);
    }
    else if (lip_format(buf) == LIP_FMT_UINT_64)
    {
        return __lip_load_u64(buf);
    }
    __LIP_BUG();
}

char *lip_unpack_str(uint8_t const buf[static 1], char str[static 1])
{
    if (lip_format(buf) == LIP_FMT_FIXSTR)
    {
        __lip_load_fix_str(buf, str);
    }
    else if (lip_format(buf) == LIP_FMT_STR_8)
    {
        __lip_load_str8(buf, str);
    }
    else if (lip_format(buf) == LIP_FMT_STR_16)
    {
        __lip_load_str16(buf, str);
    }
    else if (lip_format(buf) == LIP_FMT_STR_32)
    {
        __lip_load_str32(buf, str);
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
        return __lip_load_u16(buf);
    }
    else if (lip_format(buf) == LIP_FMT_MAP_32)
    {
        return __lip_load_u32(buf);
    }
    __LIP_BUG();
}
