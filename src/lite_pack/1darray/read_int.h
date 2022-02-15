#ifndef LIP_EXT_1DARRAY_READ_INT_H
#define LIP_EXT_1DARRAY_READ_INT_H

#include "lite_pack/export.h"
#include <stdint.h>

struct lip_io_file;

#define __lip_read_1darray_signed_data(io, arr)                               \
    sizeof(*arr) == 1   ? lip_read_1darray_i8_data(io, (int8_t *)(arr))       \
    : sizeof(*arr) == 2 ? lip_read_1darray_i16_data(io, (int16_t *)(arr))     \
    : sizeof(*arr) == 4 ? lip_read_1darray_i32_data(io, (int32_t *)(arr))     \
    : sizeof(*arr) == 8 ? lip_read_1darray_i64_data(io, (int64_t *)(arr))     \
                        : 0

#define __lip_read_1darray_unsigned(io, arr)                                  \
    sizeof(*arr) == 1   ? lip_read_1darray_u8_data(io, (uint8_t *)(arr))      \
    : sizeof(*arr) == 2 ? lip_read_1darray_u16_data(io, (uint16_t *)(arr))    \
    : sizeof(*arr) == 4 ? lip_read_1darray_u32_data(io, (uint32_t *)(arr))    \
    : sizeof(*arr) == 8 ? lip_read_1darray_u64_data(io, (uint64_t *)(arr))    \
                        : 0U

#define __lip_read_1darray_int(io, arr)                                       \
    _Generic((*arr), signed char                                               \
             : __lip_read_1darray_signed_data(io, arr), signed short          \
             : __lip_read_1darray_signed_data(io, arr), signed int            \
             : __lip_read_1darray_signed_data(io, arr), signed long           \
             : __lip_read_1darray_signed_data(io, arr), signed long long      \
             : __lip_read_1darray_signed_data(io, arr), unsigned char         \
             : __lip_read_1darray_unsigned(io, arr), unsigned short           \
             : __lip_read_1darray_unsigned(io, arr), unsigned int             \
             : __lip_read_1darray_unsigned(io, arr), unsigned long            \
             : __lip_read_1darray_unsigned(io, arr), unsigned long long       \
             : __lip_read_1darray_unsigned(io, arr))

/* SIGNED */

LIP_API void lip_read_1darray_i8_data(struct lip_io_file *io, unsigned size,
                                      int8_t arr[]);

LIP_API void lip_read_1darray_i16_data(struct lip_io_file *io, unsigned size,
                                       int16_t arr[]);

LIP_API void lip_read_1darray_i32_data(struct lip_io_file *io, unsigned size,
                                       int32_t arr[]);

LIP_API void lip_read_1darray_i64_data(struct lip_io_file *io, unsigned size,
                                       int64_t arr[]);

/* UNSIGNED */

LIP_API void lip_read_1darray_u8_data(struct lip_io_file *io, unsigned size,
                                      uint8_t arr[]);

LIP_API void lip_read_1darray_u16_data(struct lip_io_file *io, unsigned size,
                                       uint16_t arr[]);

LIP_API void lip_read_1darray_u32_data(struct lip_io_file *io, unsigned size,
                                       uint32_t arr[]);

LIP_API void lip_read_1darray_u64_data(struct lip_io_file *io, unsigned size,
                                       uint64_t arr[]);

#endif
