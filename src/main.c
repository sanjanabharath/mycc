#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"

int main() {
    int tokenCount;
    char** tokens = readFile("input.c", &tokenCount);

    for(int i=0; i<tokenCount; i++) {
        printf("%s\n", tokens[i]);
        free(tokens[i]);
    }
    free(tokens);

    return 0;
}