#ifndef LITE_PACK_LOAD_NUMBER_H
#define LITE_PACK_LOAD_NUMBER_H

#include "lite_pack/endian.h"
#include "lite_pack/number.h"
#include <string.h>

union __lip_num8 __lip_load_num8(unsigned char const buf[])
{
    union __lip_num8 num = __LIP_NUM8(buf);
    return num;
}

union __lip_num16 __lip_load_num16(unsigned char const buf[])
{
    union __lip_num16 num = __LIP_NUM16(buf);
    num.u = __lip_big_endian(num.u);
    return num;
}

union __lip_num32 __lip_load_num32(unsigned char const buf[])
{
    union __lip_num32 num = __LIP_NUM32(buf);
    num.u = __lip_big_endian(num.u);
    return num;
}

union __lip_num64 __lip_load_num64(unsigned char const buf[])
{
    union __lip_num64 num = __LIP_NUM64(buf);
    num.u = __lip_big_endian(num.u);
    return num;
}

#endif
