#include "lite_pack/unpack_object.h"
#include "lite_pack/bug.h"
#include "lite_pack/format.h"
#include "lite_pack/object.h"
#include "lite_pack/unpack_array.h"
#include "lite_pack/unpack_bool.h"
#include "lite_pack/unpack_ext.h"
#include "lite_pack/unpack_float.h"
#include "lite_pack/unpack_int.h"
#include "lite_pack/unpack_map.h"
#include "lite_pack/unpack_str.h"

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

        return lip_unpack_bool(buf, &obj->val.b);

    case LIP_FMT_FAMILY_INT:

        if (fmt == LIP_FMT_INT_8) return lip_unpack_int(buf, &obj->val.i8);
        if (fmt == LIP_FMT_INT_16) return lip_unpack_int(buf, &obj->val.i16);
        if (fmt == LIP_FMT_INT_32) return lip_unpack_int(buf, &obj->val.i32);
        if (fmt == LIP_FMT_INT_64) return lip_unpack_int(buf, &obj->val.i64);

        if (fmt == LIP_FMT_UINT_8) return lip_unpack_int(buf, &obj->val.u8);
        if (fmt == LIP_FMT_UINT_16) return lip_unpack_int(buf, &obj->val.u16);
        if (fmt == LIP_FMT_UINT_32) return lip_unpack_int(buf, &obj->val.u32);
        if (fmt == LIP_FMT_UINT_64) return lip_unpack_int(buf, &obj->val.u64);

        return __lip_bug_on_reach();

    case LIP_FMT_FAMILY_FLOAT:

        if (fmt == LIP_FMT_FLOAT_32) lip_unpack_float(buf, &obj->val.f32);
        if (fmt == LIP_FMT_FLOAT_64) lip_unpack_float(buf, &obj->val.f64);

        return __lip_bug_on_reach();

    case LIP_FMT_FAMILY_STR:

        return lip_unpack_str_size(buf, &obj->val.u);

    case LIP_FMT_FAMILY_BIN:

        return __lip_bug_on_reach();

    case LIP_FMT_FAMILY_ARRAY:

        return lip_unpack_array_size(buf, &obj->val.u);

    case LIP_FMT_FAMILY_MAP:

        return lip_unpack_map_size(buf, &obj->val.u);

    case LIP_FMT_FAMILY_EXT:

        return lip_unpack_ext_size_type(buf, &obj->val.u, &obj->type);

    case LIP_FMT_FAMILY_NEVER_USED:

        return __lip_bug_on_reach();

    default:
        return __lip_bug_on_reach();
    }

    return __lip_bug_on_reach();
}
