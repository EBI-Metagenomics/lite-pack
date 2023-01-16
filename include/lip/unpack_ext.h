#ifndef LIP_UNPACK_EXT_H
#define LIP_UNPACK_EXT_H

#include "lip/export.h"
#include <stdint.h>

LIP_API unsigned lip_unpack_ext_size_type(unsigned char const buf[],
                                          unsigned *size, uint8_t *type);

#endif
