#ifndef LIP_EXT_1DARRAY_WRITE_INT_INPLACE_H
#define LIP_EXT_1DARRAY_WRITE_INT_INPLACE_H

#include "lite_pack/export.h"
#include <stdint.h>

struct lip_ctx_file;

#define __lip_write_1darray_signed_data_inplace(ctx, sz, arr)                  \
    sizeof(*arr) == 1                                                          \
        ? lip_write_1darray_i8_data_inplace(ctx, sz, (int8_t *)(arr))          \
    : sizeof(*arr) == 2                                                        \
        ? lip_write_1darray_i16_data_inplace(ctx, sz, (int16_t *)(arr))        \
    : sizeof(*arr) == 4                                                        \
        ? lip_write_1darray_i32_data_inplace(ctx, sz, (int32_t *)(arr))        \
    : sizeof(*arr) == 8                                                        \
        ? lip_write_1darray_i64_data_inplace(ctx, sz, (int64_t *)(arr))        \
        : 0

#define __lip_write_1darray_unsigned_data_inplace(ctx, sz, arr)                \
    sizeof(*arr) == 1                                                          \
        ? lip_write_1darray_u8_data_inplace(ctx, sz, (uint8_t *)(arr))         \
    : sizeof(*arr) == 2                                                        \
        ? lip_write_1darray_u16_data_inplace(ctx, sz, (uint16_t *)(arr))       \
    : sizeof(*arr) == 4                                                        \
        ? lip_write_1darray_u32_data_inplace(ctx, sz, (uint32_t *)(arr))       \
    : sizeof(*arr) == 8                                                        \
        ? lip_write_1darray_u64_data_inplace(ctx, sz, (uint64_t *)(arr))       \
        : 0U

#define __lip_write_1darray_int_data_inplace(ctx, sz, arr)                     \
    _Generic(                                                                  \
        (*arr), signed char                                                    \
        : __lip_write_1darray_signed_data_inplace(ctx, sz, arr), signed short  \
        : __lip_write_1darray_signed_data_inplace(ctx, sz, arr), signed int    \
        : __lip_write_1darray_signed_data_inplace(ctx, sz, arr), signed long   \
        : __lip_write_1darray_signed_data_inplace(ctx, sz, arr),               \
          signed long long                                                     \
        : __lip_write_1darray_signed_data_inplace(ctx, sz, arr), unsigned char \
        : __lip_write_1darray_unsigned_data_inplace(ctx, sz, arr),             \
          unsigned short                                                       \
        : __lip_write_1darray_unsigned_data_inplace(ctx, sz, arr),             \
          unsigned int                                                         \
        : __lip_write_1darray_unsigned_data_inplace(ctx, sz, arr),             \
          unsigned long                                                        \
        : __lip_write_1darray_unsigned_data_inplace(ctx, sz, arr),             \
          unsigned long long                                                   \
        : __lip_write_1darray_unsigned_data_inplace(ctx, sz, arr))

/* SIGNED */

LIP_API void lip_write_1darray_i8_data_inplace(struct lip_ctx_file *ctx,
                                               unsigned size, int8_t arr[]);

LIP_API void lip_write_1darray_i16_data_inplace(struct lip_ctx_file *ctx,
                                                unsigned size, int16_t arr[]);

LIP_API void lip_write_1darray_i32_data_inplace(struct lip_ctx_file *ctx,
                                                unsigned size, int32_t arr[]);

LIP_API void lip_write_1darray_i64_data_inplace(struct lip_ctx_file *ctx,
                                                unsigned size, int64_t arr[]);

/* UNSIGNED */

LIP_API void lip_write_1darray_u8_data_inplace(struct lip_ctx_file *ctx,
                                               unsigned size, uint8_t arr[]);

LIP_API void lip_write_1darray_u16_data_inplace(struct lip_ctx_file *ctx,
                                                unsigned size, uint16_t arr[]);

LIP_API void lip_write_1darray_u32_data_inplace(struct lip_ctx_file *ctx,
                                                unsigned size, uint32_t arr[]);

LIP_API void lip_write_1darray_u64_data_inplace(struct lip_ctx_file *ctx,
                                                unsigned size, uint64_t arr[]);

#endif
