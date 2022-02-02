#ifndef FIRST_BYTE_H
#define FIRST_BYTE_H

#include "bug.h"
#include "format.h"

static inline uint8_t fluid_first_byte(int format, int val)
{
    switch (format)
    {
    case FMT_POSITIVE_FIXINT:
        return (uint8_t)(0x00 | val);
    case FMT_FIXMAP:
        return (uint8_t)(0x80 | val);
    case FMT_FIXARRAY:
        return (uint8_t)(0x90 | val);
    case FMT_FIXSTR:
        return (uint8_t)(0xa0 | val);
    case FMT_NEGATIVE_FIXINT:
        return (uint8_t)(0xe0 | val);
    }
    BUG();
}

static inline uint8_t first_byte(int format)
{
    switch (format)
    {
    case FMT_NIL:
        return 0xc0;
    case FMT_NEVER_USED:
        return 0xc1;
    case FMT_FALSE:
        return 0xc2;
    case FMT_TRUE:
        return 0xc3;
    case FMT_BIN_8:
        return 0xc4;
    case FMT_BIN_16:
        return 0xc5;
    case FMT_BIN_32:
        return 0xc6;
    case FMT_EXT_8:
        return 0xc7;
    case FMT_EXT_16:
        return 0xc8;
    case FMT_EXT_32:
        return 0xc9;
    case FMT_FLOAT_32:
        return 0xca;
    case FMT_FLOAT_64:
        return 0xcb;
    case FMT_UINT_8:
        return 0xcc;
    case FMT_UINT_16:
        return 0xcd;
    case FMT_UINT_32:
        return 0xce;
    case FMT_UINT_64:
        return 0xcf;
    case FMT_INT_8:
        return 0xd0;
    case FMT_INT_16:
        return 0xd1;
    case FMT_INT_32:
        return 0xd2;
    case FMT_INT_64:
        return 0xd3;
    case FMT_FIXEXT_1:
        return 0xd4;
    case FMT_FIXEXT_2:
        return 0xd5;
    case FMT_FIXEXT_4:
        return 0xd6;
    case FMT_FIXEXT_8:
        return 0xd7;
    case FMT_FIXEXT_16:
        return 0xd8;
    case FMT_STR_8:
        return 0xd9;
    case FMT_STR_16:
        return 0xda;
    case FMT_STR_32:
        return 0xdb;
    case FMT_ARRAY_16:
        return 0xdc;
    case FMT_ARRAY_32:
        return 0xdd;
    case FMT_MAP_16:
        return 0xde;
    case FMT_MAP_32:
        return 0xdf;
    }
    BUG();
}

#endif
