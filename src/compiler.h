#ifndef COMPILER_H
#define COMPILER_H

#include <arpa/inet.h>
#include <assert.h>
#include <limits.h>

static_assert(CHAR_BIT == 8, "8-bits char");
static_assert(sizeof(int) >= 4, ">=32-bits int");
static_assert(sizeof(long) >= 8, ">=64-bits long");

#define host_to_big_endianness(x)                                              \
    _Generic((x), uint16_t                                                     \
             : htons(x), uint32_t                                              \
             : htonl(x), uint64_t                                              \
             : htonll(x))

#define big_to_host_endianness(x)                                              \
    _Generic((x), uint16_t                                                     \
             : ntohs(x), uint32_t                                              \
             : ntohl(x), uint64_t                                              \
             : ntohll(x))

#endif
