#include "lip/pack_bool.h"
#include "lip/store_bool.h"

unsigned lip_pack_bool(unsigned char buf[], bool val)
{
    return lip_store_bool(buf, val);
}
