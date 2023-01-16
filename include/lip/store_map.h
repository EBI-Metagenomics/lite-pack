#ifndef LIP_STORE_MAP_H
#define LIP_STORE_MAP_H

#include "lip/export.h"
#include <stdint.h>

LIP_API unsigned lip_store_fixmap(unsigned char buf[], uint8_t size);
LIP_API unsigned lip_store_map16(unsigned char buf[], uint16_t size);
LIP_API unsigned lip_store_map32(unsigned char buf[], uint32_t size);

#endif
