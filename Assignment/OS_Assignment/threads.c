#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include "threads.h"
#include "sync.h"

pthread_t threads[NUM_THREADS]; // Declare an array to hold thread IDs

void *validate_region(void *arg) {
    thread_data *data = (thread_data *)arg;  // Cast the argument to thread_data structure

    // Validate rows for Thread 1
    if (data->thread_id == 1) 
    {
        for (int i = 0; i < 3; i++) {  // Loop through the first three rows
            int valid_row = 1;         // Flag for row validation
            int seen[10] = {0};        // Array to keep track of seen values
            for (int j = 0; j < 9; j++) {   // Loop through each element in the row
                int num = data->Sol[i][j];  // Get the number from the Sudoku grid
                if (num < 1 || num > 9 || seen[num]) {  // to check if the number is valid or seen before
                    valid_row = 0;  // Mark the row as invalid
                    break;
                }
                seen[num] = 1;  // Mark the number as seen
            }
            if (valid_row && data->Row[i + 1] == 0) {  // Update row validation status and counter if valid
                data->Row[i + 1] = 1;
                *(data->Counter) += 1;
            }
        }
        // Validate sub-grids for Thread 1
        for (int k = 0; k < 3; k++) 
        {
            for (int l = 0; l < 3; l++) {
                int valid_subgrid = 1;  // Flag for sub-grid validation
                int seen[10] = {0};     // Array to keep track of seen values
                for (int i = 0; i < 3; i++) {   // Loop through each element in the sub-grid
                    for (int j = l * 3; j < (l + 1) * 3; j++) {
                        int num = data->Sol[k * 3 + i][j];
                        if (num < 1 || num > 9 || seen[num]) {
                            valid_subgrid = 0;
                            break;
                        }
                        seen[num] = 1;  
                    }
                }
                int subgrid_index = k * 3 + l + 1;  // Update sub-grid validation status and counter if valid
                if (valid_subgrid && data->Sub[subgrid_index] == 0) 
                {
                    data->Sub[subgrid_index] = 1;
                    *(data->Counter) += 1;
                }
            }
        }
    }

    // Validate rows for Thread 2
    else if (data->thread_id == 2) 
    {
        for (int i = 3; i < 6; i++) {  
            int valid_row = 1;         // Flag for row validation
            int seen[10] = {0}; // Array to keep track of seen values
            for (int j = 0; j < 9; j++) {  // Loop through each element in the row
                int num = data->Sol[i][j];
                if (num < 1 || num > 9 || seen[num]) {
                    valid_row = 0;
                    break;
                }
                seen[num] = 1;   // Mark the number as seen
            }
            if (valid_row && data->Row[i + 1] == 0) {  // Update row validation status and counter if valid
                data->Row[i + 1] = 1;
                *(data->Counter) += 1;
            }
        }
        // Validate sub-grids for Thread 2
        for (int k = 1; k < 4; k++) 
        {
            for (int l = 0; l < 3; l++) {
                int valid_subgrid = 1;  
                int seen[10] = {0};     // Array to keep track of seen values
                for (int i = 0; i < 3; i++) {  // Loop through each element in the sub-grid
                    for (int j = l * 3; j < (l + 1) * 3; j++) {
                        int num = data->Sol[k * 3 + i][j];
                        if (num < 1 || num > 9 || seen[num]) {  // Check if the number is valid or seen before
                            valid_subgrid = 0;
                            break;
                        }
                        seen[num] = 1;  
                    }
                }
                int subgrid_index = k * 3 + l + 1;   // Update sub-grid validation status and counter if valid
                if (valid_subgrid && data->Sub[subgrid_index] == 0) 
                {
                    data->Sub[subgrid_index] = 1;
                    *(data->Counter) += 1;
                }
            }
        }
    }

    // Validate rows for Thread 3
    else if (data->thread_id == 3) 
    {
        for (int i = 6; i < 9; i++) {  
            int valid_row = 1;
            int seen[10] = {0}; // Array to keep track of seen values
            for (int j = 0; j < 9; j++) {
                int num = data->Sol[i][j];
                if (num < 1 || num > 9 || seen[num]) { // Check if the number is valid or seen before
                    valid_row = 0;
                    break;
                }
                seen[num] = 1;  
            }
            if (valid_row && data->Row[i + 1] == 0) {  // Update row validation status and counter if valid
                data->Row[i + 1] = 1;
                *(data->Counter) += 1;
            }
        }
        // Validate sub-grids for Thread 3
        for (int k = 2; k < 5; k++) {
            for (int l = 0; l < 3; l++) {
                int valid_subgrid = 1;   
                int seen[10] = {0};      
                for (int i = 0; i < 3; i++) {  // Loop through each element in the sub-grid
                    for (int j = l * 3; j < (l + 1) * 3; j++) {
                        int num = data->Sol[k * 3 + i][j];
                        if (num < 1 || num > 9 || seen[num]) {  // Check if the number is valid or seen before
                            valid_subgrid = 0;
                            break;
                        }
                        seen[num] = 1;  // Mark the number as seen
                    }
                }
                int subgrid_index = k * 3 + l + 1;  // Update sub-grid validation status and counter if valid
                if (valid_subgrid && data->Sub[subgrid_index] == 0) 
                {
                    data->Sub[subgrid_index] = 1;
                    *(data->Counter) += 1;
                }
            }
        }
    }

    // Validate columns for Thread 4
    else if (data->thread_id == 4) 
    {
        for (int j = 0; j < 9; j++) {  // Loop through each column
            int valid_col = 1;
            int seen[10] = {0}; // Array to keep track of seen values
            for (int i = 0; i < 9; i++) {
                int num = data->Sol[i][j];
                if (num < 1 || num > 9 || seen[num]) {
                    valid_col = 0;
                    break;
                }
                seen[num] = 1; // Mark the number as seen
            }
            if (valid_col && data->Col[j + 1] == 0) {  // Update column validation status and counter if valid
                data->Col[j + 1] = 1; 
                *(data->Counter) += 1;
            }
        }
    }

    // Sleep for the specified delay by the user input
    sleep(data->delay);

    // to signal parent thread that validation is complete
    pthread_mutex_lock(&mutex);
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);  // Exit the thread
}

void create_threads(int Sol[9][9], int Row[10], int Col[10], int Sub[10], int *Counter, int delay) {
    pthread_attr_t attr;  // Thread attribute variable
    pthread_attr_init(&attr);  // Initialize thread attributes
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);  // Set attributes for joinable threads

    // Create 4 threads
    for (int i = 0; i < 4; i++) {
        thread_data *data = (thread_data *)malloc(sizeof(thread_data));  // Allocate memory for thread data
        if (data == NULL) {
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }
        data->thread_id = i + 1;  // Assign thread ID
        data->Sol = Sol;
        data->Row = Row;
        data->Col = Col;
        data->Sub = Sub;
        data->Counter = Counter;
        data->delay = delay;

        // Assign regions to each thread
        switch (i) {
            case 0: // Thread 1 
                data->start_row = 0;
                data->end_row = 3;
                break;
            case 1: // Thread 2 
                data->start_row = 3;
                data->end_row = 6;
                break;
            case 2: // Thread 3 
                data->start_row = 6;
                data->end_row = 9;
                break;
            case 3: // Thread 4 
                data->start_row = 0;
                data->end_row = 9;
                break;
        }
        // Create thread with specified attributes
        pthread_create(&threads[i], &attr, validate_region, (void *)data);
    }

    pthread_attr_destroy(&attr);  // Destroy thread attributes
}

void wait_threads(thread_data *data[NUM_THREADS]) {
    for (int i = 0; i < 4; i++) {  // Wait for all threads to finish
        pthread_join(threads[i], NULL);
    }
}

