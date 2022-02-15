#ifndef LIP_IO_FILE_WRITE_INT_H
#define LIP_IO_FILE_WRITE_INT_H

#include "lite_pack/export.h"
#include <stdint.h>

#define __lip_write_signed(ctx, v)                                             \
    sizeof(v) == 1   ? __lip_write_i8(ctx, (int8_t)(v))                        \
    : sizeof(v) == 2 ? __lip_write_i16(ctx, (int16_t)(v))                      \
    : sizeof(v) == 4 ? __lip_write_i32(ctx, (int32_t)(v))                      \
    : sizeof(v) == 8 ? __lip_write_i64(ctx, (int64_t)(v))                      \
                     : 0

#define __lip_write_unsigned(ctx, v)                                           \
    sizeof(v) == 1   ? __lip_write_u8(ctx, (uint8_t)(v))                       \
    : sizeof(v) == 2 ? __lip_write_u16(ctx, (uint16_t)(v))                     \
    : sizeof(v) == 4 ? __lip_write_u32(ctx, (uint32_t)(v))                     \
    : sizeof(v) == 8 ? __lip_write_u64(ctx, (uint64_t)(v))                     \
                     : 0U

#define __lip_write_int_typed(ctx, v)                                          \
    _Generic((v), signed char                                                  \
             : __lip_write_signed(ctx, v), signed short                        \
             : __lip_write_signed(ctx, v), signed int                          \
             : __lip_write_signed(ctx, v), signed long                         \
             : __lip_write_signed(ctx, v), signed long long                    \
             : __lip_write_signed(ctx, v), unsigned char                       \
             : __lip_write_unsigned(ctx, v), unsigned short                    \
             : __lip_write_unsigned(ctx, v), unsigned int                      \
             : __lip_write_unsigned(ctx, v), unsigned long                     \
             : __lip_write_unsigned(ctx, v), unsigned long long                \
             : __lip_write_unsigned(ctx, v))

#define __lip_write_int(ctx, val)                                              \
    ({                                                                         \
        typeof(val) tmp = (val);                                               \
        __lip_write_int_typed(ctx, __builtin_constant_p(val) ? tmp : val);     \
    })

struct lip_io_file;

LIP_API void __lip_write_i8(struct lip_io_file *ctx, int val);
LIP_API void __lip_write_i16(struct lip_io_file *ctx, int val);
LIP_API void __lip_write_i32(struct lip_io_file *ctx, int val);
LIP_API void __lip_write_i64(struct lip_io_file *ctx, long val);

LIP_API void __lip_write_u8(struct lip_io_file *ctx, unsigned val);
LIP_API void __lip_write_u16(struct lip_io_file *ctx, unsigned val);
LIP_API void __lip_write_u32(struct lip_io_file *ctx, unsigned val);
LIP_API void __lip_write_u64(struct lip_io_file *ctx, unsigned long val);

#endif
