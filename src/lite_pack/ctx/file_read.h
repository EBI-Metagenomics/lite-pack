#ifndef LIP_CTX_FILE_READ_H
#define LIP_CTX_FILE_READ_H

#include "lite_pack/ctx/file_ctx.h"
#include "lite_pack/export.h"
#include "lite_pack/lite_pack.h"

static inline void lip_read_bool(struct lip_ctx_file *ctx, bool *val)
{
    if (ctx->error) return;

    ctx->error = fread(ctx->buf, 1, 1, ctx->fp) != 1;
    if (ctx->error) return;

    ctx->error = lip_unpack_bool(ctx->buf, val) == 0;
}

/* INTEGER */

#define __lip_read_signed(buf, val)                                            \
    sizeof(*val) == 1   ? __lip_read_i8(buf, (int8_t *)(val))                  \
    : sizeof(*val) == 2 ? __lip_read_i16(buf, (int16_t *)(val))                \
    : sizeof(*val) == 4 ? __lip_read_i32(buf, (int32_t *)(val))                \
    : sizeof(*val) == 8 ? __lip_read_i64(buf, (int64_t *)(val))                \
                        : 0

#define __lip_read_unsigned(buf, val)                                          \
    sizeof(*val) == 1   ? __lip_read_u8(buf, (uint8_t *)(val))                 \
    : sizeof(*val) == 2 ? __lip_read_u16(buf, (uint16_t *)(val))               \
    : sizeof(*val) == 4 ? __lip_read_u32(buf, (uint32_t *)(val))               \
    : sizeof(*val) == 8 ? __lip_read_u64(buf, (uint64_t *)(val))               \
                        : 0U

#define lip_read_int(buf, val)                                                 \
    _Generic((*val), signed char                                               \
             : __lip_read_signed(buf, val), signed short                       \
             : __lip_read_signed(buf, val), signed int                         \
             : __lip_read_signed(buf, val), signed long                        \
             : __lip_read_signed(buf, val), signed long long                   \
             : __lip_read_signed(buf, val), unsigned char                      \
             : __lip_read_unsigned(buf, val), unsigned short                   \
             : __lip_read_unsigned(buf, val), unsigned int                     \
             : __lip_read_unsigned(buf, val), unsigned long                    \
             : __lip_read_unsigned(buf, val), unsigned long long               \
             : __lip_read_unsigned(buf, val))

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

LIP_API void lip_read_f32(struct lip_ctx_file *ctx, float *val);
LIP_API void lip_read_f64(struct lip_ctx_file *ctx, double *val);

/* ARRAY */

LIP_API void lip_read_array_size(struct lip_ctx_file *ctx, unsigned *size);

/* MAP */

LIP_API void lip_read_map_size(struct lip_ctx_file *ctx, unsigned *size);

/* STR */

LIP_API void lip_read_str_size(struct lip_ctx_file *ctx, unsigned *size);
LIP_API void lip_read_str_data(struct lip_ctx_file *ctx, unsigned size,
                               char val[]);

/* EXT */

LIP_API void lip_read_ext_size_type(struct lip_ctx_file *ctx, unsigned *size,
                                    uint8_t *type);

#endif
