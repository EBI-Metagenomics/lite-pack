#ifndef SIZE_H
#define SIZE_H

#include "bug.h"
#include "format.h"
#include "map.h"
#include "str.h"

static inline unsigned long __lip_size_static(uint8_t const buf[static 1])
{
    int format = __lip_format(buf[0]);
    switch (format)
    {
    case LIP_FMT_POSITIVE_FIXINT:
        return 1;
    case LIP_FMT_NIL:
        return 1;
    case LIP_FMT_NEVER_USED:
        return 0;
    case LIP_FMT_FALSE:
        return 1;
    case LIP_FMT_TRUE:
        return 1;
    case LIP_FMT_EXT_8:
        return 0;
    case LIP_FMT_EXT_16:
        return 0;
    case LIP_FMT_EXT_32:
        return 0;
    case LIP_FMT_FLOAT_32:
        return 5;
    case LIP_FMT_FLOAT_64:
        return 9;
    case LIP_FMT_UINT_8:
        return 2;
    case LIP_FMT_UINT_16:
        return 3;
    case LIP_FMT_UINT_32:
        return 5;
    case LIP_FMT_UINT_64:
        return 9;
    case LIP_FMT_INT_8:
        return 2;
    case LIP_FMT_INT_16:
        return 3;
    case LIP_FMT_INT_32:
        return 5;
    case LIP_FMT_INT_64:
        return 9;
    case LIP_FMT_FIXEXT_1:
        return 0;
    case LIP_FMT_FIXEXT_2:
        return 0;
    case LIP_FMT_FIXEXT_4:
        return 0;
    case LIP_FMT_FIXEXT_8:
        return 0;
    case LIP_FMT_FIXEXT_16:
        return 0;
    case LIP_FMT_NEGATIVE_FIXINT:
        return 1;
    }
    return 0;
}

static inline unsigned long __lip_size_dynamic(uint8_t const buf[static 1])
{
    int format = __lip_format(buf[0]);
    switch (format)
    {
    case LIP_FMT_FIXMAP:
        return 1;
    case LIP_FMT_FIXARRAY:
        return 0;
    case LIP_FMT_FIXSTR:
        return 1 + __lip_fix_str_length(buf);
    case LIP_FMT_BIN_8:
        return 0;
    case LIP_FMT_BIN_16:
        return 0;
    case LIP_FMT_BIN_32:
        return 0;
    case LIP_FMT_STR_8:
        return 2 + __lip_str8_length(buf);
    case LIP_FMT_STR_16:
        return 3 + __lip_str16_length(buf);
    case LIP_FMT_STR_32:
        return 5 + __lip_str32_length(buf);
    case LIP_FMT_ARRAY_16:
        return 0;
    case LIP_FMT_ARRAY_32:
        return 0;
    case LIP_FMT_MAP_16:
        return 3;
    case LIP_FMT_MAP_32:
        return 5;
    }
    return 0;
}

#endif
