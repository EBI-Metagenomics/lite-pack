#ifndef LITE_PACK_STORE_INT_H
#define LITE_PACK_STORE_INT_H

#include "lite_pack/first_byte.h"
#include "lite_pack/store_number.h"

/* SIGNED INTEGER */

static inline unsigned __lip_store_negative_fixint(unsigned char buf[],
                                                   int8_t val)
{
    buf[0] = __lip_first_byte_fix(LIP_FMT_NEGATIVE_FIXINT, val);
    return 1;
}

static inline unsigned __lip_store_int8(unsigned char buf[], int8_t val)
{
    buf[0] = __lip_first_byte(LIP_FMT_INT_8);
    return 1 + __lip_store_num8(buf + 1, __LIP_NUM8(val));
}

static inline unsigned __lip_store_int16(unsigned char buf[], int16_t val)
{
    buf[0] = __lip_first_byte(LIP_FMT_INT_16);
    return 1 + __lip_store_num16(buf + 1, __LIP_NUM16(val));
}

static inline unsigned __lip_store_int32(unsigned char buf[], int32_t val)
{
    buf[0] = __lip_first_byte(LIP_FMT_INT_32);
    return 1 + __lip_store_num32(buf + 1, __LIP_NUM32(val));
}

static inline unsigned __lip_store_int64(unsigned char buf[], int64_t val)
{
    buf[0] = __lip_first_byte(LIP_FMT_INT_64);
    return 1 + __lip_store_num64(buf + 1, __LIP_NUM64(val));
}

/* UNSIGNED INTEGER */

static inline unsigned __lip_store_positive_fixint(unsigned char buf[],
                                                   uint8_t val)
{
    buf[0] = __lip_first_byte_fix(LIP_FMT_POSITIVE_FIXINT, val);
    return 1;
}

static inline unsigned __lip_store_uint8(unsigned char buf[], uint8_t val)
{
    buf[0] = __lip_first_byte(LIP_FMT_UINT_8);
    return 1 + __lip_store_num8(buf + 1, __LIP_NUM8(val));
}

static inline unsigned __lip_store_uint16(unsigned char buf[], uint16_t val)
{
    buf[0] = __lip_first_byte(LIP_FMT_UINT_16);
    return 1 + __lip_store_num16(buf + 1, __LIP_NUM16(val));
}

static inline unsigned __lip_store_uint32(unsigned char buf[], uint32_t val)
{
    buf[0] = __lip_first_byte(LIP_FMT_UINT_32);
    return 1 + __lip_store_num32(buf + 1, __LIP_NUM32(val));
}

static inline unsigned __lip_store_uint64(unsigned char buf[], uint64_t val)
{
    buf[0] = __lip_first_byte(LIP_FMT_UINT_64);
    return 1 + __lip_store_num64(buf + 1, __LIP_NUM64(val));
}

/* RAW SIGNED INTEGER FOR PUBLIC INTERFACE */

static inline unsigned lip_store_i8(unsigned char buf[], int8_t val)
{
    return __lip_store_num8(buf, __LIP_NUM8(val));
}

static inline unsigned lip_store_i8_in(unsigned char buf[])
{
    return __lip_store_num8(buf, __LIP_NUM8(buf));
}

static inline unsigned lip_store_i16(unsigned char buf[], int16_t val)
{
    return __lip_store_num16(buf, __LIP_NUM16(val));
}

static inline unsigned lip_store_i16_in(unsigned char buf[])
{
    return __lip_store_num16(buf, __LIP_NUM16(buf));
}

static inline unsigned lip_store_i32(unsigned char buf[], int32_t val)
{
    return __lip_store_num32(buf, __LIP_NUM32(val));
}

static inline unsigned lip_store_i32_in(unsigned char buf[])
{
    return __lip_store_num32(buf, __LIP_NUM32(buf));
}

static inline unsigned lip_store_i64(unsigned char buf[], int64_t val)
{
    return __lip_store_num64(buf, __LIP_NUM64(val));
}

static inline unsigned lip_store_i64_in(unsigned char buf[])
{
    return __lip_store_num64(buf, __LIP_NUM64(buf));
}

/* RAW UNSIGNED INTEGER FOR PUBLIC INTERFACE */

static inline unsigned lip_store_u8(unsigned char buf[], uint8_t val)
{
    return __lip_store_num8(buf, __LIP_NUM8(val));
}

static inline unsigned lip_store_u8_in(unsigned char buf[])
{
    return __lip_store_num8(buf, __LIP_NUM8(buf));
}

static inline unsigned lip_store_u16(unsigned char buf[], uint16_t val)
{
    return __lip_store_num16(buf, __LIP_NUM16(val));
}

static inline unsigned lip_store_u16_in(unsigned char buf[])
{
    return __lip_store_num16(buf, __LIP_NUM16(buf));
}

static inline unsigned lip_store_u32(unsigned char buf[], uint32_t val)
{
    return __lip_store_num32(buf, __LIP_NUM32(val));
}

static inline unsigned lip_store_u32_in(unsigned char buf[])
{
    return __lip_store_num32(buf, __LIP_NUM32(buf));
}

static inline unsigned lip_store_u64(unsigned char buf[], uint64_t val)
{
    return __lip_store_num64(buf, __LIP_NUM64(val));
}

static inline unsigned lip_store_u64_in(unsigned char buf[])
{
    return __lip_store_num64(buf, __LIP_NUM64(buf));
}

#endif
