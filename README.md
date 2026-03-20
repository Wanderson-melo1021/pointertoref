# pointertoref

Ferramenta em C para recuperar referências bibliográficas a partir de um DOI.

## Descrição

O programa recebe um DOI como entrada, busca o registro em formato BibTex via HTTP e converte os dados para uma estrutura interna, com objetivo de gerar referências em diferentes estilos (ABNT, APA, Vancouver...).

## Funcionalidades atuais

-   Recebe DOI via linha de comando
-   Busca BibTeX usando curl
-   Faz parsing dos campos principais:
    -   author
    -   title
    -   journal
    -   year
    -   volume
    -   pages
    -   doi
    -   url
-   Extrai tipo de entrada e chave BibTeX

## Como compilar

### Requisitos

-   gcc
-   make
-   curl

Em sistemas Linux (Ubuntu/Debian), você pode instalar com:

``` bash
sudo apt update
sudo apt install build-essential curl
```

## Compilação

``` bash
make
```

## Como executar

``` bash
./pointertoref --doi <DOI>
```

## Exemplo:

```         
./pointertoref --doi 10.1139/cjpp-2025-0146
```

```
=== RESULTADO PARSEADO ===
Autor: Melo, Wanderson Gabriel Gomes de and dos Santos Silva, Regina Lúcia and Santos Soares, Ianahanna Duarte and de Sousa Barbosa, Bruno and Cardoso de Brito, Felipe and Argôlo Neto, Napoleão Martins and Bezerra, Dayseanny de Oliveira
Título: GLP-1 and diabetic nephropathy share key molecular targets
Periódico: Canadian Journal of Physiology and Pharmacology
Ano: 2026
Volume: 104
Número:
Páginas: 1–10
DOI: 10.1139/cjpp-2025-0146
URL: http://dx.doi.org/10.1139/cjpp-2025-0146
Editora: Canadian Science Publishing
Tipo: article
Chave: Melo_2026
```

## Estrutura do projeto

```   
.
├── data
│   ├── input
│   └── output
├── include
│   ├── abnt.h
│   ├── bibtex.h
│   ├── doi.h
│   ├── fetch.h
│   └── io.h
├── Makefile
├── README.html
├── README.md
├── src
│   ├── abnt.c
│   ├── bibtex.c
│   ├── doi.c
│   ├── fetch.c
│   ├── io.c
│   └── main.c
└── tests
```

## Proximos passos

-   Formatação em ABNT
-   Suporte a APA, Vancouver
-   Tratamento de autores
-   Suporte a múltiplos DOIs

------------------------------------------------------------------------
