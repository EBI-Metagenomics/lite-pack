#ifndef LIP_CTX_FILE_WRITE_H
#define LIP_CTX_FILE_WRITE_H

#include "lite_pack/ctx/file_ctx.h"
#include "lite_pack/export.h"
#include "lite_pack/lite_pack.h"

static inline void lip_write_bool(struct lip_ctx_file *ctx, bool val)
{
    if (ctx->error) return;
    unsigned sz = lip_pack_bool(ctx->buf, val);
    ctx->error = fwrite(ctx->buf, sz, 1, ctx->fp) != 1;
}

/* INTEGER */

#define __lip_write_signed(buf, val)                                           \
    sizeof(val) == 1   ? __lip_write_i8(buf, (int8_t)(val))                    \
    : sizeof(val) == 2 ? __lip_write_i16(buf, (int16_t)(val))                  \
    : sizeof(val) == 4 ? __lip_write_i32(buf, (int32_t)(val))                  \
    : sizeof(val) == 8 ? __lip_write_i64(buf, (int64_t)(val))                  \
                       : 0

#define __lip_write_unsigned(buf, val)                                         \
    sizeof(val) == 1   ? __lip_write_u8(buf, (uint8_t)(val))                   \
    : sizeof(val) == 2 ? __lip_write_u16(buf, (uint16_t)(val))                 \
    : sizeof(val) == 4 ? __lip_write_u32(buf, (uint32_t)(val))                 \
    : sizeof(val) == 8 ? __lip_write_u64(buf, (uint64_t)(val))                 \
                       : 0U

#define __lip_write_int(buf, val)                                              \
    _Generic((val), signed char                                                \
             : __lip_write_signed(buf, val), signed short                      \
             : __lip_write_signed(buf, val), signed int                        \
             : __lip_write_signed(buf, val), signed long                       \
             : __lip_write_signed(buf, val), signed long long                  \
             : __lip_write_signed(buf, val), unsigned char                     \
             : __lip_write_unsigned(buf, val), unsigned short                  \
             : __lip_write_unsigned(buf, val), unsigned int                    \
             : __lip_write_unsigned(buf, val), unsigned long                   \
             : __lip_write_unsigned(buf, val), unsigned long long              \
             : __lip_write_unsigned(buf, val))

/* SIGNED INTEGER */

static inline void lip_write_i8(struct lip_ctx_file *ctx, int val)
{
    if (ctx->error) return;
    unsigned sz = __lip_pack_i8(ctx->buf, val);
    ctx->error = fwrite(ctx->buf, sz, 1, ctx->fp) != 1;
}

static inline void lip_write_i16(struct lip_ctx_file *ctx, int val)
{
    if (ctx->error) return;
    unsigned sz = __lip_pack_i16(ctx->buf, val);
    ctx->error = fwrite(ctx->buf, sz, 1, ctx->fp) != 1;
}

static inline void lip_write_i32(struct lip_ctx_file *ctx, int val)
{
    if (ctx->error) return;
    unsigned sz = __lip_pack_i32(ctx->buf, val);
    ctx->error = fwrite(ctx->buf, sz, 1, ctx->fp) != 1;
}

static inline void lip_write_i64(struct lip_ctx_file *ctx, long val)
{
    if (ctx->error) return;
    unsigned sz = __lip_pack_i64(ctx->buf, val);
    ctx->error = fwrite(ctx->buf, sz, 1, ctx->fp) != 1;
}

/* UNSIGNED INTEGER */

static inline void lip_write_u8(struct lip_ctx_file *ctx, unsigned val)
{
    if (ctx->error) return;
    unsigned sz = __lip_pack_u8(ctx->buf, val);
    ctx->error = fwrite(ctx->buf, sz, 1, ctx->fp) != 1;
}

static inline void lip_write_u16(struct lip_ctx_file *ctx, unsigned val)
{
    if (ctx->error) return;
    unsigned sz = __lip_pack_u16(ctx->buf, val);
    ctx->error = fwrite(ctx->buf, sz, 1, ctx->fp) != 1;
}

static inline void lip_write_u32(struct lip_ctx_file *ctx, unsigned val)
{
    if (ctx->error) return;
    unsigned sz = __lip_pack_u32(ctx->buf, val);
    ctx->error = fwrite(ctx->buf, sz, 1, ctx->fp) != 1;
}

static inline void lip_write_u64(struct lip_ctx_file *ctx, unsigned long val)
{
    if (ctx->error) return;
    unsigned sz = __lip_pack_u64(ctx->buf, val);
    ctx->error = fwrite(ctx->buf, sz, 1, ctx->fp) != 1;
}

/* FLOAT */

static inline void lip_write_f32(struct lip_ctx_file *ctx, float val)
{
    if (ctx->error) return;
    unsigned sz = __lip_pack_f32(ctx->buf, val);
    ctx->error = fwrite(ctx->buf, sz, 1, ctx->fp) != 1;
}

static inline void lip_write_f64(struct lip_ctx_file *ctx, double val)
{
    if (ctx->error) return;
    unsigned sz = __lip_pack_f64(ctx->buf, val);
    ctx->error = fwrite(ctx->buf, sz, 1, ctx->fp) != 1;
}

/* ARRAY */

static inline void lip_write_array_size(struct lip_ctx_file *ctx, unsigned size)
{
    if (ctx->error) return;
    unsigned sz = lip_pack_array_size(ctx->buf, size);
    ctx->error = fwrite(ctx->buf, sz, 1, ctx->fp) != 1;
}

/* MAP */

static inline void lip_write_map_size(struct lip_ctx_file *ctx, unsigned size)
{
    if (ctx->error) return;
    unsigned sz = lip_pack_map_size(ctx->buf, size);
    ctx->error = fwrite(ctx->buf, sz, 1, ctx->fp) != 1;
}

/* STR */

static inline void lip_write_str_size(struct lip_ctx_file *ctx, unsigned size)
{
    if (ctx->error) return;
    unsigned sz = lip_pack_str_size(ctx->buf, size);
    ctx->error = fwrite(ctx->buf, sz, 1, ctx->fp) != 1;
}

LIP_API void lip_write_str_data(struct lip_ctx_file *ctx, unsigned size,
                                char const val[]);

/* EXT */

static inline void lip_write_ext_size_type(struct lip_ctx_file *ctx,
                                           unsigned size, uint8_t type)
{
    if (ctx->error) return;
    unsigned sz = lip_pack_ext_size_type(ctx->buf, size, type);
    ctx->error = fwrite(ctx->buf, sz, 1, ctx->fp) != 1;
}

#endif
