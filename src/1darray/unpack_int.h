#ifndef LIP_1DARRAY_UNPACK_INT_H
#define LIP_1DARRAY_UNPACK_INT_H

#include <stdint.h>

void lip_unpack_1darray_i8_data(unsigned char const buf[], unsigned size,
                                int8_t arr[]);

void lip_unpack_1darray_i16_data(unsigned char const buf[], unsigned size,
                                 int16_t arr[]);

void lip_unpack_1darray_i32_data(unsigned char const buf[], unsigned size,
                                 int32_t arr[]);

void lip_unpack_1darray_i64_data(unsigned char const buf[], unsigned size,
                                 int64_t arr[]);

void lip_unpack_1darray_u8_data(unsigned char const buf[], unsigned size,
                                uint8_t arr[]);

void lip_unpack_1darray_u16_data(unsigned char const buf[], unsigned size,
                                 uint16_t arr[]);

void lip_unpack_1darray_u32_data(unsigned char const buf[], unsigned size,
                                 uint32_t arr[]);

void lip_unpack_1darray_u64_data(unsigned char const buf[], unsigned size,
                                 uint64_t arr[]);

void lip_unpack_1darray_f32_data(unsigned char const buf[], unsigned size,
                                 float arr[]);

void lip_unpack_1darray_f64_data(unsigned char const buf[], unsigned size,
                                 double arr[]);

#endif
