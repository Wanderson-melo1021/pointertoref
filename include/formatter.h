#ifndef FORMATER_H
#define FORMATER_H

#include <stddef.h>
#include "bibtex.h"
#include "style.h"

int format_reference(CitationStyle style, BibEntry *entry, char *out, size_t size);

#endif
