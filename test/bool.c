#include "helper.h"
#include "lite_pack.h"

int main(void)
{
    uint8_t buf[1] = {0};

    clear(buf);
    lip_pack_bool(buf, false);
    if (lip_format(buf) != LIP_FMT_FALSE) ERROR;
    if (lip_unpack_bool(buf) != false) ERROR;

    clear(buf);
    lip_pack_false(buf);
    if (lip_format(buf) != LIP_FMT_FALSE) ERROR;
    if (lip_unpack_bool(buf) != false) ERROR;

    clear(buf);
    lip_pack_bool(buf, true);
    if (lip_format(buf) != LIP_FMT_TRUE) ERROR;
    if (lip_unpack_bool(buf) != true) ERROR;

    clear(buf);
    lip_pack_true(buf);
    if (lip_format(buf) != LIP_FMT_TRUE) ERROR;
    if (lip_unpack_bool(buf) != true) ERROR;

    return 0;
}
