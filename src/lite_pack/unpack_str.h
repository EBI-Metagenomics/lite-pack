#ifndef LITE_PACK_UNPACK_STR_H
#define LITE_PACK_UNPACK_STR_H

#include "lite_pack/export.h"
#include <stdint.h>

LIP_API unsigned lip_unpack_str_size(unsigned char const buf[], unsigned *size);
LIP_API unsigned lip_unpack_str_data(unsigned char const buf[], unsigned size,
                                     char str[]);

#endif
