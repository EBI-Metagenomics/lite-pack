#ifndef LITE_PACK_PACK_FLOAT_H
#define LITE_PACK_PACK_FLOAT_H

#include "lite_pack/export.h"

#define lip_pack_float(buf, val)                                               \
    _Generic((val), float : lip_pack_f32, double : lip_pack_f64)(buf, val)

LIP_API unsigned lip_pack_f32(unsigned char buf[], float val);
LIP_API unsigned lip_pack_f64(unsigned char buf[], double val);

#endif
