#include "lip/store_float.h"
#include "store_number.h"

unsigned lip_store_f32(unsigned char buf[], float val)
{
    return __lip_store_num32(buf, __LIP_NUM32(val));
}

unsigned lip_store_f32_in(unsigned char buf[])
{
    return __lip_store_num32(buf, __LIP_NUM32(buf));
}

unsigned lip_store_f64(unsigned char buf[], double val)
{
    return __lip_store_num64(buf, __LIP_NUM64(val));
}

unsigned lip_store_f64_in(unsigned char buf[])
{
    return __lip_store_num64(buf, __LIP_NUM64(buf));
}
