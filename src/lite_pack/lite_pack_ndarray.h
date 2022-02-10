#ifndef LITE_PACK_NDARRAY_H
#define LITE_PACK_NDARRAY_H

#include "lite_pack/lite_pack.h"

enum lip_darray_type
{
    LIP_DARRAY_INT8,
    LIP_DARRAY_INT16,
    LIP_DARRAY_INT32,
    LIP_DARRAY_INT64,
    LIP_DARRAY_UINT8,
    LIP_DARRAY_UINT16,
    LIP_DARRAY_UINT32,
    LIP_DARRAY_UINT64,
    LIP_DARRAY_F32,
    LIP_DARRAY_F64
};

static unsigned lip_pack_darray_size_type(unsigned char buf[], unsigned size,
                                          uint8_t type)
{
    return lip_pack_ext_size_type(buf, size, type);
}

static unsigned lip_unpack_darray_size_type(unsigned char buf[], unsigned *size,
                                            uint8_t *type)
{
    return lip_unpack_ext_size_type(buf, size, type);
}

#define MAKE_DARRAY(N, T)                                                      \
    static void lip_pack_darray_##N##_data(unsigned char buf[], unsigned size, \
                                           T const arr[])                      \
    {                                                                          \
        for (unsigned i = 0; i < size; ++i)                                    \
            buf += lip_store_##N(buf, arr[i]);                                 \
    }                                                                          \
                                                                               \
    static void lip_pack_darray_##N##_data_inplace(unsigned char buf[],        \
                                                   unsigned size)              \
    {                                                                          \
        for (unsigned i = 0; i < size; ++i)                                    \
            buf += lip_store_##N##_inplace(buf);                               \
    }                                                                          \
                                                                               \
    static void lip_unpack_darray_##N##_data(unsigned char const buf[],        \
                                             unsigned size, T arr[])           \
    {                                                                          \
        for (unsigned i = 0; i < size; ++i)                                    \
            buf += lip_load_##N(buf, arr++);                                   \
    }                                                                          \
                                                                               \
    static void lip_unpack_darray_##N##_data_inplace(unsigned char buf[],      \
                                                     unsigned size)            \
    {                                                                          \
        for (unsigned i = 0; i < size; ++i)                                    \
            buf += lip_load_##N##_inplace(buf);                                \
    }

MAKE_DARRAY(i8, int8_t);
MAKE_DARRAY(i16, int16_t);
MAKE_DARRAY(i32, int32_t);
MAKE_DARRAY(i64, int64_t);

MAKE_DARRAY(u8, uint8_t);
MAKE_DARRAY(u16, uint16_t);
MAKE_DARRAY(u32, uint32_t);
MAKE_DARRAY(u64, uint64_t);

MAKE_DARRAY(f32, float);
MAKE_DARRAY(f64, double);

#endif
