#ifndef LITE_PACK_UNPACK_ARRAY_H
#define LITE_PACK_UNPACK_ARRAY_H

#include "lite_pack/export.h"
#include <stdint.h>

LIP_API unsigned lip_unpack_array_size(unsigned char const buf[],
                                       unsigned *size);

#endif
