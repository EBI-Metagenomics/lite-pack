#include "unpack.h"
#include "lite_pack.h"
#include "load.h"
#include "load_body.h"

unsigned lip_unpack_uint(uint8_t const buf[static 1])
{
    switch (lip_format(buf))
    {
    case LIP_FMT_POSITIVE_FIXINT:
        return __lip_load_num8_body(buf).u;
    case LIP_FMT_UINT_8:
        return __lip_load_num8_body(buf + 1).u;
    case LIP_FMT_UINT_16:
        return __lip_load_num16_body(buf + 1).u;
    case LIP_FMT_UINT_32:
        return __lip_load_num32_body(buf + 1).u;
    }
    __LIP_BUG();
}

unsigned long lip_unpack_ulong(uint8_t const buf[static 1])
{
    if (lip_format(buf) == LIP_FMT_UINT_64)
    {
        return __lip_load_num64_body(buf + 1).u;
    }
    return lip_unpack_uint(buf);
}

int lip_unpack_int(uint8_t const buf[static 1])
{
    switch (lip_format(buf))
    {
    case LIP_FMT_POSITIVE_FIXINT:
    case LIP_FMT_UINT_8:
    case LIP_FMT_UINT_16:
    case LIP_FMT_UINT_32:
        return (int)lip_unpack_uint(buf);

    case LIP_FMT_NEGATIVE_FIXINT:
        return __lip_load_num8_body(buf).i;

    case LIP_FMT_INT_8:
        return __lip_load_num8_body(buf + 1).i;

    case LIP_FMT_INT_16:
        return __lip_load_num16_body(buf + 1).i;

    case LIP_FMT_INT_32:
        return __lip_load_num32_body(buf + 1).i;
    }
    __LIP_BUG();
}

long lip_unpack_long(uint8_t const buf[static 1])
{
    if (lip_format(buf) == LIP_FMT_UINT_64 || lip_format(buf) == LIP_FMT_INT_64)
    {
        return __lip_load_num64_body(buf + 1).i;
    }
    return lip_unpack_int(buf);
}

char *lip_unpack_str(uint8_t const buf[static 1], char str[static 1])
{
    switch (lip_format(buf))
    {
    case LIP_FMT_FIXSTR:
        return __lip_load_fix_str(buf, str);
    case LIP_FMT_STR_8:
        return __lip_load_str8(buf, str);
    case LIP_FMT_STR_16:
        return __lip_load_str16(buf, str);
    case LIP_FMT_STR_32:
        return __lip_load_str32(buf, str);
    }
    __LIP_BUG();
    return 0;
}

unsigned lip_unpack_str_head(uint8_t const buf[static 1])
{
    switch (lip_format(buf))
    {
    case LIP_FMT_FIXSTR:
        return __lip_fix_str_length(buf);
    case LIP_FMT_STR_8:
        return __lip_str8_length(buf);
    case LIP_FMT_STR_16:
        return __lip_str16_length(buf);
    case LIP_FMT_STR_32:
        return __lip_str32_length(buf);
    }
    return 0;
}

char *lip_unpack_str_body(uint8_t const buf[static 1], unsigned length,
                          char str[static 1])
{
    return __lip_load_str_body(buf, length, str);
}

unsigned lip_unpack_map_head(uint8_t const buf[static 1])
{
    switch (lip_format(buf))
    {
    case LIP_FMT_FIXMAP:
        return (unsigned)__lip_format_fix_value(buf[0]);
    case LIP_FMT_MAP_16:
        return __lip_load_num16_body(buf + 1).u;
    case LIP_FMT_MAP_32:
        return __lip_load_num32_body(buf + 1).u;
    }
    return 0;
}
