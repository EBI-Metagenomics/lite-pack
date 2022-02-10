#ifndef LIP_LOAD_FLOAT_H
#define LIP_LOAD_FLOAT_H

#include "format.h"
#include "load_number.h"

static inline unsigned lip_load_f32(unsigned char buf[], float *val)
{
    *val = __lip_load_num32(buf).f;
    return 4;
}

static inline unsigned lip_load_f64(unsigned char buf[], double *val)
{
    *val = __lip_load_num64(buf).f;
    return 8;
}

#endif
