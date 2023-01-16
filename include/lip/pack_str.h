#ifndef LIP_PACK_STR_H
#define LIP_PACK_STR_H

#include "lip/export.h"
#include <stdint.h>

LIP_API unsigned lip_pack_str_size(unsigned char buf[], unsigned size);
LIP_API unsigned lip_pack_str_data(unsigned char buf[], unsigned size,
                                   char const val[]);

#endif
