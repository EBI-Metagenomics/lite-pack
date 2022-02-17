#include "helper.h"
#include "lite_pack/io/file.h"
#include "lite_pack/lite_pack.h"

static void test_correct_usage()
{
    struct lip_file io = {0};

    io.fp = fopen(TMPDIR "/io_file.mp", "wb");
    lip_write_int(&io, 0);
    lip_write_int(&io, 39290);
    lip_write_array_size(&io, 2);
    lip_write_float(&io, 3.2f);
    lip_write_str_size(&io, 5);
    lip_write_str_data(&io, 5, "hello");
    if (io.error) ERROR;
    fclose(io.fp);

    io.fp = fopen(TMPDIR "/io_file.mp", "rb");
    int ival = 0;
    lip_read_int(&io, &ival);
    if (ival != 0) ERROR;
    lip_read_int(&io, &ival);
    if (ival != 39290) ERROR;
    unsigned uval = 0;
    lip_read_array_size(&io, &uval);
    if (uval != 2) ERROR;
    float fval = 0.f;
    lip_read_float(&io, &fval);
    if (fval != 3.2f) ERROR;
    lip_read_str_size(&io, &uval);
    if (uval != 5) ERROR;
    char hello[6] = {0};
    lip_read_str_data(&io, 5, hello);
    if (strncmp(hello, "hello", 5) != 0) ERROR;
    if (io.error) ERROR;
    fclose(io.fp);
}

static void test_incorrect_usage()
{
    struct lip_file io = {0};

    io.fp = fopen(TMPDIR "/io_file.mp", "wb");
    lip_write_int(&io, INT64_MAX);
    if (io.error) ERROR;
    fclose(io.fp);

    io.fp = fopen(TMPDIR "/io_file.mp", "rb");
    uint16_t x = 0;
    lip_read_int(&io, &x);
    if (!io.error) ERROR;
    fclose(io.fp);
}

int main(void)
{
    test_correct_usage();
    test_incorrect_usage();
    return 0;
}
