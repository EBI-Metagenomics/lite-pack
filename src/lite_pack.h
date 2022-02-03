#ifndef LITE_PACK_H
#define LITE_PACK_H

#include "format.h"
#include "pack.h"
#include "unpack.h"

/* clang-format off */

static inline void     lip_pack_false(uint8_t buf[static 1]);
static inline void     lip_pack_true(uint8_t buf[static 1]);
static inline void     lip_pack_bool(uint8_t buf[static 1], bool val);
#define                lip_pack_int(buf, val)            _Generic((val),\
uint8_t            : __lip_pack_u8,                                     \
uint16_t           : __lip_pack_u16,                                    \
uint32_t           : __lip_pack_u32,                                    \
uint64_t           : __lip_pack_u64,                                    \
unsigned long      : __lip_pack_u64)(buf, val)
#define                lip_pack_float(buf, val)          _Generic((val),\
float              : __lip_pack_f32,                                    \
double             : __lip_pack_f64)(buf, val)
static inline void     lip_pack_str(uint8_t buf[static 1], char const val[static 1]);
static inline void     lip_pack_map_length(uint8_t buf[static 1], unsigned length);

unsigned               lip_unpack_uint(uint8_t const buf[static 1]);
unsigned long          lip_unpack_ulong(uint8_t const buf[static 1]);
static inline float    lip_unpack_float(uint8_t const buf[static 1]);
static inline double   lip_unpack_double(uint8_t const buf[static 1]);
char*                  lip_unpack_str(uint8_t const buf[static 1], char str[static 1]);
unsigned               lip_unpack_map_length(uint8_t buf[static 1]);

enum lip_format;
enum lip_format_family;

static inline int lip_format(uint8_t const buf[static 1]);
static inline int lip_format_family(uint8_t const buf[static 1]);

/* clang-format on */

#endif