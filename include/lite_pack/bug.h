#ifndef LITE_PACK_BUG_H
#define LITE_PACK_BUG_H

#include <assert.h>

static inline __attribute__((const)) int __lip_bug_on_reach(void)
{
    assert(0);
    return 0;
}

#endif
