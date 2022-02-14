#include "lite_pack/io/file.h"
#include "lite_pack/unpack_bool.h"

void lip_read_bool(struct lip_ctx_file *ctx, bool *val)
{
    if (ctx->error) return;

    ctx->error = fread(ctx->buf, 1, 1, ctx->fp) != 1;
    if (ctx->error) return;

    ctx->error = lip_unpack_bool(ctx->buf, val) == 0;
}
