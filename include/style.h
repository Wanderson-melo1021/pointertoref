#ifndef STYLE_H
#define STYLE_H

typedef enum {
    STYLE_ABNT,
    STYLE_APA,
    STYLE_VANCOUVER,
    STYLE_UNKNOWN
} CitationStyle;

CitationStyle parse_style(const char *value);

#endif
