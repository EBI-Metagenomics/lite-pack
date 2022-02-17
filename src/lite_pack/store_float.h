#ifndef LIP_STORE_FLOAT_H
#define LIP_STORE_FLOAT_H

#include "lite_pack/first_byte.h"
#include "lite_pack/store_number.h"

static inline unsigned lip_store_f32(unsigned char buf[], float val)
{
    return __lip_store_num32(buf, __LIP_NUM32(val));
}

static inline unsigned lip_store_f32_in(unsigned char buf[])
{
    return __lip_store_num32(buf, __LIP_NUM32(buf));
}

static inline unsigned lip_store_f64(unsigned char buf[], double val)
{
    return __lip_store_num64(buf, __LIP_NUM64(val));
}

static inline unsigned lip_store_f64_in(unsigned char buf[])
{
    return __lip_store_num64(buf, __LIP_NUM64(buf));
}

static inline unsigned __lip_store_f32(unsigned char buf[], float val)
{
    buf[0] = __lip_first_byte(LIP_FMT_FLOAT_32);
    return 1 + lip_store_f32(buf + 1, val);
}

static inline unsigned __lip_store_f64(unsigned char buf[], double val)
{
    buf[0] = __lip_first_byte(LIP_FMT_FLOAT_64);
    return 1 + lip_store_f64(buf + 1, val);
}

#endif
