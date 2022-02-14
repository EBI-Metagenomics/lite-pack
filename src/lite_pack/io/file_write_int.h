#ifndef LIP_IO_FILE_WRITE_INT_H
#define LIP_IO_FILE_WRITE_INT_H

#include "lite_pack/export.h"

#define __lip_write_signed(ctx, val)                                           \
    sizeof(val) == 1   ? __lip_write_i8(ctx, (int8_t)(val))                    \
    : sizeof(val) == 2 ? __lip_write_i16(ctx, (int16_t)(val))                  \
    : sizeof(val) == 4 ? __lip_write_i32(ctx, (int32_t)(val))                  \
    : sizeof(val) == 8 ? __lip_write_i64(ctx, (int64_t)(val))                  \
                       : 0

#define __lip_write_unsigned(ctx, val)                                         \
    sizeof(val) == 1   ? __lip_write_u8(ctx, (uint8_t)(val))                   \
    : sizeof(val) == 2 ? __lip_write_u16(ctx, (uint16_t)(val))                 \
    : sizeof(val) == 4 ? __lip_write_u32(ctx, (uint32_t)(val))                 \
    : sizeof(val) == 8 ? __lip_write_u64(ctx, (uint64_t)(val))                 \
                       : 0U

#define __lip_write_int(ctx, val)                                              \
    _Generic((val), signed char                                                \
             : __lip_write_signed(ctx, val), signed short                      \
             : __lip_write_signed(ctx, val), signed int                        \
             : __lip_write_signed(ctx, val), signed long                       \
             : __lip_write_signed(ctx, val), signed long long                  \
             : __lip_write_signed(ctx, val), unsigned char                     \
             : __lip_write_unsigned(ctx, val), unsigned short                  \
             : __lip_write_unsigned(ctx, val), unsigned int                    \
             : __lip_write_unsigned(ctx, val), unsigned long                   \
             : __lip_write_unsigned(ctx, val), unsigned long long              \
             : __lip_write_unsigned(ctx, val))

struct lip_ctx_file;

LIP_API void __lip_write_i8(struct lip_ctx_file *ctx, int val);
LIP_API void __lip_write_i16(struct lip_ctx_file *ctx, int val);
LIP_API void __lip_write_i32(struct lip_ctx_file *ctx, int val);
LIP_API void __lip_write_i64(struct lip_ctx_file *ctx, long val);

LIP_API void __lip_write_u8(struct lip_ctx_file *ctx, unsigned val);
LIP_API void __lip_write_u16(struct lip_ctx_file *ctx, unsigned val);
LIP_API void __lip_write_u32(struct lip_ctx_file *ctx, unsigned val);
LIP_API void __lip_write_u64(struct lip_ctx_file *ctx, unsigned long val);

#endif
