#ifndef LIP_FILE_READ_FLOAT_H
#define LIP_FILE_READ_FLOAT_H

#include "lite_pack/export.h"
#include <stdbool.h>

#define __lip_read_float(f, v)                                                 \
    _Generic(*(v), float : __lip_read_f32, double : __lip_read_f64)(f, v)

struct lip_file;

LIP_API bool __lip_read_f32(struct lip_file *, float *val);
LIP_API bool __lip_read_f64(struct lip_file *, double *val);

#endif
