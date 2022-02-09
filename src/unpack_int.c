#include "unpack_int.h"
#include "format.h"
#include "load_number.h"

/* SIGNED INTEGER */

unsigned __lip_unpack_i8(unsigned char const buf[static 1], int8_t *val)
{
    int fmt = lip_format(buf);
    switch (fmt)
    {
    case LIP_FMT_POSITIVE_FIXINT:
    case LIP_FMT_NEGATIVE_FIXINT:
        *val = __lip_load_num8(buf).i;
        return 1;

    case LIP_FMT_INT_8:
        *val = __lip_load_num8(buf + 1).i;
        return 2;
    }

    if (fmt == LIP_FMT_UINT_8 && __lip_load_num8(buf + 1).u <= INT8_MAX)
    {
        *val = __lip_load_num8(buf + 1).i;
        return 2;
    }
    return 0;
}

unsigned __lip_unpack_i16(unsigned char const buf[static 1], int16_t *val)
{
    int fmt = lip_format(buf);
    switch (fmt)
    {
    case LIP_FMT_POSITIVE_FIXINT:
    case LIP_FMT_NEGATIVE_FIXINT:
        *val = __lip_load_num8(buf).i;
        return 1;

    case LIP_FMT_UINT_8:
        *val = __lip_load_num8(buf + 1).u;
        return 2;
    case LIP_FMT_INT_8:
        *val = __lip_load_num8(buf + 1).i;
        return 2;

    case LIP_FMT_INT_16:
        *val = __lip_load_num16(buf + 1).i;
        return 3;
    }

    if (fmt == LIP_FMT_UINT_16 && __lip_load_num16(buf + 1).u <= INT16_MAX)
    {
        *val = __lip_load_num16(buf + 1).i;
        return 3;
    }
    return 0;
}

unsigned __lip_unpack_i32(unsigned char const buf[static 1], int32_t *val)
{
    int fmt = lip_format(buf);
    switch (fmt)
    {
    case LIP_FMT_POSITIVE_FIXINT:
    case LIP_FMT_NEGATIVE_FIXINT:
        *val = __lip_load_num8(buf).i;
        return 1;

    case LIP_FMT_UINT_8:
        *val = __lip_load_num8(buf + 1).u;
        return 2;
    case LIP_FMT_INT_8:
        *val = __lip_load_num8(buf + 1).i;
        return 2;

    case LIP_FMT_UINT_16:
        *val = __lip_load_num16(buf + 1).u;
        return 3;
    case LIP_FMT_INT_16:
        *val = __lip_load_num16(buf + 1).i;
        return 3;

    case LIP_FMT_INT_32:
        *val = __lip_load_num32(buf + 1).i;
        return 5;
    }

    if (fmt == LIP_FMT_UINT_32 && __lip_load_num32(buf + 1).u <= INT32_MAX)
    {
        *val = __lip_load_num32(buf + 1).i;
        return 5;
    }
    return 0;
}

unsigned __lip_unpack_i64(unsigned char const buf[static 1], int64_t *val)
{
    int fmt = lip_format(buf);
    switch (fmt)
    {
    case LIP_FMT_POSITIVE_FIXINT:
    case LIP_FMT_NEGATIVE_FIXINT:
        *val = __lip_load_num8(buf).i;
        return 1;

    case LIP_FMT_UINT_8:
        *val = __lip_load_num8(buf + 1).u;
        return 2;
    case LIP_FMT_INT_8:
        *val = __lip_load_num8(buf + 1).i;
        return 2;

    case LIP_FMT_UINT_16:
        *val = __lip_load_num16(buf + 1).u;
        return 3;
    case LIP_FMT_INT_16:
        *val = __lip_load_num16(buf + 1).i;
        return 3;

    case LIP_FMT_UINT_32:
        *val = __lip_load_num32(buf + 1).u;
        return 5;
    case LIP_FMT_INT_32:
        *val = __lip_load_num32(buf + 1).i;
        return 5;

    case LIP_FMT_INT_64:
        *val = __lip_load_num64(buf + 1).i;
        return 9;
    }

    if (fmt == LIP_FMT_UINT_64 && __lip_load_num64(buf + 1).u <= INT64_MAX)
    {
        *val = __lip_load_num64(buf + 1).i;
        return 9;
    }
    return 0;
}

/* UNSIGNED INTEGER */

unsigned __lip_unpack_u8(unsigned char const buf[static 1], uint8_t *val)
{
    int fmt = lip_format(buf);
    switch (fmt)
    {
    case LIP_FMT_NEGATIVE_FIXINT:
        if (__lip_load_num8(buf).i < 0) return 0;
    case LIP_FMT_POSITIVE_FIXINT:
        *val = __lip_load_num8(buf).u;
        return 1;

    case LIP_FMT_INT_8:
        if (__lip_load_num8(buf + 1).i < 0) return 0;
    case LIP_FMT_UINT_8:
        *val = __lip_load_num8(buf + 1).u;
        return 2;
    }
    return 0;
}

unsigned __lip_unpack_u16(unsigned char const buf[static 1], uint16_t *val)
{
    int fmt = lip_format(buf);
    switch (fmt)
    {
    case LIP_FMT_NEGATIVE_FIXINT:
        if (__lip_load_num8(buf).i < 0) return 0;
    case LIP_FMT_POSITIVE_FIXINT:
        *val = __lip_load_num8(buf).u;
        return 1;

    case LIP_FMT_INT_8:
        if (__lip_load_num8(buf + 1).i < 0) return 0;
    case LIP_FMT_UINT_8:
        *val = __lip_load_num8(buf + 1).u;
        return 2;

    case LIP_FMT_INT_16:
        if (__lip_load_num16(buf + 1).i < 0) return 0;
    case LIP_FMT_UINT_16:
        *val = __lip_load_num16(buf + 1).u;
        return 3;
    }
    return 0;
}

unsigned __lip_unpack_u32(unsigned char const buf[static 1], uint32_t *val)
{
    int fmt = lip_format(buf);
    switch (fmt)
    {
    case LIP_FMT_NEGATIVE_FIXINT:
        if (__lip_load_num8(buf).i < 0) return 0;
    case LIP_FMT_POSITIVE_FIXINT:
        *val = __lip_load_num8(buf).u;
        return 1;

    case LIP_FMT_INT_8:
        if (__lip_load_num8(buf + 1).i < 0) return 0;
    case LIP_FMT_UINT_8:
        *val = __lip_load_num8(buf + 1).u;
        return 2;

    case LIP_FMT_INT_16:
        if (__lip_load_num16(buf + 1).i < 0) return 0;
    case LIP_FMT_UINT_16:
        *val = __lip_load_num16(buf + 1).u;
        return 3;

    case LIP_FMT_INT_32:
        if (__lip_load_num32(buf + 1).i < 0) return 0;
    case LIP_FMT_UINT_32:
        *val = __lip_load_num32(buf + 1).u;
        return 5;
    }
    return 0;
}

unsigned __lip_unpack_u64(unsigned char const buf[static 1], uint64_t *val)
{
    int fmt = lip_format(buf);
    switch (fmt)
    {
    case LIP_FMT_NEGATIVE_FIXINT:
        if (__lip_load_num8(buf).i < 0) return 0;
    case LIP_FMT_POSITIVE_FIXINT:
        *val = __lip_load_num8(buf).u;
        return 1;

    case LIP_FMT_INT_8:
        if (__lip_load_num8(buf + 1).i < 0) return 0;
    case LIP_FMT_UINT_8:
        *val = __lip_load_num8(buf + 1).u;
        return 2;

    case LIP_FMT_INT_16:
        if (__lip_load_num16(buf + 1).i < 0) return 0;
    case LIP_FMT_UINT_16:
        *val = __lip_load_num16(buf + 1).u;
        return 3;

    case LIP_FMT_INT_32:
        if (__lip_load_num32(buf + 1).i < 0) return 0;
    case LIP_FMT_UINT_32:
        *val = __lip_load_num32(buf + 1).u;
        return 5;

    case LIP_FMT_INT_64:
        if (__lip_load_num64(buf + 1).i < 0) return 0;
    case LIP_FMT_UINT_64:
        *val = __lip_load_num64(buf + 1).u;
        return 9;
    }
    return 0;
}
