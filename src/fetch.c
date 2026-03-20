#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fetch.h"

char *fetch_bibtex_by_doi(const char *doi) {

    char command[1024];

    snprintf(
        command,
        sizeof(command),
        "curl -L -s -H 'Accept: application/x-bibtex' https://doi.org/%s",
        doi
    );

    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        return NULL;
    }

    char buffer[256];
    size_t total_size = 1;

    char *result = malloc(total_size);
    if (!result) {
        pclose(fp);
        return NULL;
    }

    result[0] = '\0';

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        size_t len = strlen(buffer);

        char *tmp = realloc(result, total_size + len);
        if (!tmp) {
            free(result);
            pclose(fp);
            return NULL;
        }

        result = tmp;
        strcpy(result + total_size - 1, buffer);
        total_size += len;
    }

    pclose(fp);

    return result;
}
