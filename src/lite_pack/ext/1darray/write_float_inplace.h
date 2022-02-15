#ifndef LIP_EXT_1DARRAY_WRITE_FLOAT_INPLACE_H
#define LIP_EXT_1DARRAY_WRITE_FLOAT_INPLACE_H

#include "lite_pack/export.h"

struct lip_ctx_file;

#define __lip_write_1darray_float_inplace(ctx, size, arr)                      \
    _Generic((*arr), float                                                     \
             : lip_write_1darray_f32_data_inplace, double                      \
             : lip_write_1darray_f64_data_inplace)(ctx, size, arr)

LIP_API void lip_write_1darray_f32_data_inplace(struct lip_ctx_file *ctx,
                                                unsigned size, float arr[]);

LIP_API void lip_write_1darray_f64_data_inplace(struct lip_ctx_file *ctx,
                                                unsigned size, double arr[]);

#endif
