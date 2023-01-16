#ifndef LIP_LOAD_INT_H
#define LIP_LOAD_INT_H

#include "lip/export.h"
#include <stdint.h>

/* RAW SIGNED INTEGER FOR PUBLIC INTERFACE */

LIP_API unsigned lip_load_i8(unsigned char const buf[], int8_t *val);
LIP_API unsigned lip_load_i8_in(unsigned char buf[]);

LIP_API unsigned lip_load_i16(unsigned char const buf[], int16_t *val);
LIP_API unsigned lip_load_i16_in(unsigned char buf[]);

LIP_API unsigned lip_load_i32(unsigned char const buf[], int32_t *val);
LIP_API unsigned lip_load_i32_in(unsigned char buf[]);

LIP_API unsigned lip_load_i64(unsigned char const buf[], int64_t *val);
LIP_API unsigned lip_load_i64_in(unsigned char buf[]);

/* RAW UNSIGNED INTEGER FOR PUBLIC INTERFACE */

LIP_API unsigned lip_load_u8(unsigned char const buf[], uint8_t *val);
LIP_API unsigned lip_load_u8_in(unsigned char buf[]);

LIP_API unsigned lip_load_u16(unsigned char const buf[], uint16_t *val);
LIP_API unsigned lip_load_u16_in(unsigned char buf[]);

LIP_API unsigned lip_load_u32(unsigned char const buf[], uint32_t *val);
LIP_API unsigned lip_load_u32_in(unsigned char buf[]);

LIP_API unsigned lip_load_u64(unsigned char const buf[], uint64_t *val);
LIP_API unsigned lip_load_u64_in(unsigned char buf[]);

#endif
