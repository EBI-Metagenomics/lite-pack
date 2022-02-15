#ifndef LIP_1DARRAY_PACK_FLOAT_H
#define LIP_1DARRAY_PACK_FLOAT_H

void lip_pack_1darray_f32_data(unsigned char buf[], unsigned size,
                               float const arr[]);
void lip_pack_1darray_f32_data_inplace(unsigned char buf[], unsigned size);

void lip_pack_1darray_f64_data(unsigned char buf[], unsigned size,
                               double const arr[]);
void lip_pack_1darray_f64_data_inplace(unsigned char buf[], unsigned size);

#endif
