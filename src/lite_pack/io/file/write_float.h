#ifndef LIP_IO_FILE_WRITE_FLOAT_H
#define LIP_IO_FILE_WRITE_FLOAT_H

#include "lite_pack/export.h"

#define __lip_write_float(io, v)                                               \
    _Generic((v), float : __lip_write_f32, double : __lip_write_f64)(io, v)

struct lip_io_file;

LIP_API void __lip_write_f32(struct lip_io_file *, float val);
LIP_API void __lip_write_f64(struct lip_io_file *, double val);

#endif
