#include "lite_pack/file/read_object.h"
#include "lite_pack/file/file.h"
#include "lite_pack/file/read_array.h"
#include "lite_pack/file/read_bool.h"
#include "lite_pack/file/read_ext.h"
#include "lite_pack/file/read_float.h"
#include "lite_pack/file/read_int.h"
#include "lite_pack/file/read_map.h"
#include "lite_pack/file/read_str.h"
#include "lite_pack/format.h"
#include "lite_pack/object.h"

static inline int fpeek(FILE *fp)
{
    int c = fgetc(fp);
    ungetc(c, fp);

    return c;
}

bool lip_read_object(struct lip_file *file, struct lip_object *obj)
{
    if (file->error) return false;

    int ch = fpeek(lip_file_ptr(file));
    if (ch == EOF) return false;

    enum lip_format fmt = lip_format(ch);
    enum lip_format_family family = lip_format_family(fmt);

    switch (family)
    {
    case LIP_FMT_FAMILY_NIL:

        return true;

    case LIP_FMT_FAMILY_BOOL:

        return lip_read_bool(file, &obj->val.b);

    case LIP_FMT_FAMILY_INT:

        if (fmt == LIP_FMT_INT_8) return lip_read_int(file, &obj->val.i8);
        if (fmt == LIP_FMT_INT_16) return lip_read_int(file, &obj->val.i16);
        if (fmt == LIP_FMT_INT_32) return lip_read_int(file, &obj->val.i32);
        if (fmt == LIP_FMT_INT_64) return lip_read_int(file, &obj->val.i64);

        if (fmt == LIP_FMT_UINT_8) return lip_read_int(file, &obj->val.u8);
        if (fmt == LIP_FMT_UINT_16) return lip_read_int(file, &obj->val.u16);
        if (fmt == LIP_FMT_UINT_32) return lip_read_int(file, &obj->val.u32);
        if (fmt == LIP_FMT_UINT_64) return lip_read_int(file, &obj->val.u64);

        return __lip_bug_on_reach();

    case LIP_FMT_FAMILY_FLOAT:

        if (fmt == LIP_FMT_FLOAT_32) lip_read_float(file, &obj->val.f32);
        if (fmt == LIP_FMT_FLOAT_64) lip_read_float(file, &obj->val.f64);

        return __lip_bug_on_reach();

    case LIP_FMT_FAMILY_STR:

        return lip_read_str_size(file, &obj->val.u);

    case LIP_FMT_FAMILY_BIN:

        return __lip_bug_on_reach();

    case LIP_FMT_FAMILY_ARRAY:

        return lip_read_array_size(file, &obj->val.u);

    case LIP_FMT_FAMILY_MAP:

        return lip_read_map_size(file, &obj->val.u);

    case LIP_FMT_FAMILY_EXT:

        return lip_read_ext_size_type(file, &obj->val.u, &obj->type);

    case LIP_FMT_FAMILY_NEVER_USED:

        return __lip_bug_on_reach();

    default:
        return __lip_bug_on_reach();
    }

    return __lip_bug_on_reach();
}
