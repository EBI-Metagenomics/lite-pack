#ifndef LITE_PACK_ENDIAN_H
#define LITE_PACK_ENDIAN_H

#include "lite_pack/compiler.h"
#include <arpa/inet.h>
#include <stdbool.h>

#if __APPLE__
#include <machine/endian.h>
#else
#include <endian.h>
#endif

#if BYTE_ORDER != LITTLE_ENDIAN && BYTE_ORDER != BIG_ENDIAN
#error We are supporting little and big endian only for now.
#endif

#ifndef htonll

#ifndef BYTE_ORDER
#define BYTE_ORDER __BYTE_ORDER__
#endif

#ifndef BIG_ENDIAN
#define BIG_ENDIAN __BIG_ENDIAN__
#endif

#if BYTE_ORDER == BIG_ENDIAN

static inline uint64_t htonll(uint64_t x) { return x; }
static inline uint64_t ntohll(uint64_t x) { return x; }

#else

static inline uint64_t htonll(uint64_t x) { return __builtin_bswap64(x); }
static inline uint64_t ntohll(uint64_t x) { return __builtin_bswap64(x); }

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

static inline bool __lip_is_big_endian(void)
{
#if BYTE_ORDER == BIG_ENDIAN
    return true;
#else
    return false;
#endif
}

#endif
