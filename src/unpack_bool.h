#ifndef LIP_UNPACK_BOOL_H
#define LIP_UNPACK_BOOL_H

#include <stdbool.h>
#include <stdint.h>

unsigned lip_unpack_bool(uint8_t const buf[static 1], bool *val);

#endif
