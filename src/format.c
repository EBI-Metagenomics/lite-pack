#include "format.h"
#include <assert.h>
#include <limits.h>
#include <stdlib.h>

int const format_family_map[] = {
    [FMT_POSITIVE_FIXINT] = FMT_FAMILY_INT,
    [FMT_FIXMAP] = FMT_FAMILY_MAP,
    [FMT_FIXARRAY] = FMT_FAMILY_ARRAY,
    [FMT_FIXSTR] = FMT_FAMILY_STR,
    [FMT_NIL] = FMT_FAMILY_NIL,
    [FMT_NEVER_USED] = FMT_FAMILY_SENTINEL,
    [FMT_FALSE] = FMT_FAMILY_BOOL,
    [FMT_TRUE] = FMT_FAMILY_BOOL,
    [FMT_BIN_8] = FMT_FAMILY_BIN,
    [FMT_BIN_16] = FMT_FAMILY_BIN,
    [FMT_BIN_32] = FMT_FAMILY_BIN,
    [FMT_EXT_8] = FMT_FAMILY_EXT,
    [FMT_EXT_16] = FMT_FAMILY_EXT,
    [FMT_EXT_32] = FMT_FAMILY_EXT,
    [FMT_FLOAT_32] = FMT_FAMILY_FLOAT,
    [FMT_FLOAT_64] = FMT_FAMILY_FLOAT,
    [FMT_UINT_8] = FMT_FAMILY_INT,
    [FMT_UINT_16] = FMT_FAMILY_INT,
    [FMT_UINT_32] = FMT_FAMILY_INT,
    [FMT_UINT_64] = FMT_FAMILY_INT,
    [FMT_INT_8] = FMT_FAMILY_INT,
    [FMT_INT_16] = FMT_FAMILY_INT,
    [FMT_INT_32] = FMT_FAMILY_INT,
    [FMT_INT_64] = FMT_FAMILY_INT,
    [FMT_FIXEXT_1] = FMT_FAMILY_EXT,
    [FMT_FIXEXT_2] = FMT_FAMILY_EXT,
    [FMT_FIXEXT_4] = FMT_FAMILY_EXT,
    [FMT_FIXEXT_8] = FMT_FAMILY_EXT,
    [FMT_FIXEXT_16] = FMT_FAMILY_EXT,
    [FMT_STR_8] = FMT_FAMILY_STR,
    [FMT_STR_16] = FMT_FAMILY_STR,
    [FMT_STR_32] = FMT_FAMILY_STR,
    [FMT_ARRAY_16] = FMT_FAMILY_ARRAY,
    [FMT_ARRAY_32] = FMT_FAMILY_ARRAY,
    [FMT_MAP_16] = FMT_FAMILY_MAP,
    [FMT_MAP_32] = FMT_FAMILY_MAP,
    [FMT_NEGATIVE_FIXINT] = FMT_FAMILY_INT,
};

int format_parse(uint8_t first_byte)
{
    switch (first_byte)
    {
    case 0x00 ... 0x7f:
        return FMT_POSITIVE_FIXINT;

    case 0xe0 ... 0xff:
        return FMT_NEGATIVE_FIXINT;

    case 0x80 ... 0x8f:
        return FMT_FIXMAP;

    case 0x90 ... 0x9f:
        return FMT_FIXARRAY;

    case 0xa0 ... 0xbf:
        return FMT_FIXSTR;

    case 0xc0:
        return FMT_NIL;

    case 0xc2:
        return FMT_TRUE;

    case 0xc3:
        return FMT_FALSE;

    case 0xc4:
        return FMT_BIN_8;

    case 0xc5:
        return FMT_BIN_16;

    case 0xc6:
        return FMT_BIN_32;

    case 0xc7:
        return FMT_EXT_8;

    case 0xc8:
        return FMT_EXT_16;

    case 0xc9:
        return FMT_EXT_32;

    case 0xca:
        return FMT_FLOAT_32;

    case 0xcb:
        return FMT_FLOAT_64;

    case 0xcc:
        return FMT_UINT_8;

    case 0xcd:
        return FMT_UINT_16;

    case 0xce:
        return FMT_UINT_32;

    case 0xcf:
        return FMT_UINT_64;

    case 0xd0:
        return FMT_INT_8;

    case 0xd1:
        return FMT_INT_16;

    case 0xd2:
        return FMT_INT_32;

    case 0xd3:
        return FMT_INT_64;

    case 0xd4:
        return FMT_FIXEXT_1;

    case 0xd5:
        return FMT_FIXEXT_2;

    case 0xd6:
        return FMT_FIXEXT_4;

    case 0xd7:
        return FMT_FIXEXT_8;

    case 0xd8:
        return FMT_FIXEXT_16;

    case 0xd9:
        return FMT_STR_8;

    case 0xda:
        return FMT_STR_16;

    case 0xdb:
        return FMT_STR_32;

    case 0xdc:
        return FMT_ARRAY_16;

    case 0xdd:
        return FMT_ARRAY_32;

    case 0xde:
        return FMT_MAP_16;

    case 0xdf:
        return FMT_MAP_32;

    case 0xc1:
        return FMT_NEVER_USED;
    }
    __builtin_unreachable();
}
