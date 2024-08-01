#include "lite_pack.h"
#include <string.h>

typedef union
{
  char    c[8];
  uint64_t u64;
  int64_t  i64;
  uint32_t u32;
  int32_t  i32;
  uint16_t u16;
  int16_t  i16;
  uint8_t   u8;
  int8_t    i8;
  double     d;
  float      f;
} number;

enum format
{
  LIP_FMT_POSITIVE_FIXINT,
  LIP_FMT_FIXMAP,
  LIP_FMT_FIXARRAY,
  LIP_FMT_FIXSTR,
  LIP_FMT_NIL,
  LIP_FMT_NEVER_USED,
  LIP_FMT_FALSE,
  LIP_FMT_TRUE,
  LIP_FMT_BIN_8,
  LIP_FMT_BIN_16,
  LIP_FMT_BIN_32,
  LIP_FMT_EXT_8,
  LIP_FMT_EXT_16,
  LIP_FMT_EXT_32,
  LIP_FMT_FLOAT_32,
  LIP_FMT_FLOAT_64,
  LIP_FMT_UINT_8,
  LIP_FMT_UINT_16,
  LIP_FMT_UINT_32,
  LIP_FMT_UINT_64,
  LIP_FMT_INT_8,
  LIP_FMT_INT_16,
  LIP_FMT_INT_32,
  LIP_FMT_INT_64,
  LIP_FMT_FIXEXT_1,
  LIP_FMT_FIXEXT_2,
  LIP_FMT_FIXEXT_4,
  LIP_FMT_FIXEXT_8,
  LIP_FMT_FIXEXT_16,
  LIP_FMT_STR_8,
  LIP_FMT_STR_16,
  LIP_FMT_STR_32,
  LIP_FMT_ARRAY_16,
  LIP_FMT_ARRAY_32,
  LIP_FMT_MAP_16,
  LIP_FMT_MAP_32,
  LIP_FMT_NEGATIVE_FIXINT,
};

enum lip_format_family
{
  LIP_FMT_FAMILY_NIL,
  LIP_FMT_FAMILY_BOOL,
  LIP_FMT_FAMILY_INT,
  LIP_FMT_FAMILY_FLOAT,
  LIP_FMT_FAMILY_STR,
  LIP_FMT_FAMILY_BIN,
  LIP_FMT_FAMILY_ARRAY,
  LIP_FMT_FAMILY_MAP,
  LIP_FMT_FAMILY_EXT,
  LIP_FMT_FAMILY_NEVER_USED,
};

static inline unsigned char first_byte(enum format format, number number)
{
  switch (format)
  {
  case LIP_FMT_NIL:        return 0xc0;
  case LIP_FMT_NEVER_USED: return 0xc1;
  case LIP_FMT_FALSE:      return 0xc2;
  case LIP_FMT_TRUE:       return 0xc3;
  case LIP_FMT_BIN_8:      return 0xc4;
  case LIP_FMT_BIN_16:     return 0xc5;
  case LIP_FMT_BIN_32:     return 0xc6;
  case LIP_FMT_EXT_8:      return 0xc7;
  case LIP_FMT_EXT_16:     return 0xc8;
  case LIP_FMT_EXT_32:     return 0xc9;
  case LIP_FMT_FLOAT_32:   return 0xca;
  case LIP_FMT_FLOAT_64:   return 0xcb;
  case LIP_FMT_UINT_8:     return 0xcc;
  case LIP_FMT_UINT_16:    return 0xcd;
  case LIP_FMT_UINT_32:    return 0xce;
  case LIP_FMT_UINT_64:    return 0xcf;
  case LIP_FMT_INT_8:      return 0xd0;
  case LIP_FMT_INT_16:     return 0xd1;
  case LIP_FMT_INT_32:     return 0xd2;
  case LIP_FMT_INT_64:     return 0xd3;
  case LIP_FMT_FIXEXT_1:   return 0xd4;
  case LIP_FMT_FIXEXT_2:   return 0xd5;
  case LIP_FMT_FIXEXT_4:   return 0xd6;
  case LIP_FMT_FIXEXT_8:   return 0xd7;
  case LIP_FMT_FIXEXT_16:  return 0xd8;
  case LIP_FMT_STR_8:      return 0xd9;
  case LIP_FMT_STR_16:     return 0xda;
  case LIP_FMT_STR_32:     return 0xdb;
  case LIP_FMT_ARRAY_16:   return 0xdc;
  case LIP_FMT_ARRAY_32:   return 0xdd;
  case LIP_FMT_MAP_16:     return 0xde;
  case LIP_FMT_MAP_32:     return 0xdf;
  case LIP_FMT_POSITIVE_FIXINT: return (unsigned char)(0x00 | number.u8);
  case LIP_FMT_FIXMAP:          return (unsigned char)(0x80 | number.u8);
  case LIP_FMT_FIXARRAY:        return (unsigned char)(0x90 | number.u8);
  case LIP_FMT_FIXSTR:          return (unsigned char)(0xa0 | number.u8);
  case LIP_FMT_NEGATIVE_FIXINT: return (unsigned char)(0xe0 | number.u8);
  default:                 return 0;
  }
}

static enum format format(int first_byte)
{
  if      (0x00 <= first_byte && first_byte <= 0x7f) return LIP_FMT_POSITIVE_FIXINT;
  else if (0xe0 <= first_byte && first_byte <= 0xff) return LIP_FMT_NEGATIVE_FIXINT;
  else if (0x80 <= first_byte && first_byte <= 0x8f) return LIP_FMT_FIXMAP;
  else if (0x90 <= first_byte && first_byte <= 0x9f) return LIP_FMT_FIXARRAY;
  else if (0xa0 <= first_byte && first_byte <= 0xbf) return LIP_FMT_FIXSTR;
  else
  {
    switch (first_byte)
    {
    case 0xc0: return LIP_FMT_NIL;
    case 0xc1: return LIP_FMT_NEVER_USED;
    case 0xc2: return LIP_FMT_FALSE;
    case 0xc3: return LIP_FMT_TRUE;
    case 0xc4: return LIP_FMT_BIN_8;
    case 0xc5: return LIP_FMT_BIN_16;
    case 0xc6: return LIP_FMT_BIN_32;
    case 0xc7: return LIP_FMT_EXT_8;
    case 0xc8: return LIP_FMT_EXT_16;
    case 0xc9: return LIP_FMT_EXT_32;
    case 0xca: return LIP_FMT_FLOAT_32;
    case 0xcb: return LIP_FMT_FLOAT_64;
    case 0xcc: return LIP_FMT_UINT_8;
    case 0xcd: return LIP_FMT_UINT_16;
    case 0xce: return LIP_FMT_UINT_32;
    case 0xcf: return LIP_FMT_UINT_64;
    case 0xd0: return LIP_FMT_INT_8;
    case 0xd1: return LIP_FMT_INT_16;
    case 0xd2: return LIP_FMT_INT_32;
    case 0xd3: return LIP_FMT_INT_64;
    case 0xd4: return LIP_FMT_FIXEXT_1;
    case 0xd5: return LIP_FMT_FIXEXT_2;
    case 0xd6: return LIP_FMT_FIXEXT_4;
    case 0xd7: return LIP_FMT_FIXEXT_8;
    case 0xd8: return LIP_FMT_FIXEXT_16;
    case 0xd9: return LIP_FMT_STR_8;
    case 0xda: return LIP_FMT_STR_16;
    case 0xdb: return LIP_FMT_STR_32;
    case 0xdc: return LIP_FMT_ARRAY_16;
    case 0xdd: return LIP_FMT_ARRAY_32;
    case 0xde: return LIP_FMT_MAP_16;
    case 0xdf: return LIP_FMT_MAP_32;
    default:   return 0;
    }
  }
}

static inline uint64_t bswap64(uint64_t x)
{
  return ((x & 0xFF00000000000000u) >> 56) |
         ((x & 0x00FF000000000000u) >> 40) |
         ((x & 0x0000FF0000000000u) >> 24) |
         ((x & 0x000000FF00000000u) >>  8) |
         ((x & 0x00000000FF000000u) <<  8) |
         ((x & 0x0000000000FF0000u) << 24) |
         ((x & 0x000000000000FF00u) << 40) |
         ((x & 0x00000000000000FFu) << 56);
}

static inline uint32_t bswap32(uint32_t x)
{
  return ((x & 0xFF000000u) >> 24) |
         ((x & 0x00FF0000u) >>  8) |
         ((x & 0x0000FF00u) <<  8) |
         ((x & 0x000000FFu) << 24);
}

static inline uint16_t bswap16(uint16_t x)
{
  return (uint16_t)(((x & 0xFF00u) >> 8) | ((x & 0x00FFu) << 8));
}

static inline int is_little_endian(void)
{
  const union { uint32_t u; uint8_t c[4]; } one = { .u = 1 };
  return one.c[0];
}

#define as_number(x)                                                          \
  _Generic((x),                                                               \
      uint64_t: (number){.u64 = (x)},                                         \
      uint32_t: (number){.u32 = (x)},                                         \
      uint16_t: (number){.u16 = (x)},                                         \
      uint8_t:  (number){.u8 = (x)},                                          \
      int64_t:  (number){.i64 = (x)},                                         \
      int32_t:  (number){.i32 = (x)},                                         \
      int16_t:  (number){.i16 = (x)},                                         \
      int8_t:   (number){.i8 = (x)},                                          \
      double:   (number){.d = (x)},                                           \
      float:    (number){.f = (x)})

static inline size_t copy_number(unsigned char buffer[], int size,
                                 number number)
{
  if (is_little_endian() && size == 2) number.u16 = bswap16(number.u16);
  if (is_little_endian() && size == 4) number.u32 = bswap32(number.u32);
  if (is_little_endian() && size == 8) number.u64 = bswap64(number.u64);
  memcpy(buffer, &number, size);
  return (size_t)size;
}

static inline size_t store_number(unsigned char buffer[], enum format format,
                                  int size, number number)
{
  buffer[0] = first_byte(format, number);
  return 1 + copy_number(buffer + 1, size, number);
}

static inline void load_number(unsigned char const buffer[], int size,
                               number *number)
{
  memcpy(number->c, buffer, size);
  if (is_little_endian() && size == 2) number->u16 = bswap16(number->u16);
  if (is_little_endian() && size == 4) number->u32 = bswap32(number->u32);
  if (is_little_endian() && size == 8) number->u64 = bswap64(number->u64);
}

/*****************************************************************************/
/* PACK FUNCTIONS BLOCK                                                      */
/*****************************************************************************/
size_t lip_pack_nil(unsigned char buffer[])
{
  buffer[0] = first_byte(LIP_FMT_NIL, as_number(0));
  return 1;
}

size_t lip_pack_bool(unsigned char buffer[], bool data)
{
  buffer[0] = first_byte(data ? LIP_FMT_TRUE : LIP_FMT_FALSE, as_number(0));
  return 1;
}

size_t lip_pack_u64(unsigned char buffer[], uint64_t data)
{
  if      (data <= 0xFF)       return lip_pack_u8 (buffer, (uint8_t) data);
  else if (data <= 0xFFFF)     return lip_pack_u16(buffer, (uint16_t)data);
  else if (data <= 0xFFFFFFFF) return lip_pack_u32(buffer, (uint32_t)data);
  else                         return store_number(buffer, LIP_FMT_UINT_64, 8, as_number(data));
}

size_t lip_pack_u32(unsigned char buffer[], uint32_t data)
{
  if      (data <= 0xFF)   return lip_pack_u8 (buffer, (uint8_t) data);
  else if (data <= 0xFFFF) return lip_pack_u16(buffer, (uint16_t)data);
  else                     return store_number(buffer, LIP_FMT_UINT_32, 4, as_number(data));
}

size_t lip_pack_u16(unsigned char buffer[], uint16_t data)
{
  if (data <= 0xFF) return lip_pack_u8 (buffer, (uint8_t)data);
  else              return store_number(buffer, LIP_FMT_UINT_16, 2, as_number(data));
}

size_t lip_pack_u8(unsigned char buffer[], uint8_t data)
{
  if (data <= 0x7F) return store_number(buffer, LIP_FMT_POSITIVE_FIXINT, 0,  as_number(data));
  else              return store_number(buffer, LIP_FMT_UINT_8, 1        , as_number(data));
}

size_t lip_pack_i64(unsigned char buffer[], int64_t data)
{
  if      (data >= 0)         return lip_pack_u64(buffer, (uint64_t)data);
  else if (data >= -32)       return store_number(buffer, LIP_FMT_NEGATIVE_FIXINT, 0, as_number((int8_t )data));
  else if (data >= INT8_MIN)  return store_number(buffer, LIP_FMT_INT_8          , 1, as_number((int8_t )data));
  else if (data >= INT16_MIN) return store_number(buffer, LIP_FMT_INT_16         , 2, as_number((int16_t)data));
  else if (data >= INT32_MIN) return store_number(buffer, LIP_FMT_INT_32         , 4, as_number((int32_t)data));
  else                        return store_number(buffer, LIP_FMT_INT_64         , 8, as_number((int64_t)data));
}

size_t lip_pack_i32(unsigned char buffer[], int32_t data)
{
  if      (data >= 0)         return lip_pack_u32(buffer, (uint32_t)data);
  else if (data >= -32)       return store_number(buffer, LIP_FMT_NEGATIVE_FIXINT, 0, as_number((int8_t )data));
  else if (data >= INT8_MIN)  return store_number(buffer, LIP_FMT_INT_8          , 1, as_number((int8_t )data));
  else if (data >= INT16_MIN) return store_number(buffer, LIP_FMT_INT_16         , 2, as_number((int16_t)data));
  else                        return store_number(buffer, LIP_FMT_INT_32         , 4, as_number((int32_t)data));
}

size_t lip_pack_i16(unsigned char buffer[], int16_t data)
{
  if      (data >= 0)        return lip_pack_u16(buffer, (uint16_t)data);
  else if (data >= -32)      return store_number(buffer, LIP_FMT_NEGATIVE_FIXINT, 0, as_number((int8_t )data));
  else if (data >= INT8_MIN) return store_number(buffer, LIP_FMT_INT_8          , 1, as_number((int8_t )data));
  else                       return store_number(buffer, LIP_FMT_INT_16         , 2, as_number((int16_t)data));
}

size_t lip_pack_i8(unsigned char buffer[], int8_t data)
{
  if      (data >= 0)   return lip_pack_u8 (buffer, (uint8_t)data);
  else if (data >= -32) return store_number(buffer, LIP_FMT_NEGATIVE_FIXINT, 0, as_number((int8_t )data));
  else                  return store_number(buffer, LIP_FMT_INT_8          , 1, as_number((int8_t )data));
}

size_t lip_pack_f64(unsigned char buffer[], double data)
{
  return store_number(buffer, LIP_FMT_FLOAT_64, 8, as_number(data));
}

size_t lip_pack_f32(unsigned char buffer[], float data)
{
  return store_number(buffer, LIP_FMT_FLOAT_32, 4, as_number(data));
}

size_t lip_pack_string(unsigned char buffer[], uint32_t size)
{
  if      (size <= 0x1F)   return store_number(buffer, LIP_FMT_FIXSTR, 0, as_number(size));
  else if (size <= 0xFF)   return store_number(buffer, LIP_FMT_STR_8 , 1, as_number(size));
  else if (size <= 0xFFFF) return store_number(buffer, LIP_FMT_STR_16, 2, as_number(size));
  else                     return store_number(buffer, LIP_FMT_STR_32, 4, as_number(size));
}

size_t lip_pack_array(unsigned char buffer[], uint32_t size)
{
  if      (size <= 0xF)    return store_number(buffer, LIP_FMT_FIXARRAY, 0, as_number(size));
  else if (size <= 0xFFFF) return store_number(buffer, LIP_FMT_ARRAY_16, 2, as_number(size));
  else                     return store_number(buffer, LIP_FMT_ARRAY_32, 4, as_number(size));
}

size_t lip_pack_map(unsigned char buffer[], uint32_t size)
{
  if      (size <= 0xF)    return store_number(buffer, LIP_FMT_FIXMAP, 0, as_number(size));
  else if (size <= 0xFFFF) return store_number(buffer, LIP_FMT_MAP_16, 2, as_number(size));
  else                     return store_number(buffer, LIP_FMT_MAP_32, 4, as_number(size));
}

size_t lip_pack_ext(unsigned char buffer[], uint32_t size, uint8_t type)
{
  if      (size == 1)       return store_number(buffer, LIP_FMT_FIXEXT_1 , 1, as_number(type));
  else if (size == 2)       return store_number(buffer, LIP_FMT_FIXEXT_2 , 1, as_number(type));
  else if (size == 4)       return store_number(buffer, LIP_FMT_FIXEXT_4 , 1, as_number(type));
  else if (size == 8)       return store_number(buffer, LIP_FMT_FIXEXT_8 , 1, as_number(type));
  else if (size == 16)      return store_number(buffer, LIP_FMT_FIXEXT_16, 1, as_number(type));
  else if (size <= 0xFFU)   return store_number(buffer, LIP_FMT_EXT_8    , 1, as_number(size)) + copy_number(buffer + 2, 1, as_number(type));
  else if (size <= 0xFFFFU) return store_number(buffer, LIP_FMT_EXT_16   , 2, as_number(size)) + copy_number(buffer + 3, 1, as_number(type));
  else                      return store_number(buffer, LIP_FMT_EXT_32   , 4, as_number(size)) + copy_number(buffer + 5, 1, as_number(type));
}

size_t lip_pack_bin(unsigned char buffer[], uint32_t size)
{

  if      (size <= 0xFF)   return store_number(buffer, LIP_FMT_BIN_8 , 1, as_number(size));
  else if (size <= 0xFFFF) return store_number(buffer, LIP_FMT_BIN_16, 2, as_number(size));
  else                     return store_number(buffer, LIP_FMT_BIN_32, 4, as_number(size));
}

/*****************************************************************************/
/* UNPACK FUNCTIONS BLOCK                                                    */
/*****************************************************************************/
size_t lip_unpack_nil(unsigned char buffer[])
{
  return format(buffer[0]) == LIP_FMT_NIL ? 1 : 0;
}

size_t lip_unpack_bool(unsigned char const buffer[], bool *data)
{
  if (format(buffer[0]) == LIP_FMT_FALSE || format(buffer[0]) == LIP_FMT_TRUE)
  {
    *data = format(buffer[0]) ^ LIP_FMT_FALSE;
    return 1;
  }
  return 0;
}

size_t lip_unpack_u64(unsigned char const buffer[], uint64_t *data)
{
  number number;
  switch (format(buffer[0]))
  {
  case LIP_FMT_POSITIVE_FIXINT: load_number(buffer + 0, 1, &number); *data = number.u8 ; /* assigned within limits  */ return 1 + 0;
  case LIP_FMT_NEGATIVE_FIXINT: load_number(buffer + 0, 1, &number); *data = number.u8 ; if (number.i8  < 0) return 0; return 1 + 0;
  case LIP_FMT_UINT_8         : load_number(buffer + 1, 1, &number); *data = number.u8 ; /* assigned within limits  */ return 1 + 1;
  case LIP_FMT_INT_8          : load_number(buffer + 1, 1, &number); *data = number.u8 ; if (number.i8  < 0) return 0; return 1 + 1;
  case LIP_FMT_UINT_16        : load_number(buffer + 1, 2, &number); *data = number.u16; /* assigned within limits  */ return 2 + 1;
  case LIP_FMT_INT_16         : load_number(buffer + 1, 2, &number); *data = number.u16; if (number.i16 < 0) return 0; return 2 + 1;
  case LIP_FMT_UINT_32        : load_number(buffer + 1, 4, &number); *data = number.u32; /* assigned within limits  */ return 4 + 1;
  case LIP_FMT_INT_32         : load_number(buffer + 1, 4, &number); *data = number.u32; if (number.i32 < 0) return 0; return 4 + 1;
  case LIP_FMT_UINT_64        : load_number(buffer + 1, 8, &number); *data = number.u64; /* assigned within limits  */ return 8 + 1;
  case LIP_FMT_INT_64         : load_number(buffer + 1, 8, &number); *data = number.u64; if (number.i64 < 0) return 0; return 8 + 1;
  default                     : return 0; /* invalid buffer */
  }
}

size_t lip_unpack_u32(unsigned char const buffer[], uint32_t *data)
{
  number number;
  switch (format(buffer[0]))
  {
  case LIP_FMT_POSITIVE_FIXINT: load_number(buffer + 0, 1, &number); *data = number.u8 ; /* assigned within limits  */ return 1 + 0;
  case LIP_FMT_NEGATIVE_FIXINT: load_number(buffer + 0, 1, &number); *data = number.u8 ; if (number.i8  < 0) return 0; return 1 + 0;
  case LIP_FMT_UINT_8         : load_number(buffer + 1, 1, &number); *data = number.u8 ; /* assigned within limits  */ return 1 + 1;
  case LIP_FMT_INT_8          : load_number(buffer + 1, 1, &number); *data = number.u8 ; if (number.i8  < 0) return 0; return 1 + 1;
  case LIP_FMT_UINT_16        : load_number(buffer + 1, 2, &number); *data = number.u16; /* assigned within limits  */ return 2 + 1;
  case LIP_FMT_INT_16         : load_number(buffer + 1, 2, &number); *data = number.u16; if (number.i16 < 0) return 0; return 2 + 1;
  case LIP_FMT_UINT_32        : load_number(buffer + 1, 4, &number); *data = number.u32; /* assigned within limits  */ return 4 + 1;
  case LIP_FMT_INT_32         : load_number(buffer + 1, 4, &number); *data = number.u32; if (number.i32 < 0) return 0; return 4 + 1;
  default                     : return 0; /* invalid buffer */
  }
}

size_t lip_unpack_u16(unsigned char const buffer[], uint16_t *data)
{
  number number;
  switch (format(buffer[0]))
  {
  case LIP_FMT_POSITIVE_FIXINT: load_number(buffer + 0, 1, &number); *data = number.u8 ; /* assigned within limits  */ return 1 + 0;
  case LIP_FMT_NEGATIVE_FIXINT: load_number(buffer + 0, 1, &number); *data = number.u8 ; if (number.i8  < 0) return 0; return 1 + 0;
  case LIP_FMT_UINT_8         : load_number(buffer + 1, 1, &number); *data = number.u8 ; /* assigned within limits  */ return 1 + 1;
  case LIP_FMT_INT_8          : load_number(buffer + 1, 1, &number); *data = number.u8 ; if (number.i8  < 0) return 0; return 1 + 1;
  case LIP_FMT_UINT_16        : load_number(buffer + 1, 2, &number); *data = number.u16; /* assigned within limits  */ return 2 + 1;
  case LIP_FMT_INT_16         : load_number(buffer + 1, 2, &number); *data = number.u16; if (number.i16 < 0) return 0; return 2 + 1;
  default                     : return 0; /* invalid buffer */
  }
}

size_t lip_unpack_u8(unsigned char const buffer[], uint8_t *data)
{
  number number;
  switch (format(buffer[0]))
  {
  case LIP_FMT_POSITIVE_FIXINT: load_number(buffer + 0, 1, &number); *data = number.u8 ; /* assigned within limits  */ return 1 + 0;
  case LIP_FMT_NEGATIVE_FIXINT: load_number(buffer + 0, 1, &number); *data = number.u8 ; if (number.i8  < 0) return 0; return 1 + 0;
  case LIP_FMT_UINT_8         : load_number(buffer + 1, 1, &number); *data = number.u8 ; /* assigned within limits  */ return 1 + 1;
  case LIP_FMT_INT_8          : load_number(buffer + 1, 1, &number); *data = number.u8 ; if (number.i8  < 0) return 0; return 1 + 1;
  default                     : return 0; /* invalid buffer */
  }
}

size_t lip_unpack_i64(unsigned char const buffer[], int64_t *data)
{
  number number;
  switch (format(buffer[0]))
  {
  case LIP_FMT_POSITIVE_FIXINT: load_number(buffer + 0, 1, &number); *data = number.u8 ; /* assigned within limits          */ return 1 + 0;
  case LIP_FMT_NEGATIVE_FIXINT: load_number(buffer + 0, 1, &number); *data = number.i8 ; /* assigned within limits          */ return 1 + 0;
  case LIP_FMT_UINT_8         : load_number(buffer + 1, 1, &number); *data = number.u8 ; /* assigned within limits          */ return 1 + 1;
  case LIP_FMT_INT_8          : load_number(buffer + 1, 1, &number); *data = number.i8 ; /* assigned within limits          */ return 1 + 1;
  case LIP_FMT_UINT_16        : load_number(buffer + 1, 2, &number); *data = number.u16; /* assigned within limits          */ return 2 + 1;
  case LIP_FMT_INT_16         : load_number(buffer + 1, 2, &number); *data = number.i16; /* assigned within limits          */ return 2 + 1;
  case LIP_FMT_UINT_32        : load_number(buffer + 1, 4, &number); *data = number.u32; /* assigned within limits          */ return 4 + 1;
  case LIP_FMT_INT_32         : load_number(buffer + 1, 4, &number); *data = number.i32; /* assigned within limits          */ return 4 + 1;
  case LIP_FMT_UINT_64        : load_number(buffer + 1, 8, &number); *data = number.i64; if (number.u64 > INT64_MAX) return 0; return 8 + 1;
  case LIP_FMT_INT_64         : load_number(buffer + 1, 8, &number); *data = number.i64; /* assigned within limits          */ return 8 + 1;
  default                     : return 0; /* invalid buffer */
  }
}

size_t lip_unpack_i32(unsigned char const buffer[], int32_t *data)
{
  number number;
  switch (format(buffer[0]))
  {
  case LIP_FMT_POSITIVE_FIXINT: load_number(buffer + 0, 1, &number); *data = number.u8 ; /* assigned within limits          */ return 1 + 0;
  case LIP_FMT_NEGATIVE_FIXINT: load_number(buffer + 0, 1, &number); *data = number.i8 ; /* assigned within limits          */ return 1 + 0;
  case LIP_FMT_UINT_8         : load_number(buffer + 1, 1, &number); *data = number.u8 ; /* assigned within limits          */ return 1 + 1;
  case LIP_FMT_INT_8          : load_number(buffer + 1, 1, &number); *data = number.i8 ; /* assigned within limits          */ return 1 + 1;
  case LIP_FMT_UINT_16        : load_number(buffer + 1, 2, &number); *data = number.u16; /* assigned within limits          */ return 2 + 1;
  case LIP_FMT_INT_16         : load_number(buffer + 1, 2, &number); *data = number.i16; /* assigned within limits          */ return 2 + 1;
  case LIP_FMT_UINT_32        : load_number(buffer + 1, 4, &number); *data = number.i32; if (number.u32 > INT32_MAX) return 0; return 4 + 1;
  case LIP_FMT_INT_32         : load_number(buffer + 1, 4, &number); *data = number.i32; /* assigned within limits          */ return 4 + 1;
  default                     : return 0; /* invalid buffer */
  }
}

size_t lip_unpack_i16(unsigned char const buffer[], int16_t *data)
{
  number number;
  switch (format(buffer[0]))
  {
  case LIP_FMT_POSITIVE_FIXINT: load_number(buffer + 0, 1, &number); *data = number.u8 ; /* assigned within limits          */ return 1 + 0;
  case LIP_FMT_NEGATIVE_FIXINT: load_number(buffer + 0, 1, &number); *data = number.i8 ; /* assigned within limits          */ return 1 + 0;
  case LIP_FMT_UINT_8         : load_number(buffer + 1, 1, &number); *data = number.u8 ; /* assigned within limits          */ return 1 + 1;
  case LIP_FMT_INT_8          : load_number(buffer + 1, 1, &number); *data = number.i8 ; /* assigned within limits          */ return 1 + 1;
  case LIP_FMT_UINT_16        : load_number(buffer + 1, 2, &number); *data = number.i16; if (number.u16 > INT16_MAX) return 0; return 2 + 1;
  case LIP_FMT_INT_16         : load_number(buffer + 1, 2, &number); *data = number.i16; /* assigned within limits          */ return 2 + 1;
  default                     : return 0; /* invalid buffer */
  }
}

size_t lip_unpack_i8(unsigned char const buffer[], int8_t *data)
{
  number number;
  switch (format(buffer[0]))
  {
  case LIP_FMT_POSITIVE_FIXINT: load_number(buffer + 0, 1, &number); *data = number.i8 ; if (number.u8 > INT8_MAX) return 0; return 1 + 0;
  case LIP_FMT_NEGATIVE_FIXINT: load_number(buffer + 0, 1, &number); *data = number.i8 ; /* assigned within limits        */ return 1 + 0;
  case LIP_FMT_UINT_8         : load_number(buffer + 1, 1, &number); *data = number.i8 ; if (number.u8 > INT8_MAX) return 0; return 1 + 1;
  case LIP_FMT_INT_8          : load_number(buffer + 1, 1, &number); *data = number.i8 ; /* assigned within limits        */ return 1 + 1;
  default                     : return 0; /* invalid buffer */
  }
}

size_t lip_unpack_f64(unsigned char const buffer[], double *data)
{
  number number;
  if (format(buffer[0]) == LIP_FMT_FLOAT_32)
  {
    load_number(buffer + 1, 4, &number);
    *data = (double)number.f;
    return 5;
  }
  if (format(buffer[0]) == LIP_FMT_FLOAT_64)
  {
    load_number(buffer + 1, 8, &number);
    *data = number.d;
    return 9;
  }

  return 0;
}

size_t lip_unpack_f32(unsigned char const buffer[], float *data)
{
  number number;
  if (format(buffer[0]) == LIP_FMT_FLOAT_32)
  {
    load_number(buffer + 1, 4, &number);
    *data = number.f;
    return 5;
  }
  return 0;
}

size_t lip_unpack_string(unsigned char const buffer[], uint32_t *size)
{
  number number;
  switch (format(buffer[0]))
  {
  case LIP_FMT_FIXSTR: *size = (uint8_t)(~0xA0 & buffer[0]);                    return 1 + 0;
  case LIP_FMT_STR_8 : load_number(buffer + 1, 1, &number); *size = number.u8 ; return 1 + 1;
  case LIP_FMT_STR_16: load_number(buffer + 1, 2, &number); *size = number.u16; return 1 + 2;
  case LIP_FMT_STR_32: load_number(buffer + 1, 4, &number); *size = number.u32; return 1 + 4;
  default            : return 0; /* invalid buffer */
  }
}

size_t lip_unpack_array(unsigned char const buffer[], uint32_t *size)
{
  number number;
  switch (format(buffer[0]))
  {
  case LIP_FMT_FIXARRAY: *size = (uint8_t)(~0x90 & buffer[0]);                    return 1 + 0;
  case LIP_FMT_ARRAY_16: load_number(buffer + 1, 2, &number); *size = number.u16; return 1 + 2;
  case LIP_FMT_ARRAY_32: load_number(buffer + 1, 4, &number); *size = number.u32; return 1 + 4;
  default            : return 0; /* invalid buffer */
  }
}

size_t lip_unpack_map(unsigned char const buffer[], uint32_t *size)
{
  number number;
  switch (format(buffer[0]))
  {
  case LIP_FMT_FIXMAP: *size = (uint8_t)(~0x80 & buffer[0]);                    return 1 + 0;
  case LIP_FMT_MAP_16: load_number(buffer + 1, 2, &number); *size = number.u16; return 1 + 2;
  case LIP_FMT_MAP_32: load_number(buffer + 1, 4, &number); *size = number.u32; return 1 + 4;
  default            : return 0; /* invalid buffer */
  }
}

size_t lip_unpack_ext(unsigned char const buffer[], uint32_t *size, uint8_t *type)
{
  number number;
  switch (format(buffer[0]))
  {
  case LIP_FMT_FIXEXT_1 :                                      *size =          1; load_number(buffer + 1, 1, &number); *type = number.u8; return 1 + 1;
  case LIP_FMT_FIXEXT_2 :                                      *size =          2; load_number(buffer + 1, 1, &number); *type = number.u8; return 1 + 1;
  case LIP_FMT_FIXEXT_4 :                                      *size =          4; load_number(buffer + 1, 1, &number); *type = number.u8; return 1 + 1;
  case LIP_FMT_FIXEXT_8 :                                      *size =          8; load_number(buffer + 1, 1, &number); *type = number.u8; return 1 + 1;
  case LIP_FMT_FIXEXT_16:                                      *size =         16; load_number(buffer + 1, 1, &number); *type = number.u8; return 1 + 1;
  case LIP_FMT_EXT_8    : load_number(buffer + 1, 1, &number); *size = number.u8 ; load_number(buffer + 2, 1, &number); *type = number.u8; return 1 + 1 + 1;
  case LIP_FMT_EXT_16   : load_number(buffer + 1, 2, &number); *size = number.u16; load_number(buffer + 3, 1, &number); *type = number.u8; return 1 + 2 + 1;
  case LIP_FMT_EXT_32   : load_number(buffer + 1, 4, &number); *size = number.u32; load_number(buffer + 5, 1, &number); *type = number.u8; return 1 + 4 + 1;
  default               : return 0; /* invalid buffer */
  }
}

size_t lip_unpack_bin(unsigned char const buffer[], uint32_t *size)
{
  number number;
  switch (format(buffer[0]))
  {
  case LIP_FMT_BIN_8 : load_number(buffer + 1, 1, &number); *size = number.u8 ; return 1 + 1;
  case LIP_FMT_BIN_16: load_number(buffer + 1, 2, &number); *size = number.u16; return 1 + 2;
  case LIP_FMT_BIN_32: load_number(buffer + 1, 4, &number); *size = number.u32; return 1 + 4;
  default            : return 0; /* invalid buffer */
  }
}

size_t lip_size(unsigned char const buffer[])
{
  switch (format(buffer[0]))
  {
  case LIP_FMT_NIL:             return 1;
  case LIP_FMT_NEVER_USED:      return 0;
  case LIP_FMT_FALSE:           return 1;
  case LIP_FMT_TRUE:            return 1;
  case LIP_FMT_BIN_8:           return 2;
  case LIP_FMT_BIN_16:          return 3;
  case LIP_FMT_BIN_32:          return 5;
  case LIP_FMT_EXT_8:           return 3;
  case LIP_FMT_EXT_16:          return 4;
  case LIP_FMT_EXT_32:          return 6;
  case LIP_FMT_FLOAT_32:        return 5;
  case LIP_FMT_FLOAT_64:        return 9;
  case LIP_FMT_UINT_8:          return 2;
  case LIP_FMT_UINT_16:         return 3;
  case LIP_FMT_UINT_32:         return 5;
  case LIP_FMT_UINT_64:         return 9;
  case LIP_FMT_INT_8:           return 2;
  case LIP_FMT_INT_16:          return 3;
  case LIP_FMT_INT_32:          return 5;
  case LIP_FMT_INT_64:          return 9;
  case LIP_FMT_FIXEXT_1:        return 2;
  case LIP_FMT_FIXEXT_2:        return 2;
  case LIP_FMT_FIXEXT_4:        return 2;
  case LIP_FMT_FIXEXT_8:        return 2;
  case LIP_FMT_FIXEXT_16:       return 2;
  case LIP_FMT_STR_8:           return 2;
  case LIP_FMT_STR_16:          return 3;
  case LIP_FMT_STR_32:          return 5;
  case LIP_FMT_ARRAY_16:        return 3;
  case LIP_FMT_ARRAY_32:        return 5;
  case LIP_FMT_MAP_16:          return 3;
  case LIP_FMT_MAP_32:          return 5;
  case LIP_FMT_POSITIVE_FIXINT: return 1;
  case LIP_FMT_FIXMAP:          return 1;
  case LIP_FMT_FIXARRAY:        return 1;
  case LIP_FMT_FIXSTR:          return 1;
  case LIP_FMT_NEGATIVE_FIXINT: return 1;
  default:                      return 0;
  }
}
