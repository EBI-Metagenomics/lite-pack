#ifndef FIRST_BYTE_H
#define FIRST_BYTE_H

#include "format.h"

uint8_t __lip_first_byte(enum lip_format format);
uint8_t __lip_first_byte_fix(enum lip_format format, int val);

#endif
