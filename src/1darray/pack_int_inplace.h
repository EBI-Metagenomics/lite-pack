#ifndef LIP_1DARRAY_PACK_INT_INPLACE_H
#define LIP_1DARRAY_PACK_INT_INPLACE_H

#include <stdint.h>

void lip_pack_1darray_i8_data_inplace(unsigned char buf[], unsigned size);
void lip_pack_1darray_i16_data_inplace(unsigned char buf[], unsigned size);
void lip_pack_1darray_i32_data_inplace(unsigned char buf[], unsigned size);
void lip_pack_1darray_i64_data_inplace(unsigned char buf[], unsigned size);

void lip_pack_1darray_u8_data_inplace(unsigned char buf[], unsigned size);
void lip_pack_1darray_u16_data_inplace(unsigned char buf[], unsigned size);
void lip_pack_1darray_u32_data_inplace(unsigned char buf[], unsigned size);
void lip_pack_1darray_u64_data_inplace(unsigned char buf[], unsigned size);

#endif
