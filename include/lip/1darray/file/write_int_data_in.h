#ifndef LIP_1DARRAY_FILE_WRITE_INT_DATA_IN_H
#define LIP_1DARRAY_FILE_WRITE_INT_DATA_IN_H

#include "lip/export.h"
#include <stdbool.h>
#include <stdint.h>

struct lip_file;

#define __lip_write_1darray_signed_data_in(f, s, a)                            \
    sizeof(*a) == 1   ? lip_write_1darray_i8_data_in(f, s, (int8_t *)(a))      \
    : sizeof(*a) == 2 ? lip_write_1darray_i16_data_in(f, s, (int16_t *)(a))    \
    : sizeof(*a) == 4 ? lip_write_1darray_i32_data_in(f, s, (int32_t *)(a))    \
    : sizeof(*a) == 8 ? lip_write_1darray_i64_data_in(f, s, (int64_t *)(a))    \
                      : 0

#define __lip_write_1darray_unsigned_data_in(f, s, a)                          \
    sizeof(*a) == 1   ? lip_write_1darray_u8_data_in(f, s, (uint8_t *)(a))     \
    : sizeof(*a) == 2 ? lip_write_1darray_u16_data_in(f, s, (uint16_t *)(a))   \
    : sizeof(*a) == 4 ? lip_write_1darray_u32_data_in(f, s, (uint32_t *)(a))   \
    : sizeof(*a) == 8 ? lip_write_1darray_u64_data_in(f, s, (uint64_t *)(a))   \
                      : 0U

#define lip_write_1darray_int_data_in(f, s, a)                                 \
    _Generic((*a), signed char                                                 \
             : __lip_write_1darray_signed_data_in(f, s, a), signed short       \
             : __lip_write_1darray_signed_data_in(f, s, a), signed int         \
             : __lip_write_1darray_signed_data_in(f, s, a), signed long        \
             : __lip_write_1darray_signed_data_in(f, s, a), signed long long   \
             : __lip_write_1darray_signed_data_in(f, s, a), unsigned char      \
             : __lip_write_1darray_unsigned_data_in(f, s, a), unsigned short   \
             : __lip_write_1darray_unsigned_data_in(f, s, a), unsigned int     \
             : __lip_write_1darray_unsigned_data_in(f, s, a), unsigned long    \
             : __lip_write_1darray_unsigned_data_in(f, s, a),                  \
               unsigned long long                                              \
             : __lip_write_1darray_unsigned_data_in(f, s, a))

/* SIGNED */

LIP_API bool lip_write_1darray_i8_data_in(struct lip_file *file, unsigned size,
                                          int8_t arr[]);

LIP_API bool lip_write_1darray_i16_data_in(struct lip_file *file, unsigned size,
                                           int16_t arr[]);

LIP_API bool lip_write_1darray_i32_data_in(struct lip_file *file, unsigned size,
                                           int32_t arr[]);

LIP_API bool lip_write_1darray_i64_data_in(struct lip_file *file, unsigned size,
                                           int64_t arr[]);

/* UNSIGNED */

LIP_API bool lip_write_1darray_u8_data_in(struct lip_file *file, unsigned size,
                                          uint8_t arr[]);

LIP_API bool lip_write_1darray_u16_data_in(struct lip_file *file, unsigned size,
                                           uint16_t arr[]);

LIP_API bool lip_write_1darray_u32_data_in(struct lip_file *file, unsigned size,
                                           uint32_t arr[]);

LIP_API bool lip_write_1darray_u64_data_in(struct lip_file *file, unsigned size,
                                           uint64_t arr[]);

#endif
