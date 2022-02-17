#ifndef LIP_1DARRAY_WRITE_FLOAT_IN_H
#define LIP_1DARRAY_WRITE_FLOAT_IN_H

#include "lite_pack/export.h"

struct lip_io_file;

#define __lip_write_1darray_float_data_in(io, size, arr)                       \
    _Generic((*arr), float                                                     \
             : lip_write_1darray_f32_data_in, double                           \
             : lip_write_1darray_f64_data_in)(io, size, arr)

LIP_API void lip_write_1darray_f32_data_in(struct lip_io_file *io,
                                           unsigned size, float arr[]);

LIP_API void lip_write_1darray_f64_data_in(struct lip_io_file *io,
                                           unsigned size, double arr[]);

#endif
