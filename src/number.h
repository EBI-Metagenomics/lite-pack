#ifndef NUMBER_H
#define NUMBER_H

#include <stdint.h>

union __lip_num
{
    int i;
    unsigned u;
};

static inline union __lip_num __lip_num_int(int x)
{
    return (union __lip_num){.i = x};
}

static inline union __lip_num __lip_num_unsigned(unsigned x)
{
    return (union __lip_num){.u = x};
}

union __lip_num8
{
    unsigned char c[1];
    int8_t i;
    uint8_t u;
};

static inline union __lip_num8 __lip_num_uchar8(unsigned char const x[])
{
    return (union __lip_num8){.c = {x[0]}};
}

static inline union __lip_num8 __lip_num_i8(int8_t x)
{
    return (union __lip_num8){.i = x};
}

static inline union __lip_num8 __lip_num_u8(uint8_t x)
{
    return (union __lip_num8){.u = x};
}

union __lip_num16
{
    unsigned char c[2];
    int16_t i;
    uint16_t u;
};

static inline union __lip_num16 __lip_num_uchar16(unsigned char const x[])
{
    return (union __lip_num16){.c = {x[0], x[1]}};
}

static inline union __lip_num16 __lip_num_i16(int16_t x)
{
    return (union __lip_num16){.i = x};
}

static inline union __lip_num16 __lip_num_u16(uint16_t x)
{
    return (union __lip_num16){.u = x};
}

union __lip_num32
{
    unsigned char c[4];
    int32_t i;
    uint32_t u;
    float f;
};

static inline union __lip_num32 __lip_num_uchar32(unsigned char const x[])
{
    return (union __lip_num32){.c = {x[0], x[1], x[2], x[3]}};
}

static inline union __lip_num32 __lip_num_i32(int32_t x)
{
    return (union __lip_num32){.i = x};
}

static inline union __lip_num32 __lip_num_u32(uint32_t x)
{
    return (union __lip_num32){.u = x};
}

static inline union __lip_num32 __lip_num_f32(float x)
{
    return (union __lip_num32){.f = x};
}

union __lip_num64
{
    unsigned char c[8];
    int64_t i;
    uint64_t u;
    double f;
};

static inline union __lip_num64 __lip_num_uchar64(unsigned char const x[])
{
    return (union __lip_num64){
        .c = {x[0], x[1], x[2], x[3], x[4], x[5], x[6], x[7]}};
}

static inline union __lip_num64 __lip_num_i64(int64_t x)
{
    return (union __lip_num64){.i = x};
}

static inline union __lip_num64 __lip_num_u64(uint64_t x)
{
    return (union __lip_num64){.u = x};
}

static inline union __lip_num64 __lip_num_f64(double x)
{
    return (union __lip_num64){.f = x};
}

#define __LIP_NUM(x)                                                           \
    _Generic((x), int : __lip_num_int, unsigned : __lip_num_unsigned)(x)

#define __LIP_NUM8(x)                                                          \
    _Generic((x), unsigned char*                                               \
             : __lip_num_uchar8, unsigned char const*                          \
             : __lip_num_uchar8, int8_t                                        \
             : __lip_num_i8, uint8_t                                           \
             : __lip_num_u8)(x)

#define __LIP_NUM16(x)                                                         \
    _Generic((x), unsigned char*                                               \
             : __lip_num_uchar16, unsigned char const*                         \
             : __lip_num_uchar16, int16_t                                      \
             : __lip_num_i16, uint16_t                                         \
             : __lip_num_u16)(x)

#define __LIP_NUM32(x)                                                         \
    _Generic((x), unsigned char*                                               \
             : __lip_num_uchar32, unsigned char const*                         \
             : __lip_num_uchar32, int32_t                                      \
             : __lip_num_i32, uint32_t                                         \
             : __lip_num_u32, float                                            \
             : __lip_num_f32)(x)

#define __LIP_NUM64(x)                                                         \
    _Generic((x), unsigned char*                                               \
             : __lip_num_uchar64, unsigned char const*                         \
             : __lip_num_uchar64, int64_t                                      \
             : __lip_num_i64, uint64_t                                         \
             : __lip_num_u64, double                                           \
             : __lip_num_f64)(x)

#endif
