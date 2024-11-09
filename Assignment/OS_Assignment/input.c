#include <stdio.h>
#include "input.h"

int read_solution(const char *filename, int Sol[9][9]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1; // indicates failure
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (fscanf(file, "%d", &Sol[i][j]) != 1) {
                fclose(file);
                fprintf(stderr, "Error reading file\n");
                return -1; // indicates failure
            }
        }
    }

    fclose(file);
    return 0; // success
}


