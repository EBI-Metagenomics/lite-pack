#ifndef STORE_NUMBER_H
#define STORE_NUMBER_H

#include "number.h"

unsigned __lip_store_num8(unsigned char buf[], union __lip_num8 val);
unsigned __lip_store_num16(unsigned char buf[], union __lip_num16 val);
unsigned __lip_store_num32(unsigned char buf[], union __lip_num32 val);
unsigned __lip_store_num64(unsigned char buf[], union __lip_num64 val);

#endif
