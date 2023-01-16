#ifndef LIP_UNPACK_BOOL_H
#define LIP_UNPACK_BOOL_H

#include "lip/export.h"
#include <stdbool.h>
#include <stdint.h>

LIP_API unsigned lip_unpack_bool(unsigned char const buf[], bool *val);

#endif
