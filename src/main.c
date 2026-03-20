#include <stdio.h>
#include <stdlib.h>
#include "doi.h"
#include "fetch.h"
#include "bibtex.h"

int main(int argc, char *argv[]) {
    
    if (argc != 3) {
        printf("Uso:\n");
        printf("  ./pointertoref --doi <DOI>\n");
        return 1;
    }

    if (!is_valid_doi_input(argv[1])) {
        printf("Erro: flag inválida.\n");
        return 1;
    }

    char *bibtex = fetch_bibtex_by_doi(argv[2]);

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

    free(bibtex);

    return 0;
}
