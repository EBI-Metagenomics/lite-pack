#ifndef LIP_1DARRAY_1DARRAY_H
#define LIP_1DARRAY_1DARRAY_H

#include "lite_pack/1darray/read_float.h"
#include "lite_pack/1darray/read_int.h"
#include "lite_pack/1darray/type.h"

LIP_API unsigned lip_pack_1darray_size_type(unsigned char buf[], unsigned size,
                                            uint8_t type);

LIP_API void lip_read_1darray_size_type(struct lip_ctx_file *ctx,
                                        unsigned *size, uint8_t *type);
#define lip_read_1darray_int_data(ctx, sz, arr)                                \
    __lip_read_1darray_int_data(ctx, sz, arr)
#define lip_read_1darray_float(ctx, sz, arr)                                   \
    __lip_read_1darray_float(ctx, sz, arr)

#endif
