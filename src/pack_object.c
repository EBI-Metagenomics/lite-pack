#include "lite_pack/pack_object.h"
#include "lite_pack/compiler.h"
#include "lite_pack/object.h"
#include "lite_pack/pack_array.h"
#include "lite_pack/pack_bool.h"
#include "lite_pack/pack_ext.h"
#include "lite_pack/pack_float.h"
#include "lite_pack/pack_int.h"
#include "lite_pack/pack_map.h"
#include "lite_pack/pack_str.h"

LIP_API unsigned lip_pack_object(unsigned char buf[],
                                 struct lip_object const *obj)
{
    enum lip_format fmt = obj->format;
    enum lip_format_family family = obj->family;

    switch (family)
    {
    case LIP_FMT_FAMILY_NIL:

        return 1;

    case LIP_FMT_FAMILY_BOOL:

        return lip_pack_bool(buf, obj->value.b);

    case LIP_FMT_FAMILY_INT:

        if (fmt == LIP_FMT_POSITIVE_FIXINT)
            return lip_pack_int(buf, obj->value.u8);

        if (fmt == LIP_FMT_INT_8) return lip_pack_int(buf, obj->value.i8);
        if (fmt == LIP_FMT_INT_16) return lip_pack_int(buf, obj->value.i16);
        if (fmt == LIP_FMT_INT_32) return lip_pack_int(buf, obj->value.i32);
        if (fmt == LIP_FMT_INT_64) return lip_pack_int(buf, obj->value.i64);

        if (fmt == LIP_FMT_UINT_8) return lip_pack_int(buf, obj->value.u8);
        if (fmt == LIP_FMT_UINT_16) return lip_pack_int(buf, obj->value.u16);
        if (fmt == LIP_FMT_UINT_32) return lip_pack_int(buf, obj->value.u32);
        if (fmt == LIP_FMT_UINT_64) return lip_pack_int(buf, obj->value.u64);

        if (fmt == LIP_FMT_NEGATIVE_FIXINT)
            return lip_pack_int(buf, obj->value.i8);

        return __lip_bug_on_reach();

    case LIP_FMT_FAMILY_FLOAT:

        if (fmt == LIP_FMT_FLOAT_32) return lip_pack_float(buf, obj->value.f32);
        if (fmt == LIP_FMT_FLOAT_64) return lip_pack_float(buf, obj->value.f64);

        return __lip_bug_on_reach();

    case LIP_FMT_FAMILY_STR:

        return lip_pack_str_size(buf, obj->value.size);

    case LIP_FMT_FAMILY_BIN:

        return __lip_bug_on_reach();

    case LIP_FMT_FAMILY_ARRAY:

        return lip_pack_array_size(buf, obj->value.size);

    case LIP_FMT_FAMILY_MAP:

        return lip_pack_map_size(buf, obj->value.size);

    case LIP_FMT_FAMILY_EXT:

        return lip_pack_ext_size_type(buf, obj->value.size, obj->type);

    case LIP_FMT_FAMILY_NEVER_USED:

        return __lip_bug_on_reach();

    default:
        return __lip_bug_on_reach();
    }

    return __lip_bug_on_reach();
}
