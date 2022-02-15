#ifndef LIP_IO_FILE_READ_FLOAT_H
#define LIP_IO_FILE_READ_FLOAT_H

#include "lite_pack/export.h"

struct lip_io_file;

LIP_API void __lip_read_f32(struct lip_io_file *ctx, float *val);
LIP_API void __lip_read_f64(struct lip_io_file *ctx, double *val);

#define __lip_read_float(ctx, val)                                             \
    _Generic(*(val), float : __lip_read_f32, double : __lip_read_f64)(ctx, val)

#endif
