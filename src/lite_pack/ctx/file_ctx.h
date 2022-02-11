#ifndef LIP_CTX_FILE_CTX_H
#define LIP_CTX_FILE_CTX_H

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

struct lip_ctx_file
{
    FILE *fp;
    unsigned char buf[BUFSIZ];
    bool error;
};

static_assert(BUFSIZ >= 256, "Minimum bufsize.");

#endif
