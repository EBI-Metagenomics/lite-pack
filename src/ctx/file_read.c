#include "lite_pack/ctx/file_read.h"

void lip_read_bool(struct lip_ctx_file *ctx, bool *val)
{
    if (ctx->error) return;

    ctx->error = fread(ctx->buf, 1, 1, ctx->fp) != 1;
    if (ctx->error) return;

    ctx->error = lip_unpack_bool(ctx->buf, val) == 0;
}

static inline unsigned int_size(enum lip_format fmt)
{
    unsigned sz = 0;
    switch (fmt)
    {
    case LIP_FMT_INT_64:
    case LIP_FMT_UINT_64:
        sz += 2;
        fallthrough;
    case LIP_FMT_INT_32:
    case LIP_FMT_UINT_32:
        sz += 2;
        fallthrough;
    case LIP_FMT_INT_16:
    case LIP_FMT_UINT_16:
        sz += 1;
        fallthrough;
    case LIP_FMT_INT_8:
    case LIP_FMT_UINT_8:
        sz += 1;
        fallthrough;
    default:
        return 0;
    }
}

/* SIGNED INTEGER */

static inline void read_int(struct lip_ctx_file *ctx)
{
    ctx->error = fread(ctx->buf, 1, 1, ctx->fp) != 1;
    if (ctx->error) return;

    unsigned sz = 0;
    switch (lip_format(ctx->buf))
    {
    case LIP_FMT_INT_64:
    case LIP_FMT_UINT_64:
        sz += 4;
        fallthrough;

    case LIP_FMT_INT_32:
    case LIP_FMT_UINT_32:
        sz += 2;

        fallthrough;
    case LIP_FMT_INT_16:
    case LIP_FMT_UINT_16:
        sz += 1;
        fallthrough;

    case LIP_FMT_INT_8:
    case LIP_FMT_UINT_8:
        sz += 1;
        ctx->error = fread(ctx->buf + 1, sz, 1, ctx->fp) != 1;
        if (ctx->error) return;
        fallthrough;

    case LIP_FMT_POSITIVE_FIXINT:
    case LIP_FMT_NEGATIVE_FIXINT:
        break;

    default:
        ctx->error = true;
        return;
    }
}

void __lip_read_i8(struct lip_ctx_file *ctx, int8_t *val)
{
    if (ctx->error) return;

    read_int(ctx);
    if (ctx->error) return;

    ctx->error = __lip_unpack_i8(ctx->buf, val) == 0;
}

void __lip_read_i16(struct lip_ctx_file *ctx, int16_t *val)
{
    if (ctx->error) return;

    read_int(ctx);
    if (ctx->error) return;

    ctx->error = __lip_unpack_i16(ctx->buf, val) == 0;
}

void __lip_read_i32(struct lip_ctx_file *ctx, int32_t *val)
{
    if (ctx->error) return;

    read_int(ctx);
    if (ctx->error) return;

    ctx->error = __lip_unpack_i32(ctx->buf, val) == 0;
}

void __lip_read_i64(struct lip_ctx_file *ctx, int64_t *val)
{
    if (ctx->error) return;

    read_int(ctx);
    if (ctx->error) return;

    ctx->error = __lip_unpack_i64(ctx->buf, val) == 0;
}

/* UNSIGNED INTEGER */

void __lip_read_u8(struct lip_ctx_file *ctx, uint8_t *val)
{
    if (ctx->error) return;

    read_int(ctx);
    if (ctx->error) return;

    ctx->error = __lip_unpack_u8(ctx->buf, val) == 0;
}

void __lip_read_u16(struct lip_ctx_file *ctx, uint16_t *val)
{
    if (ctx->error) return;

    read_int(ctx);
    if (ctx->error) return;

    ctx->error = __lip_unpack_u16(ctx->buf, val) == 0;
}

void __lip_read_u32(struct lip_ctx_file *ctx, uint32_t *val)
{
    if (ctx->error) return;

    read_int(ctx);
    if (ctx->error) return;

    ctx->error = __lip_unpack_u32(ctx->buf, val) == 0;
}

void __lip_read_u64(struct lip_ctx_file *ctx, uint64_t *val)
{
    if (ctx->error) return;

    read_int(ctx);
    if (ctx->error) return;

    ctx->error = __lip_unpack_u64(ctx->buf, val) == 0;
}

/* FLOAT */

void __lip_read_f32(struct lip_ctx_file *ctx, float *val)
{
    if (ctx->error) return;

    ctx->error = fread(ctx->buf, 1, 1, ctx->fp) != 1;
    if (ctx->error) return;

    if (lip_format(ctx->buf) != LIP_FMT_FLOAT_32)
    {
        ctx->error = true;
        return;
    }

    ctx->error = fread(ctx->buf + 1, 4, 1, ctx->fp) != 1;
    if (ctx->error) return;

    ctx->error = __lip_unpack_f32(ctx->buf, val) == 0;
}

void __lip_read_f64(struct lip_ctx_file *ctx, double *val)
{
    if (ctx->error) return;

    ctx->error = fread(ctx->buf, 1, 1, ctx->fp) != 1;
    if (ctx->error) return;

    unsigned sz = 0;
    if (lip_format(ctx->buf) == LIP_FMT_FLOAT_32)
    {
        sz = 4;
    }
    else if (lip_format(ctx->buf) == LIP_FMT_FLOAT_64)
    {
        sz = 8;
    }
    else
    {
        ctx->error = true;
        return;
    }

    ctx->error = fread(ctx->buf + 1, sz, 1, ctx->fp) != 1;
    if (ctx->error) return;

    ctx->error = __lip_unpack_f64(ctx->buf, val) == 0;
}

/* ARRAY */

void lip_read_array_size(struct lip_ctx_file *ctx, unsigned *size)
{
    if (ctx->error) return;

    ctx->error = fread(ctx->buf, 1, 1, ctx->fp) != 1;
    if (ctx->error) return;

    unsigned sz = 0;
    switch (lip_format(ctx->buf))
    {
    case LIP_FMT_ARRAY_32:
        sz += 2;
        fallthrough;

    case LIP_FMT_ARRAY_16:
        sz += 2;
        ctx->error = fread(ctx->buf + 1, sz, 1, ctx->fp) != 1;
        if (ctx->error) return;
        fallthrough;

    case LIP_FMT_FIXARRAY:
        break;

    default:
        ctx->error = true;
        return;
    }

    ctx->error = lip_unpack_array_size(ctx->buf, size) == 0;
}

/* MAP */

void lip_read_map_size(struct lip_ctx_file *ctx, unsigned *size)
{
    if (ctx->error) return;

    ctx->error = fread(ctx->buf, 1, 1, ctx->fp) != 1;
    if (ctx->error) return;

    unsigned sz = 0;
    switch (lip_format(ctx->buf))
    {
    case LIP_FMT_MAP_32:
        sz += 2;
        fallthrough;

    case LIP_FMT_MAP_16:
        sz += 2;
        ctx->error = fread(ctx->buf + 1, sz, 1, ctx->fp) != 1;
        if (ctx->error) return;
        fallthrough;

    case LIP_FMT_FIXMAP:
        break;

    default:
        ctx->error = true;
        return;
    }

    ctx->error = lip_unpack_map_size(ctx->buf, size) == 0;
}

/* STR */

void lip_read_str_size(struct lip_ctx_file *ctx, unsigned *size)
{
    if (ctx->error) return;

    ctx->error = fread(ctx->buf, 1, 1, ctx->fp) != 1;
    if (ctx->error) return;

    unsigned sz = 0;
    switch (lip_format(ctx->buf))
    {
    case LIP_FMT_STR_32:
        sz += 2;
        fallthrough;

    case LIP_FMT_STR_16:
        sz += 1;
        fallthrough;

    case LIP_FMT_STR_8:
        sz += 1;
        ctx->error = fread(ctx->buf + 1, sz, 1, ctx->fp) != 1;
        if (ctx->error) return;
        fallthrough;

    case LIP_FMT_FIXSTR:
        break;

    default:
        ctx->error = true;
        return;
    }

    ctx->error = lip_unpack_str_size(ctx->buf, size) == 0;
}

void lip_read_str_data(struct lip_ctx_file *ctx, unsigned size, char val[])
{
    while (size > 0)
    {
        if (ctx->error) return;
        unsigned sz = size > BUFSIZ ? BUFSIZ : size;
        ctx->error = fread(ctx->buf, sz, 1, ctx->fp) != 1;
        val += lip_unpack_str_data(ctx->buf, sz, val);
        size = (unsigned)(size - sz);
    }
}

/* EXT */

void lip_read_ext_size_type(struct lip_ctx_file *ctx, unsigned *size,
                            uint8_t *type)
{
    if (ctx->error) return;

    ctx->error = fread(ctx->buf, 1, 1, ctx->fp) != 1;
    if (ctx->error) return;

    unsigned sz = 1;
    switch (lip_format(ctx->buf))
    {
    case LIP_FMT_FIXEXT_16:
        fallthrough;
    case LIP_FMT_FIXEXT_8:
        fallthrough;
    case LIP_FMT_FIXEXT_4:
        fallthrough;
    case LIP_FMT_FIXEXT_2:
        fallthrough;
    case LIP_FMT_FIXEXT_1:
        fallthrough;

    case LIP_FMT_EXT_32:
        sz += 2;
        fallthrough;
    case LIP_FMT_EXT_16:
        sz += 1;
        fallthrough;
    case LIP_FMT_EXT_8:
        sz += 1;
        ctx->error = fread(ctx->buf + 1, sz, 1, ctx->fp) != 1;
        if (ctx->error) return;
        break;

    default:
        ctx->error = true;
        return;
    }

    ctx->error = lip_unpack_ext_size_type(ctx->buf, size, type) == 0;
}
