#ifndef _1DARRAY_PACK_H
#define _1DARRAY_PACK_H

#include "1darray/item_size.h"
#include "lip/1darray/type.h"
#include "lip/pack_ext.h"
#include <limits.h>

static inline unsigned pack_1darray_size_type(unsigned char buf[],
                                              unsigned size,
                                              enum lip_1darray_type type)
{
    if (size > UINT_MAX / _1darray_item_size(type)) return 0;
    return lip_pack_ext_size_type(buf, _1darray_item_size(type) * size,
                                  (uint8_t)type);
}

#endif
