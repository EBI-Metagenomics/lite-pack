#include "unpack.h"

float unpack_f32(uint8_t buf[static 1])
{
    union
    {
        float f;
        uint32_t u;
    } v;
    v.u = big_to_host_endian(*((uint32_t *)buf));
    return v.f;
}

double unpack_f64(uint8_t buf[static 1])
{
    union
    {
        double f;
        uint64_t u;
    } v;
    v.u = big_to_host_endian(*((uint64_t *)buf));
    return v.f;
}
