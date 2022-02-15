#include "lite_pack/format.h"
#include "lite_pack/io/file.h"
#include "lite_pack/unpack_ext.h"

void lip_read_ext_size_type(struct lip_ctx_file *ctx, unsigned *size,
                            uint8_t *type)
{
    if (ctx->error) return;

    unsigned char buf[6] = {0};

    ctx->error = fread(buf, 1, 1, ctx->fp) != 1;
    if (ctx->error) return;

    unsigned sz = 1;
    switch (lip_format(buf))
    {
    case LIP_FMT_FIXEXT_16:
        fallthrough;
    case LIP_FMT_FIXEXT_8:
        fallthrough;
    case LIP_FMT_FIXEXT_4:
        fallthrough;
    case LIP_FMT_FIXEXT_2:
        fallthrough;
    case LIP_FMT_FIXEXT_1:
        fallthrough;

    case LIP_FMT_EXT_32:
        sz += 2;
        fallthrough;
    case LIP_FMT_EXT_16:
        sz += 1;
        fallthrough;
    case LIP_FMT_EXT_8:
        sz += 1;
        ctx->error = fread(buf + 1, sz, 1, ctx->fp) != 1;
        if (ctx->error) return;
        break;

    default:
        ctx->error = true;
        return;
    }

    ctx->error = lip_unpack_ext_size_type(buf, size, type) == 0;
}
