#ifndef LIP_EXT_1DARRAY_READ_H
#define LIP_EXT_1DARRAY_READ_H

#include "lite_pack/export.h"
#include "lite_pack/1darray/read_float.h"
#include "lite_pack/1darray/read_int.h"
#include <stdint.h>

struct lip_ctx_file;

LIP_API void lip_read_1darray_size_type(struct lip_ctx_file *ctx,
                                        unsigned *size, uint8_t *type);
#define lip_read_1darray_int_data(ctx, sz, arr)                                \
    __lip_read_1darray_int_data(ctx, sz, arr)
#define lip_read_1darray_float(ctx, sz, arr)                                   \
    __lip_read_1darray_float(ctx, sz, arr)

#endif
