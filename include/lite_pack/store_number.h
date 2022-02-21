#ifndef LITE_PACK_STORE_NUMBER_H
#define LITE_PACK_STORE_NUMBER_H

#include "lite_pack/endian.h"
#include "lite_pack/number.h"
#include <string.h>

static inline unsigned __lip_store_num8(unsigned char buf[],
                                        union __lip_num8 val)
{
    memcpy(buf, &val, 1);
    return 1;
}

static inline unsigned __lip_store_num16(unsigned char buf[],
                                         union __lip_num16 val)
{
    val.u = __lip_big_endian(val.u);
    memcpy(buf, &val, 2);
    return 2;
}

static inline unsigned __lip_store_num32(unsigned char buf[],
                                         union __lip_num32 val)
{
    val.u = __lip_big_endian(val.u);
    memcpy(buf, &val, 4);
    return 4;
}

static inline unsigned __lip_store_num64(unsigned char buf[],
                                         union __lip_num64 val)
{
    val.u = __lip_big_endian(val.u);
    memcpy(buf, &val, 8);
    return 8;
}

#endif
