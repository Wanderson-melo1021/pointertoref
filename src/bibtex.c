#include <string.h>
#include "bibtex.h"

void extract_field(const char *bibtex, const char *field, char *dest, size_t size) {
    const char *start = strstr(bibtex, field);

    if (start == NULL) {
        dest[0] = '\0';
        return;
    }

    start = strchr(start, '{');
    if (start == NULL) {
        dest[0] = '\0';
        return;
    }

    start++;

    const char *end = strchr(start, '}');
    if (end == NULL) {
        dest[0] = '\0';
        return;
    }

    size_t len = (size_t)(end - start);

    if (len >= size) {
        len = size - 1;
    }

    strncpy(dest, start, len);
    dest[len] = '\0';
}

void extract_entry_header(const char *bibtex, BibEntry *entry) {
    if (bibtex == NULL || entry == NULL) {
        return;
    }

    const char *at = strchr(bibtex, '@');
    if (at == NULL) {
        entry->entry_type[0] = '\0';
        entry->citation_key[0] = '\0';
        return;
    }

    const char *open_brace = strchr(at, '{');
    if (open_brace == NULL) {
        entry->entry_type[0] = '\0';
        entry->citation_key[0] = '\0';
        return;
    }

    size_t type_len = (size_t)(open_brace - at - 1);
    if (type_len >= sizeof(entry->entry_type)) {
        type_len = sizeof(entry->entry_type) - 1;
    }

    strncpy(entry->entry_type, at + 1, type_len);
    entry->entry_type[type_len] = '\0';

    const char *comma = strchr(open_brace, ',');
    if (comma == NULL) {
        entry->citation_key[0] = '\0';
        return;
    }

    size_t key_len = (size_t)(comma - open_brace - 1);
    if (key_len >= sizeof(entry->citation_key)) {
        key_len = sizeof(entry->citation_key) - 1;
    }

    strncpy(entry->citation_key, open_brace + 1, key_len);
    entry->citation_key[key_len] = '\0';
}

int parse_bibtex(const char *bibtex, BibEntry *entry) {

    if (bibtex == NULL || entry == NULL) {
        return 0;
    }

    extract_entry_header(bibtex, entry);

    extract_field(bibtex, "author", entry->author, sizeof(entry->author));
    extract_field(bibtex, "title", entry->title, sizeof(entry->title));
    extract_field(bibtex, "journal", entry->journal, sizeof(entry->journal));
    extract_field(bibtex, "year", entry->year, sizeof(entry->year));
    extract_field(bibtex, "volume", entry->volume, sizeof(entry->volume));
    extract_field(bibtex, "number", entry->number, sizeof(entry->number));
    extract_field(bibtex, "pages", entry->pages, sizeof(entry->pages));
    extract_field(bibtex, "doi", entry->doi, sizeof(entry->doi));
    extract_field(bibtex, "url", entry->url, sizeof(entry->url));
    extract_field(bibtex, "publisher", entry->publisher, sizeof(entry->publisher));

    return 1;
}
