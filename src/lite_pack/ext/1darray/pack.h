#ifndef LIP_EXT_PACK_1DARRAY_H
#define LIP_EXT_PACK_1DARRAY_H

#include "lite_pack/export.h"
#include "lite_pack/lite_pack.h"

static inline unsigned lip_pack_1darray_size_type(unsigned char buf[],
                                                  unsigned size, uint8_t type)
{
    return lip_pack_ext_size_type(buf, size, type);
}

LIP_API void lip_pack_1darray_i8_data(unsigned char buf[], unsigned size,
                                      int8_t const arr[]);

LIP_API void lip_pack_1darray_i8_data_inplace(unsigned char buf[],
                                              unsigned size);

LIP_API void lip_pack_1darray_i16_data(unsigned char buf[], unsigned size,
                                       int16_t const arr[]);

LIP_API void lip_pack_1darray_i16_data_inplace(unsigned char buf[],
                                               unsigned size);

LIP_API void lip_pack_1darray_i32_data(unsigned char buf[], unsigned size,
                                       int32_t const arr[]);

LIP_API void lip_pack_1darray_i32_data_inplace(unsigned char buf[],
                                               unsigned size);

LIP_API void lip_pack_1darray_i64_data(unsigned char buf[], unsigned size,
                                       int64_t const arr[]);

LIP_API void lip_pack_1darray_i64_data_inplace(unsigned char buf[],
                                               unsigned size);

LIP_API void lip_pack_1darray_u8_data(unsigned char buf[], unsigned size,
                                      uint8_t const arr[]);

LIP_API void lip_pack_1darray_u8_data_inplace(unsigned char buf[],
                                              unsigned size);

LIP_API void lip_pack_1darray_u16_data(unsigned char buf[], unsigned size,
                                       uint16_t const arr[]);

LIP_API void lip_pack_1darray_u16_data_inplace(unsigned char buf[],
                                               unsigned size);

LIP_API void lip_pack_1darray_u32_data(unsigned char buf[], unsigned size,
                                       uint32_t const arr[]);

LIP_API void lip_pack_1darray_u32_data_inplace(unsigned char buf[],
                                               unsigned size);

LIP_API void lip_pack_1darray_u64_data(unsigned char buf[], unsigned size,
                                       uint64_t const arr[]);

LIP_API void lip_pack_1darray_u64_data_inplace(unsigned char buf[],
                                               unsigned size);

LIP_API void lip_pack_1darray_f32_data(unsigned char buf[], unsigned size,
                                       float const arr[]);

LIP_API void lip_pack_1darray_f32_data_inplace(unsigned char buf[],
                                               unsigned size);

LIP_API void lip_pack_1darray_f64_data(unsigned char buf[], unsigned size,
                                       double const arr[]);

LIP_API void lip_pack_1darray_f64_data_inplace(unsigned char buf[],
                                               unsigned size);

#endif
