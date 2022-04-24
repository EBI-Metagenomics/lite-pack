#ifndef LITE_PACK_FILE_READ_INT_H
#define LITE_PACK_FILE_READ_INT_H

#include "lite_pack/bug.h"
#include "lite_pack/export.h"
#include <stdbool.h>
#include <stdint.h>

#define __lip_read_signed(f, v)                                                \
    sizeof(*v) == 1   ? __lip_read_i8(f, (int8_t *)(v))                        \
    : sizeof(*v) == 2 ? __lip_read_i16(f, (int16_t *)(v))                      \
    : sizeof(*v) == 4 ? __lip_read_i32(f, (int32_t *)(v))                      \
    : sizeof(*v) == 8 ? __lip_read_i64(f, (int64_t *)(v))                      \
                      : (int)__lip_bug_on_reach()

#define __lip_read_unsigned(f, v)                                              \
    sizeof(*v) == 1   ? __lip_read_u8(f, (uint8_t *)(v))                       \
    : sizeof(*v) == 2 ? __lip_read_u16(f, (uint16_t *)(v))                     \
    : sizeof(*v) == 4 ? __lip_read_u32(f, (uint32_t *)(v))                     \
    : sizeof(*v) == 8 ? __lip_read_u64(f, (uint64_t *)(v))                     \
                      : (unsigned)__lip_bug_on_reach()

#define __lip_read_int(f, v)                                                   \
    _Generic((*v), signed char                                                 \
             : __lip_read_signed(f, v), signed short                           \
             : __lip_read_signed(f, v), signed int                             \
             : __lip_read_signed(f, v), signed long                            \
             : __lip_read_signed(f, v), signed long long                       \
             : __lip_read_signed(f, v), unsigned char                          \
             : __lip_read_unsigned(f, v), unsigned short                       \
             : __lip_read_unsigned(f, v), unsigned int                         \
             : __lip_read_unsigned(f, v), unsigned long                        \
             : __lip_read_unsigned(f, v), unsigned long long                   \
             : __lip_read_unsigned(f, v))

struct lip_file;

/* SIGNED */

LIP_API bool __lip_read_i8(struct lip_file *, int8_t *val);
LIP_API bool __lip_read_i16(struct lip_file *, int16_t *val);
LIP_API bool __lip_read_i32(struct lip_file *, int32_t *val);
LIP_API bool __lip_read_i64(struct lip_file *, int64_t *val);

/* UNSIGNED */

LIP_API bool __lip_read_u8(struct lip_file *, uint8_t *val);
LIP_API bool __lip_read_u16(struct lip_file *, uint16_t *val);
LIP_API bool __lip_read_u32(struct lip_file *, uint32_t *val);
LIP_API bool __lip_read_u64(struct lip_file *, uint64_t *val);

#endif
