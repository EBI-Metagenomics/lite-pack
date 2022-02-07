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

union num8
{
    char c[1];
    int8_t i;
    uint8_t u;
};

union num16
{
    char c[2];
    int16_t i;
    uint16_t u;
};

union num32
{
    char c[4];
    int32_t i;
    uint32_t u;
    float f;
};

union num64
{
    char c[8];
    int64_t i;
    uint64_t u;
    double d;
};

#define NUM8(x)                                                                \
    _Generic((x), unsigned                                                     \
             : (union num8){.u = (uint8_t)(x)}, int                            \
             : (union num8){.i = (int8_t)(x)})
#define NUM16(x)                                                               \
    _Generic((x), unsigned                                                     \
             : (union num16){.u = (uint16_t)(x)}, int                          \
             : (union num16){.i = (int16_t)(x)})
#define NUM32(x)                                                               \
    _Generic((x), unsigned                                                     \
             : (union num32){.u = (uint32_t)(x)}, int                          \
             : (union num32){.i = (int32_t)(x)}, float                         \
             : (union num32){.f = (float)(x)})
#define NUM64(x)                                                               \
    _Generic((x), unsigned long                                                \
             : (union num64){.u = (uint64_t)(x)}, long                         \
             : (union num64){.i = (int64_t)(x)}, double                        \
             : (union num64){.d = (double)(x)})

#endif
