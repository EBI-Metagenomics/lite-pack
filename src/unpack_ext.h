#ifndef LIP_UNPACK_EXT_H
#define LIP_UNPACK_EXT_H

#include <stdint.h>

unsigned lip_unpack_ext_size_type(unsigned char const buf[], unsigned *size,
                                  uint8_t *type);

#endif
