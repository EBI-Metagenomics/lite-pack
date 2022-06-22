#ifndef LITE_PACK_LOAD_NUMBER_H
#define LITE_PACK_LOAD_NUMBER_H

#include "lite_pack/export.h"

LIP_API union __lip_num8 __lip_load_num8(unsigned char const buf[]);
LIP_API union __lip_num16 __lip_load_num16(unsigned char const buf[]);
LIP_API union __lip_num32 __lip_load_num32(unsigned char const buf[]);
LIP_API union __lip_num64 __lip_load_num64(unsigned char const buf[]);

#endif
