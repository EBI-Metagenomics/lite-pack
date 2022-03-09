#ifndef LITE_PACK_FILE_WRITE_INT_H
#define LITE_PACK_FILE_WRITE_INT_H

#include "lite_pack/bug.h"
#include "lite_pack/export.h"
#include <stdbool.h>
#include <stdint.h>

#define __lip_write_signed(f, v)                                               \
    sizeof(typeof(v)) == 1   ? __lip_write_i8(f, (int8_t)(v))                  \
    : sizeof(typeof(v)) == 2 ? __lip_write_i16(f, (int16_t)(v))                \
    : sizeof(typeof(v)) == 4 ? __lip_write_i32(f, (int32_t)(v))                \
    : sizeof(typeof(v)) == 8 ? __lip_write_i64(f, (int64_t)(v))                \
                             : __lip_bug_on_reach()

#define __lip_write_unsigned(f, v)                                             \
    sizeof(typeof(v)) == 1   ? __lip_write_u8(f, (uint8_t)(v))                 \
    : sizeof(typeof(v)) == 2 ? __lip_write_u16(f, (uint16_t)(v))               \
    : sizeof(typeof(v)) == 4 ? __lip_write_u32(f, (uint32_t)(v))               \
    : sizeof(typeof(v)) == 8 ? __lip_write_u64(f, (uint64_t)(v))               \
                             : __lip_bug_on_reach()

#define __lip_write_int(f, v)                                                  \
    _Generic((v), signed char                                                  \
             : __lip_write_signed(f, v), signed short                          \
             : __lip_write_signed(f, v), signed int                            \
             : __lip_write_signed(f, v), signed long                           \
             : __lip_write_signed(f, v), signed long long                      \
             : __lip_write_signed(f, v), unsigned char                         \
             : __lip_write_unsigned(f, v), unsigned short                      \
             : __lip_write_unsigned(f, v), unsigned int                        \
             : __lip_write_unsigned(f, v), unsigned long                       \
             : __lip_write_unsigned(f, v), unsigned long long                  \
             : __lip_write_unsigned(f, v))

struct lip_file;

LIP_API bool __lip_write_i8(struct lip_file *, int val);
LIP_API bool __lip_write_i16(struct lip_file *, int val);
LIP_API bool __lip_write_i32(struct lip_file *, int val);
LIP_API bool __lip_write_i64(struct lip_file *, long val);

LIP_API bool __lip_write_u8(struct lip_file *, unsigned val);
LIP_API bool __lip_write_u16(struct lip_file *, unsigned val);
LIP_API bool __lip_write_u32(struct lip_file *, unsigned val);
LIP_API bool __lip_write_u64(struct lip_file *, unsigned long val);

#endif
