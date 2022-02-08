#include "helper.h"
#include "lite_pack.h"

int main(void)
{
    uint8_t buf[1] = {0};
    bool v = 0;

    clear(buf);
    lip_pack_bool(buf, false);
    if (lip_format(buf) != LIP_FMT_FALSE) ERROR;
    if (lip_unpack_bool(buf, &v) != 1) ERROR;
    if (v != false) ERROR;

    clear(buf);
    __lip_pack_false(buf);
    if (lip_format(buf) != LIP_FMT_FALSE) ERROR;
    if (lip_unpack_bool(buf, &v) != 1) ERROR;
    if (v != false) ERROR;

    clear(buf);
    lip_pack_bool(buf, true);
    if (lip_format(buf) != LIP_FMT_TRUE) ERROR;
    if (lip_unpack_bool(buf, &v) != 1) ERROR;
    if (v != true) ERROR;

    clear(buf);
    __lip_pack_true(buf);
    if (lip_format(buf) != LIP_FMT_TRUE) ERROR;
    if (lip_unpack_bool(buf, &v) != 1) ERROR;
    if (v != true) ERROR;

    return 0;
}
