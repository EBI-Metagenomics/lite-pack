#ifndef LIP_IO_FILE_READ_INT_H
#define LIP_IO_FILE_READ_INT_H

#include "lite_pack/export.h"
#include <stdint.h>

#define __lip_read_signed(ctx, val)                                            \
    sizeof(*val) == 1   ? __lip_read_i8(ctx, (int8_t *)(val))                  \
    : sizeof(*val) == 2 ? __lip_read_i16(ctx, (int16_t *)(val))                \
    : sizeof(*val) == 4 ? __lip_read_i32(ctx, (int32_t *)(val))                \
    : sizeof(*val) == 8 ? __lip_read_i64(ctx, (int64_t *)(val))                \
                        : 0

#define __lip_read_unsigned(ctx, val)                                          \
    sizeof(*val) == 1   ? __lip_read_u8(ctx, (uint8_t *)(val))                 \
    : sizeof(*val) == 2 ? __lip_read_u16(ctx, (uint16_t *)(val))               \
    : sizeof(*val) == 4 ? __lip_read_u32(ctx, (uint32_t *)(val))               \
    : sizeof(*val) == 8 ? __lip_read_u64(ctx, (uint64_t *)(val))               \
                        : 0U

#define __lip_read_int(ctx, val)                                               \
    _Generic((*val), signed char                                               \
             : __lip_read_signed(ctx, val), signed short                       \
             : __lip_read_signed(ctx, val), signed int                         \
             : __lip_read_signed(ctx, val), signed long                        \
             : __lip_read_signed(ctx, val), signed long long                   \
             : __lip_read_signed(ctx, val), unsigned char                      \
             : __lip_read_unsigned(ctx, val), unsigned short                   \
             : __lip_read_unsigned(ctx, val), unsigned int                     \
             : __lip_read_unsigned(ctx, val), unsigned long                    \
             : __lip_read_unsigned(ctx, val), unsigned long long               \
             : __lip_read_unsigned(ctx, val))

struct lip_ctx_file;

/* SIGNED INTEGER */

LIP_API void __lip_read_i8(struct lip_ctx_file *ctx, int8_t *val);
LIP_API void __lip_read_i16(struct lip_ctx_file *ctx, int16_t *val);
LIP_API void __lip_read_i32(struct lip_ctx_file *ctx, int32_t *val);
LIP_API void __lip_read_i64(struct lip_ctx_file *ctx, int64_t *val);

/* UNSIGNED INTEGER */

LIP_API void __lip_read_u8(struct lip_ctx_file *ctx, uint8_t *val);
LIP_API void __lip_read_u16(struct lip_ctx_file *ctx, uint16_t *val);
LIP_API void __lip_read_u32(struct lip_ctx_file *ctx, uint32_t *val);
LIP_API void __lip_read_u64(struct lip_ctx_file *ctx, uint64_t *val);

#endif
