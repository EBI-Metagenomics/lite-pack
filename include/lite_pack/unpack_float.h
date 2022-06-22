#ifndef LITE_PACK_UNPACK_FLOAT_H
#define LITE_PACK_UNPACK_FLOAT_H

#include "lite_pack/export.h"
#include <stdint.h>

#define lip_unpack_float(buf, val)                                             \
    _Generic((val), float*                                                     \
             : lip_unpack_f32, double*                                         \
             : lip_unpack_f64)(buf, val)

LIP_API unsigned lip_unpack_f32(unsigned char const buf[], float *val);
LIP_API unsigned lip_unpack_f64(unsigned char const buf[], double *val);

#endif
