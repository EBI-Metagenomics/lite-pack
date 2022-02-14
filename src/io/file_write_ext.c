#include "lite_pack/io/file.h"
#include "lite_pack/pack_ext.h"

void lip_write_ext_size_type(struct lip_ctx_file *ctx, unsigned size,
                             uint8_t type)
{
    if (ctx->error) return;
    unsigned sz = lip_pack_ext_size_type(ctx->buf, size, type);
    ctx->error = fwrite(ctx->buf, sz, 1, ctx->fp) != 1;
}
