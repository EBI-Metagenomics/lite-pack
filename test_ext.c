#include "lite_pack.h"
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

int main(void)
{
  struct
  {
    unsigned size;
    unsigned pack_size;
  } a[] = {

      {0, 3}, {1, 2},  {2, 2},  {3, 3},     {4, 2},     {5, 3},
      {8, 2}, {15, 3}, {16, 2}, {65535, 4}, {65536, 6}, {4294967295, 6}};

  unsigned char buffer[9] = {0};
  uint8_t type = 0;
  unsigned size = 0;
  for (unsigned i = 0; i < array_size(a); ++i)
  {
    memset(buffer, 0, array_size(buffer));
    if (lip_pack_ext(buffer, a[i].size, 33) != a[i].pack_size) fail();
    if (lip_unpack_ext(buffer, &size, &type) != a[i].pack_size) fail();
    if (lip_size(buffer) != a[i].pack_size) fail();
    if (type != 33) fail();
    if (size != a[i].size) fail();
  }

  return 0;
}
