#ifndef SKIP_H
#define SKIP_H

#include "format.h"
#include "size.h"
#include <stdint.h>

static inline unsigned long lip_skip(uint8_t const buf[static 1])
{
    return __lip_size_static(buf) + __lip_size_dynamic(buf);
}

#endif
