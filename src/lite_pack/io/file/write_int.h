#ifndef LIP_IO_FILE_WRITE_INT_H
#define LIP_IO_FILE_WRITE_INT_H

#include "lite_pack/export.h"
#include <stdbool.h>
#include <stdint.h>

#define __lip_write_signed(io, v)                                              \
    sizeof(v) == 1   ? __lip_write_i8(io, (int8_t)(v))                         \
    : sizeof(v) == 2 ? __lip_write_i16(io, (int16_t)(v))                       \
    : sizeof(v) == 4 ? __lip_write_i32(io, (int32_t)(v))                       \
    : sizeof(v) == 8 ? __lip_write_i64(io, (int64_t)(v))                       \
                     : 0

#define __lip_write_unsigned(io, v)                                            \
    sizeof(v) == 1   ? __lip_write_u8(io, (uint8_t)(v))                        \
    : sizeof(v) == 2 ? __lip_write_u16(io, (uint16_t)(v))                      \
    : sizeof(v) == 4 ? __lip_write_u32(io, (uint32_t)(v))                      \
    : sizeof(v) == 8 ? __lip_write_u64(io, (uint64_t)(v))                      \
                     : 0U

#define __lip_write_int_typed(io, v)                                           \
    _Generic((v), signed char                                                  \
             : __lip_write_signed(io, v), signed short                         \
             : __lip_write_signed(io, v), signed int                           \
             : __lip_write_signed(io, v), signed long                          \
             : __lip_write_signed(io, v), signed long long                     \
             : __lip_write_signed(io, v), unsigned char                        \
             : __lip_write_unsigned(io, v), unsigned short                     \
             : __lip_write_unsigned(io, v), unsigned int                       \
             : __lip_write_unsigned(io, v), unsigned long                      \
             : __lip_write_unsigned(io, v), unsigned long long                 \
             : __lip_write_unsigned(io, v))

#define __lip_write_int(io, v)                                                 \
    ({                                                                         \
        __auto_type tmp = (v);                                                 \
        __lip_write_int_typed(io, (__builtin_constant_p(v) ? tmp : v));        \
    })

struct lip_io_file;

LIP_API bool __lip_write_i8(struct lip_io_file *, int val);
LIP_API bool __lip_write_i16(struct lip_io_file *, int val);
LIP_API bool __lip_write_i32(struct lip_io_file *, int val);
LIP_API bool __lip_write_i64(struct lip_io_file *, long val);

LIP_API bool __lip_write_u8(struct lip_io_file *, unsigned val);
LIP_API bool __lip_write_u16(struct lip_io_file *, unsigned val);
LIP_API bool __lip_write_u32(struct lip_io_file *, unsigned val);
LIP_API bool __lip_write_u64(struct lip_io_file *, unsigned long val);

#endif
