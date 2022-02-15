#include "lite_pack/io/file.h"
#include "lite_pack/pack_ext.h"

void lip_write_ext_size_type(struct lip_ctx_file *ctx, unsigned size,
                             uint8_t type)
{
    if (ctx->error) return;

    unsigned char buf[6] = {0};
    unsigned sz = lip_pack_ext_size_type(buf, size, type);
    ctx->error = fwrite(buf, sz, 1, ctx->fp) != 1;
}
