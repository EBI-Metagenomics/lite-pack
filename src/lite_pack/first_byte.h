#ifndef LITE_PACK_FIRST_BYTE_H
#define LITE_PACK_FIRST_BYTE_H

#include "lite_pack/export.h"
#include "lite_pack/format.h"

LIP_API unsigned char __lip_first_byte(enum lip_format format);
LIP_API unsigned char __lip_first_byte_fix(enum lip_format format, int val);

#endif
