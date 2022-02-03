#include "load.h"

float __lip_load_f32_data(uint8_t const buf[static 4])
{
    union
    {
        float f;
        uint32_t u;
    } v;
    v.u = host_endian(*((uint32_t *)buf));
    return v.f;
}

double __lip_load_f64_data(uint8_t const buf[static 8])
{
    union
    {
        double f;
        uint64_t u;
    } v;
    v.u = host_endian(*((uint64_t *)buf));
    return v.f;
}
