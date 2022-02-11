#ifndef LIP_CTX_FILE_WRITE_1DARRAY_H
#define LIP_CTX_FILE_WRITE_1DARRAY_H

#include "lite_pack/1darray.h"
#include "lite_pack/ctx/file_ctx.h"
#include "lite_pack/export.h"

/* INTEGER */

/* clang-format off */
#define __lip_write_1d_array_signed_data(buf, sz, arr)                         \
    sizeof(*arr) == 1   ? lip_write_1darray_i8_data(buf, sz, (int8_t*)(arr))   \
    : sizeof(*arr) == 2 ? lip_write_1darray_i16_data(buf, sz, (int16_t*)(arr)) \
    : sizeof(*arr) == 4 ? lip_write_1darray_i32_data(buf, sz, (int32_t*)(arr)) \
    : sizeof(*arr) == 8 ? lip_write_1darray_i64_data(buf, sz, (int64_t*)(arr)) \
                        : 0

#define __lip_write_1darray_unsigned_data(buf, sz, arr)                        \
    sizeof(*arr) == 1   ? lip_write_1darray_u8_data(buf, sz, (uint8_t*)(arr))  \
    : sizeof(*arr) == 2 ? lip_write_1darray_u16_data(buf, sz, (uint16_t*)(arr))\
    : sizeof(*arr) == 4 ? lip_write_1darray_u32_data(buf, sz, (uint32_t*)(arr))\
    : sizeof(*arr) == 8 ? lip_write_1darray_u64_data(buf, sz, (uint64_t*)(arr))\
                        : 0U

#define lip_write_1darray_int_data(buf, sz, arr)                                  \
    _Generic((*arr), signed char                                                  \
             : __lip_write_1d_array_signed_data(buf, sz, arr), signed short       \
             : __lip_write_1d_array_signed_data(buf, sz, arr), signed int         \
             : __lip_write_1d_array_signed_data(buf, sz, arr), signed long        \
             : __lip_write_1d_array_signed_data(buf, sz, arr), signed long long   \
             : __lip_write_1d_array_signed_data(buf, sz, arr), unsigned char      \
             : __lip_write_1darray_unsigned_data(buf, sz, arr), unsigned short    \
             : __lip_write_1darray_unsigned_data(buf, sz, arr), unsigned int      \
             : __lip_write_1darray_unsigned_data(buf, sz, arr), unsigned long     \
             : __lip_write_1darray_unsigned_data(buf, sz, arr), unsigned long long\
             : __lip_write_1darray_unsigned_data(buf, sz, arr))
/* clang-format on */

LIP_API void lip_write_1darray_size_type(struct lip_ctx_file *ctx,
                                         unsigned size, uint8_t type);

/* SIGNED INTEGER */

LIP_API void lip_write_1darray_i8_data(struct lip_ctx_file *ctx, unsigned size,
                                       int8_t const arr[]);
static inline void lip_write_1darray_i16_data(struct lip_ctx_file *ctx,
                                              unsigned size,
                                              int16_t const arr[])
{
}
static inline void lip_write_1darray_i32_data(struct lip_ctx_file *ctx,
                                              unsigned size,
                                              int32_t const arr[])
{
}
static inline void lip_write_1darray_i64_data(struct lip_ctx_file *ctx,
                                              unsigned size,
                                              int64_t const arr[])
{
}

/* UNSIGNED INTEGER */

LIP_API void lip_write_1darray_u8_data(struct lip_ctx_file *ctx, unsigned size,
                                       uint8_t const arr[]);
static inline void lip_write_1darray_u16_data(struct lip_ctx_file *ctx,
                                              unsigned size,
                                              uint16_t const arr[])
{
}
static inline void lip_write_1darray_u32_data(struct lip_ctx_file *ctx,
                                              unsigned size,
                                              uint32_t const arr[])
{
}
static inline void lip_write_1darray_u64_data(struct lip_ctx_file *ctx,
                                              unsigned size,
                                              uint64_t const arr[])
{
}

/* FLOAT */

/* clang-format off */
#define lip_write_1darray_float(ctx, size, arr) _Generic((*arr),              \
float  : __lip_write_1darray_f32_data,                               \
double : __lip_write_1darray_f64_data)(ctx, size, arr)
/* clang-format on */

LIP_API void __lip_write_1darray_f32_data(struct lip_ctx_file *ctx,
                                          unsigned size, float const arr[]);
LIP_API void __lip_write_1darray_f64_data(struct lip_ctx_file *ctx,
                                          unsigned size, double const arr[]);

#endif
