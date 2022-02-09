#ifndef LIP_PACK_INT_H
#define LIP_PACK_INT_H

#include "store_int.h"
#include <stdint.h>

#define __lip_pack_signed(buf, val)                                            \
    sizeof(val) == 1   ? __lip_pack_i8(buf, (int8_t)(val))                     \
    : sizeof(val) == 2 ? __lip_pack_i16(buf, (int16_t)(val))                   \
    : sizeof(val) == 4 ? __lip_pack_i32(buf, (int32_t)(val))                   \
    : sizeof(val) == 8 ? __lip_pack_i64(buf, (int64_t)(val))                   \
                       : 0

#define __lip_pack_unsigned(buf, val)                                          \
    sizeof(val) == 1   ? __lip_pack_u8(buf, (uint8_t)(val))                    \
    : sizeof(val) == 2 ? __lip_pack_u16(buf, (uint16_t)(val))                  \
    : sizeof(val) == 4 ? __lip_pack_u32(buf, (uint32_t)(val))                  \
    : sizeof(val) == 8 ? __lip_pack_u64(buf, (uint64_t)(val))                  \
                       : 0U

#define __lip_pack_int(buf, val)                                               \
    _Generic((val), signed char                                                \
             : __lip_pack_signed(buf, val), signed short                       \
             : __lip_pack_signed(buf, val), signed int                         \
             : __lip_pack_signed(buf, val), signed long                        \
             : __lip_pack_signed(buf, val), signed long long                   \
             : __lip_pack_signed(buf, val), unsigned char                      \
             : __lip_pack_unsigned(buf, val), unsigned short                   \
             : __lip_pack_unsigned(buf, val), unsigned int                     \
             : __lip_pack_unsigned(buf, val), unsigned long                    \
             : __lip_pack_unsigned(buf, val), unsigned long long               \
             : __lip_pack_unsigned(buf, val))

unsigned __lip_pack_i8(unsigned char buf[], int val);
unsigned __lip_pack_i16(unsigned char buf[], int val);
unsigned __lip_pack_i32(unsigned char buf[], int val);
unsigned __lip_pack_i64(unsigned char buf[], long val);

unsigned __lip_pack_u8(unsigned char buf[], unsigned val);
unsigned __lip_pack_u16(unsigned char buf[], unsigned val);
unsigned __lip_pack_u32(unsigned char buf[], unsigned val);
unsigned __lip_pack_u64(unsigned char buf[], unsigned long val);

#endif
