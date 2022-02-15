#ifndef LIP_EXT_1DARRAY_READ_INT_H
#define LIP_EXT_1DARRAY_READ_INT_H

#include "lite_pack/export.h"
#include <stdint.h>

struct lip_io_file;

#define __lip_read_1darray_signed_data(ctx, arr)                               \
    sizeof(*arr) == 1   ? lip_read_1darray_i8_data(ctx, (int8_t *)(arr))       \
    : sizeof(*arr) == 2 ? lip_read_1darray_i16_data(ctx, (int16_t *)(arr))     \
    : sizeof(*arr) == 4 ? lip_read_1darray_i32_data(ctx, (int32_t *)(arr))     \
    : sizeof(*arr) == 8 ? lip_read_1darray_i64_data(ctx, (int64_t *)(arr))     \
                        : 0

#define __lip_read_1darray_unsigned(ctx, arr)                                  \
    sizeof(*arr) == 1   ? lip_read_1darray_u8_data(ctx, (uint8_t *)(arr))      \
    : sizeof(*arr) == 2 ? lip_read_1darray_u16_data(ctx, (uint16_t *)(arr))    \
    : sizeof(*arr) == 4 ? lip_read_1darray_u32_data(ctx, (uint32_t *)(arr))    \
    : sizeof(*arr) == 8 ? lip_read_1darray_u64_data(ctx, (uint64_t *)(arr))    \
                        : 0U

#define __lip_read_1darray_int(ctx, arr)                                       \
    _Generic((*arr), signed char                                               \
             : __lip_read_1darray_signed_data(ctx, arr), signed short          \
             : __lip_read_1darray_signed_data(ctx, arr), signed int            \
             : __lip_read_1darray_signed_data(ctx, arr), signed long           \
             : __lip_read_1darray_signed_data(ctx, arr), signed long long      \
             : __lip_read_1darray_signed_data(ctx, arr), unsigned char         \
             : __lip_read_1darray_unsigned(ctx, arr), unsigned short           \
             : __lip_read_1darray_unsigned(ctx, arr), unsigned int             \
             : __lip_read_1darray_unsigned(ctx, arr), unsigned long            \
             : __lip_read_1darray_unsigned(ctx, arr), unsigned long long       \
             : __lip_read_1darray_unsigned(ctx, arr))

/* SIGNED */

LIP_API void lip_read_1darray_i8_data(struct lip_io_file *ctx, unsigned size,
                                      int8_t arr[]);

LIP_API void lip_read_1darray_i16_data(struct lip_io_file *ctx, unsigned size,
                                       int16_t arr[]);

LIP_API void lip_read_1darray_i32_data(struct lip_io_file *ctx, unsigned size,
                                       int32_t arr[]);

LIP_API void lip_read_1darray_i64_data(struct lip_io_file *ctx, unsigned size,
                                       int64_t arr[]);

/* UNSIGNED */

LIP_API void lip_read_1darray_u8_data(struct lip_io_file *ctx, unsigned size,
                                      uint8_t arr[]);

LIP_API void lip_read_1darray_u16_data(struct lip_io_file *ctx, unsigned size,
                                       uint16_t arr[]);

LIP_API void lip_read_1darray_u32_data(struct lip_io_file *ctx, unsigned size,
                                       uint32_t arr[]);

LIP_API void lip_read_1darray_u64_data(struct lip_io_file *ctx, unsigned size,
                                       uint64_t arr[]);

#endif
