#ifndef LIP_1DARRAY_FILE_WRITE_INT_DATA_H
#define LIP_1DARRAY_FILE_WRITE_INT_DATA_H

#include "lip/export.h"
#include "lip/file/file.h"
#include "lip/store_int.h"
#include <stdint.h>

struct lip_file;

#define __lip_write_1darray_signed_data(f, s, a)                               \
    sizeof(*a) == 1   ? lip_write_1darray_i8_data(f, s, (int8_t const *)(a))   \
    : sizeof(*a) == 2 ? lip_write_1darray_i16_data(f, s, (int16_t const *)(a)) \
    : sizeof(*a) == 4 ? lip_write_1darray_i32_data(f, s, (int32_t const *)(a)) \
    : sizeof(*a) == 8 ? lip_write_1darray_i64_data(f, s, (int64_t const *)(a)) \
                      : 0

#define __lip_write_1darray_unsigned_data(f, s, a)                             \
    sizeof(*a) == 1 ? lip_write_1darray_u8_data(f, s, (uint8_t const *)(a))    \
    : sizeof(*a) == 2                                                          \
        ? lip_write_1darray_u16_data(f, s, (uint16_t const *)(a))              \
    : sizeof(*a) == 4                                                          \
        ? lip_write_1darray_u32_data(f, s, (uint32_t const *)(a))              \
    : sizeof(*a) == 8                                                          \
        ? lip_write_1darray_u64_data(f, s, (uint64_t const *)(a))              \
        : 0U

#define lip_write_1darray_int_data(f, s, a)                                    \
    _Generic((*a), signed char                                                 \
             : __lip_write_1darray_signed_data(f, s, a), signed short          \
             : __lip_write_1darray_signed_data(f, s, a), signed int            \
             : __lip_write_1darray_signed_data(f, s, a), signed long           \
             : __lip_write_1darray_signed_data(f, s, a), signed long long      \
             : __lip_write_1darray_signed_data(f, s, a), unsigned char         \
             : __lip_write_1darray_unsigned_data(f, s, a), unsigned short      \
             : __lip_write_1darray_unsigned_data(f, s, a), unsigned int        \
             : __lip_write_1darray_unsigned_data(f, s, a), unsigned long       \
             : __lip_write_1darray_unsigned_data(f, s, a), unsigned long long  \
             : __lip_write_1darray_unsigned_data(f, s, a))

/* SIGNED */

LIP_API bool lip_write_1darray_i8_data(struct lip_file *file, unsigned size,
                                       int8_t const arr[]);

LIP_API bool lip_write_1darray_i16_data(struct lip_file *file, unsigned size,
                                        int16_t const arr[]);

LIP_API bool lip_write_1darray_i32_data(struct lip_file *file, unsigned size,
                                        int32_t const arr[]);

LIP_API bool lip_write_1darray_i64_data(struct lip_file *file, unsigned size,
                                        int64_t const arr[]);

/* UNSIGNED */

LIP_API bool lip_write_1darray_u8_data(struct lip_file *file, unsigned size,
                                       uint8_t const arr[]);

LIP_API bool lip_write_1darray_u16_data(struct lip_file *file, unsigned size,
                                        uint16_t const arr[]);

LIP_API bool lip_write_1darray_u32_data(struct lip_file *file, unsigned size,
                                        uint32_t const arr[]);

LIP_API bool lip_write_1darray_u64_data(struct lip_file *file, unsigned size,
                                        uint64_t const arr[]);

#endif
