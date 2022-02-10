#ifndef LIP_NUMBER_H
#define LIP_NUMBER_H

#include <stdint.h>

union __lip_num
{
    int i;
    unsigned u;
};

static inline union __lip_num __lip_unum(unsigned x)
{
    return (union __lip_num){.u = (x)};
}

static inline union __lip_num __lip_inum(int x)
{
    return (union __lip_num){.i = (x)};
}

union __lip_num8
{
    char c[1];
    int8_t i;
    uint8_t u;
};

static inline union __lip_num8 __lip_unum8(uint8_t x)
{
    return (union __lip_num8){.u = (x)};
}

static inline union __lip_num8 __lip_inum8(int8_t x)
{
    return (union __lip_num8){.i = (x)};
}

union __lip_num16
{
    char c[2];
    int16_t i;
    uint16_t u;
};

static inline union __lip_num16 __lip_unum16(uint16_t x)
{
    return (union __lip_num16){.u = (x)};
}

static inline union __lip_num16 __lip_inum16(int16_t x)
{
    return (union __lip_num16){.i = (x)};
}

union __lip_num32
{
    char c[4];
    int32_t i;
    uint32_t u;
    float f;
};

static inline union __lip_num32 __lip_unum32(uint32_t x)
{
    return (union __lip_num32){.u = (x)};
}

static inline union __lip_num32 __lip_inum32(int32_t x)
{
    return (union __lip_num32){.i = (x)};
}

static inline union __lip_num32 __lip_fnum32(float x)
{
    return (union __lip_num32){.f = (x)};
}

union __lip_num64
{
    char c[8];
    int64_t i;
    uint64_t u;
    double f;
};

static inline union __lip_num64 __lip_unum64(uint64_t x)
{
    return (union __lip_num64){.u = (x)};
}

static inline union __lip_num64 __lip_inum64(int64_t x)
{
    return (union __lip_num64){.i = (x)};
}

static inline union __lip_num64 __lip_fnum64(double x)
{
    return (union __lip_num64){.f = (x)};
}

#define __LIP_NUM(x) _Generic((x), unsigned : __lip_unum, int : __lip_inum)(x)

#define __LIP_NUM8(x)                                                          \
    _Generic((x), uint8_t : __lip_unum8, int8_t : __lip_inum8)(x)

#define __LIP_NUM16(x)                                                         \
    _Generic((x), uint16_t : __lip_unum16, int16_t : __lip_inum16)(x)

#define __LIP_NUM32(x)                                                         \
    _Generic((x), uint32_t                                                     \
             : __lip_unum32, int32_t                                           \
             : __lip_inum32, float                                             \
             : __lip_fnum32)(x)

#define __LIP_NUM64(x)                                                         \
    _Generic((x), uint64_t                                                     \
             : __lip_unum64, int64_t                                           \
             : __lip_inum64, double                                            \
             : __lip_fnum64)(x)

#endif
