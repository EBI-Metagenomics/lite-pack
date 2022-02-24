#include "helper.h"
#include "lite_pack/lite_pack.h"
#include <float.h>
#include <math.h>

static float const f32_values[] = {-1.2f,       -0.0f,    +0.0f,
                                   1.2f,        FLT_MAX,  FLT_MIN,
                                   FLT_EPSILON, INFINITY, -INFINITY};

static double const f64_values[] = {
    -1.2, -0.0, +0.0, 1.2, DBL_MAX, DBL_MIN, DBL_EPSILON, INFINITY, -INFINITY};

static unsigned char buf[9] = {0};

static int test_f32(void)
{
    for (unsigned i = 0; i < array_size(f32_values); ++i)
    {
        clear(buf);
        if (lip_pack_float(buf, f32_values[i]) != 5) ERROR;
        if (lip_format(buf[0]) != LIP_FMT_FLOAT_32) ERROR;

        float v = 0;
        if (lip_unpack_float(buf, &v) != 5) ERROR;
        if (v != f32_values[i]) ERROR;
    }

    return 0;
}

static int test_f64(void)
{
    for (unsigned i = 0; i < array_size(f64_values); ++i)
    {
        clear(buf);
        if (lip_pack_float(buf, f64_values[i]) != 9) ERROR;
        if (lip_format(buf[0]) != LIP_FMT_FLOAT_64) ERROR;

        double v = 0;
        if (lip_unpack_float(buf, &v) != 9) ERROR;
        if (v != f64_values[i]) ERROR;
    }

    return 0;
}

int main(void) { return test_f32() | test_f64(); }
