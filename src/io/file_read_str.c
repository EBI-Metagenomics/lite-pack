#include "lite_pack/format.h"
#include "lite_pack/io/file.h"
#include "lite_pack/unpack_str.h"

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
