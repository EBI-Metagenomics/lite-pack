#ifndef LIP_STORE_NUMBER_H
#define LIP_STORE_NUMBER_H

#include "compiler.h"
#include <stdint.h>
#include <string.h>

static inline unsigned lip_store_num8(uint8_t buf[static 1], union num8 val)
{
    val.u = big_endian(val.u);
    memcpy(buf, &val, 1);
    return 1;
}

static inline unsigned lip_store_num16(uint8_t buf[static 2], union num16 val)
{
    val.u = big_endian(val.u);
    memcpy(buf, &val, 2);
    return 2;
}

static inline unsigned lip_store_num32(uint8_t buf[static 4], union num32 val)
{
    val.u = big_endian(val.u);
    memcpy(buf, &val, 4);
    return 4;
}

static inline unsigned lip_store_num64(uint8_t buf[static 8], union num64 val)
{
    val.u = big_endian(val.u);
    memcpy(buf, &val, 8);
    return 8;
}

#endif
