#ifndef FORMAT_H
#define FORMAT_H

#include "compiler.h"
#include "number.h"
#include <stdint.h>

enum lip_format
{
    LIP_FMT_POSITIVE_FIXINT,
    LIP_FMT_FIXMAP,
    LIP_FMT_FIXARRAY,
    LIP_FMT_FIXSTR,
    LIP_FMT_NIL,
    LIP_FMT_NEVER_USED,
    LIP_FMT_FALSE,
    LIP_FMT_TRUE,
    LIP_FMT_BIN_8,
    LIP_FMT_BIN_16,
    LIP_FMT_BIN_32,
    LIP_FMT_EXT_8,
    LIP_FMT_EXT_16,
    LIP_FMT_EXT_32,
    LIP_FMT_FLOAT_32,
    LIP_FMT_FLOAT_64,
    LIP_FMT_UINT_8,
    LIP_FMT_UINT_16,
    LIP_FMT_UINT_32,
    LIP_FMT_UINT_64,
    LIP_FMT_INT_8,
    LIP_FMT_INT_16,
    LIP_FMT_INT_32,
    LIP_FMT_INT_64,
    LIP_FMT_FIXEXT_1,
    LIP_FMT_FIXEXT_2,
    LIP_FMT_FIXEXT_4,
    LIP_FMT_FIXEXT_8,
    LIP_FMT_FIXEXT_16,
    LIP_FMT_STR_8,
    LIP_FMT_STR_16,
    LIP_FMT_STR_32,
    LIP_FMT_ARRAY_16,
    LIP_FMT_ARRAY_32,
    LIP_FMT_MAP_16,
    LIP_FMT_MAP_32,
    LIP_FMT_NEGATIVE_FIXINT,
};

enum lip_format_family
{
    LIP_FMT_FAMILY_NIL,
    LIP_FMT_FAMILY_BOOL,
    LIP_FMT_FAMILY_INT,
    LIP_FMT_FAMILY_FLOAT,
    LIP_FMT_FAMILY_STR,
    LIP_FMT_FAMILY_BIN,
    LIP_FMT_FAMILY_ARRAY,
    LIP_FMT_FAMILY_MAP,
    LIP_FMT_FAMILY_EXT,
};

extern int const __lip_format_family_map[];

static inline int __lip_format_family(int first_byte)
{
    return __lip_format_family_map[first_byte];
}

int __lip_format(int first_byte);

static inline int lip_format(uint8_t const buf[])
{
    return __lip_format(buf[0]);
}

static inline int lip_format_family(uint8_t const buf[])
{
    return __lip_format_family(buf[0]);
}

static inline int __lip_format_fix_value(uint8_t first_byte)
{
    int format = __lip_format(first_byte);
    switch (format)
    {
    case LIP_FMT_POSITIVE_FIXINT:
        return (int)first_byte;
    case LIP_FMT_FIXMAP:
        return (int)(~0x80 & first_byte);
    case LIP_FMT_FIXARRAY:
        return (int)(~0x90 & first_byte);
    case LIP_FMT_FIXSTR:
        return (int)(~0xa0 & first_byte);
    case LIP_FMT_NEGATIVE_FIXINT:
        return __LIP_NUM8(first_byte).i;
    }
    return 0;
}

static inline unsigned __lip_format_fix_pvalue(union __lip_num8 first_byte)
{
    int format = __lip_format(first_byte.i);
    switch (format)
    {
    case LIP_FMT_POSITIVE_FIXINT:
        return (~0x00U & first_byte.u);
    case LIP_FMT_FIXMAP:
        return (~0x80U & first_byte.u);
    case LIP_FMT_FIXARRAY:
        return (~0x90U & first_byte.u);
    case LIP_FMT_FIXSTR:
        return (~0xa0U & first_byte.u);
    }
    return 0U;
}

static inline int __lip_format_fix_nvalue(union __lip_num8 first_byte)
{
    int format = __lip_format(first_byte.i);
    switch (format)
    {
    case LIP_FMT_NEGATIVE_FIXINT:
        return (int)(~0xe0U & first_byte.u);
    }
    return 0;
}

#endif
