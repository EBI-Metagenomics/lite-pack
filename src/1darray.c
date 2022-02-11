#include "lite_pack/1darray.h"

#define DEFINE_1DARRAY(N, T)                                                     \
    void lip_pack_1darray_##N##_data(unsigned char buf[],               \
                                            unsigned size, T const arr[])      \
    {                                                                          \
        for (unsigned i = 0; i < size; ++i)                                    \
            buf += lip_store_##N(buf, arr[i]);                                 \
    }                                                                          \
                                                                               \
    void lip_pack_1darray_##N##_data_inplace(unsigned char buf[],       \
                                                    unsigned size)             \
    {                                                                          \
        for (unsigned i = 0; i < size; ++i)                                    \
            buf += lip_store_##N##_inplace(buf);                               \
    }                                                                          \
                                                                               \
    void lip_unpack_1darray_##N##_data(unsigned char const buf[],       \
                                              unsigned size, T arr[])          \
    {                                                                          \
        for (unsigned i = 0; i < size; ++i)                                    \
            buf += lip_load_##N(buf, arr++);                                   \
    }                                                                          \
                                                                               \
    void lip_unpack_1darray_##N##_data_inplace(unsigned char buf[],     \
                                                      unsigned size)           \
    {                                                                          \
        for (unsigned i = 0; i < size; ++i)                                    \
            buf += lip_load_##N##_inplace(buf);                                \
    }

DEFINE_1DARRAY(i8, int8_t);
DEFINE_1DARRAY(i16, int16_t);
DEFINE_1DARRAY(i32, int32_t);
DEFINE_1DARRAY(i64, int64_t);

DEFINE_1DARRAY(u8, uint8_t);
DEFINE_1DARRAY(u16, uint16_t);
DEFINE_1DARRAY(u32, uint32_t);
DEFINE_1DARRAY(u64, uint64_t);

DEFINE_1DARRAY(f32, float);
DEFINE_1DARRAY(f64, double);
