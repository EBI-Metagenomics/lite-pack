#ifndef EXT_EXAMPLE_H
#define EXT_EXAMPLE_H

#include "lite_pack/lite_pack.h"

enum type
{
    TYPE_INT8,
    TYPE_INT16,
    TYPE_INT32,
    TYPE_INT64,
    TYPE_UINT8,
    TYPE_UINT16,
    TYPE_UINT32,
    TYPE_UINT64,
    TYPE_F32,
    TYPE_F64
};

static unsigned pack_darray_size(unsigned char buf[], unsigned size,
                                 uint8_t type)
{
    return lip_pack_ext_size_type(buf, size, type);
}

static unsigned unpack_darray_size(unsigned char buf[], unsigned *size,
                                   uint8_t *type)
{
    return lip_unpack_ext_size_type(buf, size, type);
}

#define MAKE_DARRAY(N, T)                                                      \
    static void pack_darray_##N##_data(unsigned char buf[], unsigned size,     \
                                       T const arr[])                          \
    {                                                                          \
        for (unsigned i = 0; i < size; ++i)                                    \
            buf += lip_store_##N(buf, arr[i]);                                 \
    }                                                                          \
                                                                               \
    static void pack_darray_##N##_data_inplace(unsigned char buf[],            \
                                               unsigned size)                  \
    {                                                                          \
        for (unsigned i = 0; i < size; ++i)                                    \
            buf += lip_store_##N##_inplace(buf);                               \
    }                                                                          \
                                                                               \
    static void unpack_darray_##N##_data(unsigned char const buf[],            \
                                         unsigned size, T arr[])               \
    {                                                                          \
        for (unsigned i = 0; i < size; ++i)                                    \
            buf += lip_load_##N(buf, arr++);                                   \
    }                                                                          \
                                                                               \
    static void unpack_darray_##N##_data_inplace(unsigned char buf[],          \
                                                 unsigned size)                \
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

#endif
