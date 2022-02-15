#ifndef LIP_EXT_1DARRAY_WRITE_FLOAT_H
#define LIP_EXT_1DARRAY_WRITE_FLOAT_H

#include "lite_pack/export.h"

struct lip_io_file;

#define __lip_write_1darray_float(ctx, size, arr)                              \
    _Generic((*arr), float                                                     \
             : lip_write_1darray_f32_data, double                              \
             : lip_write_1darray_f64_data)(ctx, size, arr)

LIP_API void lip_write_1darray_f32_data(struct lip_io_file *ctx, unsigned size,
                                        float const arr[]);

LIP_API void lip_write_1darray_f64_data(struct lip_io_file *ctx, unsigned size,
                                        double const arr[]);

LIP_API void lip_write_1darray_f32_data_inplace(struct lip_io_file *ctx,
                                                unsigned size, float arr[]);

LIP_API void lip_write_1darray_f64_data_inplace(struct lip_io_file *ctx,
                                                unsigned size, double arr[]);

#endif
