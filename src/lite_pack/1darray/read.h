#ifndef LIP_1DARRAY_READ_H
#define LIP_1DARRAY_READ_H

#include "lite_pack/export.h"
#include <stdint.h>

struct lip_ctx_file;

LIP_API void lip_read_1darray_size_type(struct lip_ctx_file *ctx,
                                        unsigned *size, uint8_t *type);

#endif
