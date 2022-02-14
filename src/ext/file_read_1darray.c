#include "lite_pack/ctx/file_read_1darray.h"
#include "lite_pack/1darray.h"

void lip_read_1darray_size_type(struct lip_ctx_file *ctx, unsigned *size,
                                uint8_t *type)
{
    if (ctx->error) return;
    ctx->error = fread(ctx->buf, 1, 1, ctx->fp) != 1;

    unsigned sz = 1;
    switch (lip_format(ctx->buf))
    {
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
        fallthrough;

    case LIP_FMT_FIXEXT_1:
    case LIP_FMT_FIXEXT_2:
    case LIP_FMT_FIXEXT_8:
    case LIP_FMT_FIXEXT_16:
        break;

    default:
        ctx->error = true;
        return;
    }

    ctx->error = lip_unpack_1darray_size_type(ctx->buf, size, type) == 0;
}

/* SIGNED INTEGER */

void lip_read_1darray_i8_data(struct lip_ctx_file *ctx, unsigned size,
                              int8_t arr[])
{
    while (size > 0)
    {
        if (ctx->error) return;
        unsigned sz =
            size > BUFSIZ / sizeof(int8_t) ? BUFSIZ / sizeof(int8_t) : size;
        ctx->error = fread(ctx->buf, sz * sizeof(int8_t), 1, ctx->fp) != 1;
        lip_unpack_1darray_i8_data(ctx->buf, sz, arr);
        arr += sz * sizeof(int8_t);
        size = (unsigned)(size - sz);
    }
}

/* UNSIGNED INTEGER */

void lip_read_1darray_u8_data(struct lip_ctx_file *ctx, unsigned size,
                              uint8_t arr[])
{
    while (size > 0)
    {
        if (ctx->error) return;
        unsigned sz =
            size > BUFSIZ / sizeof(uint8_t) ? BUFSIZ / sizeof(uint8_t) : size;
        ctx->error = fread(ctx->buf, sz * sizeof(uint8_t), 1, ctx->fp) != 1;
        lip_unpack_1darray_u8_data(ctx->buf, sz, arr);
        arr += sz * sizeof(uint8_t);
        size = (unsigned)(size - sz);
    }
}

/* FLOAT */

void __lip_read_1darray_f32_data(struct lip_ctx_file *ctx, unsigned size,
                               float arr[])
{
    while (size > 0)
    {
        if (ctx->error) return;
        unsigned sz =
            size > BUFSIZ / sizeof(float) ? BUFSIZ / sizeof(float) : size;
        ctx->error = fread(ctx->buf, sz * sizeof(float), 1, ctx->fp) != 1;
        lip_unpack_1darray_f32_data(ctx->buf, sz, arr);
        arr += sz * sizeof(float);
        size = (unsigned)(size - sz);
    }
}

void __lip_read_1darray_f64_data(struct lip_ctx_file *ctx, unsigned size,
                               double arr[])
{
    while (size > 0)
    {
        if (ctx->error) return;
        unsigned sz =
            size > BUFSIZ / sizeof(double) ? BUFSIZ / sizeof(double) : size;
        ctx->error = fread(ctx->buf, sz * sizeof(double), 1, ctx->fp) != 1;
        lip_unpack_1darray_f64_data(ctx->buf, sz, arr);
        arr += sz * sizeof(double);
        size = (unsigned)(size - sz);
    }
}
