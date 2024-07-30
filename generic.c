#include <stdint.h>
#include <stdio.h>

#define pack_int(x)                                                            \
  _Generic((x),                                                                \
      signed char: "signed char       ",                                       \
      signed short: "signed short      ",                                      \
      signed int: "signed int        ",                                        \
      signed long: "signed long       ",                                       \
      signed long long: "signed long long  ",                                  \
      unsigned char: "unsigned char     ",                                     \
      unsigned short: "unsigned short    ",                                    \
      unsigned int: "unsigned int      ",                                      \
      unsigned long: "unsigned long     ",                                     \
      unsigned long long: "unsigned long long")

#define pack_int2(x)                                                           \
  _Generic((x),                                                                \
      char: "char       ",                                                     \
      int8_t: "int8_t       ",                                                 \
      int32_t: "int32_t",                                                      \
      int64_t: "int64_t",                                                      \
      uint8_t: "uint8_t",                                                      \
      uint32_t: "uint32_t",                                                    \
      uint64_t: "uint64_t")

int main(void)
{
  char c = 0;
  int x = 0;
  long y = 0;
  unsigned int z = 0;
  int32_t a = 0;
  int64_t b = 0;
  unsigned long long ull = 0;
  printf("%s\n", pack_int2(x));
  printf("%s\n", pack_int2(a));
  printf("%s\n", pack_int2(b));
  printf("%s\n", pack_int2(c));
  printf("%s\n", pack_int2(ull));
  return 0;
}
