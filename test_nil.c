#include "lite_pack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define fail()                                                                 \
  do                                                                           \
  {                                                                            \
    fprintf(stderr, "\nFailure at %s:%d\n", __FILE__, __LINE__);               \
    exit(1);                                                                   \
  } while (1)

int main(void)
{
  unsigned char buffer[1] = {0};

  memset(buffer, 0, sizeof(buffer));
  if (lip_pack_nil(buffer) != 1) fail();
  if (lip_unpack_nil(buffer) != 1) fail();
  if (lip_size(buffer) != 1) fail();

  memset(buffer, 0, sizeof(buffer));
  if (lip_unpack_nil(buffer) != 0) fail();

  return 0;
}
