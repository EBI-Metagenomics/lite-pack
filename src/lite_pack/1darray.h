#ifndef LIP_1DARRAY_H
#define LIP_1DARRAY_H

#include "lite_pack/export.h"
#include "lite_pack/lite_pack.h"

enum lip_1darray_type
{
    LIP_1DARRAY_INT8,
    LIP_1DARRAY_INT16,
    LIP_1DARRAY_INT32,
    LIP_1DARRAY_INT64,
    LIP_1DARRAY_UINT8,
    LIP_1DARRAY_UINT16,
    LIP_1DARRAY_UINT32,
    LIP_1DARRAY_UINT64,
    LIP_1DARRAY_F32,
    LIP_1DARRAY_F64
};

static inline unsigned lip_pack_1darray_size_type(unsigned char buf[],
                                                  unsigned size, uint8_t type)
{
    return lip_pack_ext_size_type(buf, size, type);
}

static inline unsigned
lip_unpack_1darray_size_type(unsigned char buf[], unsigned *size, uint8_t *type)
{
    return lip_unpack_ext_size_type(buf, size, type);
}

#define DECLARE_1DARRAY(N, T)                                                  \
    LIP_API void lip_pack_1darray_##N##_data(unsigned char buf[],              \
                                             unsigned size, T const arr[]);    \
    LIP_API void lip_pack_1darray_##N##_data_inplace(unsigned char buf[],      \
                                                     unsigned size);           \
    LIP_API void lip_unpack_1darray_##N##_data(unsigned char const buf[],      \
                                               unsigned size, T arr[]);        \
    LIP_API void lip_unpack_1darray_##N##_data_inplace(unsigned char buf[],    \
                                                       unsigned size);

DECLARE_1DARRAY(i8, int8_t);
DECLARE_1DARRAY(i16, int16_t);
DECLARE_1DARRAY(i32, int32_t);
DECLARE_1DARRAY(i64, int64_t);

DECLARE_1DARRAY(u8, uint8_t);
DECLARE_1DARRAY(u16, uint16_t);
DECLARE_1DARRAY(u32, uint32_t);
DECLARE_1DARRAY(u64, uint64_t);

DECLARE_1DARRAY(f32, float);
DECLARE_1DARRAY(f64, double);

#endif
