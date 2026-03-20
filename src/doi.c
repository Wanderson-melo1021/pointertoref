#include <string.h>
#include "doi.h"

int is_valid_doi_input(const char *arg) {
    
    if (arg == NULL) return 0;

    return strcmp(arg, "--doi") == 0;
}
