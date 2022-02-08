#ifndef STORE_BODY_H
#define STORE_BODY_H

#include "compiler.h"
#include <stdint.h>
#include <string.h>

static inline unsigned __lip_store_body_num8(uint8_t buf[static 1],
                                             union num8 val)
{
    val.u = big_endian(val.u);
    memcpy(buf, &val, 1);
    return 1;
}

static inline unsigned __lip_store_body_num16(uint8_t buf[static 2],
                                              union num16 val)
{
    val.u = big_endian(val.u);
    memcpy(buf, &val, 2);
    return 2;
}

static inline unsigned __lip_store_body_num32(uint8_t buf[static 4],
                                              union num32 val)
{
    val.u = big_endian(val.u);
    memcpy(buf, &val, 4);
    return 4;
}

static inline unsigned __lip_store_body_num64(uint8_t buf[static 8],
                                              union num64 val)
{
    val.u = big_endian(val.u);
    memcpy(buf, &val, 8);
    return 8;
}

static inline unsigned __lip_store_body_str(uint8_t buf[static 1],
                                            unsigned length,
                                            char const val[static 1])
{
    memcpy(buf, val, length);
    return length;
}

#endif
