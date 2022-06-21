#ifndef LITE_PACK_LOAD_FLOAT_H
#define LITE_PACK_LOAD_FLOAT_H

#include "lite_pack/export.h"

LIP_API unsigned lip_load_f32(unsigned char const buf[], float *val);
LIP_API unsigned lip_load_f32_in(unsigned char buf[]);

LIP_API unsigned lip_load_f64(unsigned char const buf[], double *val);
LIP_API unsigned lip_load_f64_in(unsigned char buf[]);

#endif
