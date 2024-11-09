#include <stdio.h>
#include "results.h"

void print_results(const int Row[10], const int Col[10], const int Sub[10], const int Counter) {
    // for Thread 1
    printf("Thread ID-1: ");
    if (Row[1] && Row[2] && Row[3] && Sub[1] && Sub[2] && Sub[3])  // Check if rows 1, 2, 3 and sub-grids 1, 2, 3 are valid
        printf("valid\n");
    else {
        printf("invalid - ");
        if (!Row[1]) printf("row 1 ");
        if (!Row[2]) printf("row 2 ");
        if (!Row[3]) printf("row 3 ");
        if (!Sub[1]) printf("sub-grid 1 ");
        if (!Sub[2]) printf("sub-grid 2 ");
        if (!Sub[3]) printf("sub-grid 3 ");
        printf("\n");
    }

    // for Thread 2
    printf("Thread ID-2: ");
    if (Row[4] && Row[5] && Row[6] && Sub[4] && Sub[5] && Sub[6]) // Check if rows 4, 5, 6 and sub-grids 4, 5, 6 are valid
        printf("valid\n");
    else {
        printf("invalid - ");
        if (!Row[4]) printf("row 4 ");
        if (!Row[5]) printf("row 5 ");
        if (!Row[6]) printf("row 6 ");
        if (!Sub[4]) printf("sub-grid 4 ");
        if (!Sub[5]) printf("sub-grid 5 ");
        if (!Sub[6]) printf("sub-grid 6 ");
        printf("\n");
    }

    // for Thread 3
    printf("Thread ID-3: ");
    if (Row[7] && Row[8] && Row[9] && Sub[7] && Sub[8] && Sub[9]) // Check if rows 7, 8, 9 and sub-grids 7, 8, 9 are valid
        printf("valid\n");
    else {
        printf("invalid - ");
        if (!Row[7]) printf("row 7 ");
        if (!Row[8]) printf("row 8 ");
        if (!Row[9]) printf("row 9 ");
        if (!Sub[7]) printf("sub-grid 7 ");
        if (!Sub[8]) printf("sub-grid 8 ");
        if (!Sub[9]) printf("sub-grid 9 ");
        printf("\n");
    }

    // for Thread 4
    printf("Thread ID-4: ");
    int valid_cols = 0;
    for (int i = 1; i <= 9; i++) {
        if (Col[i])
            valid_cols++;
    }
    if (valid_cols == 9)
        printf("valid\n");
    else {
        printf("invalid - ");
        for (int i = 1; i <= 9; i++) {
            if (!Col[i])
                printf("column %d ", i);   // Print invalid if column i is not valid
        }
        printf("\n");
    }

    // To determine the solution's validity based on the counter and the number of valid sub-grids
    printf("There are %d valid sub-grids, and thus the solution is %s\n",
           Counter, (Counter == 27) ? "valid" : "invalid");
}


