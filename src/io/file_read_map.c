#include "lite_pack/format.h"
#include "lite_pack/io/file.h"
#include "lite_pack/unpack_map.h"

void lip_read_map_size(struct lip_ctx_file *ctx, unsigned *size)
{
    if (ctx->error) return;

    ctx->error = fread(ctx->buf, 1, 1, ctx->fp) != 1;
    if (ctx->error) return;

    unsigned sz = 0;
    switch (lip_format(ctx->buf))
    {
    case LIP_FMT_MAP_32:
        sz += 2;
        fallthrough;

    case LIP_FMT_MAP_16:
        sz += 2;
        ctx->error = fread(ctx->buf + 1, sz, 1, ctx->fp) != 1;
        if (ctx->error) return;
        fallthrough;

    case LIP_FMT_FIXMAP:
        break;

    default:
        ctx->error = true;
        return;
    }

    ctx->error = lip_unpack_map_size(ctx->buf, size) == 0;
}
