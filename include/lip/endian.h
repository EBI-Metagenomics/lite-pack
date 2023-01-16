#ifndef LIP_ENDIAN_H
#define LIP_ENDIAN_H

#include "lip/export.h"
#include <stdbool.h>
#include <stdint.h>

LIP_API uint16_t __lip_htons(uint16_t x);
LIP_API uint32_t __lip_htonl(uint32_t x);
LIP_API uint64_t __lip_htonll(uint64_t x);

LIP_API uint16_t __lip_ntohs(uint16_t x);
LIP_API uint32_t __lip_ntohl(uint32_t x);
LIP_API uint64_t __lip_ntohll(uint64_t x);

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

LIP_API bool __lip_is_big_endian(void);

#endif
