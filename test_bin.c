#include "lite_pack.h"
#include <stddef.h>
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
  unsigned char buffer[9] = {0};
  unsigned size = 0;
  unsigned sizes[] = {0, 0x1F, 0x20, 0xFF, 0x100, 0xFFFF, 0x10000U};
  unsigned pack_sizes[] = {
      2, 2, 2, 2, 3, 3, 5,
  };

  for (unsigned i = 0; i < array_size(sizes); ++i)
  {
    memset(buffer, 0, array_size(buffer));
    if (lip_pack_bin(buffer, sizes[i]) != pack_sizes[i]) fail();
    if (lip_unpack_bin(buffer, &size) != pack_sizes[i]) fail();
    if (lip_size(buffer) != pack_sizes[i]) fail();
    if (size != sizes[i]) fail();
  }

  return 0;
}
