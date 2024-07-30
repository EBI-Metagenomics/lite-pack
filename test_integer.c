#include "lite_pack.h"
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define array_size(x) (sizeof(x) / sizeof((x)[0]))

#define fail()                                                                 \
  do                                                                           \
  {                                                                            \
    fprintf(stderr, "\nFailure at %s:%d\n", __FILE__, __LINE__);               \
    exit(1);                                                                   \
  } while (1)

static unsigned const u32_values[] = {
    0,          1,          2,          3,          4,          5,
    7,          8,          9,          15,         16,         17,
    31,         32,         33,         63,         64,         65,
    127,        128,        129,        255,        256,        257,
    511,        512,        513,        1023,       1024,       1025,
    2047,       2048,       2049,       4095,       4096,       4097,
    8191,       8192,       8193,       16383,      16384,      16385,
    32767,      32768,      32769,      65535,      65536,      65537,
    131071,     131072,     131073,     262143,     262144,     262145,
    524287,     524288,     524289,     1048575,    1048576,    1048577,
    2097151,    2097152,    2097153,    4194303,    4194304,    4194305,
    8388607,    8388608,    8388609,    16777215,   16777216,   16777217,
    33554431,   33554432,   33554433,   67108863,   67108864,   67108865,
    134217727,  134217728,  134217729,  268435455,  268435456,  268435457,
    536870911,  536870912,  536870913,  1073741823, 1073741824, 1073741825,
    2147483647, 2147483648, 2147483649, 4294967295};

static int const i32_values[] = {
    -2147483648, -2147483647, -1073741825, -1073741824, -1073741823, -536870913,
    -536870912,  -536870911,  -268435457,  -268435456,  -268435455,  -134217729,
    -134217728,  -134217727,  -67108865,   -67108864,   -67108863,   -33554433,
    -33554432,   -33554431,   -16777217,   -16777216,   -16777215,   -8388609,
    -8388608,    -8388607,    -4194305,    -4194304,    -4194303,    -2097153,
    -2097152,    -2097151,    -1048577,    -1048576,    -1048575,    -524289,
    -524288,     -524287,     -262145,     -262144,     -262143,     -131073,
    -131072,     -131071,     -65537,      -65536,      -65535,      -32769,
    -32768,      -32767,      -16385,      -16384,      -16383,      -8193,
    -8192,       -8191,       -4097,       -4096,       -4095,       -2049,
    -2048,       -2047,       -1025,       -1024,       -1023,       -513,
    -512,        -511,        -257,        -256,        -255,        -129,
    -128,        -127,        -65,         -64,         -63,         -33,
    -32,         -31,         -17,         -16,         -15,         -9,
    -8,          -7,          -5,          -4,          -3,          -2,
    -1,          0,           1,           2,           3,           4,
    5,           7,           8,           9,           15,          16,
    17,          31,          32,          33,          63,          64,
    65,          127,         128,         129,         255,         256,
    257,         511,         512,         513,         1023,        1024,
    1025,        2047,        2048,        2049,        4095,        4096,
    4097,        8191,        8192,        8193,        16383,       16384,
    16385,       32767,       32768,       32769,       65535,       65536,
    65537,       131071,      131072,      131073,      262143,      262144,
    262145,      524287,      524288,      524289,      1048575,     1048576,
    1048577,     2097151,     2097152,     2097153,     4194303,     4194304,
    4194305,     8388607,     8388608,     8388609,     16777215,    16777216,
    16777217,    33554431,    33554432,    33554433,    67108863,    67108864,
    67108865,    134217727,   134217728,   134217729,   268435455,   268435456,
    268435457,   536870911,   536870912,   536870913,   1073741823,  1073741824,
    1073741825,  2147483647,
};

static unsigned long const u64_values[] = {0UL,
                                           63UL,
                                           127UL,
                                           191UL,
                                           255UL,
                                           32895UL,
                                           65535UL,
                                           2147516415UL,
                                           4294967295UL,
                                           9223372039002259456UL,
                                           18446744073709551615UL};

static long const i64_values[] = {-9223372036854775807L,
                                  -4294967295L,
                                  -2147516415L,
                                  -65535L,
                                  -32895L,
                                  -255L,
                                  -191L,
                                  -127L,
                                  -63L,
                                  0L,
                                  63L,
                                  127L,
                                  191L,
                                  255L,
                                  32895L,
                                  65535L,
                                  2147516415L,
                                  4294967295L,
                                  9223372036854775807L};

static int positive_integer_check(unsigned char buffer[9], unsigned long v)
{
  uint8_t u8 = 0;
  uint16_t u16 = 0;
  uint32_t u32 = 0;
  uint64_t u64 = 0;
  int8_t i8 = 0;
  int16_t i16 = 0;
  int32_t i32 = 0;
  int64_t i64 = 0;
  unsigned char uchar = 0;
  unsigned short ushort = 0;
  unsigned int uint = 0;
  unsigned long ulong = 0;
  unsigned long long ullong = 0;
  signed char ichar = 0;
  signed short ishort = 0;
  signed int iint = 0;
  signed long ilong = 0;
  signed long long illong = 0;

  static_assert(UINT8_MAX  == UCHAR_MAX );
  static_assert(UINT16_MAX == USHRT_MAX );
  static_assert(UINT32_MAX == UINT_MAX  );
  static_assert(UINT64_MAX == ULONG_MAX );
  static_assert(UINT64_MAX == ULLONG_MAX);
  static_assert(INT8_MAX   == CHAR_MAX  );
  static_assert(INT16_MAX  == SHRT_MAX  );
  static_assert(INT32_MAX  == INT_MAX   );
  static_assert(INT64_MAX  == LONG_MAX  );
  static_assert(INT64_MAX  == LLONG_MAX );

  if (/*0 <= v &&   */v <= INT8_MAX && (lip_unpack_int(buffer, &u8)     != 1 || v != (unsigned long) u8    )) fail();
  if (/*0 <= v &&   */v <= INT8_MAX && (lip_unpack_int(buffer, &u16)    != 1 || v != (unsigned long) u16   )) fail();
  if (/*0 <= v &&   */v <= INT8_MAX && (lip_unpack_int(buffer, &u32)    != 1 || v != (unsigned long) u32   )) fail();
  if (/*0 <= v &&   */v <= INT8_MAX && (lip_unpack_int(buffer, &u64)    != 1 || v != (unsigned long) u64   )) fail();
  if (/*0 <= v &&   */v <= INT8_MAX && (lip_unpack_int(buffer, &i8)     != 1 || v != (unsigned long) i8    )) fail();
  if (/*0 <= v &&   */v <= INT8_MAX && (lip_unpack_int(buffer, &i16)    != 1 || v != (unsigned long) i16   )) fail();
  if (/*0 <= v &&   */v <= INT8_MAX && (lip_unpack_int(buffer, &i32)    != 1 || v != (unsigned long) i32   )) fail();
  if (/*0 <= v &&   */v <= INT8_MAX && (lip_unpack_int(buffer, &i64)    != 1 || v != (unsigned long) i64   )) fail();
  if (/*0 <= v &&   */v <= INT8_MAX && (lip_unpack_int(buffer, &uchar)  != 1 || v != (unsigned long) uchar )) fail();
  if (/*0 <= v &&   */v <= INT8_MAX && (lip_unpack_int(buffer, &ushort) != 1 || v != (unsigned long) ushort)) fail();
  if (/*0 <= v &&   */v <= INT8_MAX && (lip_unpack_int(buffer, &uint)   != 1 || v != (unsigned long) uint  )) fail();
  if (/*0 <= v &&   */v <= INT8_MAX && (lip_unpack_int(buffer, &ulong)  != 1 || v != (unsigned long) ulong )) fail();
  if (/*0 <= v &&   */v <= INT8_MAX && (lip_unpack_int(buffer, &ullong) != 1 || v != (unsigned long) ullong)) fail();
  if (/*0 <= v &&   */v <= INT8_MAX && (lip_unpack_int(buffer, &ichar)  != 1 || v != (unsigned long) ichar )) fail();
  if (/*0 <= v &&   */v <= INT8_MAX && (lip_unpack_int(buffer, &ishort) != 1 || v != (unsigned long) ishort)) fail();
  if (/*0 <= v &&   */v <= INT8_MAX && (lip_unpack_int(buffer, &iint)   != 1 || v != (unsigned long) iint  )) fail();
  if (/*0 <= v &&   */v <= INT8_MAX && (lip_unpack_int(buffer, &ilong)  != 1 || v != (unsigned long) ilong )) fail();
  if (/*0 <= v &&   */v <= INT8_MAX && (lip_unpack_int(buffer, &illong) != 1 || v != (unsigned long) illong)) fail();

  if (INT8_MAX < v && v <= UINT8_MAX && (lip_unpack_int(buffer, &u8)     != 2 || v != (unsigned long) u8    )) fail();
  if (INT8_MAX < v && v <= UINT8_MAX && (lip_unpack_int(buffer, &u16)    != 2 || v != (unsigned long) u16   )) fail();
  if (INT8_MAX < v && v <= UINT8_MAX && (lip_unpack_int(buffer, &u32)    != 2 || v != (unsigned long) u32   )) fail();
  if (INT8_MAX < v && v <= UINT8_MAX && (lip_unpack_int(buffer, &u64)    != 2 || v != (unsigned long) u64   )) fail();
  if (INT8_MAX < v && v <= UINT8_MAX && (lip_unpack_int(buffer, &i8)     != 0                               )) fail();
  if (INT8_MAX < v && v <= UINT8_MAX && (lip_unpack_int(buffer, &i16)    != 2 || v != (unsigned long) i16   )) fail();
  if (INT8_MAX < v && v <= UINT8_MAX && (lip_unpack_int(buffer, &i32)    != 2 || v != (unsigned long) i32   )) fail();
  if (INT8_MAX < v && v <= UINT8_MAX && (lip_unpack_int(buffer, &i64)    != 2 || v != (unsigned long) i64   )) fail();
  if (INT8_MAX < v && v <= UINT8_MAX && (lip_unpack_int(buffer, &uchar)  != 2 || v != (unsigned long) uchar )) fail();
  if (INT8_MAX < v && v <= UINT8_MAX && (lip_unpack_int(buffer, &ushort) != 2 || v != (unsigned long) ushort)) fail();
  if (INT8_MAX < v && v <= UINT8_MAX && (lip_unpack_int(buffer, &uint)   != 2 || v != (unsigned long) uint  )) fail();
  if (INT8_MAX < v && v <= UINT8_MAX && (lip_unpack_int(buffer, &ulong)  != 2 || v != (unsigned long) ulong )) fail();
  if (INT8_MAX < v && v <= UINT8_MAX && (lip_unpack_int(buffer, &ullong) != 2 || v != (unsigned long) ullong)) fail();
  if (INT8_MAX < v && v <= UINT8_MAX && (lip_unpack_int(buffer, &ichar)  != 0                               )) fail();
  if (INT8_MAX < v && v <= UINT8_MAX && (lip_unpack_int(buffer, &ishort) != 2 || v != (unsigned long) ishort)) fail();
  if (INT8_MAX < v && v <= UINT8_MAX && (lip_unpack_int(buffer, &iint)   != 2 || v != (unsigned long) iint  )) fail();
  if (INT8_MAX < v && v <= UINT8_MAX && (lip_unpack_int(buffer, &ilong)  != 2 || v != (unsigned long) ilong )) fail();
  if (INT8_MAX < v && v <= UINT8_MAX && (lip_unpack_int(buffer, &illong) != 2 || v != (unsigned long) illong)) fail();

  if (UINT8_MAX < v && v <= INT16_MAX && (lip_unpack_int(buffer, &u8)     != 0                               )) fail();
  if (UINT8_MAX < v && v <= INT16_MAX && (lip_unpack_int(buffer, &u16)    != 3 || v != (unsigned long) u16   )) fail();
  if (UINT8_MAX < v && v <= INT16_MAX && (lip_unpack_int(buffer, &u32)    != 3 || v != (unsigned long) u32   )) fail();
  if (UINT8_MAX < v && v <= INT16_MAX && (lip_unpack_int(buffer, &u64)    != 3 || v != (unsigned long) u64   )) fail();
  if (UINT8_MAX < v && v <= INT16_MAX && (lip_unpack_int(buffer, &i8)     != 0                               )) fail();
  if (UINT8_MAX < v && v <= INT16_MAX && (lip_unpack_int(buffer, &i16)    != 3 || v != (unsigned long) i16   )) fail();
  if (UINT8_MAX < v && v <= INT16_MAX && (lip_unpack_int(buffer, &i32)    != 3 || v != (unsigned long) i32   )) fail();
  if (UINT8_MAX < v && v <= INT16_MAX && (lip_unpack_int(buffer, &i64)    != 3 || v != (unsigned long) i64   )) fail();
  if (UINT8_MAX < v && v <= INT16_MAX && (lip_unpack_int(buffer, &uchar)  != 0                               )) fail();
  if (UINT8_MAX < v && v <= INT16_MAX && (lip_unpack_int(buffer, &ushort) != 3 || v != (unsigned long) ushort)) fail();
  if (UINT8_MAX < v && v <= INT16_MAX && (lip_unpack_int(buffer, &uint)   != 3 || v != (unsigned long) uint  )) fail();
  if (UINT8_MAX < v && v <= INT16_MAX && (lip_unpack_int(buffer, &ulong)  != 3 || v != (unsigned long) ulong )) fail();
  if (UINT8_MAX < v && v <= INT16_MAX && (lip_unpack_int(buffer, &ullong) != 3 || v != (unsigned long) ullong)) fail();
  if (UINT8_MAX < v && v <= INT16_MAX && (lip_unpack_int(buffer, &ichar)  != 0                               )) fail();
  if (UINT8_MAX < v && v <= INT16_MAX && (lip_unpack_int(buffer, &ishort) != 3 || v != (unsigned long) ishort)) fail();
  if (UINT8_MAX < v && v <= INT16_MAX && (lip_unpack_int(buffer, &iint)   != 3 || v != (unsigned long) iint  )) fail();
  if (UINT8_MAX < v && v <= INT16_MAX && (lip_unpack_int(buffer, &ilong)  != 3 || v != (unsigned long) ilong )) fail();
  if (UINT8_MAX < v && v <= INT16_MAX && (lip_unpack_int(buffer, &illong) != 3 || v != (unsigned long) illong)) fail();

  if (INT16_MAX < v && v <= UINT16_MAX && (lip_unpack_int(buffer, &u8)     != 0                               )) fail();
  if (INT16_MAX < v && v <= UINT16_MAX && (lip_unpack_int(buffer, &u16)    != 3 || v != (unsigned long) u16   )) fail();
  if (INT16_MAX < v && v <= UINT16_MAX && (lip_unpack_int(buffer, &u32)    != 3 || v != (unsigned long) u32   )) fail();
  if (INT16_MAX < v && v <= UINT16_MAX && (lip_unpack_int(buffer, &u64)    != 3 || v != (unsigned long) u64   )) fail();
  if (INT16_MAX < v && v <= UINT16_MAX && (lip_unpack_int(buffer, &i8)     != 0                               )) fail();
  if (INT16_MAX < v && v <= UINT16_MAX && (lip_unpack_int(buffer, &i16)    != 0                               )) fail();
  if (INT16_MAX < v && v <= UINT16_MAX && (lip_unpack_int(buffer, &i32)    != 3 || v != (unsigned long) i32   )) fail();
  if (INT16_MAX < v && v <= UINT16_MAX && (lip_unpack_int(buffer, &i64)    != 3 || v != (unsigned long) i64   )) fail();
  if (INT16_MAX < v && v <= UINT16_MAX && (lip_unpack_int(buffer, &uchar)  != 0                               )) fail();
  if (INT16_MAX < v && v <= UINT16_MAX && (lip_unpack_int(buffer, &ushort) != 3 || v != (unsigned long) ushort)) fail();
  if (INT16_MAX < v && v <= UINT16_MAX && (lip_unpack_int(buffer, &uint)   != 3 || v != (unsigned long) uint  )) fail();
  if (INT16_MAX < v && v <= UINT16_MAX && (lip_unpack_int(buffer, &ulong)  != 3 || v != (unsigned long) ulong )) fail();
  if (INT16_MAX < v && v <= UINT16_MAX && (lip_unpack_int(buffer, &ullong) != 3 || v != (unsigned long) ullong)) fail();
  if (INT16_MAX < v && v <= UINT16_MAX && (lip_unpack_int(buffer, &ichar)  != 0                               )) fail();
  if (INT16_MAX < v && v <= UINT16_MAX && (lip_unpack_int(buffer, &ishort) != 0                               )) fail();
  if (INT16_MAX < v && v <= UINT16_MAX && (lip_unpack_int(buffer, &iint)   != 3 || v != (unsigned long) iint  )) fail();
  if (INT16_MAX < v && v <= UINT16_MAX && (lip_unpack_int(buffer, &ilong)  != 3 || v != (unsigned long) ilong )) fail();
  if (INT16_MAX < v && v <= UINT16_MAX && (lip_unpack_int(buffer, &illong) != 3 || v != (unsigned long) illong)) fail();

  if (UINT16_MAX < v && v <= INT32_MAX && (lip_unpack_int(buffer, &u8)     != 0                               )) fail();
  if (UINT16_MAX < v && v <= INT32_MAX && (lip_unpack_int(buffer, &u16)    != 0                               )) fail();
  if (UINT16_MAX < v && v <= INT32_MAX && (lip_unpack_int(buffer, &u32)    != 5 || v != (unsigned long) u32   )) fail();
  if (UINT16_MAX < v && v <= INT32_MAX && (lip_unpack_int(buffer, &u64)    != 5 || v != (unsigned long) u64   )) fail();
  if (UINT16_MAX < v && v <= INT32_MAX && (lip_unpack_int(buffer, &i8)     != 0                               )) fail();
  if (UINT16_MAX < v && v <= INT32_MAX && (lip_unpack_int(buffer, &i16)    != 0                               )) fail();
  if (UINT16_MAX < v && v <= INT32_MAX && (lip_unpack_int(buffer, &i32)    != 5 || v != (unsigned long) i32   )) fail();
  if (UINT16_MAX < v && v <= INT32_MAX && (lip_unpack_int(buffer, &i64)    != 5 || v != (unsigned long) i64   )) fail();
  if (UINT16_MAX < v && v <= INT32_MAX && (lip_unpack_int(buffer, &uchar)  != 0                               )) fail();
  if (UINT16_MAX < v && v <= INT32_MAX && (lip_unpack_int(buffer, &ushort) != 0                               )) fail();
  if (UINT16_MAX < v && v <= INT32_MAX && (lip_unpack_int(buffer, &uint)   != 5 || v != (unsigned long) uint  )) fail();
  if (UINT16_MAX < v && v <= INT32_MAX && (lip_unpack_int(buffer, &ulong)  != 5 || v != (unsigned long) ulong )) fail();
  if (UINT16_MAX < v && v <= INT32_MAX && (lip_unpack_int(buffer, &ullong) != 5 || v != (unsigned long) ullong)) fail();
  if (UINT16_MAX < v && v <= INT32_MAX && (lip_unpack_int(buffer, &ichar)  != 0                               )) fail();
  if (UINT16_MAX < v && v <= INT32_MAX && (lip_unpack_int(buffer, &ishort) != 0                               )) fail();
  if (UINT16_MAX < v && v <= INT32_MAX && (lip_unpack_int(buffer, &iint)   != 5 || v != (unsigned long) iint  )) fail();
  if (UINT16_MAX < v && v <= INT32_MAX && (lip_unpack_int(buffer, &ilong)  != 5 || v != (unsigned long) ilong )) fail();
  if (UINT16_MAX < v && v <= INT32_MAX && (lip_unpack_int(buffer, &illong) != 5 || v != (unsigned long) illong)) fail();

  if (INT32_MAX < v && v <= UINT32_MAX && (lip_unpack_int(buffer, &u8)     != 0                               )) fail();
  if (INT32_MAX < v && v <= UINT32_MAX && (lip_unpack_int(buffer, &u16)    != 0                               )) fail();
  if (INT32_MAX < v && v <= UINT32_MAX && (lip_unpack_int(buffer, &u32)    != 5 || v != (unsigned long) u32   )) fail();
  if (INT32_MAX < v && v <= UINT32_MAX && (lip_unpack_int(buffer, &u64)    != 5 || v != (unsigned long) u64   )) fail();
  if (INT32_MAX < v && v <= UINT32_MAX && (lip_unpack_int(buffer, &i8)     != 0                               )) fail();
  if (INT32_MAX < v && v <= UINT32_MAX && (lip_unpack_int(buffer, &i16)    != 0                               )) fail();
  if (INT32_MAX < v && v <= UINT32_MAX && (lip_unpack_int(buffer, &i32)    != 0                               )) fail();
  if (INT32_MAX < v && v <= UINT32_MAX && (lip_unpack_int(buffer, &i64)    != 5 || v != (unsigned long) i64   )) fail();
  if (INT32_MAX < v && v <= UINT32_MAX && (lip_unpack_int(buffer, &uchar)  != 0                               )) fail();
  if (INT32_MAX < v && v <= UINT32_MAX && (lip_unpack_int(buffer, &ushort) != 0                               )) fail();
  if (INT32_MAX < v && v <= UINT32_MAX && (lip_unpack_int(buffer, &uint)   != 5 || v != (unsigned long) uint  )) fail();
  if (INT32_MAX < v && v <= UINT32_MAX && (lip_unpack_int(buffer, &ulong)  != 5 || v != (unsigned long) ulong )) fail();
  if (INT32_MAX < v && v <= UINT32_MAX && (lip_unpack_int(buffer, &ullong) != 5 || v != (unsigned long) ullong)) fail();
  if (INT32_MAX < v && v <= UINT32_MAX && (lip_unpack_int(buffer, &ichar)  != 0                               )) fail();
  if (INT32_MAX < v && v <= UINT32_MAX && (lip_unpack_int(buffer, &ishort) != 0                               )) fail();
  if (INT32_MAX < v && v <= UINT32_MAX && (lip_unpack_int(buffer, &iint)   != 0                               )) fail();
  if (INT32_MAX < v && v <= UINT32_MAX && (lip_unpack_int(buffer, &ilong)  != 5 || v != (unsigned long) ilong )) fail();
  if (INT32_MAX < v && v <= UINT32_MAX && (lip_unpack_int(buffer, &illong) != 5 || v != (unsigned long) illong)) fail();

  if (UINT32_MAX < v && v <= INT64_MAX && (lip_unpack_int(buffer, &u8)     != 0                               )) fail();
  if (UINT32_MAX < v && v <= INT64_MAX && (lip_unpack_int(buffer, &u16)    != 0                               )) fail();
  if (UINT32_MAX < v && v <= INT64_MAX && (lip_unpack_int(buffer, &u32)    != 0                               )) fail();
  if (UINT32_MAX < v && v <= INT64_MAX && (lip_unpack_int(buffer, &u64)    != 9 || v != (unsigned long) u64   )) fail();
  if (UINT32_MAX < v && v <= INT64_MAX && (lip_unpack_int(buffer, &i8)     != 0                               )) fail();
  if (UINT32_MAX < v && v <= INT64_MAX && (lip_unpack_int(buffer, &i16)    != 0                               )) fail();
  if (UINT32_MAX < v && v <= INT64_MAX && (lip_unpack_int(buffer, &i32)    != 0                               )) fail();
  if (UINT32_MAX < v && v <= INT64_MAX && (lip_unpack_int(buffer, &i64)    != 9 || v != (unsigned long) i64   )) fail();
  if (UINT32_MAX < v && v <= INT64_MAX && (lip_unpack_int(buffer, &uchar)  != 0                               )) fail();
  if (UINT32_MAX < v && v <= INT64_MAX && (lip_unpack_int(buffer, &ushort) != 0                               )) fail();
  if (UINT32_MAX < v && v <= INT64_MAX && (lip_unpack_int(buffer, &uint)   != 0                               )) fail();
  if (UINT32_MAX < v && v <= INT64_MAX && (lip_unpack_int(buffer, &ulong)  != 9 || v != (unsigned long) ulong )) fail();
  if (UINT32_MAX < v && v <= INT64_MAX && (lip_unpack_int(buffer, &ullong) != 9 || v != (unsigned long) ullong)) fail();
  if (UINT32_MAX < v && v <= INT64_MAX && (lip_unpack_int(buffer, &ichar)  != 0                               )) fail();
  if (UINT32_MAX < v && v <= INT64_MAX && (lip_unpack_int(buffer, &ishort) != 0                               )) fail();
  if (UINT32_MAX < v && v <= INT64_MAX && (lip_unpack_int(buffer, &iint)   != 0                               )) fail();
  if (UINT32_MAX < v && v <= INT64_MAX && (lip_unpack_int(buffer, &ilong)  != 9 || v != (unsigned long) ilong )) fail();
  if (UINT32_MAX < v && v <= INT64_MAX && (lip_unpack_int(buffer, &illong) != 9 || v != (unsigned long) illong)) fail();

  if (INT64_MAX < v && v <= UINT64_MAX && (lip_unpack_int(buffer, &u8)     != 0                               )) fail();
  if (INT64_MAX < v && v <= UINT64_MAX && (lip_unpack_int(buffer, &u16)    != 0                               )) fail();
  if (INT64_MAX < v && v <= UINT64_MAX && (lip_unpack_int(buffer, &u32)    != 0                               )) fail();
  if (INT64_MAX < v && v <= UINT64_MAX && (lip_unpack_int(buffer, &u64)    != 9 || v != (unsigned long) u64   )) fail();
  if (INT64_MAX < v && v <= UINT64_MAX && (lip_unpack_int(buffer, &i8)     != 0                               )) fail();
  if (INT64_MAX < v && v <= UINT64_MAX && (lip_unpack_int(buffer, &i16)    != 0                               )) fail();
  if (INT64_MAX < v && v <= UINT64_MAX && (lip_unpack_int(buffer, &i32)    != 0                               )) fail();
  if (INT64_MAX < v && v <= UINT64_MAX && (lip_unpack_int(buffer, &i64)    != 0                               )) fail();
  if (INT64_MAX < v && v <= UINT64_MAX && (lip_unpack_int(buffer, &uchar)  != 0                               )) fail();
  if (INT64_MAX < v && v <= UINT64_MAX && (lip_unpack_int(buffer, &ushort) != 0                               )) fail();
  if (INT64_MAX < v && v <= UINT64_MAX && (lip_unpack_int(buffer, &uint)   != 0                               )) fail();
  if (INT64_MAX < v && v <= UINT64_MAX && (lip_unpack_int(buffer, &ulong)  != 9 || v != (unsigned long) ulong )) fail();
  if (INT64_MAX < v && v <= UINT64_MAX && (lip_unpack_int(buffer, &ullong) != 9 || v != (unsigned long) ullong)) fail();
  if (INT64_MAX < v && v <= UINT64_MAX && (lip_unpack_int(buffer, &ichar)  != 0                               )) fail();
  if (INT64_MAX < v && v <= UINT64_MAX && (lip_unpack_int(buffer, &ishort) != 0                               )) fail();
  if (INT64_MAX < v && v <= UINT64_MAX && (lip_unpack_int(buffer, &iint)   != 0                               )) fail();
  if (INT64_MAX < v && v <= UINT64_MAX && (lip_unpack_int(buffer, &ilong)  != 0                               )) fail();
  if (INT64_MAX < v && v <= UINT64_MAX && (lip_unpack_int(buffer, &illong) != 0                               )) fail();


  return 0;
}

static int negative_integer_check(unsigned char buffer[9], long v)
{
  uint8_t u8 = 0;
  uint16_t u16 = 0;
  uint32_t u32 = 0;
  uint64_t u64 = 0;
  int8_t i8 = 0;
  int16_t i16 = 0;
  int32_t i32 = 0;
  int64_t i64 = 0;
  unsigned char uchar = 0;
  unsigned short ushort = 0;
  unsigned int uint = 0;
  unsigned long ulong = 0;
  unsigned long long ullong = 0;
  signed char ichar = 0;
  signed short ishort = 0;
  signed int iint = 0;
  signed long ilong = 0;
  signed long long illong = 0;

  static_assert(INT8_MAX   == CHAR_MAX  );
  static_assert(INT16_MAX  == SHRT_MAX  );
  static_assert(INT32_MAX  == INT_MAX   );
  static_assert(INT64_MAX  == LONG_MAX  );
  static_assert(INT64_MAX  == LLONG_MAX );


  if (-32 <= v && (lip_unpack_int(buffer, &i8)     != 1 || v != i8    )) fail();
  if (-32 <= v && (lip_unpack_int(buffer, &i16)    != 1 || v != i16   )) fail();
  if (-32 <= v && (lip_unpack_int(buffer, &i32)    != 1 || v != i32   )) fail();
  if (-32 <= v && (lip_unpack_int(buffer, &i64)    != 1 || v != i64   )) fail();
  if (-32 <= v && (lip_unpack_int(buffer, &ichar)  != 1 || v != ichar )) fail();
  if (-32 <= v && (lip_unpack_int(buffer, &ishort) != 1 || v != ishort)) fail();
  if (-32 <= v && (lip_unpack_int(buffer, &iint)   != 1 || v != iint  )) fail();
  if (-32 <= v && (lip_unpack_int(buffer, &ilong)  != 1 || v != ilong )) fail();
  if (-32 <= v && (lip_unpack_int(buffer, &illong) != 1 || v != illong)) fail();

  if (INT8_MIN <= v && v < -32 && (lip_unpack_int(buffer, &i8)     != 2 || v != i8    )) fail();
  if (INT8_MIN <= v && v < -32 && (lip_unpack_int(buffer, &i16)    != 2 || v != i16   )) fail();
  if (INT8_MIN <= v && v < -32 && (lip_unpack_int(buffer, &i32)    != 2 || v != i32   )) fail();
  if (INT8_MIN <= v && v < -32 && (lip_unpack_int(buffer, &i64)    != 2 || v != i64   )) fail();
  if (INT8_MIN <= v && v < -32 && (lip_unpack_int(buffer, &ichar)  != 2 || v != ichar )) fail();
  if (INT8_MIN <= v && v < -32 && (lip_unpack_int(buffer, &ishort) != 2 || v != ishort)) fail();
  if (INT8_MIN <= v && v < -32 && (lip_unpack_int(buffer, &iint)   != 2 || v != iint  )) fail();
  if (INT8_MIN <= v && v < -32 && (lip_unpack_int(buffer, &ilong)  != 2 || v != ilong )) fail();
  if (INT8_MIN <= v && v < -32 && (lip_unpack_int(buffer, &illong) != 2 || v != illong)) fail();


  if (INT16_MIN <= v && v < INT8_MIN && (lip_unpack_int(buffer, &i16)    != 3 || v != i16   )) fail();
  if (INT16_MIN <= v && v < INT8_MIN && (lip_unpack_int(buffer, &i32)    != 3 || v != i32   )) fail();
  if (INT16_MIN <= v && v < INT8_MIN && (lip_unpack_int(buffer, &i64)    != 3 || v != i64   )) fail();
  if (INT16_MIN <= v && v < INT8_MIN && (lip_unpack_int(buffer, &ishort) != 3 || v != ishort)) fail();
  if (INT16_MIN <= v && v < INT8_MIN && (lip_unpack_int(buffer, &iint)   != 3 || v != iint  )) fail();
  if (INT16_MIN <= v && v < INT8_MIN && (lip_unpack_int(buffer, &ilong)  != 3 || v != ilong )) fail();
  if (INT16_MIN <= v && v < INT8_MIN && (lip_unpack_int(buffer, &illong) != 3 || v != illong)) fail();

  if (INT32_MIN <= v && v < INT16_MIN && (lip_unpack_int(buffer, &i32)    != 5 || v != i32   )) fail();
  if (INT32_MIN <= v && v < INT16_MIN && (lip_unpack_int(buffer, &i64)    != 5 || v != i64   )) fail();
  if (INT32_MIN <= v && v < INT16_MIN && (lip_unpack_int(buffer, &iint)   != 5 || v != iint  )) fail();
  if (INT32_MIN <= v && v < INT16_MIN && (lip_unpack_int(buffer, &ilong)  != 5 || v != ilong )) fail();
  if (INT32_MIN <= v && v < INT16_MIN && (lip_unpack_int(buffer, &illong) != 5 || v != illong)) fail();

  if (INT64_MIN <= v && v < INT32_MIN && (lip_unpack_int(buffer, &i64)    != 9 || v != i64   )) fail();
  if (INT64_MIN <= v && v < INT32_MIN && (lip_unpack_int(buffer, &ilong)  != 9 || v != ilong )) fail();
  if (INT64_MIN <= v && v < INT32_MIN && (lip_unpack_int(buffer, &illong) != 9 || v != illong)) fail();

  if (lip_unpack_int(buffer, &u8)     != 0) fail();
  if (lip_unpack_int(buffer, &u16)    != 0) fail();
  if (lip_unpack_int(buffer, &u32)    != 0) fail();
  if (lip_unpack_int(buffer, &u64)    != 0) fail();
  if (lip_unpack_int(buffer, &uchar)  != 0) fail();
  if (lip_unpack_int(buffer, &ushort) != 0) fail();
  if (lip_unpack_int(buffer, &uint)   != 0) fail();
  if (lip_unpack_int(buffer, &ulong)  != 0) fail();
  if (lip_unpack_int(buffer, &ullong) != 0) fail();

  return 0;
}

static int test_u64(void)
{
  unsigned char buffer[9] = {0};

  for (unsigned i = 0; i < array_size(u64_values); ++i)
  {
    unsigned long v = u64_values[i];
    memset(buffer, 0, sizeof(buffer));
    lip_pack_int(buffer, v);
    if (positive_integer_check(buffer, v)) fail();
  }

  return 0;
}

static int test_u32(void)
{
  unsigned char buffer[9] = {0};

  for (unsigned i = 0; i < array_size(u32_values); ++i)
  {
    unsigned v = u32_values[i];
    memset(buffer, 0, sizeof(buffer));
    lip_pack_int(buffer, v);
    if (positive_integer_check(buffer, v)) fail();
  }

  return 0;
}

static int test_u16(void)
{
  unsigned char buffer[9] = {0};

  for (unsigned v = 0; v <= UINT16_MAX; ++v)
  {
    memset(buffer, 0, sizeof(buffer));
    lip_pack_int(buffer, v);
    if (positive_integer_check(buffer, v)) fail();
  }

  return 0;
}

static int test_u8(void)
{
  unsigned char buffer[9] = {0};

  for (unsigned v = 0; v <= UINT8_MAX; ++v)
  {
    memset(buffer, 0, sizeof(buffer));
    lip_pack_int(buffer, v);
    if (positive_integer_check(buffer, v)) fail();
  }

  return 0;
}

static int test_i64(void)
{
  unsigned char buffer[9] = {0};

  for (unsigned i = 0; i < array_size(i64_values); ++i)
  {
    long v = i64_values[i];
    memset(buffer, 0, sizeof(buffer));
    lip_pack_int(buffer, v);

    if (v >= 0 && positive_integer_check(buffer, (unsigned long)v)) fail();
    if (v <  0 && negative_integer_check(buffer, v)) fail();
  }

  return 0;
}

static int test_i32(void)
{
  unsigned char buffer[9] = {0};

  for (unsigned i = 0; i < array_size(i32_values); ++i)
  {
    int v = i32_values[i];
    memset(buffer, 0, sizeof(buffer));
    lip_pack_int(buffer, v);

    if (v >= 0 && positive_integer_check(buffer, (unsigned)v)) fail();
    if (v <  0 && negative_integer_check(buffer, v))           fail();
  }

  return 0;
}

static int test_i16(void)
{
  unsigned char buffer[9] = {0};

  for (int v = INT16_MIN; v <= INT16_MAX; ++v)
  {
    memset(buffer, 0, sizeof(buffer));
    lip_pack_int(buffer, v);

    if (v >= 0 && positive_integer_check(buffer, (unsigned)v)) fail();
    if (v <  0 && negative_integer_check(buffer, v))           fail();
  }

  return 0;
}

static int test_i8(void)
{
  unsigned char buffer[9] = {0};

  for (int v = INT8_MIN; v <= INT8_MAX; ++v)
  {
    memset(buffer, 0, sizeof(buffer));
    lip_pack_int(buffer, v);

    if (v >= 0 && positive_integer_check(buffer, (unsigned)v)) fail();
    if (v <  0 && negative_integer_check(buffer, v))           fail();
  }

  return 0;
}

int main(void)
{
  if (test_u64()) return 1;
  if (test_u32()) return 1;
  if (test_u16()) return 1;
  if (test_u8()) return 1;

  if (test_i64()) return 1;
  if (test_i32()) return 1;
  if (test_i16()) return 1;
  if (test_i8()) return 1;
  return 0;
}
