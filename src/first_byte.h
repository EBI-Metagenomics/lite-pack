#ifndef FIRST_BYTE_H
#define FIRST_BYTE_H

#include "format.h"

unsigned char __lip_first_byte(enum lip_format format);
unsigned char __lip_first_byte_fix(enum lip_format format, int val);

#endif
