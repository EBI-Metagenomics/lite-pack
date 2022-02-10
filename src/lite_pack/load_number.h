#ifndef LIP_LOAD_NUMBER_H
#define LIP_LOAD_NUMBER_H

#include "lite_pack/compiler.h"
#include "lite_pack/number.h"
#include <string.h>

static inline union __lip_num8
__lip_load_num8(unsigned char const buf[])
{
    union __lip_num8 num;
    memcpy(num.c, buf, sizeof(num));
    return num;
}

static inline union __lip_num16
__lip_load_num16(unsigned char const buf[])
{
    union __lip_num16 num;
    memcpy(num.c, buf, sizeof(num));
    num.u = __lip_big_endian(num.u);
    return num;
}

static inline union __lip_num32
__lip_load_num32(unsigned char const buf[])
{
    union __lip_num32 num;
    memcpy(num.c, buf, sizeof(num));
    num.u = __lip_big_endian(num.u);
    return num;
}

static inline union __lip_num64
__lip_load_num64(unsigned char const buf[])
{
    union __lip_num64 num;
    memcpy(num.c, buf, sizeof(num));
    num.u = __lip_big_endian(num.u);
    return num;
}

#endif
