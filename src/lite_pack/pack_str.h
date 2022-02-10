#ifndef LIP_PACK_STR_H
#define LIP_PACK_STR_H

#include <stdint.h>

unsigned lip_pack_str_size(unsigned char buf[], unsigned size);
unsigned lip_pack_str_data(unsigned char buf[], unsigned size,
                           char const val[]);

// unsigned long lip_pack_str(unsigned char buf[], char const val[]);

#endif
