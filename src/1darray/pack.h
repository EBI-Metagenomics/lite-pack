#ifndef LIP_1DARRAY_PACK_H
#define LIP_1DARRAY_PACK_H

#include "lite_pack/pack_ext.h"

static inline unsigned lip_pack_1darray_size_type(unsigned char buf[],
                                                  unsigned size, uint8_t type)
{
    return lip_pack_ext_size_type(buf, size, type);
}

#endif
