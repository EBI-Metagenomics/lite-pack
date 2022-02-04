#ifndef MAP_H
#define MAP_H

#include "compiler.h"
#include "format.h"

static inline unsigned __lip_fix_map_length(uint8_t const buf[static 1])
{
    return (unsigned)__lip_format_fix_value(buf[0]);
}

static inline unsigned __lip_map8_length(uint8_t const buf[static 2])
{
    return (unsigned)buf[1];
}

static inline unsigned __lip_map16_length(uint8_t const buf[static 3])
{
    return (unsigned)host_endian(*((uint16_t *)(buf + 1)));
}

static inline unsigned __lip_map32_length(uint8_t const buf[static 6])
{
    return (unsigned)host_endian(*((uint32_t *)(buf + 1)));
}

#endif
