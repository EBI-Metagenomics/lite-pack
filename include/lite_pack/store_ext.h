#ifndef LITE_PACK_STORE_EXT_H
#define LITE_PACK_STORE_EXT_H

#include "lite_pack/export.h"
#include <stdint.h>

enum lip_format;

LIP_API unsigned lip_store_fixext(unsigned char buf[], enum lip_format fmt,
                                  uint8_t type);

LIP_API unsigned lip_store_fixext_type(unsigned char buf[], enum lip_format fmt,
                                       uint8_t type);

LIP_API unsigned lip_store_fixext1(unsigned char buf[], uint8_t type);

LIP_API unsigned lip_store_fixext2(unsigned char buf[], uint8_t type);

LIP_API unsigned lip_store_fixext4(unsigned char buf[], uint8_t type);

LIP_API unsigned lip_store_fixext8(unsigned char buf[], uint8_t type);

LIP_API unsigned lip_store_fixext16(unsigned char buf[], uint8_t type);

LIP_API unsigned lip_store_ext8(unsigned char buf[], uint8_t size,
                                uint8_t type);

LIP_API unsigned lip_store_ext16(unsigned char buf[], uint16_t size,
                                 uint8_t type);

LIP_API unsigned lip_store_ext32(unsigned char buf[], uint32_t size,
                                 uint8_t type);

#endif
