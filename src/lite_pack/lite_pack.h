#ifndef LITE_PACK_H
#define LITE_PACK_H

#include "lite_pack/export.h"
#include "lite_pack/format.h"
#include "lite_pack/load_float.h"
#include "lite_pack/load_int.h"
#include "lite_pack/pack_array.h"
#include "lite_pack/pack_bool.h"
#include "lite_pack/pack_ext.h"
#include "lite_pack/pack_float.h"
#include "lite_pack/pack_int.h"
#include "lite_pack/pack_map.h"
#include "lite_pack/pack_str.h"
#include "lite_pack/store_float.h"
#include "lite_pack/store_int.h"
#include "lite_pack/unpack_array.h"
#include "lite_pack/unpack_bool.h"
#include "lite_pack/unpack_ext.h"
#include "lite_pack/unpack_float.h"
#include "lite_pack/unpack_int.h"
#include "lite_pack/unpack_map.h"
#include "lite_pack/unpack_str.h"

/* PACK */

static inline unsigned lip_pack_bool(unsigned char buf[], bool val);
#define lip_pack_int(buf, val) __lip_pack_int(buf, val)
#define lip_pack_float(buf, val) __lip_pack_float(buf, val)
LIP_API unsigned lip_pack_str_size(unsigned char buf[], unsigned size);
LIP_API unsigned lip_pack_str_data(unsigned char buf[], unsigned size,
                                   char const str[]);
LIP_API unsigned lip_pack_array_size(unsigned char buf[], unsigned size);
LIP_API unsigned lip_pack_map_size(unsigned char buf[], unsigned size);
LIP_API unsigned lip_pack_ext_size_type(unsigned char buf[], unsigned size,
                                        uint8_t type);

/* UNPACK */

LIP_API unsigned lip_unpack_bool(unsigned char const buf[], bool *val);
#define lip_unpack_int(buf, val) __lip_unpack_int(buf, val)
#define lip_unpack_float(buf, val) __lip_unpack_float(buf, val)
LIP_API unsigned lip_unpack_str_size(unsigned char const buf[], unsigned *size);
LIP_API unsigned lip_unpack_str_data(unsigned char const buf[], unsigned size,
                                     char str[]);
LIP_API unsigned lip_unpack_array_size(unsigned char const buf[],
                                       unsigned *size);
LIP_API unsigned lip_unpack_map_size(unsigned char const buf[], unsigned *size);
LIP_API unsigned lip_unpack_ext_size_type(unsigned char const buf[],
                                          unsigned *size, uint8_t *type);

/* STORE RAW NUMBERS */

/* clang-format off */
static inline unsigned lip_store_i8(unsigned char buf[], int8_t val);
static inline unsigned lip_store_i16(unsigned char buf[], int16_t val);
static inline unsigned lip_store_i32(unsigned char buf[], int32_t val);
static inline unsigned lip_store_i64(unsigned char buf[], int64_t val);
static inline unsigned lip_store_u8(unsigned char buf[], uint8_t val);
static inline unsigned lip_store_u16(unsigned char buf[], uint16_t val);
static inline unsigned lip_store_u32(unsigned char buf[], uint32_t val);
static inline unsigned lip_store_u64(unsigned char buf[], uint64_t val);
static inline unsigned lip_store_f32(unsigned char buf[], float val);
static inline unsigned lip_store_f64(unsigned char buf[], double val);

static inline unsigned lip_store_i8_in(unsigned char buf[]);
static inline unsigned lip_store_i16_in(unsigned char buf[]);
static inline unsigned lip_store_i32_in(unsigned char buf[]);
static inline unsigned lip_store_i64_in(unsigned char buf[]);
static inline unsigned lip_store_u8_in(unsigned char buf[]);
static inline unsigned lip_store_u16_in(unsigned char buf[]);
static inline unsigned lip_store_u32_in(unsigned char buf[]);
static inline unsigned lip_store_u64_in(unsigned char buf[]);
static inline unsigned lip_store_f32_in(unsigned char buf[]);
static inline unsigned lip_store_f64_in(unsigned char buf[]);
/* clang-format on */

/* LOAD RAW NUMBERS */

static inline unsigned lip_load_i8(unsigned char const buf[], int8_t *val);
static inline unsigned lip_load_i16(unsigned char const buf[], int16_t *val);
static inline unsigned lip_load_i32(unsigned char const buf[], int32_t *val);
static inline unsigned lip_load_i64(unsigned char const buf[], int64_t *val);
static inline unsigned lip_load_u8(unsigned char const buf[], uint8_t *val);
static inline unsigned lip_load_u16(unsigned char const buf[], uint16_t *val);
static inline unsigned lip_load_u32(unsigned char const buf[], uint32_t *val);
static inline unsigned lip_load_u64(unsigned char const buf[], uint64_t *val);
static inline unsigned lip_load_f32(unsigned char const buf[], float *val);
static inline unsigned lip_load_f64(unsigned char const buf[], double *val);

static inline unsigned lip_load_i8_in(unsigned char buf[]);
static inline unsigned lip_load_i16_in(unsigned char buf[]);
static inline unsigned lip_load_i32_in(unsigned char buf[]);
static inline unsigned lip_load_i64_in(unsigned char buf[]);
static inline unsigned lip_load_u8_in(unsigned char buf[]);
static inline unsigned lip_load_u16_in(unsigned char buf[]);
static inline unsigned lip_load_u32_in(unsigned char buf[]);
static inline unsigned lip_load_u64_in(unsigned char buf[]);
static inline unsigned lip_load_f32_in(unsigned char buf[]);
static inline unsigned lip_load_f64_in(unsigned char buf[]);

/* clang-format off */
enum lip_format;
enum lip_format_family;

static inline enum lip_format lip_format(unsigned char const buf[]);
static inline enum lip_format_family lip_format_family(unsigned char const buf[]);
/* clang-format on */

#endif
