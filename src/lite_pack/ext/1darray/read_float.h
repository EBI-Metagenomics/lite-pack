#ifndef LIP_EXT_1DARRAY_READ_FLOAT_H
#define LIP_EXT_1DARRAY_READ_FLOAT_H

#include "lite_pack/export.h"
#include <stdint.h>

struct lip_ctx_file;

#define __lip_read_1darray_float(ctx, sz, arr)                                 \
    _Generic((*arr), float                                                     \
             : lip_read_1darray_f32_data, double                               \
             : lip_read_1darray_f64_data)(ctx, sz, arr)

LIP_API void lip_read_1darray_f32_data(struct lip_ctx_file *ctx, unsigned size,
                                       float arr[]);

LIP_API void lip_read_1darray_f64_data(struct lip_ctx_file *ctx, unsigned size,
                                       double arr[]);

#endif
