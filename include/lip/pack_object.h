#ifndef LIP_PACK_OBJECT_H
#define LIP_PACK_OBJECT_H

#include "lip/export.h"
#include <stdint.h>

struct lip_object;

LIP_API unsigned lip_pack_object(unsigned char buf[],
                                 struct lip_object const *obj);

#endif
