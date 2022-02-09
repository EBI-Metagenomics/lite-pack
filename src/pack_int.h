#ifndef LIP_PACK_INT_H
#define LIP_PACK_INT_H

#include "store_int.h"
#include <stdint.h>

#define __lip_pack_int(buf, val)                                               \
    _Generic((val), uint8_t                                                    \
             : __lip_pack_u8, uint16_t                                         \
             : __lip_pack_u16, uint32_t                                        \
             : __lip_pack_u32, uint64_t                                        \
             : __lip_pack_u64, unsigned long                                   \
             : __lip_pack_u64, int8_t                                          \
             : __lip_pack_i8, int16_t                                          \
             : __lip_pack_i16, int32_t                                         \
             : __lip_pack_i32, int64_t                                         \
             : __lip_pack_i64, long                                            \
             : __lip_pack_i64)(buf, val)

unsigned __lip_pack_i8(uint8_t buf[static 1], int val);
unsigned __lip_pack_i16(uint8_t buf[static 1], int val);
unsigned __lip_pack_i32(uint8_t buf[static 1], int val);
unsigned __lip_pack_i64(uint8_t buf[static 1], long val);

unsigned __lip_pack_u8(uint8_t buf[static 1], unsigned val);
unsigned __lip_pack_u16(uint8_t buf[static 1], unsigned val);
unsigned __lip_pack_u32(uint8_t buf[static 1], unsigned val);
unsigned __lip_pack_u64(uint8_t buf[static 1], unsigned long val);

#endif
