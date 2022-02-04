#ifndef CTX_H
#define CTX_H

#include "size.h"
#include <stddef.h>
#include <stdint.h>

struct lip_ctx_read
{
    uint8_t const *buf;
    uint8_t const *pos;
    uint8_t const *end;
    int error;
};

#define __LIP_CTX_READ(BUF)                                                    \
    (struct lip_ctx_read) { .error = 0, .buf = BUF, .pos = BUF, .end = 0 }

static inline void __lip_ctx_read_skip_static(struct lip_ctx_read *ctx)
{
    ctx->pos += __lip_size_static(ctx->pos);
}

static inline void __lip_ctx_read_skip_dynamic(struct lip_ctx_read *ctx)
{
    ctx->pos += __lip_size_dynamic(ctx->pos);
}

#endif
