#ifndef UNPACK_H
#define UNPACK_H

#include "bug.h"
#include "compiler.h"
#include "first_byte.h"
#include "format.h"
#include "load.h"
#include <stdbool.h>

static inline unsigned lip_unpack_bool(uint8_t const buf[static 1], bool *val)
{
    if (lip_format(buf) == LIP_FMT_FALSE || lip_format(buf) == LIP_FMT_TRUE)
        return __lip_load_bool(buf, val);
    return 0;
}

unsigned __lip_unpack_u8(uint8_t const buf[static 1], uint8_t *val);
unsigned __lip_unpack_u16(uint8_t const buf[static 1], uint16_t *val);
unsigned __lip_unpack_u32(uint8_t const buf[static 1], uint32_t *val);
unsigned __lip_unpack_u64(uint8_t const buf[static 1], uint64_t *val);

unsigned __lip_unpack_i8(uint8_t const buf[static 1], int8_t *val);
unsigned __lip_unpack_i16(uint8_t const buf[static 1], int16_t *val);
unsigned __lip_unpack_i32(uint8_t const buf[static 1], int32_t *val);
unsigned __lip_unpack_i64(uint8_t const buf[static 1], int64_t *val);

unsigned __lip_unpack_f32(uint8_t const buf[static 5], float *val);
unsigned __lip_unpack_f64(uint8_t const buf[static 5], double *val);

#endif
