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

void lip_pack_1darray_i8_data(unsigned char buf[], unsigned size,
                              int8_t const arr[]);
void lip_pack_1darray_i8_data_inplace(unsigned char buf[], unsigned size);
void lip_unpack_1darray_i8_data(unsigned char const buf[], unsigned size,
                                int8_t arr[]);
void lip_unpack_1darray_i8_data_inplace(unsigned char buf[], unsigned size);

void lip_pack_1darray_i16_data(unsigned char buf[], unsigned size,
                               int16_t const arr[]);
void lip_pack_1darray_i16_data_inplace(unsigned char buf[], unsigned size);
void lip_unpack_1darray_i16_data(unsigned char const buf[], unsigned size,
                                 int16_t arr[]);
void lip_unpack_1darray_i16_data_inplace(unsigned char buf[], unsigned size);

void lip_pack_1darray_i32_data(unsigned char buf[], unsigned size,
                               int32_t const arr[]);
void lip_pack_1darray_i32_data_inplace(unsigned char buf[], unsigned size);
void lip_unpack_1darray_i32_data(unsigned char const buf[], unsigned size,
                                 int32_t arr[]);
void lip_unpack_1darray_i32_data_inplace(unsigned char buf[], unsigned size);

void lip_pack_1darray_i64_data(unsigned char buf[], unsigned size,
                               int64_t const arr[]);
void lip_pack_1darray_i64_data_inplace(unsigned char buf[], unsigned size);
void lip_unpack_1darray_i64_data(unsigned char const buf[], unsigned size,
                                 int64_t arr[]);
void lip_unpack_1darray_i64_data_inplace(unsigned char buf[], unsigned size);

void lip_pack_1darray_u8_data(unsigned char buf[], unsigned size,
                              uint8_t const arr[]);
void lip_pack_1darray_u8_data_inplace(unsigned char buf[], unsigned size);
void lip_unpack_1darray_u8_data(unsigned char const buf[], unsigned size,
                                uint8_t arr[]);
void lip_unpack_1darray_u8_data_inplace(unsigned char buf[], unsigned size);

void lip_pack_1darray_u16_data(unsigned char buf[], unsigned size,
                               uint16_t const arr[]);
void lip_pack_1darray_u16_data_inplace(unsigned char buf[], unsigned size);
void lip_unpack_1darray_u16_data(unsigned char const buf[], unsigned size,
                                 uint16_t arr[]);
void lip_unpack_1darray_u16_data_inplace(unsigned char buf[], unsigned size);

void lip_pack_1darray_u32_data(unsigned char buf[], unsigned size,
                               uint32_t const arr[]);
void lip_pack_1darray_u32_data_inplace(unsigned char buf[], unsigned size);
void lip_unpack_1darray_u32_data(unsigned char const buf[], unsigned size,
                                 uint32_t arr[]);
void lip_unpack_1darray_u32_data_inplace(unsigned char buf[], unsigned size);

void lip_pack_1darray_u64_data(unsigned char buf[], unsigned size,
                               uint64_t const arr[]);
void lip_pack_1darray_u64_data_inplace(unsigned char buf[], unsigned size);
void lip_unpack_1darray_u64_data(unsigned char const buf[], unsigned size,
                                 uint64_t arr[]);
void lip_unpack_1darray_u64_data_inplace(unsigned char buf[], unsigned size);

void lip_pack_1darray_f32_data(unsigned char buf[], unsigned size,
                               float const arr[]);
void lip_pack_1darray_f32_data_inplace(unsigned char buf[], unsigned size);
void lip_unpack_1darray_f32_data(unsigned char const buf[], unsigned size,
                                 float arr[]);
void lip_unpack_1darray_f32_data_inplace(unsigned char buf[], unsigned size);

void lip_pack_1darray_f64_data(unsigned char buf[], unsigned size,
                               double const arr[]);
void lip_pack_1darray_f64_data_inplace(unsigned char buf[], unsigned size);
void lip_unpack_1darray_f64_data(unsigned char const buf[], unsigned size,
                                 double arr[]);
void lip_unpack_1darray_f64_data_inplace(unsigned char buf[], unsigned size);

#endif
