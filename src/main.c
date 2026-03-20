#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doi.h"
#include "fetch.h"
#include "bibtex.h"
#include "abnt.h"
#include "style.h"
#include "formatter.h"


int main(int argc, char *argv[]) {
    const char *doi_input = NULL;
    CitationStyle style = STYLE_ABNT;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--doi") == 0) {
            if (i + 1 >= argc) {
                printf("Erro: --doi requer um valor.\n");
                return 1;
            }
            doi_input = argv[i + 1];
            i++;
        } else if (strcmp(argv[i], "--style") == 0) {
            if (i + 1 >= argc) {
                printf("Erro: --style requer um valor.\n");
                return 1;
            }

            style = parse_style(argv[i + 1]);

            if (style == STYLE_UNKNOWN) {
                printf("Erro: estilo inválido.\n");
                return 1;
            }

            i++;
        } else {
            printf("Erro: argumento desconhecido.\n");
            return 1;
        }
    }

    if (doi_input == NULL) {
        printf("Uso:\n");
        printf("  ./pointertoref --doi <DOI>\n");
        return 1;
    }

    char *bibtex = fetch_bibtex_by_doi(doi_input);

    if (bibtex == NULL) {
        printf("Erro ao buscar BibTex.\n");
        return 1;
    }

    BibEntry entry;

    if (!parse_bibtex(bibtex, &entry)) {
        printf("Erro ao processar BibTex.\n");
        free(bibtex);
        return 1;
    }

    printf("\n=== RESULTADO PARSEADO ===\n");
    printf("Autor: %s\n", entry.author);
    printf("Título: %s\n", entry.title);
    printf("Periódico: %s\n", entry.journal);
    printf("Ano: %s\n", entry.year);
    printf("Volume: %s\n", entry.volume);
    printf("Número: %s\n", entry.number);
    printf("Páginas: %s\n", entry.pages);
    printf("DOI: %s\n", entry.doi);
    printf("URL: %s\n", entry.url);
    printf("Editora: %s\n", entry.publisher);
    printf("Tipo: %s\n", entry.entry_type);
    printf("Chave: %s\n", entry.citation_key);

    char reference[2048];

    if (!format_reference(style, &entry, reference, sizeof(reference))) {
        free(bibtex);
        return 1;
    }

    printf("\n=== REFERÊNCIA ===\n");
    printf("%s\n", reference);

    return 0;
}
