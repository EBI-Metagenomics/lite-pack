#ifndef LIP_EXT_UNPACK_1DARRAY_H
#define LIP_EXT_UNPACK_1DARRAY_H

#include "lite_pack/export.h"
#include "lite_pack/lite_pack.h"

static inline unsigned
lip_unpack_1darray_size_type(unsigned char buf[], unsigned *size, uint8_t *type)
{
    return lip_unpack_ext_size_type(buf, size, type);
}

LIP_API void lip_unpack_1darray_i8_data(unsigned char const buf[],
                                        unsigned size, int8_t arr[]);

LIP_API void lip_unpack_1darray_i8_data_inplace(unsigned char buf[],
                                                unsigned size);

LIP_API void lip_unpack_1darray_i16_data(unsigned char const buf[],
                                         unsigned size, int16_t arr[]);

LIP_API void lip_unpack_1darray_i16_data_inplace(unsigned char buf[],
                                                 unsigned size);

LIP_API void lip_unpack_1darray_i32_data(unsigned char const buf[],
                                         unsigned size, int32_t arr[]);

LIP_API void lip_unpack_1darray_i32_data_inplace(unsigned char buf[],
                                                 unsigned size);

LIP_API void lip_unpack_1darray_i64_data(unsigned char const buf[],
                                         unsigned size, int64_t arr[]);

LIP_API void lip_unpack_1darray_i64_data_inplace(unsigned char buf[],
                                                 unsigned size);

LIP_API void lip_unpack_1darray_u8_data(unsigned char const buf[],
                                        unsigned size, uint8_t arr[]);

LIP_API void lip_unpack_1darray_u8_data_inplace(unsigned char buf[],
                                                unsigned size);

LIP_API void lip_unpack_1darray_u16_data(unsigned char const buf[],
                                         unsigned size, uint16_t arr[]);

LIP_API void lip_unpack_1darray_u16_data_inplace(unsigned char buf[],
                                                 unsigned size);

LIP_API void lip_unpack_1darray_u32_data(unsigned char const buf[],
                                         unsigned size, uint32_t arr[]);

LIP_API void lip_unpack_1darray_u32_data_inplace(unsigned char buf[],
                                                 unsigned size);

LIP_API void lip_unpack_1darray_u64_data(unsigned char const buf[],
                                         unsigned size, uint64_t arr[]);

LIP_API void lip_unpack_1darray_u64_data_inplace(unsigned char buf[],
                                                 unsigned size);

LIP_API void lip_unpack_1darray_f32_data(unsigned char const buf[],
                                         unsigned size, float arr[]);

LIP_API void lip_unpack_1darray_f32_data_inplace(unsigned char buf[],
                                                 unsigned size);

LIP_API void lip_unpack_1darray_f64_data(unsigned char const buf[],
                                         unsigned size, double arr[]);

LIP_API void lip_unpack_1darray_f64_data_inplace(unsigned char buf[],
                                                 unsigned size);

#endif
