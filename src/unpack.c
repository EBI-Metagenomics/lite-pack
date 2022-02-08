#include "unpack.h"
#include "lite_pack.h"
#include "load.h"
#include "load_body.h"

unsigned __lip_unpack_u8(uint8_t const buf[static 1], uint8_t *val)
{
    switch (lip_format(buf))
    {
    case LIP_FMT_POSITIVE_FIXINT:
    case LIP_FMT_NEGATIVE_FIXINT:
        return __lip_load_num8_body(buf, (union num8 *)val);
    case LIP_FMT_UINT_8:
    case LIP_FMT_INT_8:
        return 1 + __lip_load_num8_body(buf + 1, (union num8 *)val);
    }
    return 0;
}

unsigned __lip_unpack_u16(uint8_t const buf[static 1], uint16_t *val)
{
    switch (lip_format(buf))
    {
    case LIP_FMT_POSITIVE_FIXINT:
    case LIP_FMT_NEGATIVE_FIXINT:
        return __lip_load_num8_body(buf, (union num8 *)val);
    case LIP_FMT_UINT_8:
    case LIP_FMT_INT_8:
        return 1 + __lip_load_num8_body(buf + 1, (union num8 *)val);
    case LIP_FMT_UINT_16:
    case LIP_FMT_INT_16:
        return 1 + __lip_load_num16_body(buf + 1, (union num16 *)val);
    }
    return 0;
}

unsigned __lip_unpack_u32(uint8_t const buf[static 1], uint32_t *val)
{
    switch (lip_format(buf))
    {
    case LIP_FMT_POSITIVE_FIXINT:
    case LIP_FMT_NEGATIVE_FIXINT:
        return __lip_load_num8_body(buf, (union num8 *)val);
    case LIP_FMT_UINT_8:
    case LIP_FMT_INT_8:
        return 1 + __lip_load_num8_body(buf + 1, (union num8 *)val);
    case LIP_FMT_UINT_16:
    case LIP_FMT_INT_16:
        return 1 + __lip_load_num16_body(buf + 1, (union num16 *)val);
    case LIP_FMT_UINT_32:
    case LIP_FMT_INT_32:
        return 1 + __lip_load_num32_body(buf + 1, (union num32 *)val);
    }
    return 0;
}

unsigned __lip_unpack_u64(uint8_t const buf[static 1], uint64_t *val)
{
    switch (lip_format(buf))
    {
    case LIP_FMT_POSITIVE_FIXINT:
    case LIP_FMT_NEGATIVE_FIXINT:
        return __lip_load_num8_body(buf, (union num8 *)val);
    case LIP_FMT_UINT_8:
    case LIP_FMT_INT_8:
        return 1 + __lip_load_num8_body(buf + 1, (union num8 *)val);
    case LIP_FMT_UINT_16:
    case LIP_FMT_INT_16:
        return 1 + __lip_load_num16_body(buf + 1, (union num16 *)val);
    case LIP_FMT_UINT_32:
    case LIP_FMT_INT_32:
        return 1 + __lip_load_num32_body(buf + 1, (union num32 *)val);
    case LIP_FMT_UINT_64:
    case LIP_FMT_INT_64:
        return 1 + __lip_load_num64_body(buf + 1, (union num64 *)val);
    }
    return 0;
}

unsigned __lip_unpack_i8(uint8_t const buf[static 1], int8_t *val)
{
    switch (lip_format(buf))
    {
    case LIP_FMT_POSITIVE_FIXINT:
    case LIP_FMT_NEGATIVE_FIXINT:
        return __lip_load_num8_body(buf, (union num8 *)val);
    case LIP_FMT_UINT_8:
    case LIP_FMT_INT_8:
        return 1 + __lip_load_num8_body(buf + 1, (union num8 *)val);
    }
    return 0;
}

unsigned __lip_unpack_i16(uint8_t const buf[static 1], int16_t *val)
{
    switch (lip_format(buf))
    {
    case LIP_FMT_POSITIVE_FIXINT:
    case LIP_FMT_NEGATIVE_FIXINT:
        return __lip_load_num8_body(buf, (union num8 *)val);
    case LIP_FMT_UINT_8:
    case LIP_FMT_INT_8:
        return 1 + __lip_load_num8_body(buf + 1, (union num8 *)val);
    case LIP_FMT_UINT_16:
    case LIP_FMT_INT_16:
        return 1 + __lip_load_num16_body(buf + 1, (union num16 *)val);
    }
    return 0;
}

unsigned __lip_unpack_i32(uint8_t const buf[static 1], int32_t *val)
{
    switch (lip_format(buf))
    {
    case LIP_FMT_POSITIVE_FIXINT:
    case LIP_FMT_NEGATIVE_FIXINT:
        return __lip_load_num8_body(buf, (union num8 *)val);
    case LIP_FMT_UINT_8:
    case LIP_FMT_INT_8:
        return 1 + __lip_load_num8_body(buf + 1, (union num8 *)val);
    case LIP_FMT_UINT_16:
    case LIP_FMT_INT_16:
        return 1 + __lip_load_num16_body(buf + 1, (union num16 *)val);
    case LIP_FMT_UINT_32:
    case LIP_FMT_INT_32:
        return 1 + __lip_load_num32_body(buf + 1, (union num32 *)val);
    }
    return 0;
}

unsigned __lip_unpack_i64(uint8_t const buf[static 1], int64_t *val)
{
    switch (lip_format(buf))
    {
    case LIP_FMT_POSITIVE_FIXINT:
    case LIP_FMT_NEGATIVE_FIXINT:
        return __lip_load_num8_body(buf, (union num8 *)val);
    case LIP_FMT_UINT_8:
    case LIP_FMT_INT_8:
        return 1 + __lip_load_num8_body(buf + 1, (union num8 *)val);
    case LIP_FMT_UINT_16:
    case LIP_FMT_INT_16:
        return 1 + __lip_load_num16_body(buf + 1, (union num16 *)val);
    case LIP_FMT_UINT_32:
    case LIP_FMT_INT_32:
        return 1 + __lip_load_num32_body(buf + 1, (union num32 *)val);
    case LIP_FMT_UINT_64:
    case LIP_FMT_INT_64:
        return 1 + __lip_load_num64_body(buf + 1, (union num64 *)val);
    }
    return 0;
}

unsigned __lip_unpack_f32(uint8_t const buf[static 5], float *val)
{
    if (lip_format(buf) == LIP_FMT_FLOAT_32)
        return 1 + __lip_load_num32_body(buf + 1, (union num32 *)val);
    return 0;
}

unsigned __lip_unpack_f64(uint8_t const buf[static 5], double *val)
{
    if (lip_format(buf) == LIP_FMT_FLOAT_64)
        return 1 + __lip_load_num64_body(buf + 1, (union num64 *)val);

    if (lip_format(buf) == LIP_FMT_FLOAT_32)
        return 1 + __lip_load_num32_body(buf + 1, (union num32 *)val);

    return 0;
}

#if 0
char *lip_unpack_str(uint8_t const buf[static 1], char str[static 1])
{
    switch (lip_format(buf))
    {
    case LIP_FMT_FIXSTR:
        return __lip_load_fix_str(buf, str);
    case LIP_FMT_STR_8:
        return __lip_load_str8(buf, str);
    case LIP_FMT_STR_16:
        return __lip_load_str16(buf, str);
    case LIP_FMT_STR_32:
        return __lip_load_str32(buf, str);
    }
    return 0;
}
#endif

unsigned lip_unpack_str_size(uint8_t const buf[static 1], unsigned *size)
{
    switch (lip_format(buf))
    {
    case LIP_FMT_FIXSTR:
        *size = __lip_format_fix_pvalue(NUM8(buf[0]));
    case LIP_FMT_STR_8:
        *size = __lip_load_num8(buf + 1).u;
    case LIP_FMT_STR_16:
        *size = __lip_load_num16(buf + 1).u;
    case LIP_FMT_STR_32:
        *size = __lip_load_num32(buf + 1).u;
    }
    return 0;
}

unsigned lip_unpack_str_data(uint8_t const buf[static 1], unsigned size,
                             char str[static 1])
{
    return __lip_load_str_body(buf, size, str);
}

unsigned lip_unpack_array_head(uint8_t const buf[static 1], unsigned *size)
{
    switch (lip_format(buf))
    {
    case LIP_FMT_FIXARRAY:
        return __lip_format_fix_pvalue(NUM8(buf[0]));
    case LIP_FMT_ARRAY_16:
        return __lip_load_num16_body(buf + 1, (union num16 *)size);
    case LIP_FMT_ARRAY_32:
        return __lip_load_num32_body(buf + 1, (union num32 *)size);
    }
    return 0;
}

unsigned lip_unpack_map_size(uint8_t const buf[static 1], unsigned *size)
{
    switch (lip_format(buf))
    {
    case LIP_FMT_FIXMAP:
        *size = (unsigned)__lip_format_fix_value(buf[0]);
        return 1;
    case LIP_FMT_MAP_16:
        *size = __lip_load_num16(buf + 1).u;
        return 3;
    case LIP_FMT_MAP_32:
        *size = __lip_load_num32(buf + 1).u;
        return 5;
    }
    return 0;
}
