#include "lite_pack/io/file.h"
#include "lite_pack/pack_bool.h"

void lip_write_bool(struct lip_ctx_file *ctx, bool val)
{
    if (ctx->error) return;
    unsigned sz = lip_pack_bool(ctx->buf, val);
    ctx->error = fwrite(ctx->buf, sz, 1, ctx->fp) != 1;
}
