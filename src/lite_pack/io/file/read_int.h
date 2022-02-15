#ifndef LIP_IO_FILE_READ_INT_H
#define LIP_IO_FILE_READ_INT_H

#include "lite_pack/export.h"
#include <stdint.h>

#define __lip_read_signed(io, v)                                               \
    sizeof(*v) == 1   ? __lip_read_i8(io, (int8_t *)(v))                       \
    : sizeof(*v) == 2 ? __lip_read_i16(io, (int16_t *)(v))                     \
    : sizeof(*v) == 4 ? __lip_read_i32(io, (int32_t *)(v))                     \
    : sizeof(*v) == 8 ? __lip_read_i64(io, (int64_t *)(v))                     \
                      : 0

#define __lip_read_unsigned(io, v)                                             \
    sizeof(*v) == 1   ? __lip_read_u8(io, (uint8_t *)(v))                      \
    : sizeof(*v) == 2 ? __lip_read_u16(io, (uint16_t *)(v))                    \
    : sizeof(*v) == 4 ? __lip_read_u32(io, (uint32_t *)(v))                    \
    : sizeof(*v) == 8 ? __lip_read_u64(io, (uint64_t *)(v))                    \
                      : 0U

#define __lip_read_int(io, v)                                                  \
    _Generic((*v), signed char                                                 \
             : __lip_read_signed(io, v), signed short                          \
             : __lip_read_signed(io, v), signed int                            \
             : __lip_read_signed(io, v), signed long                           \
             : __lip_read_signed(io, v), signed long long                      \
             : __lip_read_signed(io, v), unsigned char                         \
             : __lip_read_unsigned(io, v), unsigned short                      \
             : __lip_read_unsigned(io, v), unsigned int                        \
             : __lip_read_unsigned(io, v), unsigned long                       \
             : __lip_read_unsigned(io, v), unsigned long long                  \
             : __lip_read_unsigned(io, v))

struct lip_io_file;

/* SIGNED */

LIP_API void __lip_read_i8(struct lip_io_file *, int8_t *val);
LIP_API void __lip_read_i16(struct lip_io_file *, int16_t *val);
LIP_API void __lip_read_i32(struct lip_io_file *, int32_t *val);
LIP_API void __lip_read_i64(struct lip_io_file *, int64_t *val);

/* UNSIGNED */

LIP_API void __lip_read_u8(struct lip_io_file *, uint8_t *val);
LIP_API void __lip_read_u16(struct lip_io_file *, uint16_t *val);
LIP_API void __lip_read_u32(struct lip_io_file *, uint32_t *val);
LIP_API void __lip_read_u64(struct lip_io_file *, uint64_t *val);

#endif
