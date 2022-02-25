#ifndef _1DARRAY_ITEM_SIZE_H
#define _1DARRAY_ITEM_SIZE_H

#include "lite_pack/1darray/type.h"

static inline unsigned _1darray_item_size(enum lip_1darray_type type)
{
    switch (type)
    {
    case LIP_1DARRAY_UINT8:
    case LIP_1DARRAY_INT8:
        return 1;
    case LIP_1DARRAY_UINT16:
    case LIP_1DARRAY_INT16:
        return 2;
    case LIP_1DARRAY_UINT32:
    case LIP_1DARRAY_INT32:
    case LIP_1DARRAY_F32:
        return 4;
    case LIP_1DARRAY_UINT64:
    case LIP_1DARRAY_INT64:
    case LIP_1DARRAY_F64:
        return 8;
    default:
        __builtin_unreachable();
    }
}

#endif
