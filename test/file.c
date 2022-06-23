#include "helper.h"
#include "lite_pack/lite_pack.h"

static void test_correct_usage()
{
    struct lip_file file = {0};

    file.fp = fopen(TMPDIR "/file.mp", "wb");
    if (!lip_write_int(&file, 0)) ERROR;
    if (!lip_write_int(&file, 39290)) ERROR;
    if (!lip_write_array_size(&file, 2)) ERROR;
    if (!lip_write_float(&file, 3.2f)) ERROR;
    if (!lip_write_str_size(&file, 5)) ERROR;
    if (!lip_write_str_data(&file, 5, "hello")) ERROR;
    if (!lip_write_str_size(&file, 0)) ERROR;
    if (!lip_write_str_data(&file, 0, "")) ERROR;
    if (file.error) ERROR;
    fclose(file.fp);

    file.fp = fopen(TMPDIR "/file.mp", "rb");
    int ival = 0;
    if (!lip_read_int(&file, &ival)) ERROR;
    if (ival != 0) ERROR;
    if (!lip_read_int(&file, &ival)) ERROR;
    if (ival != 39290) ERROR;
    unsigned uval = 0;
    if (!lip_read_array_size(&file, &uval)) ERROR;
    if (uval != 2) ERROR;
    float fval = 0.f;
    if (!lip_read_float(&file, &fval)) ERROR;
    if (fval != 3.2f) ERROR;
    if (!lip_read_str_size(&file, &uval)) ERROR;
    if (uval != 5) ERROR;
    char hello[6] = {0};
    if (!lip_read_str_data(&file, 5, hello)) ERROR;
    if (strncmp(hello, "hello", 5) != 0) ERROR;
    char empty[1] = {0};
    if (!lip_read_str_data(&file, 0, hello)) ERROR;
    if (strncmp(empty, "", 0) != 0) ERROR;
    if (file.error) ERROR;
    fclose(file.fp);
}

static void test_incorrect_usage()
{
    struct lip_file file = {0};

    file.fp = fopen(TMPDIR "/file.mp", "wb");
    if (!lip_write_int(&file, INT64_MAX)) ERROR;
    if (file.error) ERROR;
    fclose(file.fp);

    file.fp = fopen(TMPDIR "/file.mp", "rb");
    uint16_t x = 0;
    if (lip_read_int(&file, &x)) ERROR;
    if (!file.error) ERROR;
    fclose(file.fp);
}

static void test_warnings()
{
    struct lip_file file = {0};

    file.fp = fopen(TMPDIR "/file2.mp", "wb");
    lip_write_int(&file, 0);
    if (file.error) ERROR;
    fclose(file.fp);
}

int main(void)
{
    test_correct_usage();
    test_incorrect_usage();
    test_warnings();
    return 0;
}
