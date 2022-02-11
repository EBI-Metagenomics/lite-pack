#include "lite_pack/ctx/file_write.h"

void lip_write_str_data(struct lip_ctx_file *ctx, unsigned size,
                        char const val[])
{
    while (size > 0)
    {
        if (ctx->error) return;
        unsigned sz = size > BUFSIZ ? BUFSIZ : size;
        val += lip_pack_str_data(ctx->buf, sz, val);
        ctx->error = fwrite(ctx->buf, sz, 1, ctx->fp) != 1;
        size = (unsigned)(size - sz);
    }
}
