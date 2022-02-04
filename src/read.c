#include "ctx.h"
#include "lite_pack.h"
#include "size.h"

unsigned lip_read_uint(struct lip_ctx_read *ctx)
{
    unsigned v = lip_unpack_uint(ctx->pos);
    __lip_ctx_read_skip_static(ctx);
    return v;
}

unsigned lip_read_map(struct lip_ctx_read *ctx)
{
    unsigned v = lip_unpack_map(ctx->pos);
    __lip_ctx_read_skip_dynamic(ctx);
    return v;
}

// unsigned long lip_read_ulong(struct lip_ctx_read *ctx);
// static inline float lip_read_float(struct lip_ctx_read *ctx);
// static inline double lip_read_double(struct lip_ctx_read *ctx);
// char *lip_read_str(struct lip_ctx_read *ctx);
// unsigned lip_read_map_length(struct lip_ctx_read *ctx);
