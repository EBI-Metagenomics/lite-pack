#ifndef LITE_PACK_PACK_INT_H
#define LITE_PACK_PACK_INT_H

#include "lite_pack/export.h"
#include "lite_pack/store_int.h"
#include <stdint.h>

#define __lip_pack_signed(buf, v)                                              \
    sizeof(typeof(v)) == 1   ? __lip_pack_i8(buf, (int8_t)(v))                 \
    : sizeof(typeof(v)) == 2 ? __lip_pack_i16(buf, (int16_t)(v))               \
    : sizeof(typeof(v)) == 4 ? __lip_pack_i32(buf, (int32_t)(v))               \
    : sizeof(typeof(v)) == 8 ? __lip_pack_i64(buf, (int64_t)(v))               \
                             : 0

#define __lip_pack_unsigned(buf, v)                                            \
    sizeof(typeof(v)) == 1   ? __lip_pack_u8(buf, (uint8_t)(v))                \
    : sizeof(typeof(v)) == 2 ? __lip_pack_u16(buf, (uint16_t)(v))              \
    : sizeof(typeof(v)) == 4 ? __lip_pack_u32(buf, (uint32_t)(v))              \
    : sizeof(typeof(v)) == 8 ? __lip_pack_u64(buf, (uint64_t)(v))              \
                             : 0U

#define __lip_pack_int(buf, v)                                                 \
    _Generic((v), signed char                                                  \
             : __lip_pack_signed(buf, v), signed short                         \
             : __lip_pack_signed(buf, v), signed int                           \
             : __lip_pack_signed(buf, v), signed long                          \
             : __lip_pack_signed(buf, v), signed long long                     \
             : __lip_pack_signed(buf, v), unsigned char                        \
             : __lip_pack_unsigned(buf, v), unsigned short                     \
             : __lip_pack_unsigned(buf, v), unsigned int                       \
             : __lip_pack_unsigned(buf, v), unsigned long                      \
             : __lip_pack_unsigned(buf, v), unsigned long long                 \
             : __lip_pack_unsigned(buf, v))

LIP_API unsigned __lip_pack_i8(unsigned char buf[], int val);
LIP_API unsigned __lip_pack_i16(unsigned char buf[], int val);
LIP_API unsigned __lip_pack_i32(unsigned char buf[], int val);
LIP_API unsigned __lip_pack_i64(unsigned char buf[], long val);

LIP_API unsigned __lip_pack_u8(unsigned char buf[], unsigned val);
LIP_API unsigned __lip_pack_u16(unsigned char buf[], unsigned val);
LIP_API unsigned __lip_pack_u32(unsigned char buf[], unsigned val);
LIP_API unsigned __lip_pack_u64(unsigned char buf[], unsigned long val);

#endif
