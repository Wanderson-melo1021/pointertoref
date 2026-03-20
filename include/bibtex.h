#ifndef BIBTEX_H
#define BIBTEX_H

#include <stddef.h>

typedef struct {
    char entry_type[50];
    char citation_key[100];
    char author[500];
    char title[500];
    char journal[300];
    char year[20];
    char volume[50];
    char number[50];
    char pages[50];
    char doi[150];
    char url[300];
    char publisher[200];
} BibEntry;

void extract_entry_header(const char *bibtex, BibEntry *entry);
void extract_field(const char *bibtex, const char *field, char *dest, size_t size);
int parse_bibtex(const char *bibtex, BibEntry *entry);

#endif
