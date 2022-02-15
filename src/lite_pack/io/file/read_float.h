#ifndef LIP_IO_FILE_READ_FLOAT_H
#define LIP_IO_FILE_READ_FLOAT_H

#include "lite_pack/export.h"

#define __lip_read_float(io, v)                                                \
    _Generic(*(v), float : __lip_read_f32, double : __lip_read_f64)(io, v)

struct lip_io_file;

LIP_API void __lip_read_f32(struct lip_io_file *, float *val);
LIP_API void __lip_read_f64(struct lip_io_file *, double *val);

#endif
