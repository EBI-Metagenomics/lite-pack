#include "lite_pack/format.h"
#include "format.h"
#include "number.h"
#include <assert.h>
#include <limits.h>
#include <stdlib.h>

char const __lip_format_string[][24] = {
    [LIP_FMT_POSITIVE_FIXINT] = "LIP_FMT_POSITIVE_FIXINT",
    [LIP_FMT_FIXMAP] = "LIP_FMT_FIXMAP",
    [LIP_FMT_FIXARRAY] = "LIP_FMT_FIXARRAY",
    [LIP_FMT_FIXSTR] = "LIP_FMT_FIXSTR",
    [LIP_FMT_NIL] = "LIP_FMT_NIL",
    [LIP_FMT_NEVER_USED] = "LIP_FMT_NEVER_USED",
    [LIP_FMT_FALSE] = "LIP_FMT_FALSE",
    [LIP_FMT_TRUE] = "LIP_FMT_TRUE",
    [LIP_FMT_BIN_8] = "LIP_FMT_BIN_8",
    [LIP_FMT_BIN_16] = "LIP_FMT_BIN_16",
    [LIP_FMT_BIN_32] = "LIP_FMT_BIN_32",
    [LIP_FMT_EXT_8] = "LIP_FMT_EXT_8",
    [LIP_FMT_EXT_16] = "LIP_FMT_EXT_16",
    [LIP_FMT_EXT_32] = "LIP_FMT_EXT_32",
    [LIP_FMT_FLOAT_32] = "LIP_FMT_FLOAT_32",
    [LIP_FMT_FLOAT_64] = "LIP_FMT_FLOAT_64",
    [LIP_FMT_UINT_8] = "LIP_FMT_UINT_8",
    [LIP_FMT_UINT_16] = "LIP_FMT_UINT_16",
    [LIP_FMT_UINT_32] = "LIP_FMT_UINT_32",
    [LIP_FMT_UINT_64] = "LIP_FMT_UINT_64",
    [LIP_FMT_INT_8] = "LIP_FMT_INT_8",
    [LIP_FMT_INT_16] = "LIP_FMT_INT_16",
    [LIP_FMT_INT_32] = "LIP_FMT_INT_32",
    [LIP_FMT_INT_64] = "LIP_FMT_INT_64",
    [LIP_FMT_FIXEXT_1] = "LIP_FMT_FIXEXT_1",
    [LIP_FMT_FIXEXT_2] = "LIP_FMT_FIXEXT_2",
    [LIP_FMT_FIXEXT_4] = "LIP_FMT_FIXEXT_4",
    [LIP_FMT_FIXEXT_8] = "LIP_FMT_FIXEXT_8",
    [LIP_FMT_FIXEXT_16] = "LIP_FMT_FIXEXT_16",
    [LIP_FMT_STR_8] = "LIP_FMT_STR_8",
    [LIP_FMT_STR_16] = "LIP_FMT_STR_16",
    [LIP_FMT_STR_32] = "LIP_FMT_STR_32",
    [LIP_FMT_ARRAY_16] = "LIP_FMT_ARRAY_16",
    [LIP_FMT_ARRAY_32] = "LIP_FMT_ARRAY_32",
    [LIP_FMT_MAP_16] = "LIP_FMT_MAP_16",
    [LIP_FMT_MAP_32] = "LIP_FMT_MAP_32",
    [LIP_FMT_NEGATIVE_FIXINT] = "LIP_FMT_NEGATIVE_FIXINT",
};

char const *lip_format_string(enum lip_format fmt)
{
    return __lip_format_string[fmt];
}

enum lip_format_family const __lip_format_family_map[] = {
    [LIP_FMT_POSITIVE_FIXINT] = LIP_FMT_FAMILY_INT,
    [LIP_FMT_FIXMAP] = LIP_FMT_FAMILY_MAP,
    [LIP_FMT_FIXARRAY] = LIP_FMT_FAMILY_ARRAY,
    [LIP_FMT_FIXSTR] = LIP_FMT_FAMILY_STR,
    [LIP_FMT_NIL] = LIP_FMT_FAMILY_NIL,
    [LIP_FMT_NEVER_USED] = LIP_FMT_FAMILY_NEVER_USED,
    [LIP_FMT_FALSE] = LIP_FMT_FAMILY_BOOL,
    [LIP_FMT_TRUE] = LIP_FMT_FAMILY_BOOL,
    [LIP_FMT_BIN_8] = LIP_FMT_FAMILY_BIN,
    [LIP_FMT_BIN_16] = LIP_FMT_FAMILY_BIN,
    [LIP_FMT_BIN_32] = LIP_FMT_FAMILY_BIN,
    [LIP_FMT_EXT_8] = LIP_FMT_FAMILY_EXT,
    [LIP_FMT_EXT_16] = LIP_FMT_FAMILY_EXT,
    [LIP_FMT_EXT_32] = LIP_FMT_FAMILY_EXT,
    [LIP_FMT_FLOAT_32] = LIP_FMT_FAMILY_FLOAT,
    [LIP_FMT_FLOAT_64] = LIP_FMT_FAMILY_FLOAT,
    [LIP_FMT_UINT_8] = LIP_FMT_FAMILY_INT,
    [LIP_FMT_UINT_16] = LIP_FMT_FAMILY_INT,
    [LIP_FMT_UINT_32] = LIP_FMT_FAMILY_INT,
    [LIP_FMT_UINT_64] = LIP_FMT_FAMILY_INT,
    [LIP_FMT_INT_8] = LIP_FMT_FAMILY_INT,
    [LIP_FMT_INT_16] = LIP_FMT_FAMILY_INT,
    [LIP_FMT_INT_32] = LIP_FMT_FAMILY_INT,
    [LIP_FMT_INT_64] = LIP_FMT_FAMILY_INT,
    [LIP_FMT_FIXEXT_1] = LIP_FMT_FAMILY_EXT,
    [LIP_FMT_FIXEXT_2] = LIP_FMT_FAMILY_EXT,
    [LIP_FMT_FIXEXT_4] = LIP_FMT_FAMILY_EXT,
    [LIP_FMT_FIXEXT_8] = LIP_FMT_FAMILY_EXT,
    [LIP_FMT_FIXEXT_16] = LIP_FMT_FAMILY_EXT,
    [LIP_FMT_STR_8] = LIP_FMT_FAMILY_STR,
    [LIP_FMT_STR_16] = LIP_FMT_FAMILY_STR,
    [LIP_FMT_STR_32] = LIP_FMT_FAMILY_STR,
    [LIP_FMT_ARRAY_16] = LIP_FMT_FAMILY_ARRAY,
    [LIP_FMT_ARRAY_32] = LIP_FMT_FAMILY_ARRAY,
    [LIP_FMT_MAP_16] = LIP_FMT_FAMILY_MAP,
    [LIP_FMT_MAP_32] = LIP_FMT_FAMILY_MAP,
    [LIP_FMT_NEGATIVE_FIXINT] = LIP_FMT_FAMILY_INT,
};

char const __lip_format_family_string[][26] = {
    [LIP_FMT_FAMILY_NIL] = "LIP_FMT_FAMILY_NIL",
    [LIP_FMT_FAMILY_BOOL] = "LIP_FMT_FAMILY_BOOL",
    [LIP_FMT_FAMILY_INT] = "LIP_FMT_FAMILY_INT",
    [LIP_FMT_FAMILY_FLOAT] = "LIP_FMT_FAMILY_FLOAT",
    [LIP_FMT_FAMILY_STR] = "LIP_FMT_FAMILY_STR",
    [LIP_FMT_FAMILY_BIN] = "LIP_FMT_FAMILY_BIN",
    [LIP_FMT_FAMILY_ARRAY] = "LIP_FMT_FAMILY_ARRAY",
    [LIP_FMT_FAMILY_MAP] = "LIP_FMT_FAMILY_MAP",
    [LIP_FMT_FAMILY_EXT] = "LIP_FMT_FAMILY_EXT",
    [LIP_FMT_FAMILY_NEVER_USED] = "LIP_FMT_FAMILY_NEVER_USED",
};

enum lip_format_family lip_format_family(enum lip_format fmt)
{
    return __lip_format_family_map[fmt];
}

char const *lip_format_family_string(enum lip_format_family family)
{
    return __lip_format_family_string[family];
}

enum lip_format lip_format(int first_byte)
{
    switch (first_byte)
    {
    case 0x00 ... 0x7f:
        return LIP_FMT_POSITIVE_FIXINT;

    case 0xe0 ... 0xff:
        return LIP_FMT_NEGATIVE_FIXINT;

    case 0x80 ... 0x8f:
        return LIP_FMT_FIXMAP;

    case 0x90 ... 0x9f:
        return LIP_FMT_FIXARRAY;

    case 0xa0 ... 0xbf:
        return LIP_FMT_FIXSTR;

    case 0xc0:
        return LIP_FMT_NIL;

    case 0xc1:
        return LIP_FMT_NEVER_USED;

    case 0xc2:
        return LIP_FMT_FALSE;

    case 0xc3:
        return LIP_FMT_TRUE;

    case 0xc4:
        return LIP_FMT_BIN_8;

    case 0xc5:
        return LIP_FMT_BIN_16;

    case 0xc6:
        return LIP_FMT_BIN_32;

    case 0xc7:
        return LIP_FMT_EXT_8;

    case 0xc8:
        return LIP_FMT_EXT_16;

    case 0xc9:
        return LIP_FMT_EXT_32;

    case 0xca:
        return LIP_FMT_FLOAT_32;

    case 0xcb:
        return LIP_FMT_FLOAT_64;

    case 0xcc:
        return LIP_FMT_UINT_8;

    case 0xcd:
        return LIP_FMT_UINT_16;

    case 0xce:
        return LIP_FMT_UINT_32;

    case 0xcf:
        return LIP_FMT_UINT_64;

    case 0xd0:
        return LIP_FMT_INT_8;

    case 0xd1:
        return LIP_FMT_INT_16;

    case 0xd2:
        return LIP_FMT_INT_32;

    case 0xd3:
        return LIP_FMT_INT_64;

    case 0xd4:
        return LIP_FMT_FIXEXT_1;

    case 0xd5:
        return LIP_FMT_FIXEXT_2;

    case 0xd6:
        return LIP_FMT_FIXEXT_4;

    case 0xd7:
        return LIP_FMT_FIXEXT_8;

    case 0xd8:
        return LIP_FMT_FIXEXT_16;

    case 0xd9:
        return LIP_FMT_STR_8;

    case 0xda:
        return LIP_FMT_STR_16;

    case 0xdb:
        return LIP_FMT_STR_32;

    case 0xdc:
        return LIP_FMT_ARRAY_16;

    case 0xdd:
        return LIP_FMT_ARRAY_32;

    case 0xde:
        return LIP_FMT_MAP_16;

    case 0xdf:
        return LIP_FMT_MAP_32;
    }
    __builtin_unreachable();
}

int __lip_format_fix_value(unsigned char first_byte)
{
    enum lip_format format = lip_format(first_byte);
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
    default:
        return 0;
    }
}
