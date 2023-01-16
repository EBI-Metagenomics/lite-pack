#include "lip/object.h"
#include <string.h>

void lip_object_init(struct lip_object *obj) { memset(obj, 0, sizeof(*obj)); }
