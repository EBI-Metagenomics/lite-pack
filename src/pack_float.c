#include "lite_pack/pack_float.h"
#include "first_byte.h"
#include "lite_pack/store_float.h"

unsigned lip_pack_f32(unsigned char buf[], float val)
{
    buf[0] = __lip_first_byte(LIP_FMT_FLOAT_32);
    return 1 + lip_store_f32(buf + 1, val);
}

unsigned lip_pack_f64(unsigned char buf[], double val)
{
    buf[0] = __lip_first_byte(LIP_FMT_FLOAT_64);
    return 1 + lip_store_f64(buf + 1, val);
}
