#ifndef LIP_FORMAT_H
#define LIP_FORMAT_H

#include "lip/compiler.h"
#include "lip/export.h"
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
    LIP_FMT_FAMILY_NEVER_USED,
};

LIP_API enum lip_format lip_format(int first_byte);
LIP_API enum lip_format_family lip_format_family(enum lip_format fmt);

LIP_API char const *lip_format_string(enum lip_format fmt);
LIP_API char const *lip_format_family_string(enum lip_format_family family);

#endif
