#ifndef CTX_H
#define CTX_H

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

#endif
