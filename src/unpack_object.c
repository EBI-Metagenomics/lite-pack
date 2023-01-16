#include "lip/unpack_object.h"
#include "lip/compiler.h"
#include "lip/format.h"
#include "lip/object.h"
#include "lip/unpack_array.h"
#include "lip/unpack_bool.h"
#include "lip/unpack_ext.h"
#include "lip/unpack_float.h"
#include "lip/unpack_int.h"
#include "lip/unpack_map.h"
#include "lip/unpack_str.h"

unsigned lip_unpack_object(unsigned char const buf[], struct lip_object *obj)
{
    lip_object_init(obj);

    enum lip_format fmt = lip_format(buf[0]);
    enum lip_format_family family = lip_format_family(fmt);

    obj->format = fmt;
    obj->family = family;

    switch (family)
    {
    case LIP_FMT_FAMILY_NIL:

        return 1;

    case LIP_FMT_FAMILY_BOOL:

        return lip_unpack_bool(buf, &obj->value.b);

    case LIP_FMT_FAMILY_INT:

        if (fmt == LIP_FMT_POSITIVE_FIXINT)
            return lip_unpack_int(buf, &obj->value.u8);

        if (fmt == LIP_FMT_INT_8) return lip_unpack_int(buf, &obj->value.i8);
        if (fmt == LIP_FMT_INT_16) return lip_unpack_int(buf, &obj->value.i16);
        if (fmt == LIP_FMT_INT_32) return lip_unpack_int(buf, &obj->value.i32);
        if (fmt == LIP_FMT_INT_64) return lip_unpack_int(buf, &obj->value.i64);

        if (fmt == LIP_FMT_UINT_8) return lip_unpack_int(buf, &obj->value.u8);
        if (fmt == LIP_FMT_UINT_16) return lip_unpack_int(buf, &obj->value.u16);
        if (fmt == LIP_FMT_UINT_32) return lip_unpack_int(buf, &obj->value.u32);
        if (fmt == LIP_FMT_UINT_64) return lip_unpack_int(buf, &obj->value.u64);

        if (fmt == LIP_FMT_NEGATIVE_FIXINT)
            return lip_unpack_int(buf, &obj->value.i8);

        return __lip_bug_on_reach();

    case LIP_FMT_FAMILY_FLOAT:

        if (fmt == LIP_FMT_FLOAT_32)
            return lip_unpack_float(buf, &obj->value.f32);
        if (fmt == LIP_FMT_FLOAT_64)
            return lip_unpack_float(buf, &obj->value.f64);

        return __lip_bug_on_reach();

    case LIP_FMT_FAMILY_STR:

        return lip_unpack_str_size(buf, &obj->value.size);

    case LIP_FMT_FAMILY_BIN:

        return __lip_bug_on_reach();

    case LIP_FMT_FAMILY_ARRAY:

        return lip_unpack_array_size(buf, &obj->value.size);

    case LIP_FMT_FAMILY_MAP:

        return lip_unpack_map_size(buf, &obj->value.size);

    case LIP_FMT_FAMILY_EXT:

        return lip_unpack_ext_size_type(buf, &obj->value.size, &obj->type);

    case LIP_FMT_FAMILY_NEVER_USED:

        return __lip_bug_on_reach();

    default:
        return __lip_bug_on_reach();
    }

    return __lip_bug_on_reach();
}
