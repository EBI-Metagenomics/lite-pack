#ifndef LIP_PACK_STR_H
#define LIP_PACK_STR_H

#include <stdint.h>

unsigned lip_pack_str_size(unsigned char buf[static 1], unsigned size);
unsigned lip_pack_str_data(unsigned char buf[static 1], unsigned size,
                           char const val[static 1]);

// unsigned long lip_pack_str(unsigned char buf[static 2], char const val[static 1]);

#endif
