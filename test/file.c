#include "helper.h"
#include "lite_pack/lite_pack.h"

static void test_correct_usage()
{
    struct lip_file file = {0};

    lip_file_init(&file, fopen(TMPDIR "/file.mp", "wb"));
    if (!lip_write_int(&file, 0)) ERROR;
    if (!lip_write_int(&file, 39290)) ERROR;
    if (!lip_write_array_size(&file, 2)) ERROR;
    if (!lip_write_float(&file, 3.2f)) ERROR;
    if (!lip_write_str_size(&file, 5)) ERROR;
    if (!lip_write_str_data(&file, 5, "hello")) ERROR;
    if (!lip_write_str_size(&file, 0)) ERROR;
    if (!lip_write_str_data(&file, 0, "")) ERROR;
    if (file.error) ERROR;
    fclose(lip_file_ptr(&file));

    lip_file_init(&file, fopen(TMPDIR "/file.mp", "rb"));
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
    fclose(lip_file_ptr(&file));
}

static void test_incorrect_usage()
{
    struct lip_file file = {0};

    lip_file_init(&file, fopen(TMPDIR "/file.mp", "wb"));
    if (!lip_write_int(&file, INT64_MAX)) ERROR;
    if (file.error) ERROR;
    fclose(lip_file_ptr(&file));

    lip_file_init(&file, fopen(TMPDIR "/file.mp", "rb"));
    uint16_t x = 0;
    if (lip_read_int(&file, &x)) ERROR;
    if (!file.error) ERROR;
    fclose(lip_file_ptr(&file));
}

static void test_warnings()
{
    struct lip_file file = {0};
    lip_file_init(&file, fopen(TMPDIR "/file_warn.mp", "wb"));
    lip_write_int(&file, 0);
    if (file.error) ERROR;
    fclose(lip_file_ptr(&file));
}

static void test_object()
{
    struct lip_file f1 = {0};
    struct lip_file f2 = {0};
    struct lip_object obj = {0};

    lip_file_init(&f1, fopen(TMPDIR "/file_obj1.mp", "wb"));
    if (!lip_write_int(&f1, 0)) ERROR;
    if (!lip_write_int(&f1, 39290)) ERROR;
    if (!lip_write_array_size(&f1, 2)) ERROR;
    if (!lip_write_float(&f1, 3.2f)) ERROR;
    if (!lip_write_str_size(&f1, 5)) ERROR;
    if (!lip_write_str_data(&f1, 5, "hello")) ERROR;
    if (!lip_write_str_size(&f1, 0)) ERROR;
    if (!lip_write_str_data(&f1, 0, "")) ERROR;
    if (f1.error) ERROR;
    fclose(lip_file_ptr(&f1));

    lip_object_init(&obj);
    lip_file_init(&f1, fopen(TMPDIR "/file_obj1.mp", "rb"));
    lip_file_init(&f2, fopen(TMPDIR "/file_obj2.mp", "wb"));
    if (!lip_read_object(&f1, &obj)) ERROR;
    if (obj.family != LIP_FMT_FAMILY_INT) ERROR;
    if (obj.format != LIP_FMT_POSITIVE_FIXINT) ERROR;
    if (obj.value.u8 != 0) ERROR;
    if (!lip_write_object(&f2, &obj)) ERROR;

    if (!lip_read_object(&f1, &obj)) ERROR;
    if (obj.family != LIP_FMT_FAMILY_INT) ERROR;
    if (obj.format != LIP_FMT_UINT_16) ERROR;
    if (obj.value.u16 != 39290) ERROR;
    if (!lip_write_object(&f2, &obj)) ERROR;

    if (!lip_read_object(&f1, &obj)) ERROR;
    if (obj.family != LIP_FMT_FAMILY_ARRAY) ERROR;
    if (obj.format != LIP_FMT_FIXARRAY) ERROR;
    if (obj.value.size != 2) ERROR;
    if (!lip_write_object(&f2, &obj)) ERROR;

    if (!lip_read_object(&f1, &obj)) ERROR;
    if (obj.family != LIP_FMT_FAMILY_FLOAT) ERROR;
    if (obj.format != LIP_FMT_FLOAT_32) ERROR;
    if (obj.value.f32 != 3.2f) ERROR;
    if (!lip_write_object(&f2, &obj)) ERROR;

    if (!lip_read_object(&f1, &obj)) ERROR;
    if (obj.family != LIP_FMT_FAMILY_STR) ERROR;
    if (obj.format != LIP_FMT_FIXSTR) ERROR;
    if (obj.value.size != 5) ERROR;
    if (!lip_write_object(&f2, &obj)) ERROR;
    char hello[6] = {0};
    if (!lip_read_str_data(&f1, 5, hello)) ERROR;
    if (strncmp(hello, "hello", 5) != 0) ERROR;
    if (!lip_write_str_data(&f2, 5, hello)) ERROR;

    if (!lip_read_object(&f1, &obj)) ERROR;
    if (obj.family != LIP_FMT_FAMILY_STR) ERROR;
    if (obj.format != LIP_FMT_FIXSTR) ERROR;
    if (obj.value.size != 0) ERROR;
    if (!lip_write_object(&f2, &obj)) ERROR;
    char empty[1] = {0};
    if (!lip_read_str_data(&f1, 0, empty)) ERROR;
    if (strncmp(empty, "", 0) != 0) ERROR;
    if (!lip_write_str_data(&f2, 0, empty)) ERROR;

    if (f1.error) ERROR;
    if (f2.error) ERROR;
    fclose(lip_file_ptr(&f2));
    fclose(lip_file_ptr(&f1));

    lip_object_init(&obj);
    lip_file_init(&f1, fopen(TMPDIR "/file_obj2.mp", "rb"));

    if (!lip_read_object(&f1, &obj)) ERROR;
    if (obj.family != LIP_FMT_FAMILY_INT) ERROR;
    if (obj.format != LIP_FMT_POSITIVE_FIXINT) ERROR;
    if (obj.value.u8 != 0) ERROR;

    if (!lip_read_object(&f1, &obj)) ERROR;
    if (obj.family != LIP_FMT_FAMILY_INT) ERROR;
    if (obj.format != LIP_FMT_UINT_16) ERROR;
    if (obj.value.u16 != 39290) ERROR;

    if (!lip_read_object(&f1, &obj)) ERROR;
    if (obj.family != LIP_FMT_FAMILY_ARRAY) ERROR;
    if (obj.format != LIP_FMT_FIXARRAY) ERROR;
    if (obj.value.size != 2) ERROR;

    if (!lip_read_object(&f1, &obj)) ERROR;
    if (obj.family != LIP_FMT_FAMILY_FLOAT) ERROR;
    if (obj.format != LIP_FMT_FLOAT_32) ERROR;
    if (obj.value.f32 != 3.2f) ERROR;

    if (!lip_read_object(&f1, &obj)) ERROR;
    if (obj.family != LIP_FMT_FAMILY_STR) ERROR;
    if (obj.format != LIP_FMT_FIXSTR) ERROR;
    if (obj.value.size != 5) ERROR;
    hello[0] = 0;
    if (!lip_read_str_data(&f1, 5, hello)) ERROR;
    if (strncmp(hello, "hello", 5) != 0) ERROR;

    if (!lip_read_object(&f1, &obj)) ERROR;
    if (obj.family != LIP_FMT_FAMILY_STR) ERROR;
    if (obj.format != LIP_FMT_FIXSTR) ERROR;
    if (obj.value.size != 0) ERROR;
    empty[0] = 0;
    if (!lip_read_str_data(&f1, 0, empty)) ERROR;
    if (strncmp(empty, "", 0) != 0) ERROR;

    if (f1.error) ERROR;
    if (f2.error) ERROR;
    fclose(lip_file_ptr(&f2));
}

int main(void)
{
    test_correct_usage();
    test_incorrect_usage();
    test_warnings();
    test_object();
    return 0;
}
