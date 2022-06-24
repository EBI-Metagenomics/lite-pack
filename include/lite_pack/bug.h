#ifndef LITE_PACK_BUG_H
#define LITE_PACK_BUG_H

#include "lite_pack/compiler.h"
#include <assert.h>

__attribute__((const)) static __always_inline int __lip_bug_on_reach(void)
{
    assert(0);
    return 0;
}

#endif
