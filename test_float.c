#include "lite_pack.h"
#include <float.h>
#include <math.h>
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

static int test_f32(void)
{
  unsigned char buffer[9] = {0};
  float v = 0;
  float values[] = {-1.2f,   -0.0f,       +0.0f,    1.2f,     FLT_MAX,
                    FLT_MIN, FLT_EPSILON, INFINITY, -INFINITY};

  for (unsigned i = 0; i < array_size(values); ++i)
  {
    memset(buffer, 0, sizeof(buffer));
    if (lip_pack_float(buffer, values[i]) != 5) fail();
    if (lip_unpack_float(buffer, &v) != 5) fail();
    if (v != values[i]) fail();
  }

  return 0;
}

static int test_f64(void)
{
  unsigned char buffer[9] = {0};
  double v = 0;
  double values[] = {-1.2,
                     -0.0,
                     +0.0,
                     1.2,
                     DBL_MAX,
                     DBL_MIN,
                     DBL_EPSILON,
                     (double)INFINITY,
                     (double)-INFINITY};

  for (unsigned i = 0; i < array_size(values); ++i)
  {
    memset(buffer, 0, sizeof(buffer));
    if (lip_pack_float(buffer, values[i]) != 9) fail();
    if (lip_unpack_float(buffer, &v) != 9) fail();
    if (v != values[i]) fail();
  }

  return 0;
}

int main(void) { return test_f32() | test_f64(); }
