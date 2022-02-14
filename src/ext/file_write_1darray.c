#include "lite_pack/ctx/file_write_1darray.h"
#include "lite_pack/1darray.h"

void lip_write_1darray_size_type(struct lip_ctx_file *ctx, unsigned size,
                                 uint8_t type)
{
    if (ctx->error) return;
    unsigned sz = lip_pack_1darray_size_type(ctx->buf, size, type);
    ctx->error = fwrite(ctx->buf, sz, 1, ctx->fp) != 1;
}

void lip_write_1darray_i8_data(struct lip_ctx_file *ctx, unsigned size,
                               int8_t const arr[])
{
    while (size > 0)
    {
        if (ctx->error) return;
        unsigned sz =
            size > BUFSIZ / sizeof(int8_t) ? BUFSIZ / sizeof(int8_t) : size;
        lip_pack_1darray_i8_data(ctx->buf, sz, arr);
        arr += sz * sizeof(int8_t);
        ctx->error = fwrite(ctx->buf, sz * sizeof(int8_t), 1, ctx->fp) != 1;
        size = (unsigned)(size - sz);
    }
}

void lip_write_1darray_u8_data(struct lip_ctx_file *ctx, unsigned size,
                               uint8_t const arr[])
{
    while (size > 0)
    {
        if (ctx->error) return;
        unsigned sz =
            size > BUFSIZ / sizeof(int8_t) ? BUFSIZ / sizeof(int8_t) : size;
        lip_pack_1darray_u8_data(ctx->buf, sz, arr);
        arr += sz * sizeof(uint8_t);
        ctx->error = fwrite(ctx->buf, sz * sizeof(int8_t), 1, ctx->fp) != 1;
        size = (unsigned)(size - sz);
    }
}

void __lip_write_1darray_f32_data(struct lip_ctx_file *ctx, unsigned size,
                                  float const arr[])
{
    while (size > 0)
    {
        if (ctx->error) return;
        unsigned sz =
            size > BUFSIZ / sizeof(float) ? BUFSIZ / sizeof(float) : size;
        lip_pack_1darray_f32_data(ctx->buf, sz, arr);
        ctx->error = fwrite(ctx->buf, sz * sizeof(float), 1, ctx->fp) != 1;
        arr += sz * sizeof(float);
        size = (unsigned)(size - sz);
    }
}

void __lip_write_1darray_f64_data(struct lip_ctx_file *ctx, unsigned size,
                                  double const arr[])
{
    while (size > 0)
    {
        if (ctx->error) return;
        unsigned sz =
            size > BUFSIZ / sizeof(double) ? BUFSIZ / sizeof(double) : size;
        lip_pack_1darray_f64_data(ctx->buf, sz, arr);
        ctx->error = fwrite(ctx->buf, sz * sizeof(double), 1, ctx->fp) != 1;
        arr += sz * sizeof(double);
        size = (unsigned)(size - sz);
    }
}
