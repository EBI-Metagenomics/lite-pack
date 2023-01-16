#ifndef LIP_UNPACK_STR_H
#define LIP_UNPACK_STR_H

#include "lip/export.h"
#include <stdint.h>

LIP_API unsigned lip_unpack_str_size(unsigned char const buf[], unsigned *size);
LIP_API unsigned lip_unpack_str_data(unsigned char const buf[], unsigned size,
                                     char str[]);

#endif
