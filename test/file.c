#include "lite_pack/file/file.h"
#include "helper.h"
#include "lite_pack/lite_pack.h"

static void test_correct_usage()
{
    struct lip_file file = {0};

    file.fp = fopen(TMPDIR "/file.mp", "wb");
    lip_write_int(&file, 0);
    lip_write_int(&file, 39290);
    lip_write_array_size(&file, 2);
    lip_write_float(&file, 3.2f);
    lip_write_str_size(&file, 5);
    lip_write_str_data(&file, 5, "hello");
    if (file.error) ERROR;
    fclose(file.fp);

    file.fp = fopen(TMPDIR "/file.mp", "rb");
    int ival = 0;
    lip_read_int(&file, &ival);
    if (ival != 0) ERROR;
    lip_read_int(&file, &ival);
    if (ival != 39290) ERROR;
    unsigned uval = 0;
    lip_read_array_size(&file, &uval);
    if (uval != 2) ERROR;
    float fval = 0.f;
    lip_read_float(&file, &fval);
    if (fval != 3.2f) ERROR;
    lip_read_str_size(&file, &uval);
    if (uval != 5) ERROR;
    char hello[6] = {0};
    lip_read_str_data(&file, 5, hello);
    if (strncmp(hello, "hello", 5) != 0) ERROR;
    if (file.error) ERROR;
    fclose(file.fp);
}

static void test_incorrect_usage()
{
    struct lip_file file = {0};

    file.fp = fopen(TMPDIR "/file.mp", "wb");
    lip_write_int(&file, INT64_MAX);
    if (file.error) ERROR;
    fclose(file.fp);

    file.fp = fopen(TMPDIR "/file.mp", "rb");
    uint16_t x = 0;
    lip_read_int(&file, &x);
    if (!file.error) ERROR;
    fclose(file.fp);
}

int main(void)
{
    test_correct_usage();
    test_incorrect_usage();
    return 0;
}
