#ifndef LITE_PACK_STORE_INT_H
#define LITE_PACK_STORE_INT_H

#include "lite_pack/export.h"
#include <stdint.h>

/* SIGNED INTEGER */

LIP_API unsigned lip_store_negative_fixint(unsigned char buf[], int8_t val);
LIP_API unsigned lip_store_int8(unsigned char buf[], int8_t val);
LIP_API unsigned lip_store_int16(unsigned char buf[], int16_t val);
LIP_API unsigned lip_store_int32(unsigned char buf[], int32_t val);
LIP_API unsigned lip_store_int64(unsigned char buf[], int64_t val);

/* UNSIGNED INTEGER */

LIP_API unsigned lip_store_positive_fixint(unsigned char buf[], uint8_t val);
LIP_API unsigned lip_store_uint8(unsigned char buf[], uint8_t val);
LIP_API unsigned lip_store_uint16(unsigned char buf[], uint16_t val);
LIP_API unsigned lip_store_uint32(unsigned char buf[], uint32_t val);
LIP_API unsigned lip_store_uint64(unsigned char buf[], uint64_t val);

/* RAW SIGNED INTEGER FOR PUBLIC INTERFACE */

LIP_API unsigned lip_store_i8(unsigned char buf[], int8_t val);
LIP_API unsigned lip_store_i8_in(unsigned char buf[]);

LIP_API unsigned lip_store_i16(unsigned char buf[], int16_t val);
LIP_API unsigned lip_store_i16_in(unsigned char buf[]);

LIP_API unsigned lip_store_i32(unsigned char buf[], int32_t val);
LIP_API unsigned lip_store_i32_in(unsigned char buf[]);

LIP_API unsigned lip_store_i64(unsigned char buf[], int64_t val);
LIP_API unsigned lip_store_i64_in(unsigned char buf[]);

/* RAW UNSIGNED INTEGER FOR PUBLIC INTERFACE */

LIP_API unsigned lip_store_u8(unsigned char buf[], uint8_t val);
LIP_API unsigned lip_store_u8_in(unsigned char buf[]);

LIP_API unsigned lip_store_u16(unsigned char buf[], uint16_t val);
LIP_API unsigned lip_store_u16_in(unsigned char buf[]);

LIP_API unsigned lip_store_u32(unsigned char buf[], uint32_t val);
LIP_API unsigned lip_store_u32_in(unsigned char buf[]);

LIP_API unsigned lip_store_u64(unsigned char buf[], uint64_t val);
LIP_API unsigned lip_store_u64_in(unsigned char buf[]);

#endif
