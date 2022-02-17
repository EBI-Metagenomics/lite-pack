#ifndef LIP_1DARRAY_WRITE_INT_DATA_H
#define LIP_1DARRAY_WRITE_INT_DATA_H

#include "lite_pack/export.h"
#include "lite_pack/io/file.h"
#include "lite_pack/store_int.h"
#include <stdint.h>

struct lip_file;

#define __lip_write_1darray_signed_data(i, s, a)                               \
    sizeof(*a) == 1   ? lip_write_1darray_i8_data(i, s, (int8_t const *)(a))   \
    : sizeof(*a) == 2 ? lip_write_1darray_i16_data(i, s, (int16_t const *)(a)) \
    : sizeof(*a) == 4 ? lip_write_1darray_i32_data(i, s, (int32_t const *)(a)) \
    : sizeof(*a) == 8 ? lip_write_1darray_i64_data(i, s, (int64_t const *)(a)) \
                      : 0

#define __lip_write_1darray_unsigned_data(i, s, a)                             \
    sizeof(*a) == 1 ? lip_write_1darray_u8_data(i, s, (uint8_t const *)(a))    \
    : sizeof(*a) == 2                                                          \
        ? lip_write_1darray_u16_data(i, s, (uint16_t const *)(a))              \
    : sizeof(*a) == 4                                                          \
        ? lip_write_1darray_u32_data(i, s, (uint32_t const *)(a))              \
    : sizeof(*a) == 8                                                          \
        ? lip_write_1darray_u64_data(i, s, (uint64_t const *)(a))              \
        : 0U

#define __lip_write_1darray_int_data_typed(i, s, a)                            \
    _Generic((*a), signed char                                                 \
             : __lip_write_1darray_signed_data(i, s, a), signed short          \
             : __lip_write_1darray_signed_data(i, s, a), signed int            \
             : __lip_write_1darray_signed_data(i, s, a), signed long           \
             : __lip_write_1darray_signed_data(i, s, a), signed long long      \
             : __lip_write_1darray_signed_data(i, s, a), unsigned char         \
             : __lip_write_1darray_unsigned_data(i, s, a), unsigned short      \
             : __lip_write_1darray_unsigned_data(i, s, a), unsigned int        \
             : __lip_write_1darray_unsigned_data(i, s, a), unsigned long       \
             : __lip_write_1darray_unsigned_data(i, s, a), unsigned long long  \
             : __lip_write_1darray_unsigned_data(i, s, a))

#define __lip_write_1darray_int_data(i, s, a)                                  \
    __lip_write_1darray_int_data_typed(i, s, (a));

/* SIGNED */

LIP_API void lip_write_1darray_i8_data(struct lip_file *io, unsigned size,
                                       int8_t const arr[]);

LIP_API void lip_write_1darray_i16_data(struct lip_file *io, unsigned size,
                                        int16_t const arr[]);

LIP_API void lip_write_1darray_i32_data(struct lip_file *io, unsigned size,
                                        int32_t const arr[]);

LIP_API void lip_write_1darray_i64_data(struct lip_file *io, unsigned size,
                                        int64_t const arr[]);

/* UNSIGNED */

LIP_API void lip_write_1darray_u8_data(struct lip_file *io, unsigned size,
                                       uint8_t const arr[]);

LIP_API void lip_write_1darray_u16_data(struct lip_file *io, unsigned size,
                                        uint16_t const arr[]);

LIP_API void lip_write_1darray_u32_data(struct lip_file *io, unsigned size,
                                        uint32_t const arr[]);

LIP_API void lip_write_1darray_u64_data(struct lip_file *io, unsigned size,
                                        uint64_t const arr[]);

#endif
