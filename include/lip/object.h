#ifndef LIP_OBJECT_H
#define LIP_OBJECT_H

#include "lip/export.h"
#include "lip/format.h"

struct lip_object
{
    enum lip_format format;
    enum lip_format_family family;
    uint8_t type;
    union
    {
        bool b;

        unsigned size;

        uint8_t u8;
        uint16_t u16;
        uint32_t u32;
        uint64_t u64;

        int8_t i8;
        int16_t i16;
        int32_t i32;
        int64_t i64;

        float f32;
        double f64;
    } value;
};

LIP_API void lip_object_init(struct lip_object *obj);

#endif
