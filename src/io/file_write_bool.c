#include "lite_pack/io/file.h"
#include "lite_pack/pack_bool.h"

void lip_write_bool(struct lip_ctx_file *ctx, bool val)
{
    if (ctx->error) return;

    unsigned char buf[1] = {0};
    unsigned sz = lip_pack_bool(buf, val);
    ctx->error = fwrite(buf, sz, 1, ctx->fp) != 1;
}
