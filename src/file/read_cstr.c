#include "lite_pack/file/read_cstr.h"
#include "lite_pack/file/file.h"
#include "lite_pack/file/read_str.h"

/**
 * lip_read_cstr(): Read a null-terminated string.
 * @file: Stream.
 * @size: Size of @str.
 * @str: Destination of the c-string.
 *
 * @str must be of size 1 or larger. Size of @str must be sufficient
 * to hold the null byte. On success, @size will be equal to
 * `strlen(str)+1`.
 *
 * Return:
 * * true       - Success.
 * * false      - Failure.
 */
bool lip_read_cstr(struct lip_file *file, unsigned size, char str[])
{
    if (file->error) return false;

    str[0] = 0;
    unsigned sz = 0;
    if (!lip_read_str_size(file, &sz)) return false;

    if (sz > size) return !(file->error = true);
    lip_read_str_data(file, sz, str);
    str[sz] = 0;
    return !file->error;
}
