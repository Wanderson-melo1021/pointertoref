#include <string.h>
#include "style.h"

CitationStyle parse_style(const char *value) {
    if (strcmp(value, "abnt") == 0) {
        return STYLE_ABNT;
    }

    if (strcmp(value, "apa") == 0) {
        return STYLE_APA;
    }

    if (strcmp(value, "vancouver") == 0) {
        return STYLE_VANCOUVER;
    }

    return STYLE_UNKNOWN;
}
