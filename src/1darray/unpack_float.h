#ifndef LIP_1DARRAY_UNPACK_FLOAT_H
#define LIP_1DARRAY_UNPACK_FLOAT_H

void unpack_1darray_f32_data(unsigned char const buf[], unsigned size,
                             float arr[]);
void unpack_1darray_f64_data(unsigned char const buf[], unsigned size,
                             double arr[]);

void unpack_1darray_f32_data_in(unsigned char buf[], unsigned size);
void unpack_1darray_f64_data_in(unsigned char buf[], unsigned size);

#endif
