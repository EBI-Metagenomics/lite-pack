#ifndef LITE_PACK_H
#define LITE_PACK_H

#include "format.h"
#include "pack.h"
#include "unpack.h"

enum lip_format;
enum lip_format_family;

static inline void lip_pack_true(uint8_t buf[static 1]);
static inline void lip_pack_false(uint8_t buf[static 1]);
static inline void lip_pack_bool(uint8_t buf[static 1], bool val);

/* clang-format off */
#define lip_pack_int(buf, val)                                                 \
    _Generic((val),                                                            \
        uint8_t       : __lip_pack_u8(buf, val),                               \
        uint16_t      : __lip_pack_u16(buf, val),                              \
        uint32_t      : __lip_pack_u32(buf, val),                              \
        uint64_t      : __lip_pack_u64(buf, val),                              \
        unsigned long : __lip_pack_u64(buf, val))

#define lip_pack_float(buf, val)                                               \
    _Generic((val),                                                            \
        float  : __lip_pack_f32(buf, val),                                     \
        double : __lip_pack_f64(buf, val))
/* clang-format on */

static inline void lip_pack_str(uint8_t buf[static 1],
                                char const val[static 1]);

static inline int lip_format(uint8_t const buf[static 1]);

#endif
