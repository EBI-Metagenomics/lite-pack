#include "first_byte.h"

uint8_t __lip_first_byte(enum lip_format format)
{
    switch (format)
    {
    case LIP_FMT_NIL:
        return 0xc0;
    case LIP_FMT_NEVER_USED:
        return 0xc1;
    case LIP_FMT_FALSE:
        return 0xc2;
    case LIP_FMT_TRUE:
        return 0xc3;
    case LIP_FMT_BIN_8:
        return 0xc4;
    case LIP_FMT_BIN_16:
        return 0xc5;
    case LIP_FMT_BIN_32:
        return 0xc6;
    case LIP_FMT_EXT_8:
        return 0xc7;
    case LIP_FMT_EXT_16:
        return 0xc8;
    case LIP_FMT_EXT_32:
        return 0xc9;
    case LIP_FMT_FLOAT_32:
        return 0xca;
    case LIP_FMT_FLOAT_64:
        return 0xcb;
    case LIP_FMT_UINT_8:
        return 0xcc;
    case LIP_FMT_UINT_16:
        return 0xcd;
    case LIP_FMT_UINT_32:
        return 0xce;
    case LIP_FMT_UINT_64:
        return 0xcf;
    case LIP_FMT_INT_8:
        return 0xd0;
    case LIP_FMT_INT_16:
        return 0xd1;
    case LIP_FMT_INT_32:
        return 0xd2;
    case LIP_FMT_INT_64:
        return 0xd3;
    case LIP_FMT_FIXEXT_1:
        return 0xd4;
    case LIP_FMT_FIXEXT_2:
        return 0xd5;
    case LIP_FMT_FIXEXT_4:
        return 0xd6;
    case LIP_FMT_FIXEXT_8:
        return 0xd7;
    case LIP_FMT_FIXEXT_16:
        return 0xd8;
    case LIP_FMT_STR_8:
        return 0xd9;
    case LIP_FMT_STR_16:
        return 0xda;
    case LIP_FMT_STR_32:
        return 0xdb;
    case LIP_FMT_ARRAY_16:
        return 0xdc;
    case LIP_FMT_ARRAY_32:
        return 0xdd;
    case LIP_FMT_MAP_16:
        return 0xde;
    case LIP_FMT_MAP_32:
        return 0xdf;
    default:
        return 0;
    }
    return 0;
}

uint8_t __lip_first_byte_fix(enum lip_format format, int val)
{
    switch (format)
    {
    case LIP_FMT_POSITIVE_FIXINT:
        return (uint8_t)__LIP_NUM(0x00 | val).u;
    case LIP_FMT_FIXMAP:
        return (uint8_t)__LIP_NUM(0x80 | val).u;
    case LIP_FMT_FIXARRAY:
        return (uint8_t)__LIP_NUM(0x90 | val).u;
    case LIP_FMT_FIXSTR:
        return (uint8_t)__LIP_NUM(0xa0 | val).u;
    case LIP_FMT_NEGATIVE_FIXINT:
        return __LIP_NUM8((int8_t)__LIP_NUM(0xe0 | val).i).u;
    default:
        return 0;
    }
}
