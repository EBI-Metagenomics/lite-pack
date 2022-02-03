#ifndef FORMAT_H
#define FORMAT_H

#include "bug.h"
#include <stdint.h>

enum lip_format
{
    FMT_POSITIVE_FIXINT,
    FMT_FIXMAP,
    FMT_FIXARRAY,
    FMT_FIXSTR,
    FMT_NIL,
    FMT_NEVER_USED,
    FMT_FALSE,
    FMT_TRUE,
    FMT_BIN_8,
    FMT_BIN_16,
    FMT_BIN_32,
    FMT_EXT_8,
    FMT_EXT_16,
    FMT_EXT_32,
    FMT_FLOAT_32,
    FMT_FLOAT_64,
    FMT_UINT_8,
    FMT_UINT_16,
    FMT_UINT_32,
    FMT_UINT_64,
    FMT_INT_8,
    FMT_INT_16,
    FMT_INT_32,
    FMT_INT_64,
    FMT_FIXEXT_1,
    FMT_FIXEXT_2,
    FMT_FIXEXT_4,
    FMT_FIXEXT_8,
    FMT_FIXEXT_16,
    FMT_STR_8,
    FMT_STR_16,
    FMT_STR_32,
    FMT_ARRAY_16,
    FMT_ARRAY_32,
    FMT_MAP_16,
    FMT_MAP_32,
    FMT_NEGATIVE_FIXINT,
    FMT_SENTINEL,
};

enum lip_format_family
{
    FMT_FAMILY_NIL,
    FMT_FAMILY_BOOL,
    FMT_FAMILY_INT,
    FMT_FAMILY_FLOAT,
    FMT_FAMILY_STR,
    FMT_FAMILY_BIN,
    FMT_FAMILY_ARRAY,
    FMT_FAMILY_MAP,
    FMT_FAMILY_EXT,
    FMT_FAMILY_SENTINEL,
};

extern int const __lip_format_family_map[];

static inline int __lip_format_family(int first_byte)
{
    return __lip_format_family_map[first_byte];
}

int __lip_format(int first_byte);

static inline int lip_format(uint8_t const buf[static 1])
{
    return __lip_format(buf[0]);
}

static inline int lip_format_family(uint8_t const buf[static 1])
{
    return __lip_format_family(buf[0]);
}

static inline int __lip_format_fix_value(uint8_t first_byte)
{
    int format = __lip_format(first_byte);
    switch (format)
    {
    case FMT_POSITIVE_FIXINT:
        return ~0x00 & first_byte;
    case FMT_FIXMAP:
        return ~0x80 & first_byte;
    case FMT_FIXARRAY:
        return ~0x90 & first_byte;
    case FMT_FIXSTR:
        return ~0xa0 & first_byte;
    case FMT_NEGATIVE_FIXINT:
        return ~0xe0 & first_byte;
    }
    __LIP_BUG();
}

#endif
