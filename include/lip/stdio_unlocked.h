#ifndef LIP_STDIO_UNLOCKED_H
#define LIP_STDIO_UNLOCKED_H

#include "lip/export.h"
#include <stddef.h>
#include <stdio.h>

LIP_API size_t lip_fread(void *restrict buf, size_t size, size_t count,
                         FILE *restrict fp);

#endif
