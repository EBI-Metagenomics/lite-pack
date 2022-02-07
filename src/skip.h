#ifndef SKIP_H
#define SKIP_H

#include "format.h"
#include "size.h"
#include <stdint.h>

static inline unsigned long lip_skip_head(uint8_t const buf[static 1])
{
    int format = __lip_format(buf[0]);
    unsigned long size = 0;
    switch (format)
    {
    case LIP_FMT_POSITIVE_FIXINT:
    case LIP_FMT_FIXMAP:
    case LIP_FMT_FIXARRAY:
    case LIP_FMT_FIXSTR:
    case LIP_FMT_NIL:
    case LIP_FMT_FALSE:
    case LIP_FMT_TRUE:
    case LIP_FMT_FLOAT_32:
    case LIP_FMT_FLOAT_64:
    case LIP_FMT_UINT_8:
    case LIP_FMT_UINT_16:
    case LIP_FMT_UINT_32:
    case LIP_FMT_UINT_64:
    case LIP_FMT_INT_8:
    case LIP_FMT_INT_16:
    case LIP_FMT_INT_32:
    case LIP_FMT_INT_64:
    case LIP_FMT_NEGATIVE_FIXINT:
        size = 1;
    }
    switch (format)
    {
    case LIP_FMT_BIN_8:
    case LIP_FMT_FIXEXT_1:
    case LIP_FMT_FIXEXT_2:
    case LIP_FMT_FIXEXT_4:
    case LIP_FMT_FIXEXT_8:
    case LIP_FMT_FIXEXT_16:
    case LIP_FMT_STR_8:
        size = 2;
    }
    switch (format)
    {
    case LIP_FMT_BIN_16:
    case LIP_FMT_EXT_8:
    case LIP_FMT_STR_16:
    case LIP_FMT_ARRAY_16:
    case LIP_FMT_MAP_16:
        size = 3;
    }

    if (format == LIP_FMT_EXT_16) size = 4;

    switch (format)
    {
    case LIP_FMT_BIN_32:
    case LIP_FMT_STR_32:
    case LIP_FMT_ARRAY_32:
    case LIP_FMT_MAP_32:
        size = 5;
    }

    if (format == LIP_FMT_EXT_32) size = 6;

    return size;
}

static inline unsigned long lip_skip_body(uint8_t const buf[static 1])
{
    int format = __lip_format(buf[0]);
    unsigned long size = 0;
    switch (format)
    {
    case LIP_FMT_POSITIVE_FIXINT:
    case LIP_FMT_NIL:
    case LIP_FMT_FALSE:
    case LIP_FMT_TRUE:
    case LIP_FMT_NEGATIVE_FIXINT:
        size = 0;
    }

    switch (format)
    {
    case LIP_FMT_UINT_8:
    case LIP_FMT_INT_8:
        size = 1;
    }

    switch (format)
    {
    case LIP_FMT_UINT_16:
    case LIP_FMT_INT_16:
        size = 2;
    }

    switch (format)
    {
    case LIP_FMT_FLOAT_32:
    case LIP_FMT_UINT_32:
    case LIP_FMT_INT_32:
        size = 4;
    }

    switch (format)
    {
    case LIP_FMT_FLOAT_64:
    case LIP_FMT_UINT_64:
    case LIP_FMT_INT_64:
        size = 8;
    }

    switch (format)
    {
    case LIP_FMT_FIXMAP:
    case LIP_FMT_FIXARRAY:
    case LIP_FMT_FIXSTR:
    case LIP_FMT_EXT_8:
    case LIP_FMT_EXT_16:
    case LIP_FMT_EXT_32:
    case LIP_FMT_FIXEXT_1:
    case LIP_FMT_FIXEXT_2:
    case LIP_FMT_FIXEXT_4:
    case LIP_FMT_FIXEXT_8:
    case LIP_FMT_FIXEXT_16:
        size = 0; /* TODO: implement */
    }

    switch (format)
    {
    case LIP_FMT_BIN_8:
    case LIP_FMT_STR_8:
        size = 0; /* TODO: implement */
    }
    switch (format)
    {
    case LIP_FMT_BIN_16:
    case LIP_FMT_STR_16:
    case LIP_FMT_ARRAY_16:
    case LIP_FMT_MAP_16:
        size = 0; /* TODO: implement */
    }

    switch (format)
    {
    case LIP_FMT_BIN_32:
    case LIP_FMT_STR_32:
    case LIP_FMT_ARRAY_32:
    case LIP_FMT_MAP_32:
        size = 0; /* TODO: implement */
    }
    return 0;
}

static inline unsigned long lip_skip(uint8_t const buf[static 1])
{
    return lip_skip_head(buf) + lip_skip_body(buf);
}

#endif
