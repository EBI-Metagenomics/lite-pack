#include "lip/unpack_float.h"
#include "lip/format.h"
#include "load_number.h"
#include "number.h"

unsigned lip_unpack_f32(unsigned char const buf[], float *val)
{
    if (lip_format(buf[0]) == LIP_FMT_FLOAT_32)
    {
        *val = __lip_load_num32(buf + 1).f;
        return 5;
    }
    return 0;
}

unsigned lip_unpack_f64(unsigned char const buf[], double *val)
{
    if (lip_format(buf[0]) == LIP_FMT_FLOAT_32)
    {
        *val = __lip_load_num32(buf + 1).f;
        return 5;
    }

    if (lip_format(buf[0]) == LIP_FMT_FLOAT_64)
    {
        *val = __lip_load_num64(buf + 1).f;
        return 9;
    }

    return 0;
}
