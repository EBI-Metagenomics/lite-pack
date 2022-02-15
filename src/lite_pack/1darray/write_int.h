#ifndef LIP_EXT_1DARRAY_WRITE_INT_H
#define LIP_EXT_1DARRAY_WRITE_INT_H

#include "lite_pack/export.h"
#include <stdint.h>

struct lip_io_file;

#define __lip_write_1darray_signed_data(io, sz, arr)                          \
    sizeof(*arr) == 1                                                          \
        ? lip_write_1darray_i8_data(io, sz, (int8_t const *)(arr))            \
    : sizeof(*arr) == 2                                                        \
        ? lip_write_1darray_i16_data(io, sz, (int16_t const *)(arr))          \
    : sizeof(*arr) == 4                                                        \
        ? lip_write_1darray_i32_data(io, sz, (int32_t const *)(arr))          \
    : sizeof(*arr) == 8                                                        \
        ? lip_write_1darray_i64_data(io, sz, (int64_t const *)(arr))          \
        : 0

#define __lip_write_1darray_unsigned_data(io, sz, arr)                        \
    sizeof(*arr) == 1                                                          \
        ? lip_write_1darray_u8_data(io, sz, (uint8_t const *)(arr))           \
    : sizeof(*arr) == 2                                                        \
        ? lip_write_1darray_u16_data(io, sz, (uint16_t const *)(arr))         \
    : sizeof(*arr) == 4                                                        \
        ? lip_write_1darray_u32_data(io, sz, (uint32_t const *)(arr))         \
    : sizeof(*arr) == 8                                                        \
        ? lip_write_1darray_u64_data(io, sz, (uint64_t const *)(arr))         \
        : 0U

#define __lip_write_1darray_int_data_typed(io, sz, arr)                       \
    _Generic((*arr), signed char                                               \
             : __lip_write_1darray_signed_data(io, sz, arr), signed short     \
             : __lip_write_1darray_signed_data(io, sz, arr), signed int       \
             : __lip_write_1darray_signed_data(io, sz, arr), signed long      \
             : __lip_write_1darray_signed_data(io, sz, arr), signed long long \
             : __lip_write_1darray_signed_data(io, sz, arr), unsigned char    \
             : __lip_write_1darray_unsigned_data(io, sz, arr), unsigned short \
             : __lip_write_1darray_unsigned_data(io, sz, arr), unsigned int   \
             : __lip_write_1darray_unsigned_data(io, sz, arr), unsigned long  \
             : __lip_write_1darray_unsigned_data(io, sz, arr),                \
               unsigned long long                                              \
             : __lip_write_1darray_unsigned_data(io, sz, arr))

#define __lip_write_1darray_int_data(io, sz, arr)                             \
    ({                                                                         \
        __auto_type tmp = (arr);                                               \
        __lip_write_1darray_int_data_typed(                                    \
            io, __builtin_constant_p(arr) ? tmp : arr);                       \
    })

/* SIGNED */

LIP_API void lip_write_1darray_i8_data(struct lip_io_file *io, unsigned size,
                                       int8_t const arr[]);

LIP_API void lip_write_1darray_i16_data(struct lip_io_file *io, unsigned size,
                                        int16_t const arr[]);

LIP_API void lip_write_1darray_i32_data(struct lip_io_file *io, unsigned size,
                                        int32_t const arr[]);

LIP_API void lip_write_1darray_i64_data(struct lip_io_file *io, unsigned size,
                                        int64_t const arr[]);

/* UNSIGNED */

LIP_API void lip_write_1darray_u8_data(struct lip_io_file *io, unsigned size,
                                       uint8_t const arr[]);

LIP_API void lip_write_1darray_u16_data(struct lip_io_file *io, unsigned size,
                                        uint16_t const arr[]);

LIP_API void lip_write_1darray_u32_data(struct lip_io_file *io, unsigned size,
                                        uint32_t const arr[]);

LIP_API void lip_write_1darray_u64_data(struct lip_io_file *io, unsigned size,
                                        uint64_t const arr[]);

#endif
