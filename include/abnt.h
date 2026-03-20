#ifndef ABNT_H
#define ABNT_H

#include <stddef.h>
#include "bibtex.h"

void format_single_author_abnt(const char *author_raw, char *output, size_t size);
void format_authors_abnt(const char *authors_raw, char *output, size_t size);
void format_abnt(const BibEntry *entry, char *output, size_t size);

#endif
