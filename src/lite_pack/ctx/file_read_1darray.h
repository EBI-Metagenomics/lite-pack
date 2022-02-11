#ifndef LIP_CTX_FILE_READ_1DARRAY_H
#define LIP_CTX_FILE_READ_1DARRAY_H

#include "lite_pack/1darray.h"
#include "lite_pack/ctx/file_ctx.h"
#include "lite_pack/export.h"

LIP_API void lip_read_1darray_size_type(struct lip_ctx_file *ctx,
                                        unsigned *size, uint8_t *type);

/* SIGNED INTEGER */

LIP_API void lip_read_1darray_i8_data(struct lip_ctx_file *ctx, unsigned size,
                                      int8_t arr[]);

/* UNSIGNED INTEGER */

LIP_API void lip_read_1darray_u8_data(struct lip_ctx_file *ctx, unsigned size,
                                      uint8_t arr[]);

#endif
