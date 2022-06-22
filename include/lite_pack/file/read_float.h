#ifndef LITE_PACK_FILE_READ_FLOAT_H
#define LITE_PACK_FILE_READ_FLOAT_H

#include "lite_pack/export.h"
#include <stdbool.h>

struct lip_file;

#define lip_read_float(f, v)                                                   \
    _Generic(*(v), float : __lip_read_f32, double : __lip_read_f64)(f, v)

LIP_API bool __lip_read_f32(struct lip_file *, float *val);
LIP_API bool __lip_read_f64(struct lip_file *, double *val);

#endif
