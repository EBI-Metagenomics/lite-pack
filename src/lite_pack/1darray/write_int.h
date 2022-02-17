#ifndef LIP_1DARRAY_WRITE_INT_H
#define LIP_1DARRAY_WRITE_INT_H

#include "lite_pack/export.h"
#include "lite_pack/file/file.h"
#include "lite_pack/store_int.h"
#include <stdint.h>

struct lip_file;

#define __lip_write_1darray_signed(i, s, a)                                    \
    sizeof(*a) == 1   ? lip_write_1darray_i8(i, s, (int8_t const *)(a))        \
    : sizeof(*a) == 2 ? lip_write_1darray_i16(i, s, (int16_t const *)(a))      \
    : sizeof(*a) == 4 ? lip_write_1darray_i32(i, s, (int32_t const *)(a))      \
    : sizeof(*a) == 8 ? lip_write_1darray_i64(i, s, (int64_t const *)(a))      \
                      : 0

#define __lip_write_1darray_unsigned(i, s, a)                                  \
    sizeof(*a) == 1   ? lip_write_1darray_u8(i, s, (uint8_t const *)(a))       \
    : sizeof(*a) == 2 ? lip_write_1darray_u16(i, s, (uint16_t const *)(a))     \
    : sizeof(*a) == 4 ? lip_write_1darray_u32(i, s, (uint32_t const *)(a))     \
    : sizeof(*a) == 8 ? lip_write_1darray_u64(i, s, (uint64_t const *)(a))     \
                      : 0U

#define __lip_write_1darray_int_typed(i, s, a)                                 \
    _Generic((*a), signed char                                                 \
             : __lip_write_1darray_signed(i, s, a), signed short               \
             : __lip_write_1darray_signed(i, s, a), signed int                 \
             : __lip_write_1darray_signed(i, s, a), signed long                \
             : __lip_write_1darray_signed(i, s, a), signed long long           \
             : __lip_write_1darray_signed(i, s, a), unsigned char              \
             : __lip_write_1darray_unsigned(i, s, a), unsigned short           \
             : __lip_write_1darray_unsigned(i, s, a), unsigned int             \
             : __lip_write_1darray_unsigned(i, s, a), unsigned long            \
             : __lip_write_1darray_unsigned(i, s, a), unsigned long long       \
             : __lip_write_1darray_unsigned(i, s, a))

#define __lip_write_1darray_int(i, s, a)                                       \
    __lip_write_1darray_int_typed(i, s, (a))

/* SIGNED */

LIP_API void lip_write_1darray_i8(struct lip_file *io, unsigned size,
                                  int8_t const arr[]);

LIP_API void lip_write_1darray_i16(struct lip_file *io, unsigned size,
                                   int16_t const arr[]);

LIP_API void lip_write_1darray_i32(struct lip_file *io, unsigned size,
                                   int32_t const arr[]);

LIP_API void lip_write_1darray_i64(struct lip_file *io, unsigned size,
                                   int64_t const arr[]);

/* UNSIGNED */

LIP_API void lip_write_1darray_u8(struct lip_file *io, unsigned size,
                                  uint8_t const arr[]);

LIP_API void lip_write_1darray_u16(struct lip_file *io, unsigned size,
                                   uint16_t const arr[]);

LIP_API void lip_write_1darray_u32(struct lip_file *io, unsigned size,
                                   uint32_t const arr[]);

LIP_API void lip_write_1darray_u64(struct lip_file *io, unsigned size,
                                   uint64_t const arr[]);

#endif
