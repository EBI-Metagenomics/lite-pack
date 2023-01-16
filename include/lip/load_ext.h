#ifndef LIP_LOAD_EXT_H
#define LIP_LOAD_EXT_H

#include "lip/export.h"
#include <stdint.h>

LIP_API unsigned lip_load_fixext(unsigned char const buf[], uint8_t *type);
LIP_API unsigned lip_load_ext8(unsigned char const buf[], unsigned *size,
                               uint8_t *type);
LIP_API unsigned lip_load_ext16(unsigned char const buf[], unsigned *size,
                                uint8_t *type);
LIP_API unsigned lip_load_ext32(unsigned char const buf[], unsigned *size,
                                uint8_t *type);

#endif
