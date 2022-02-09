#ifndef LIP_NUMBER_H
#define LIP_NUMBER_H

#include <stdint.h>

union __lip_num
{
    int i;
    unsigned u;
};

union __lip_num8
{
    char c[1];
    int8_t i;
    uint8_t u;
};

union __lip_num16
{
    char c[2];
    int16_t i;
    uint16_t u;
};

union __lip_num32
{
    char c[4];
    int32_t i;
    uint32_t u;
    float f;
};

union __lip_num64
{
    char c[8];
    int64_t i;
    uint64_t u;
    double d;
};

#define __LIP_NUM(x)                                                           \
    _Generic((x), unsigned                                                     \
             : (union __lip_num){.u = (x)}, int                                \
             : (union __lip_num){.i = (x)})

#define __LIP_NUM8(x)                                                                \
    _Generic((x), uint8_t                                                      \
             : (union __lip_num8){.u = (x)}, int8_t                            \
             : (union __lip_num8){.i = (x)})
#define __LIP_NUM16(x)                                                               \
    _Generic((x), uint16_t                                                     \
             : (union __lip_num16){.u = (x)}, int16_t                          \
             : (union __lip_num16){.i = (x)})
#define __LIP_NUM32(x)                                                               \
    _Generic((x), uint32_t                                                     \
             : (union __lip_num32){.u = (x)}, int32_t                          \
             : (union __lip_num32){.i = (x)}, float                            \
             : (union __lip_num32){.f = (x)})
#define __LIP_NUM64(x)                                                               \
    _Generic((x), uint64_t                                                     \
             : (union __lip_num64){.u = (x)}, int64_t                          \
             : (union __lip_num64){.i = (x)}, double                           \
             : (union __lip_num64){.d = (x)})

#endif
