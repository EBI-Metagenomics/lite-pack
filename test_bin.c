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

static char *lorem_new(unsigned long length)
{
  static char const paragraph[] =
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod "
      "tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim "
      "veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea "
      "commodo consequat. Duis aute irure dolor in reprehenderit in voluptate "
      "velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint "
      "occaecat cupidatat non proident, sunt in culpa qui officia deserunt "
      "mollit anim id est laborum.";

  char *lorem = malloc(length + 1);
  if (!lorem) exit(1);

  for (unsigned long i = 0; i < length; ++i)
    lorem[i] = paragraph[i % (sizeof(paragraph) - 1)];

  lorem[length] = 0;

  return lorem;
}

int main(void)
{
  unsigned sizes[] = {0, 0x1F, 0x20, 0xFF, 0x100, 0xFFFF, 0x10000U};

  unsigned pack_sizes[] = {
      2, 2, 2, 2, 3, 3, 5,
  };

  unsigned long buffer_size = 0x10000UL + 6UL;
  unsigned long output_size = 0x10000UL + 1UL;
  unsigned char *buffer = malloc(buffer_size);
  if (!buffer) exit(1);

  char *output = malloc(output_size);
  if (!output) exit(1);

  char const *bin = 0;

  for (unsigned i = 0; i < array_size(sizes); ++i)
  {
    memset(buffer, 0, buffer_size);

    bin = lorem_new(sizes[i]);
    unsigned length = (unsigned)strlen(bin);
    if (lip_pack_bin_size(buffer, length) != pack_sizes[i]) fail();
    if (lip_pack_bin_data(buffer + pack_sizes[i], length, bin) != sizes[i]) fail();

    if (lip_unpack_bin_size(buffer, &length) != pack_sizes[i]) fail();
    if (length != sizes[i]) fail();
    if (lip_unpack_bin_data(buffer + pack_sizes[i], length, output) != sizes[i]) fail();
    if (memcmp(output, bin, length) != 0) fail();

    free((char *)bin);
  }

  free(buffer);
  free(output);
  return 0;
}
