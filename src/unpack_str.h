#ifndef LIP_UNPACK_STR_H
#define LIP_UNPACK_STR_H

#include <stdint.h>

unsigned lip_unpack_str_size(unsigned char const buf[static 1], unsigned *size);
unsigned lip_unpack_str_data(unsigned char const buf[static 1], unsigned size,
                             char str[static 1]);

#endif
