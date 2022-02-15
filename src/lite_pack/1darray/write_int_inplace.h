#ifndef LIP_EXT_1DARRAY_WRITE_INT_INPLACE_H
#define LIP_EXT_1DARRAY_WRITE_INT_INPLACE_H

#include "lite_pack/export.h"
#include <stdint.h>

struct lip_io_file;

#define __lip_write_1darray_signed_data_inplace(io, sz, arr)                  \
    sizeof(*arr) == 1                                                          \
        ? lip_write_1darray_i8_data_inplace(io, sz, (int8_t *)(arr))          \
    : sizeof(*arr) == 2                                                        \
        ? lip_write_1darray_i16_data_inplace(io, sz, (int16_t *)(arr))        \
    : sizeof(*arr) == 4                                                        \
        ? lip_write_1darray_i32_data_inplace(io, sz, (int32_t *)(arr))        \
    : sizeof(*arr) == 8                                                        \
        ? lip_write_1darray_i64_data_inplace(io, sz, (int64_t *)(arr))        \
        : 0

#define __lip_write_1darray_unsigned_data_inplace(io, sz, arr)                \
    sizeof(*arr) == 1                                                          \
        ? lip_write_1darray_u8_data_inplace(io, sz, (uint8_t *)(arr))         \
    : sizeof(*arr) == 2                                                        \
        ? lip_write_1darray_u16_data_inplace(io, sz, (uint16_t *)(arr))       \
    : sizeof(*arr) == 4                                                        \
        ? lip_write_1darray_u32_data_inplace(io, sz, (uint32_t *)(arr))       \
    : sizeof(*arr) == 8                                                        \
        ? lip_write_1darray_u64_data_inplace(io, sz, (uint64_t *)(arr))       \
        : 0U

#define __lip_write_1darray_int_data_inplace(io, sz, arr)                     \
    _Generic(                                                                  \
        (*arr), signed char                                                    \
        : __lip_write_1darray_signed_data_inplace(io, sz, arr), signed short  \
        : __lip_write_1darray_signed_data_inplace(io, sz, arr), signed int    \
        : __lip_write_1darray_signed_data_inplace(io, sz, arr), signed long   \
        : __lip_write_1darray_signed_data_inplace(io, sz, arr),               \
          signed long long                                                     \
        : __lip_write_1darray_signed_data_inplace(io, sz, arr), unsigned char \
        : __lip_write_1darray_unsigned_data_inplace(io, sz, arr),             \
          unsigned short                                                       \
        : __lip_write_1darray_unsigned_data_inplace(io, sz, arr),             \
          unsigned int                                                         \
        : __lip_write_1darray_unsigned_data_inplace(io, sz, arr),             \
          unsigned long                                                        \
        : __lip_write_1darray_unsigned_data_inplace(io, sz, arr),             \
          unsigned long long                                                   \
        : __lip_write_1darray_unsigned_data_inplace(io, sz, arr))

/* SIGNED */

LIP_API void lip_write_1darray_i8_data_inplace(struct lip_io_file *io,
                                               unsigned size, int8_t arr[]);

LIP_API void lip_write_1darray_i16_data_inplace(struct lip_io_file *io,
                                                unsigned size, int16_t arr[]);

LIP_API void lip_write_1darray_i32_data_inplace(struct lip_io_file *io,
                                                unsigned size, int32_t arr[]);

LIP_API void lip_write_1darray_i64_data_inplace(struct lip_io_file *io,
                                                unsigned size, int64_t arr[]);

/* UNSIGNED */

LIP_API void lip_write_1darray_u8_data_inplace(struct lip_io_file *io,
                                               unsigned size, uint8_t arr[]);

LIP_API void lip_write_1darray_u16_data_inplace(struct lip_io_file *io,
                                                unsigned size, uint16_t arr[]);

LIP_API void lip_write_1darray_u32_data_inplace(struct lip_io_file *io,
                                                unsigned size, uint32_t arr[]);

LIP_API void lip_write_1darray_u64_data_inplace(struct lip_io_file *io,
                                                unsigned size, uint64_t arr[]);

#endif
