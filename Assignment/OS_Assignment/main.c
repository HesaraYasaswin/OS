#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "threads.h"
#include "results.h"
#include "cleanup.h"

int main(int argc, char *argv[]) {
    // Check command-line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s solution delay\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse command-line arguments
    const char *solution_file = argv[1];
    int delay = atoi(argv[2]);

    // Initialize variables
    int Sol[9][9];
    int Row[10] = {0}; 
    int Col[10] = {0}; 
    int Sub[10] = {0}; 
    int Counter = 0;

    // Read solution from file
    if (read_solution(solution_file, Sol) != 0) {
        fprintf(stderr, "Error: Unable to read solution file.\n");
        return EXIT_FAILURE;
    }

    // Create threads
    create_threads(Sol, Row, Col, Sub, &Counter, delay);

    // Allocate memory for thread data structures
    thread_data *data[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        data[i] = malloc(sizeof(thread_data));
        if (data[i] == NULL) {
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for the threads to complete
    wait_threads(data);

   
    print_results(Row, Col, Sub, Counter);

    // Clean up threads and free memory
    cleanup_threads(data);

    return EXIT_SUCCESS;
}



