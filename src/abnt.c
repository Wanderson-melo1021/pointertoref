#include <stdio.h>
#include <string.h>
#include "abnt.h"

void format_authors_abnt(const char *authors_raw, char *output, size_t size) {
    if (authors_raw == NULL || output == NULL || size == 0) {
        return;
    }

    output[0] = '\0';

    char buffer[2048];
    strncpy(buffer, authors_raw, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';

    char *authors[20];
    int count = 0;

    char *start = buffer;
    while (count < 20) {
        char *pos = strstr(start, " and ");
        if (pos == NULL) {
            authors[count++] = start;
            break;
        }

        *pos = '\0';
        authors[count++] = start;
        start = pos + 5;
    }

    if (count == 0) {
        return;
    }

    if (count <= 3) {
        for (int i = 0; i < count; i++) {
            strncat(output, authors[i], size - strlen(output) - 1);

            if (i < count - 1) {
                strncat(output, "; ", size - strlen(output) - 1);
            }
        }
    } else {
        strncat(output, authors[0], size - strlen(output) - 1);
        strncat(output, " et al", size - strlen(output) - 1);
    }
}

void format_abnt(const BibEntry *entry, char *output, size_t size) {
    char authors[2048];
    char details[1024] = "";

    format_authors_abnt(entry->author, authors, sizeof(authors));

    if (strlen(entry->volume) > 0) {
        strncat(details, "v. ", sizeof(details) - strlen(details) - 1);
        strncat(details, entry->volume, sizeof(details) - strlen(details) - 1);
    }

    if (strlen(entry->number) > 0) {
        if (strlen(details) > 0) {
            strncat(details, ", ", sizeof(details) - strlen(details) - 1);
        }
        strncat(details, "n. ", sizeof(details) - strlen(details) - 1);
        strncat(details, entry->number, sizeof(details) - strlen(details) - 1);
    }

    if (strlen(entry->pages) > 0) {
        if (strlen(details) > 0) {
            strncat(details, ", ", sizeof(details) - strlen(details) - 1);
        }
        strncat(details, "p. ", sizeof(details) - strlen(details) - 1);
        strncat(details, entry->pages, sizeof(details) - strlen(details) - 1);
    }

    if (strlen(details) > 0) {
        snprintf(
            output,
            size,
            "%s. %s. %s, %s, %s. Disponível em: %s. Acesso em: 19 mar. 2026.",
            authors,
            entry->title,
            entry->journal,
            details,
            entry->year,
            entry->url
        );
    } else {
        snprintf(
            output,
            size,
            "%s. %s. %s, %s. Disponível em: %s. Acesso em: 19 mar. 2026.",
            authors,
            entry->title,
            entry->journal,
            entry->year,
            entry->url
        );
    }
}
