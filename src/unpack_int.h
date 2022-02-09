#ifndef LIP_UNPACK_INT_H
#define LIP_UNPACK_INT_H

#include <stdint.h>

/* clang-format off */
#define __lip_unpack_int(buf, val) _Generic((val),                  \
uint8_t*       : __lip_unpack_u8,                                   \
uint16_t*      : __lip_unpack_u16,                                  \
uint32_t*      : __lip_unpack_u32,                                  \
uint64_t*      : __lip_unpack_u64,                                  \
unsigned long* : __lip_unpack_u64,                                  \
int8_t*        : __lip_unpack_i8,                                   \
int16_t*       : __lip_unpack_i16,                                  \
int32_t*       : __lip_unpack_i32,                                  \
int64_t*       : __lip_unpack_i64,                                  \
long*          : __lip_unpack_i64)(buf, val)
/* clang-format on */

unsigned __lip_unpack_i8(uint8_t const buf[static 1], int8_t *val);
unsigned __lip_unpack_i16(uint8_t const buf[static 1], int16_t *val);
unsigned __lip_unpack_i32(uint8_t const buf[static 1], int32_t *val);
unsigned __lip_unpack_i64(uint8_t const buf[static 1], int64_t *val);

unsigned __lip_unpack_u8(uint8_t const buf[static 1], uint8_t *val);
unsigned __lip_unpack_u16(uint8_t const buf[static 1], uint16_t *val);
unsigned __lip_unpack_u32(uint8_t const buf[static 1], uint32_t *val);
unsigned __lip_unpack_u64(uint8_t const buf[static 1], uint64_t *val);

#endif
