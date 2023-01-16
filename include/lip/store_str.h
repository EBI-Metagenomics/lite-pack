#ifndef LIP_STORE_STR_H
#define LIP_STORE_STR_H

#include "lip/export.h"
#include <stdint.h>

LIP_API unsigned lip_store_fixstr(unsigned char buf[], uint8_t size);
LIP_API unsigned lip_store_str8(unsigned char buf[], uint8_t size);
LIP_API unsigned lip_store_str16(unsigned char buf[], uint16_t size);
LIP_API unsigned lip_store_str32(unsigned char buf[], uint32_t size);

#endif
