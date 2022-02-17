#ifndef _1DARRAY_PACK_INT_IN_H
#define _1DARRAY_PACK_INT_IN_H

#include <stdint.h>

void pack_1darray_i8_data_in(unsigned char buf[], unsigned size);
void pack_1darray_i16_data_in(unsigned char buf[], unsigned size);
void pack_1darray_i32_data_in(unsigned char buf[], unsigned size);
void pack_1darray_i64_data_in(unsigned char buf[], unsigned size);

void pack_1darray_u8_data_in(unsigned char buf[], unsigned size);
void pack_1darray_u16_data_in(unsigned char buf[], unsigned size);
void pack_1darray_u32_data_in(unsigned char buf[], unsigned size);
void pack_1darray_u64_data_in(unsigned char buf[], unsigned size);

#endif
