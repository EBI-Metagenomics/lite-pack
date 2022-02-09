#include "unpack_int.h"
#include "format.h"
#include "load_number.h"

/* SIGNED INTEGER */

unsigned __lip_unpack_i8(uint8_t const buf[static 1], int8_t *val)
{
    switch (lip_format(buf))
    {
    case LIP_FMT_POSITIVE_FIXINT:
    case LIP_FMT_NEGATIVE_FIXINT:
        *val = __lip_load_num8(buf).i;
        return 1;
    case LIP_FMT_UINT_8:
    case LIP_FMT_INT_8:
        *val = __lip_load_num8(buf + 1).i;
        return 2;
    }
    return 0;
}

unsigned __lip_unpack_i16(uint8_t const buf[static 1], int16_t *val)
{
    switch (lip_format(buf))
    {
    case LIP_FMT_POSITIVE_FIXINT:
    case LIP_FMT_NEGATIVE_FIXINT:
        *val = __lip_load_num8(buf).i;
        return 1;
    case LIP_FMT_UINT_8:
    case LIP_FMT_INT_8:
        *val = __lip_load_num8(buf + 1).i;
        return 2;
    case LIP_FMT_UINT_16:
    case LIP_FMT_INT_16:
        *val = __lip_load_num16(buf + 1).i;
        return 3;
    }
    return 0;
}

unsigned __lip_unpack_i32(uint8_t const buf[static 1], int32_t *val)
{
    switch (lip_format(buf))
    {
    case LIP_FMT_POSITIVE_FIXINT:
    case LIP_FMT_NEGATIVE_FIXINT:
        *val = __lip_load_num8(buf).i;
        return 1;
    case LIP_FMT_UINT_8:
    case LIP_FMT_INT_8:
        *val = __lip_load_num8(buf + 1).i;
        return 2;
    case LIP_FMT_UINT_16:
    case LIP_FMT_INT_16:
        *val = __lip_load_num16(buf + 1).i;
        return 3;
    case LIP_FMT_UINT_32:
    case LIP_FMT_INT_32:
        *val = __lip_load_num32(buf + 1).i;
        return 5;
    }
    return 0;
}

unsigned __lip_unpack_i64(uint8_t const buf[static 1], int64_t *val)
{
    switch (lip_format(buf))
    {
    case LIP_FMT_POSITIVE_FIXINT:
    case LIP_FMT_NEGATIVE_FIXINT:
        *val = __lip_load_num8(buf).i;
        return 1;
    case LIP_FMT_UINT_8:
    case LIP_FMT_INT_8:
        *val = __lip_load_num8(buf + 1).i;
        return 2;
    case LIP_FMT_UINT_16:
    case LIP_FMT_INT_16:
        *val = __lip_load_num16(buf + 1).i;
        return 3;
    case LIP_FMT_UINT_32:
    case LIP_FMT_INT_32:
        *val = __lip_load_num32(buf + 1).i;
        return 5;
    case LIP_FMT_UINT_64:
    case LIP_FMT_INT_64:
        *val = __lip_load_num64(buf + 1).i;
        return 9;
    }
    return 0;
}

/* UNSIGNED INTEGER */

unsigned __lip_unpack_u8(uint8_t const buf[static 1], uint8_t *val)
{
    switch (lip_format(buf))
    {
    case LIP_FMT_POSITIVE_FIXINT:
    case LIP_FMT_NEGATIVE_FIXINT:
        *val = __lip_load_num8(buf).u;
        return 1;
    case LIP_FMT_UINT_8:
    case LIP_FMT_INT_8:
        *val = __lip_load_num8(buf + 1).u;
        return 2;
    }
    return 0;
}

unsigned __lip_unpack_u16(uint8_t const buf[static 1], uint16_t *val)
{
    switch (lip_format(buf))
    {
    case LIP_FMT_POSITIVE_FIXINT:
    case LIP_FMT_NEGATIVE_FIXINT:
        *val = __lip_load_num8(buf).u;
        return 1;
    case LIP_FMT_UINT_8:
    case LIP_FMT_INT_8:
        *val = __lip_load_num8(buf + 1).u;
        return 2;
    case LIP_FMT_UINT_16:
    case LIP_FMT_INT_16:
        *val = __lip_load_num16(buf + 1).u;
        return 3;
    }
    return 0;
}

unsigned __lip_unpack_u32(uint8_t const buf[static 1], uint32_t *val)
{
    switch (lip_format(buf))
    {
    case LIP_FMT_POSITIVE_FIXINT:
    case LIP_FMT_NEGATIVE_FIXINT:
        *val = __lip_load_num8(buf).u;
        return 1;
    case LIP_FMT_UINT_8:
    case LIP_FMT_INT_8:
        *val = __lip_load_num8(buf + 1).u;
        return 2;
    case LIP_FMT_UINT_16:
    case LIP_FMT_INT_16:
        *val = __lip_load_num16(buf + 1).u;
        return 3;
    case LIP_FMT_UINT_32:
    case LIP_FMT_INT_32:
        *val = __lip_load_num32(buf + 1).u;
        return 5;
    }
    return 0;
}

unsigned __lip_unpack_u64(uint8_t const buf[static 1], uint64_t *val)
{
    switch (lip_format(buf))
    {
    case LIP_FMT_POSITIVE_FIXINT:
    case LIP_FMT_NEGATIVE_FIXINT:
        *val = __lip_load_num8(buf).u;
        return 1;
    case LIP_FMT_UINT_8:
    case LIP_FMT_INT_8:
        *val = __lip_load_num8(buf + 1).u;
        return 2;
    case LIP_FMT_UINT_16:
    case LIP_FMT_INT_16:
        *val = __lip_load_num16(buf + 1).u;
        return 3;
    case LIP_FMT_UINT_32:
    case LIP_FMT_INT_32:
        *val = __lip_load_num32(buf + 1).u;
        return 5;
    case LIP_FMT_UINT_64:
    case LIP_FMT_INT_64:
        *val = __lip_load_num64(buf + 1).u;
        return 9;
    }
    return 0;
}
