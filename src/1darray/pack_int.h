#ifndef _1DARRAY_PACK_INT_H
#define _1DARRAY_PACK_INT_H

#include <stdint.h>

void pack_1darray_i8_data(unsigned char buf[], unsigned size,
                          int8_t const arr[]);
void pack_1darray_i16_data(unsigned char buf[], unsigned size,
                           int16_t const arr[]);
void pack_1darray_i32_data(unsigned char buf[], unsigned size,
                           int32_t const arr[]);
void pack_1darray_i64_data(unsigned char buf[], unsigned size,
                           int64_t const arr[]);

void pack_1darray_u8_data(unsigned char buf[], unsigned size,
                          uint8_t const arr[]);
void pack_1darray_u16_data(unsigned char buf[], unsigned size,
                           uint16_t const arr[]);
void pack_1darray_u32_data(unsigned char buf[], unsigned size,
                           uint32_t const arr[]);
void pack_1darray_u64_data(unsigned char buf[], unsigned size,
                           uint64_t const arr[]);

#endif
