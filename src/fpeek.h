#ifndef FPEEK_H
#define FPEEK_H

#include <stdbool.h>
#include <stdio.h>

static inline bool fpeek(FILE *fp, int *ch)
{
    *ch = fgetc(fp);
    ungetc(*ch, fp);
    return *ch != EOF;
}

#endif
