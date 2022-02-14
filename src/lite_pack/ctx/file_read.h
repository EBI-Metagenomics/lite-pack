#ifndef LIP_CTX_FILE_READ_H
#define LIP_CTX_FILE_READ_H

#include "lite_pack/ctx/file_ctx.h"
#include "lite_pack/export.h"
#include "lite_pack/lite_pack.h"

void lip_read_bool(struct lip_ctx_file *ctx, bool *val);

/* INTEGER */

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

/* FLOAT */

LIP_API void __lip_read_f32(struct lip_ctx_file *ctx, float *val);
LIP_API void __lip_read_f64(struct lip_ctx_file *ctx, double *val);

#define __lip_read_float(ctx, val)                                             \
    _Generic(*(val), float : lip_read_f32, double : lip_read_f64)(ctx, val)

/* ARRAY */

void lip_read_array_size(struct lip_ctx_file *ctx, unsigned *size);

/* MAP */

void lip_read_map_size(struct lip_ctx_file *ctx, unsigned *size);

/* STR */

void lip_read_str_size(struct lip_ctx_file *ctx, unsigned *size);
void lip_read_str_data(struct lip_ctx_file *ctx, unsigned size, char val[]);

/* EXT */

void lip_read_ext_size_type(struct lip_ctx_file *ctx, unsigned *size,
                            uint8_t *type);

#endif
