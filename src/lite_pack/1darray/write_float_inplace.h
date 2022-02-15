#ifndef LIP_EXT_1DARRAY_WRITE_FLOAT_INPLACE_H
#define LIP_EXT_1DARRAY_WRITE_FLOAT_INPLACE_H

#include "lite_pack/export.h"

struct lip_io_file;

#define __lip_write_1darray_float_inplace(io, size, arr)                      \
    _Generic((*arr), float                                                     \
             : lip_write_1darray_f32_data_inplace, double                      \
             : lip_write_1darray_f64_data_inplace)(io, size, arr)

LIP_API void lip_write_1darray_f32_data_inplace(struct lip_io_file *io,
                                                unsigned size, float arr[]);

LIP_API void lip_write_1darray_f64_data_inplace(struct lip_io_file *io,
                                                unsigned size, double arr[]);

#endif
