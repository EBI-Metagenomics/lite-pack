#ifndef LITE_PACK_STDIO_UNLOCKED_H
#define LITE_PACK_STDIO_UNLOCKED_H

#include "lite_pack/export.h"
#include <stddef.h>
#include <stdio.h>

LIP_API size_t lip_fread(void *restrict buf, size_t size, size_t count,
                         FILE *restrict fp);

#endif
