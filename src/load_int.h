#ifndef LIP_LOAD_INT_H
#define LIP_LOAD_INT_H

#include "format.h"
#include "load_number.h"

/* RAW SIGNED INTEGER FOR PUBLIC INTERFACE */

static inline unsigned lip_load_i8(unsigned char buf[], int8_t *val)
{
    *val = __lip_load_num8(buf).i;
    return 1;
}

static inline unsigned lip_load_i16(unsigned char buf[], int16_t *val)
{
    *val = __lip_load_num16(buf).i;
    return 2;
}

static inline unsigned lip_load_i32(unsigned char buf[], int32_t *val)
{
    *val = __lip_load_num32(buf).i;
    return 4;
}

static inline unsigned lip_load_i64(unsigned char buf[], int64_t *val)
{
    *val = __lip_load_num64(buf).i;
    return 8;
}

/* RAW UNSIGNED INTEGER FOR PUBLIC INTERFACE */

static inline unsigned lip_load_u8(unsigned char buf[], uint8_t *val)
{
    *val = __lip_load_num8(buf).u;
    return 1;
}

static inline unsigned lip_load_u16(unsigned char buf[], uint16_t *val)
{
    *val = __lip_load_num16(buf).u;
    return 2;
}

static inline unsigned lip_load_u32(unsigned char buf[], uint32_t *val)
{
    *val = __lip_load_num32(buf).u;
    return 4;
}

static inline unsigned lip_load_u64(unsigned char buf[], uint64_t *val)
{
    *val = __lip_load_num64(buf).u;
    return 8;
}

#endif
