#ifndef LITE_PACK_UNPACK_FLOAT_H
#define LITE_PACK_UNPACK_FLOAT_H

#include "lite_pack/export.h"
#include <stdint.h>

/* clang-format off */
#define __lip_unpack_float(buf, val) _Generic((val),                \
float*  : __lip_unpack_f32,                                         \
double* : __lip_unpack_f64)(buf, val)
/* clang-format on */

LIP_API unsigned __lip_unpack_f32(unsigned char const buf[], float *val);
LIP_API unsigned __lip_unpack_f64(unsigned char const buf[], double *val);

#endif
