#ifndef LIP_LOAD_FLOAT_H
#define LIP_LOAD_FLOAT_H

#include "format.h"
#include "load_number.h"

static inline unsigned lip_load_f32(unsigned char const buf[], float *val)
{
    *val = __lip_load_num32(buf).f;
    return 4;
}

static inline unsigned lip_load_f32_inplace(unsigned char buf[])
{
    buf[0] = __lip_load_num32(buf).c[0];
    buf[1] = __lip_load_num32(buf).c[1];
    buf[2] = __lip_load_num32(buf).c[2];
    buf[3] = __lip_load_num32(buf).c[3];
    return 4;
}

static inline unsigned lip_load_f64(unsigned char const buf[], double *val)
{
    *val = __lip_load_num64(buf).f;
    return 8;
}

static inline unsigned lip_load_f64_inplace(unsigned char buf[])
{
    buf[0] = __lip_load_num64(buf).c[0];
    buf[1] = __lip_load_num64(buf).c[1];
    buf[2] = __lip_load_num64(buf).c[2];
    buf[3] = __lip_load_num64(buf).c[3];
    buf[4] = __lip_load_num64(buf).c[4];
    buf[5] = __lip_load_num64(buf).c[5];
    buf[6] = __lip_load_num64(buf).c[6];
    buf[7] = __lip_load_num64(buf).c[7];
    return 8;
}

#endif
