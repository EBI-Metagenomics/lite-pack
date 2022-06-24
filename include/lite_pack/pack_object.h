#ifndef LITE_PACK_PACK_OBJECT_H
#define LITE_PACK_PACK_OBJECT_H

#include "lite_pack/export.h"
#include <stdint.h>

struct lip_object;

LIP_API unsigned lip_pack_object(unsigned char buf[],
                                 struct lip_object const *obj);

#endif
