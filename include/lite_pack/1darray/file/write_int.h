#ifndef LITE_PACK_1DARRAY_FILE_WRITE_INT_H
#define LITE_PACK_1DARRAY_FILE_WRITE_INT_H

#include "lite_pack/export.h"
#include "lite_pack/file/file.h"
#include "lite_pack/store_int.h"
#include <stdint.h>

struct lip_file;

#define __lip_write_1darray_signed(f, s, a)                                    \
    sizeof(*a) == 1   ? lip_write_1darray_i8(f, s, (int8_t const *)(a))        \
    : sizeof(*a) == 2 ? lip_write_1darray_i16(f, s, (int16_t const *)(a))      \
    : sizeof(*a) == 4 ? lip_write_1darray_i32(f, s, (int32_t const *)(a))      \
    : sizeof(*a) == 8 ? lip_write_1darray_i64(f, s, (int64_t const *)(a))      \
                      : 0

#define __lip_write_1darray_unsigned(f, s, a)                                  \
    sizeof(*a) == 1   ? lip_write_1darray_u8(f, s, (uint8_t const *)(a))       \
    : sizeof(*a) == 2 ? lip_write_1darray_u16(f, s, (uint16_t const *)(a))     \
    : sizeof(*a) == 4 ? lip_write_1darray_u32(f, s, (uint32_t const *)(a))     \
    : sizeof(*a) == 8 ? lip_write_1darray_u64(f, s, (uint64_t const *)(a))     \
                      : 0U

#define lip_write_1darray_int(f, s, a)                                         \
    _Generic((*a), signed char                                                 \
             : __lip_write_1darray_signed(f, s, a), signed short               \
             : __lip_write_1darray_signed(f, s, a), signed int                 \
             : __lip_write_1darray_signed(f, s, a), signed long                \
             : __lip_write_1darray_signed(f, s, a), signed long long           \
             : __lip_write_1darray_signed(f, s, a), unsigned char              \
             : __lip_write_1darray_unsigned(f, s, a), unsigned short           \
             : __lip_write_1darray_unsigned(f, s, a), unsigned int             \
             : __lip_write_1darray_unsigned(f, s, a), unsigned long            \
             : __lip_write_1darray_unsigned(f, s, a), unsigned long long       \
             : __lip_write_1darray_unsigned(f, s, a))

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
