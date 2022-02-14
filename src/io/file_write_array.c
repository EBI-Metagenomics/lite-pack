#include "lite_pack/io/file.h"
#include "lite_pack/pack_array.h"

void lip_write_array_size(struct lip_ctx_file *ctx, unsigned size)
{
    if (ctx->error) return;
    unsigned sz = lip_pack_array_size(ctx->buf, size);
    ctx->error = fwrite(ctx->buf, sz, 1, ctx->fp) != 1;
}
