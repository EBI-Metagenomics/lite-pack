#ifndef LIP_1DARRAY_PACK_FLOAT_H
#define LIP_1DARRAY_PACK_FLOAT_H

void pack_1darray_f32_data(unsigned char buf[], unsigned size,
                           float const arr[]);
void pack_1darray_f32_data_in(unsigned char buf[], unsigned size);

void pack_1darray_f64_data(unsigned char buf[], unsigned size,
                           double const arr[]);
void pack_1darray_f64_data_in(unsigned char buf[], unsigned size);

#endif
