#ifndef LITE_PACK_UNPACK_OBJECT_H
#define LITE_PACK_UNPACK_OBJECT_H

#include "lite_pack/export.h"
#include <stdint.h>

struct lip_object;

LIP_API unsigned lip_unpack_object(unsigned char const buf[],
                                   struct lip_object *obj);

#endif
