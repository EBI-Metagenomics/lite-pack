#ifndef LIP_STORE_FLOAT_H
#define LIP_STORE_FLOAT_H

#include "lip/export.h"

LIP_API unsigned lip_store_f32(unsigned char buf[], float val);
LIP_API unsigned lip_store_f32_in(unsigned char buf[]);

LIP_API unsigned lip_store_f64(unsigned char buf[], double val);
LIP_API unsigned lip_store_f64_in(unsigned char buf[]);

#endif
