#ifndef LITE_PACK_STORE_NUMBER_H
#define LITE_PACK_STORE_NUMBER_H

#include "lite_pack/export.h"
#include "lite_pack/number.h"

LIP_API unsigned __lip_store_num8(unsigned char buf[], union __lip_num8 val);
LIP_API unsigned __lip_store_num16(unsigned char buf[], union __lip_num16 val);
LIP_API unsigned __lip_store_num32(unsigned char buf[], union __lip_num32 val);
LIP_API unsigned __lip_store_num64(unsigned char buf[], union __lip_num64 val);

#endif
