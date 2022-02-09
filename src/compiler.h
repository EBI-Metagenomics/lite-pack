#ifndef COMPILER_H
#define COMPILER_H

#include <arpa/inet.h>
#include <assert.h>
#include <limits.h>

static_assert(CHAR_BIT == 8, "8-bits char");
static_assert(sizeof(int) >= 4, ">=32-bits int");
static_assert(sizeof(long) >= 8, ">=64-bits long");
static_assert(UINT8_MAX >= 255, "uint8 max req.");
static_assert(UINT16_MAX >= 65535, "uint16 max req.");
static_assert(UINT32_MAX >= 4294967295U, "uint32 max req.");

static_assert(sizeof(float) == 4, "32-bits float");
static_assert(sizeof(double) == 8, "64-bits double");

#define big_endian(x)                                                          \
    _Generic((x), uint8_t                                                      \
             : (x), uint16_t                                                   \
             : htons(x), uint32_t                                              \
             : htonl(x), uint64_t                                              \
             : htonll(x), int8_t                                               \
             : (x), int16_t                                                    \
             : htons(x), int32_t                                               \
             : htonl(x), int64_t                                               \
             : htonll(x))

#define host_endian(x)                                                         \
    _Generic((x), uint8_t                                                      \
             : (x), uint16_t                                                   \
             : ntohs(x), uint32_t                                              \
             : ntohl(x), uint64_t                                              \
             : ntohll(x), int8_t                                               \
             : (x), int16_t                                                    \
             : ntohs(x), int32_t                                               \
             : ntohl(x), int64_t                                               \
             : ntohll(x))

#if defined(__FLOAT_WORD_ORDER__) && defined(__BYTE_ORDER__)

// We check where possible that the float byte order matches the
// integer byte order. This is extremely unlikely to fail, but
// we check anyway just in case.
//
// (The static assert is placed in float/double encoders instead
// of here because our static assert fallback doesn't work at
// file scope)
//
// Source: MPack library <https://github.com/ludocode/mpack>
#define CHECK_FLOAT_ORDER()                                                    \
    static_assert(                                                             \
        __FLOAT_WORD_ORDER__ == __BYTE_ORDER__,                                \
        "float byte order does not match int byte order! float/double "        \
        "encoding is not properly implemented on this platform.")

#endif

#ifndef CHECK_FLOAT_ORDER
#define CHECK_FLOAT_ORDER()
#endif

CHECK_FLOAT_ORDER();

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
