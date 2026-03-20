#include <stdio.h>
#include "formatter.h"
#include "abnt.h"

int format_reference(CitationStyle style, BibEntry *entry, char *out, size_t size) {
    if (style == STYLE_ABNT) {
        format_abnt(entry, out, size);
        return 1;
    }

    if (style == STYLE_APA) {
        printf("Erro: estilo APA ainda não implementado.\n");
        return 0;
    }

    if (style == STYLE_VANCOUVER) {
        printf("Erro: estilo Vancouver ainda não implementado.\n");
        return 0;
    }

    printf("Erro: estilo desconhecido.\n");
    return 0;
}
