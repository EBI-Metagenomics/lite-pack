#ifndef COMPILER_H
#define COMPILER_H

#include <arpa/inet.h>
#include <assert.h>
#include <limits.h>
#include <stdint.h>

static_assert(CHAR_BIT == 8, "8-bits char");
static_assert(sizeof(int) >= 4, ">=32-bits int");
static_assert(sizeof(long) >= 8, ">=64-bits long");
static_assert(UINT8_MAX >= 255, "uint8 max req.");
static_assert(UINT16_MAX >= 65535, "uint16 max req.");
static_assert(UINT32_MAX >= 4294967295U, "uint32 max req.");

static_assert(sizeof(float) == 4, "32-bits float");
static_assert(sizeof(double) == 8, "64-bits double");

/*
 * Add the pseudo keyword 'fallthrough' so case statement blocks
 * must end with any of these keywords:
 *   break;
 *   fallthrough;
 *   continue;
 *   goto <label>;
 *   return [expression];
 *
 *  gcc:
 * https://gcc.gnu.org/onlinedocs/gcc/Statement-Attributes.html#Statement-Attributes
 */
#if __has_attribute(__fallthrough__)
#define fallthrough __attribute__((__fallthrough__))
#else
#define fallthrough                                                            \
    do                                                                         \
    {                                                                          \
    } while (0) /* fallthrough */
#endif

#ifndef htonll
#include <byteswap.h>

#if __BIG_ENDIAN__

static inline uint64_t htonll(uint64_t x) { return 0; }
static inline uint64_t ntohll(uint64_t x) { return 0; }

#else

static inline uint64_t htonll(uint64_t x)
{
    return bswap_64(x);
    // return ((uint64_t)htonl((x)&0xFFFFFFFF) << 32) |
    //        htonl((uint32_t)((x) >> 32));
}

static inline uint64_t ntohll(uint64_t x)
{
    return bswap_64(x);
    // return ((uint64_t)ntohl((x)&0xFFFFFFFF) << 32) |
    //        ntohl((uint32_t)((x) >> 32));
}

#endif
#endif

static inline uint16_t __lip_htons(uint16_t x) { return htons(x); }
static inline uint32_t __lip_htonl(uint32_t x) { return htonl(x); }
static inline uint64_t __lip_htonll(uint64_t x) { return htonll(x); }

static inline uint16_t __lip_ntohs(uint16_t x) { return ntohs(x); }
static inline uint32_t __lip_ntohl(uint32_t x) { return ntohl(x); }
static inline uint64_t __lip_ntohll(uint64_t x) { return ntohll(x); }

#define __lip_big_endian(x)                                                    \
    _Generic((x), uint16_t                                                     \
             : __lip_htons, uint32_t                                           \
             : __lip_htonl, uint64_t                                           \
             : __lip_htonll, int16_t                                           \
             : __lip_htons, int32_t                                            \
             : __lip_htonl, int64_t                                            \
             : __lip_htonll)(x)

#define __lip_host_endian(x)                                                   \
    _Generic((x), uint16_t                                                     \
             : __lip_ntohs, uint32_t                                           \
             : __lip_ntohl, uint64_t                                           \
             : __lip_ntohll, int16_t                                           \
             : __lip_ntohs, int32_t                                            \
             : __lip_ntohl, int64_t                                            \
             : __lip_ntohll)(x)

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

#endif
