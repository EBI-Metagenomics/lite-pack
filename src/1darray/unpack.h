#ifndef LIP_1DARRAY_UNPACK_H
#define LIP_1DARRAY_UNPACK_H

#include "lite_pack/unpack_ext.h"

static inline unsigned unpack_1darray_size_type(unsigned char buf[],
                                                unsigned *size, uint8_t *type)
{
    return lip_unpack_ext_size_type(buf, size, type);
}

#endif
