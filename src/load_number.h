#ifndef LOAD_NUMBER_H
#define LOAD_NUMBER_H

#include "number.h"

union __lip_num8 __lip_load_num8(unsigned char const buf[]);
union __lip_num16 __lip_load_num16(unsigned char const buf[]);
union __lip_num32 __lip_load_num32(unsigned char const buf[]);
union __lip_num64 __lip_load_num64(unsigned char const buf[]);

#endif
