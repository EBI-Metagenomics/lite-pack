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
  unsigned char buffer[17] = {0};
  unsigned size = 0;
  unsigned sizes[] = {
      0, 15, 16, 65535, 65536, 4294967295,
  };
  unsigned pack_sizes[] = {1, 1, 3, 3, 5, 5};

  for (unsigned i = 0; i < array_size(sizes); ++i)
  {
    memset(buffer, 0, array_size(buffer));
    if (lip_pack_map_size(buffer, sizes[i]) != pack_sizes[i]) fail();
    if (lip_unpack_map_size(buffer, &size) != pack_sizes[i]) fail();
    if (size != sizes[i]) fail();
  }

  return 0;
}
