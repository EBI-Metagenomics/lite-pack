#ifndef LIP_STORE_INT_H
#define LIP_STORE_INT_H

#include "first_byte.h"
#include "store_number.h"

/* SIGNED INTEGER */

static inline unsigned __lip_store_negative_fixint(uint8_t buf[static 1],
                                                   int8_t val)
{
    buf[0] = __lip_first_byte_fix(LIP_FMT_NEGATIVE_FIXINT, val);
    return 1;
}

static inline unsigned __lip_store_int8(uint8_t buf[static 2], int8_t val)
{
    buf[0] = __lip_first_byte(LIP_FMT_INT_8);
    return 1 + lip_store_num8(buf + 1, NUM8(val));
}

static inline unsigned __lip_store_int16(uint8_t buf[static 3], int16_t val)
{
    buf[0] = __lip_first_byte(LIP_FMT_INT_16);
    return 1 + lip_store_num16(buf + 1, NUM16(val));
}

static inline unsigned __lip_store_int32(uint8_t buf[static 5], int32_t val)
{
    buf[0] = __lip_first_byte(LIP_FMT_INT_32);
    return 1 + lip_store_num32(buf + 1, NUM32(val));
}

static inline unsigned __lip_store_int64(uint8_t buf[static 9], int64_t val)
{
    buf[0] = __lip_first_byte(LIP_FMT_INT_64);
    return 1 + lip_store_num64(buf + 1, NUM64(val));
}

/* UNSIGNED INTEGER */

static inline unsigned __lip_store_positive_fixint(uint8_t buf[static 1],
                                                   uint8_t val)
{
    buf[0] = __lip_first_byte_fix(LIP_FMT_POSITIVE_FIXINT, val);
    return 1;
}

static inline unsigned __lip_store_uint8(uint8_t buf[static 2], uint8_t val)
{
    buf[0] = __lip_first_byte(LIP_FMT_UINT_8);
    return 1 + lip_store_num8(buf + 1, NUM8(val));
}

static inline unsigned __lip_store_uint16(uint8_t buf[static 3], uint16_t val)
{
    buf[0] = __lip_first_byte(LIP_FMT_UINT_16);
    return 1 + lip_store_num16(buf + 1, NUM16(val));
}

static inline unsigned __lip_store_uint32(uint8_t buf[static 5], uint32_t val)
{
    buf[0] = __lip_first_byte(LIP_FMT_UINT_32);
    return 1 + lip_store_num32(buf + 1, NUM32(val));
}

static inline unsigned __lip_store_uint64(uint8_t buf[static 9], uint64_t val)
{
    buf[0] = __lip_first_byte(LIP_FMT_UINT_64);
    return 1 + lip_store_num64(buf + 1, NUM64(val));
}

#endif
