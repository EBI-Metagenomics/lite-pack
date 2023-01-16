#ifndef LIP_LOAD_INT_H
#define LIP_LOAD_INT_H

#include "lip/format.h"
#include "load_number.h"
#include "number.h"
#include <string.h>

/* RAW SIGNED INTEGER FOR PUBLIC INTERFACE */

unsigned lip_load_i8(unsigned char const buf[], int8_t *val)
{
    *val = __lip_load_num8(buf).i;
    return 1;
}

unsigned lip_load_i8_in(unsigned char buf[])
{
    buf[0] = __lip_load_num8(buf).c[0];
    return 1;
}

unsigned lip_load_i16(unsigned char const buf[], int16_t *val)
{
    *val = __lip_load_num16(buf).i;
    return 2;
}

unsigned lip_load_i16_in(unsigned char buf[])
{
    union __lip_num16 num = __lip_load_num16(buf);
    memcpy(buf, num.c, 2);
    return 2;
}

unsigned lip_load_i32(unsigned char const buf[], int32_t *val)
{
    *val = __lip_load_num32(buf).i;
    return 4;
}

unsigned lip_load_i32_in(unsigned char buf[])
{
    union __lip_num32 num = __lip_load_num32(buf);
    memcpy(buf, num.c, 4);
    return 4;
}

unsigned lip_load_i64(unsigned char const buf[], int64_t *val)
{
    *val = __lip_load_num64(buf).i;
    return 8;
}

unsigned lip_load_i64_in(unsigned char buf[])
{
    union __lip_num64 num = __lip_load_num64(buf);
    memcpy(buf, num.c, 8);
    return 8;
}

/* RAW UNSIGNED INTEGER FOR PUBLIC INTERFACE */

unsigned lip_load_u8(unsigned char const buf[], uint8_t *val)
{
    *val = __lip_load_num8(buf).u;
    return 1;
}

unsigned lip_load_u8_in(unsigned char buf[])
{
    buf[0] = __lip_load_num8(buf).c[0];
    return 1;
}

unsigned lip_load_u16(unsigned char const buf[], uint16_t *val)
{
    *val = __lip_load_num16(buf).u;
    return 2;
}

unsigned lip_load_u16_in(unsigned char buf[]) { return lip_load_i16_in(buf); }

unsigned lip_load_u32(unsigned char const buf[], uint32_t *val)
{
    *val = __lip_load_num32(buf).u;
    return 4;
}

unsigned lip_load_u32_in(unsigned char buf[]) { return lip_load_i32_in(buf); }

unsigned lip_load_u64(unsigned char const buf[], uint64_t *val)
{
    *val = __lip_load_num64(buf).u;
    return 8;
}

unsigned lip_load_u64_in(unsigned char buf[]) { return lip_load_i64_in(buf); }

#endif
