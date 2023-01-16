#ifndef LIP_UNPACK_OBJECT_H
#define LIP_UNPACK_OBJECT_H

#include "lip/export.h"
#include <stdint.h>

struct lip_object;

LIP_API unsigned lip_unpack_object(unsigned char const buf[],
                                   struct lip_object *obj);

#endif
