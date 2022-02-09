#ifndef LIP_UNPACK_FLOAT_H
#define LIP_UNPACK_FLOAT_H

#include <stdint.h>

/* clang-format off */
#define __lip_unpack_float(buf, val) _Generic((val),                \
float*  : __lip_unpack_f32,                                         \
double* : __lip_unpack_f64)(buf, val)
/* clang-format on */

unsigned __lip_unpack_f32(unsigned char const buf[static 5], float *val);
unsigned __lip_unpack_f64(unsigned char const buf[static 5], double *val);

#endif
