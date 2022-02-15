#ifndef LIP_1DARRAY_UNPACK_FLOAT_H
#define LIP_1DARRAY_UNPACK_FLOAT_H

void lip_unpack_1darray_f32_data(unsigned char const buf[], unsigned size,
                                 float arr[]);
void lip_unpack_1darray_f64_data(unsigned char const buf[], unsigned size,
                                 double arr[]);

void lip_unpack_1darray_f32_data_inplace(unsigned char buf[], unsigned size);
void lip_unpack_1darray_f64_data_inplace(unsigned char buf[], unsigned size);

#endif
