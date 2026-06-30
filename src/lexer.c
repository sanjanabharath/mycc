#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char** readFile(const char* filename, int* tokenCount) {

    FILE* file = fopen(filename, "r");

    if (file == NULL)
        return NULL;

    *tokenCount = 0;

    char** tokens = malloc(1000 * sizeof(char*));

    if (tokens == NULL) {
        fclose(file);
        return NULL;
    }

    char line[1000];

    while (fgets(line, sizeof(line), file)) {

        int i = 0;

        while (line[i] != '\0') {

            if (isspace(line[i])) {
                i++;
                continue;
            }

            // Symbols → separate token
            if (strchr(";(){}+-=", line[i])) {

                tokens[*tokenCount] = malloc(2);

                tokens[*tokenCount][0] = line[i];
                tokens[*tokenCount][1] = '\0';

                (*tokenCount)++;
                i++;

                continue;
            }

            // Read normal word
            char temp[100];
            int j = 0;

            while (
                line[i] != '\0' &&
                !isspace(line[i]) &&
                !strchr(";(){}+-=", line[i])
            ) {
                temp[j++] = line[i++];
            }

            temp[j] = '\0';

            tokens[*tokenCount] = malloc(j + 1);

            strcpy(tokens[*tokenCount], temp);

            (*tokenCount)++;
        }
    }

    fclose(file);

    return tokens;
}